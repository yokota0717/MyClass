/**
* @file SceneManager.hpp
* @brief �V�[���Ǘ����s���N���X���`����
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include <iostream>
#include <stack>
#include "SceneInfo.hpp"
#include "Scene/Title.h"
#include "Scene/Stage1.h"
#include "../Utility/Error.hpp"

namespace Scene {
	/**
	* @brief �V�[���Ǘ����s��
	*/
	class SceneManager : public IOnSceneChangedListener {
	private:
		//! �V�[���̃X�^�b�N�A������炱���ɐς�
		std::stack<AbstractScene*> sceneStack_;
	public:
		SceneManager() {
			Parameter param;
			sceneStack_.push(new Title(this, param));		//�ŏ��̃V�[����ݒ�(�^�C�g��)
		}
		~SceneManager() {
			while (!sceneStack_.empty()) {
				deleteScene();
			}
		}
		void onSceneChanged(const SceneName& scene, [[maybe_unused]]const Parameter* param, const StackPopFlag stackPopFlag) override {
			switch (stackPopFlag) {
			case StackPopFlag::NON:
				break;
			case StackPopFlag::POP:
				deleteScene();
				break;
			case StackPopFlag::ALL_CLEAR:
				stackClear();
			}
			switch (scene) {
			case Scene::SceneName::TITLE:
				sceneStack_.push(new Title(this, *param));
				break;
			case Scene::SceneName::GAME:
				sceneStack_.push(new Stage1(this, *param));
				break;
			case Scene::SceneName::BACK_SCENE:
				break;
			case Scene::SceneName::NON:
				std::cout << "�V�[���Ȃ�" << std::endl;
			default:
				ERR("���݂��Ȃ��V�[�����Ă΂�܂���");
				break;
			}
		}

		/**
		* @brief �X�^�b�N����Ă���V�[�������ׂď�������
		*/
		void stackClear() {
			while (!sceneStack_.empty()) {
				sceneStack_.pop();
			}
		}
		/**
		* @brief �X�^�b�N�̃g�b�v�ɂ���V�[���̃��������������
		*/
		void deleteScene() {
			delete sceneStack_.top();
			sceneStack_.top() = nullptr;
			sceneStack_.pop();
		}
		/**
		* @brief �X�^�b�N�̃g�b�v�ɂ���V�[�����X�V����
		*/
		void updateTopScene() {
			sceneStack_.top()->update();
		}
		/**
		* @brief �X�^�b�N�̃g�b�v�ɂ���V�[���̕`�������
		*/
		void renderTopScene() {
			sceneStack_.top()->render();
		}
	};
}