/**
* @file Image.h
* @brief �摜�`��Ɋւ���N���X���`����
* @author yokota0717
* @date 2018.10.27
*/

#pragma once
#include <string>
#include <vector>
#include "DxLib.h"
#include "../Math/Math.h"


class Image
{
	//! �摜�n���h��
	int handle_;
	int* handleDiv_;
public:
	/**
	* @brief �摜�n���h����ݒ肷��
	*/
	Image();
	~Image();

	/**
	* @brief �摜�n���h����ݒ肷��
	* - �P��Ŏg���摜�̓ǂݍ��݂Ɏg��
	* @param path �摜�̃p�X
	*/
	void setHandle(const std::string& path);

	/**
	* @brief
	* - �������Ďg���摜�̓ǂݍ��݂Ɏg��
	* @param path �摜�̃p�X
	*/
	void setHandleDiv(const std::string& path, const int allNum, const int xNun, const int yNun, const int xSize, const int ySize);

	/**
	* @brief �P��œǂݍ��񂾉摜�̕`��֐��A�A�j���[�V�����͂��Ȃ�
	* @param draw �`�悷����W
	* @param center �s�{�b�g���摜�̒��S�ɂ���
	* - true�Ȃ�s�{�b�g������
	* - false�Ȃ�s�{�b�g������
	*/
	void draw(const Math::Vec& draw, const bool isCenter);

	/**
	* @brief �������ēǂݍ��񂾉摜�̕`��֐��A�A�j���[�V�����͂��Ȃ�
	* @param draw �`�悷����W
	* @param index �`�悷��摜�̃C���f�b�N�X
	* @param center �s�{�b�g���摜�̒��S�ɂ���
	* - true�Ȃ�s�{�b�g������
	* - false�Ȃ�s�{�b�g������
	*/
	void draw(const Math::Vec& draw, const int index, const bool isCenter);
};