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
#include "Title.h"

namespace Scene{
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

		void onSceneChange(const SceneName& scene, Parameter& param, const StackPopFlag stackPopFlag) {
			switch (stackPopFlag) {
			case StackPopFlag::NON:
				break;
			case StackPopFlag::POP:
				

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