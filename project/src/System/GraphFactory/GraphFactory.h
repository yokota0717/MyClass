#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>

/**
* @file GraphFactory.h
* @brief �摜�f�[�^�̃n���h�����Ǘ�����N���X���`����
* @author yokota0717
* @date 2018.10.27
*/


#include <map>
#include <string>

/**
* @brief �摜�f�[�^�̃n���h�����Ǘ�����
*/
class GraphFactory {
	//! �p�X�w��ȗ��̂���
	std::string path;
	//! �n���h����ۊǂ��Ă����R���e�i
	std::map<std::string, int> pool;

	/**
	* @brief �p�X����V���ɉ摜��ǂݍ���
	* @param fileName �摜�f�[�^�̃p�X
	* @return int �摜�f�[�^�̃n���h��
	*/
	int CreateGraph(const std::string& fileName);

public:
	GraphFactory();
	/**
	* @brief �p�X����摜�f�[�^�̃n���h����Ԃ�
	* - ���߂ēǂݍ��ރf�[�^�͐������ăv�[�����Ă���Ԃ�
	* - ���łɓǂݍ��܂�Ă���f�[�^�̓R���e�i���猟�����ĕԂ�
	*/
	int GetGraph(const std::string& fileName);
};