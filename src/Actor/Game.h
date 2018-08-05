/**
* @file Game.h
* @brief �Q�[���N���X�A���[�g�N���X���`����
*/

#pragma once
#include "../Input/Input.h"
#include "../GraphFactory/GraphFactory.h"
#include "../Object/Object.h"


/**
* @brief ���[�g�N���X
*/
class Root :public GameObject {
public:
	Root();
	~Root();
	void init(std::shared_ptr<GameObject> thisptr);
	void update() override;
	void render() override;

	/**
	* @brief �o�߃t���[������Ԃ�
	*/
	int frame();

	/**
	* @brief �V�[���؂�ւ��p���b�Z�[�W�֐�
	*/
	int receiveMsg(std::weak_ptr<GameObject> sender, const std::string& msg);

private:
	//! �o�߃t���[�������i�[����
	int frame_;
};


/**
* @brief �Q�[���Ǘ��N���X
*/
class Game {
	//! �f�o�b�O���[�h�ؑ֗p
	bool debug_;
public:
	Game();
	~Game();
	void fin();

	//!���͊֘A
	Keyboard kb;
	Mouse mouse;
	GPad pad;
	//! ���[�g�I�u�W�F�N�g
	std::shared_ptr<Root> root;
	//! �摜�n���h�����Ǘ�����t�@�N�g��
	std::unique_ptr<GraphFactory> grafac;

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
extern std::unique_ptr<Game> game;