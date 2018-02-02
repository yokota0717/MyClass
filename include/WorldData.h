#pragma once
#include "DxLib.h"

namespace {
	//-------------------------------------------------------------------------------------------------------------------
	//�E�B���h�E�T�C�Y
	const int	SCREEN_WIDTH = 800,
		SCREEN_HEIGHT = 600;
	//-------------------------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------------------------
	//�F
	int white = GetColor(255, 255, 255);
	int red = GetColor(255, 25, 50);
	int blue = GetColor(25, 50, 255);
	int green = GetColor(25, 255, 0);
	int UFO = GetColor(90, 20, 90);
	int SHOT = GetColor(50, 90, 170);
	//-------------------------------------------------------------------------------------------------------------------

	//�~����
	const float PI = 3.14159265358979323846264338327950288f;

	//�p�x�ϊ�
	const float ToRadian(const float degree) {
		return (degree / 360.0f)*(2.0f*PI);
	}
	const float ToDegree(const float radian) {
		return (radian / (2.0f*PI))*360.0f;
	}

	//�J�n���Ԃ������ɁA�o�ߎ��Ԃ��擾����
	const int GetElapseTime(const int start) {
		return GetNowCount() - start;
	}
}