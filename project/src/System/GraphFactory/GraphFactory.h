/**
* @file GraphFactory.h
* @brief �摜�f�[�^�̃n���h�����Ǘ�����N���X���`����
* @author yokota0717
* @date 2018.10.27
* @param history
- 2018.10.27 yokota0717
-# �P��摜�ƕ����摜�Ƃ���ʂ���
-# unordered_map�ɕύX
*/

#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>
#include <unordered_map>
#include <string>

/**
* @brief �摜�f�[�^�̃n���h�����Ǘ�����
*/
class GraphFactory {
	//! �p�X�w��ȗ��̂���
	std::string path;
	//! �n���h����ۊǂ��Ă����R���e�i�A�P��Ŏg�p����摜�p
	std::unordered_map<std::string, int> singlePool_;
	//! �n���h����ۊǂ��Ă����R���e�i�A��������摜�p
	std::unordered_map<std::string, int*> divPool_;

	/**
	* @brief �p�X����V���ɉ摜��ǂݍ���
	* - �P��Ŏg�p����摜�p
	* @param fileName �摜�f�[�^�̃p�X
	* @return int �摜�f�[�^�̃n���h��
	*/
	int createGraph(const std::string& fileName);

	/**
	* @brief �p�X����V���ɉ摜��ǂݍ���
	* - �������Ďg�p����摜�p
	* @param fileName �摜�f�[�^�̃p�X
	* @param allNum �摜�̕�����
	* @param xNum �摜�̉������̕�����
	* @param yNum �摜�̏c�����̕�����
	* @param xSize �摜�̉������̃T�C�Y
	* @param ySize �摜�̏c�����̃T�C�Y
	* @return int* �摜�f�[�^�̃n���h������ꂽ�z��̐擪�A�h���X
	*/
	int* createGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize);

public:
	GraphFactory();
	~GraphFactory();

	/**
	* @brief �ŏ��ɕK�v�ȉ摜��ǂݍ���
	*/
	void initLoad();

	/**
	* @brief �p�X����摜�f�[�^�̃n���h����Ԃ��A�P��Ŏg�p����摜�p
	* - ���߂ēǂݍ��ރf�[�^�͐������ăv�[�����Ă���Ԃ�
	* - ���łɓǂݍ��܂�Ă���f�[�^�̓R���e�i���猟�����ĕԂ�
	* @param fileName �ق����摜�̃p�X
	* @return int �摜�n���h��
	*/
	int getGraph(const std::string& fileName);

	/**
	* @brief �p�X����摜�f�[�^�̃n���h����Ԃ��A�������Ďg�p����摜�p
	* - ���߂ēǂݍ��ރf�[�^�͐������ăv�[�����Ă���Ԃ�
	* - ���łɓǂݍ��܂�Ă���f�[�^�̓R���e�i���猟�����ĕԂ�
	* @param fileName �ق����摜�̃p�X
	* @return int* �摜�n���h�����i�[���ꂽ�z��̐擪�A�h���X
	*/
	int* getGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize);
};