/**
* @file		Player.h
* @brief	�v���C���N���X
* @details	�������ɉ摜�̃p�X���w��
			�e�I�u�W�F�N�g��render��draw���ĂԂ��Ƃŕ`��ł���
*/

#pragma once
#include "../Object/Object.h"
#include "../Image/Image.h"


class Player : public GameObject
{
	Image image_;
public:
	Player(const std::string& path);
	~Player();

	void init() override;
	void update() override;
	void render() override;
	void fin();
};

