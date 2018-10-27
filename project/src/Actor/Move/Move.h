/**
* @file Move.h
* @brief �ӂ�܂��N���X�A�����I�u�W�F�N�g�Ɏ�������
*/
#pragma once
#include "../../System/Math/Math.h"

class Move
{
protected:
	//! ���ݍ��W
	Math::Vec pos_;
	//! �ړ����x
	float speed_;
public:
	Move(Math::Vec& pos, float speed);
	virtual ~Move();
	virtual void move() = 0;

	Math::Vec& getPos();
};

class InputMove : public Move {
public:
	InputMove(Math::Vec& pos, float speed);
	void move() override;
};