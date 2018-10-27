/**
* @file FPS.hpp
* @brief FPS�Œ�̏������L�q����
* - �Q�lURL�Fhttps://dixq.net/g/03_14.html
* @author yokota0717
* @date 2018.10.27
*/

#pragma once
#include <iostream>
#include "DxLib.h"
#include "../../Utility/Utility.hpp"

/**
* @brief FPS�Œ�̏���������N���X
*/
class FPS {
private:
	//! ����J�n����
	int startTime_;
	//! �J�E���^
	int counter_;
	//! ���݂�FPS
	float fps_;
	//! ���ς��Ƃ�T���v����
	static const int SAMPLE_NUM = 60;
	//! �w��FPS
	static const int SETTING_FPS = 60;
public:
	FPS()
		:
		counter_(0),
		fps_(0)
	{
		startTime_ = GetNowCount();
	}
	~FPS() {};
	/**
	* @brief FPS�v�Z�̏������s��
	*/
	void update() {
		if (++counter_ > SAMPLE_NUM) {
			int now = GetNowCount();
			fps_ = 1000.f / ((now - startTime_) / (float)SAMPLE_NUM);
			counter_ = 0;
			startTime_ = now;
			outputFPS();
		}
	}
	/**
	* @brief FPS���w��̒l�𒴂����ꍇ�ɃX���[�v��������
	* - ���̊֐������C�����[�v�̍Ō�ɌĂԂ���
	*/
	void wait() {
		int tookTime = GetNowCount() - startTime_;
		int waitTime = counter_ * 1000 / SETTING_FPS - tookTime;
		if (waitTime > 0) {
			Sleep(waitTime);
		}
	}
	/**
	* @brief �f�o�b�O�pFPS�o�͊֐�
	*/
	void outputFPS() {
		DOUT << "FPS�F" << fps_ << std::endl;
	}
};
