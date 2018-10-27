/**
* @file		Image.h
* @brief	�`��Ɋւ��鏈��������N���X
* @details	�������ɉ摜�̃p�X���w��
			�e�I�u�W�F�N�g��render��draw���ĂԂ��Ƃŕ`��ł���
*/

#pragma once
#include <string>
#include "DxLib.h"
#include "../Math/Math.h"


class Image
{
	//! �摜�n���h��
	int handle_;
public:
	/**
	* @brief �摜�n���h����ݒ肷��
	* @param path �摜�̃p�X
	*/
	Image(const std::string& path);
	~Image();

	/**
	* @brief �摜�n���h����ݒ肷��
	* @param path �摜�̃p�X
	*/
	void setHandle(const std::string& path);

	/**
	* @brief �`��֐�
	* @param draw �`�悷����W�A�T�C�Y��Box2D�^�Ŏw�肷��
	*/
	void draw(Math::Box2D& draw, Math::Box2D& src);
};

