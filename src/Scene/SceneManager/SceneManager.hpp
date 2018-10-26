/**
* @file SceneManager.hpp
* @brief �V�[���Ǘ����s���N���X���`����
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include <stack>
#include <unordered_map>

namespace Scene {
	/**
	* @brief �V�[�����A����ŃV�[���𔻕ʂ���
	*/
	enum class SceneName {
		NON,
		TITLE,
		GAME,
	};

	/**
	* @brief �V�[���J�ڎ��ɓn���p�����[�^
	*/
	class Parameter final {
		Parameter() = default;

	};

	/**
	* @brief �R�[���o�b�N����C���^�[�t�F�C�X�N���X
	*/
	class IOnSceneChangeListener {
	public:
		IOnSceneChangeListener() = default;
		virtual ~IOnSceneChangeListener() = default;
		virtual void onSceneChanged(const SceneName scene, const Parameter& param, const bool stackClear) = 0;
	};
	/**
	* @brief �V�[���̊��N���X
	*/
	class AbstractScene {
	private:
		IOnSceneChangeListener * sceneLister_;
	public:
		AbstractScene(IOnSceneChangeListener* listener, const Parameter& param)
			:
			sceneLister_(listener)
		{}
		virtual ~AbstractScene() = default;
		virtual void update() = 0;
		virtual void render() = 0;
	};
	class SceneManager {
	private:
		//! �V�[���̃X�^�b�N�A������炱���ɐς�
		std::stack<AbstractScene*> sceneStack;
	public:
	};
}
