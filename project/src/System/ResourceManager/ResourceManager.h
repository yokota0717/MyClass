/**
* @file ResourceManager.h
* @brief �摜����уT�E���h�̃n���h�����Ǘ�����N���X���`����
* @author yokota0717
* @date 2018.10.27
* @param history
- 2018.10.27 yokota0717
-# �P��摜�ƕ����摜�Ƃ���ʂ���
-# unordered_map�ɕύX
- 2018.10.29 yokota0717
-# �T�E���h�̒ǉ��A�t�@�C�������l�[��
-# ResourceManager�N���X�����d�l�ɕύX
*/

#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>
#include <unordered_map>
#include <string>


/**
* @brief ���\�[�X�̊Ǘ����s��
*/
class ResourceManager {
private:
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
		* @param fileName �摜�f�[�^�̖��O
		* @return int �摜�f�[�^�̃n���h��
		*/
		int createGraph(const std::string& fileName);

		/**
		* @brief �p�X����V���ɉ摜��ǂݍ���
		* - �������Ďg�p����摜�p
		* @param fileName �摜�f�[�^�̖��O
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
		* @param fileName �ق����摜�̖��O
		* @return int �摜�n���h��
		*/
		int getGraph(const std::string& fileName);

		/**
		* @brief �p�X����摜�f�[�^�̃n���h����Ԃ��A�������Ďg�p����摜�p
		* - ���߂ēǂݍ��ރf�[�^�͐������ăv�[�����Ă���Ԃ�
		* - ���łɓǂݍ��܂�Ă���f�[�^�̓R���e�i���猟�����ĕԂ�
		* @param fileName �ق����摜�̖��O
		* @return int* �摜�n���h�����i�[���ꂽ�z��̐擪�A�h���X
		*/
		int* getGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize);
	};

	class SoundFactory {
	private:
		//! �p�X�w��ȗ��̂���
		std::string path;
		//! �n���h����ۊǂ��Ă����R���e�i
		std::unordered_map<std::string, int> pool_;

		/**
		* @brief �T�E���h��ǂݍ���
		* @param fileName �T�E���h�f�[�^�̖��O
		* @return �ǂݍ��񂾃T�E���h�̃n���h��
		*/
		int loadSound(std::string& fileName);

		/**
		* @brief �T�E���h��񓯊��œǂݍ���
		* @param fileName �T�E���h�f�[�^�̖��O
		* @return ����ɓǂݍ��߂���1���Ԃ�
		* - ���łɑ��݂���f�[�^���w�肵���炻�̃n���h�����Ԃ�
		*/
		int loadSoundAsync(std::string& fileName);

	public:
		SoundFactory();
		~SoundFactory();

		/**
		* @brief �ŏ��ɕK�v�ȃT�E���h��ǂݍ���
		*/
		void initLoad();

		/**
		* @brief �p�X����T�E���h�̃n���h����Ԃ�
		* @param fileName �~�����T�E���h�̖��O
		* @return �T�E���h�̃n���h��
		*/
		int getSound(std::string& fileName);
	};


public:
	ResourceManager();
	~ResourceManager();

	/**
	* @brief �A�v���P�[�V�����J�n���ɕK�v�ȃ��\�[�X���܂Ƃ߂ēǂݍ���
	*/
	void init();

	/**
	* @brief GraphFactory��Ԃ�
	*/
	static GraphFactory& getGraphFac();

	/**
	* @brief GraphFactory��Ԃ�
	*/
	static SoundFactory& getSoundFac();
};

