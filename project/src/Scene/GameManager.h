/**
* @file GameManager.h
* @brief �Q�[���N���X�A���[�g�N���X���`����
*/

#pragma once
#include "../System/Input/Input.h"
#include "../System/ResourceManager/ResourceManager.h"
#include "../System/Node/Node.h"
#include "../Scene/SceneManager.hpp"
#include "../System/FPS/FPS.hpp"

/**
* @brief ���[�g�N���X
*/
class Root :public Node {
public:
	Root();
	~Root();
	void init(Node* thisptr);
	void update() override;
	void render() override;

	/**
	* @brief �o�߃t���[������Ԃ�
	*/
	int frame();

private:
	//! �o�߃t���[�������i�[����
	int frame_;
};


/**
* @brief �Q�[���Ǘ��N���X
*/
class GameManager {
	//! �f�o�b�O���[�h�ؑ֗p
	bool debug_;
	//! �V�[���Ǘ��p
	Scene::SceneManager* sceneManager_;
	//! FPS�Œ�
	FPS fps_;
public:
	GameManager();
	~GameManager();
	void fin();

	//!���͊֘A
	Keyboard kb;
	Mouse mouse;
	GPad pad;
	//! ���[�g�I�u�W�F�N�g
	Root* root;
	//! �摜�n���h�����Ǘ�����t�@�N�g��
	ResourceManager* resManager_;

	/**
	* @brief ���[�v�ł�����ĂԂƑS�I�u�W�F�N�g�̍X�V�A�`����s��
	*/
	void doAll();

	/**
	* @brief ���݃f�o�b�O���[�h���N��������Ԃ�
	* @return bool �f�o�b�O���[�h�N�������ǂ���
	*/
	bool DebugMode();
};

//! �Q�[���Ǘ��I�u�W�F�N�g
extern GameManager* game;