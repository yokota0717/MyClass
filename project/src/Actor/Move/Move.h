/**
* @file Move.h
* @brief �ӂ�܂��N���X�A�����I�u�W�F�N�g�Ɏ�������
* @author yokota0717
* @param history
- 2018.10.31 yokota0717
-# ��������const�ɂ���
-# �d�͂̒ǉ�
*/
#pragma once
#include "../../System/Math/Math.h"

class MoveBase
{
protected:
	//! ���ݍ��W
	Math::Vec pos_;
	//! �ړ����x
	float speed_;
	//! �d�͂�K�p���邩
	bool isGravity_;
	//! �d�͉����x
	const float gravity_;
public:
	explicit MoveBase(const Math::Vec& pos, const float speed, const bool gravity);
	virtual ~MoveBase();
	virtual void move() = 0;

	Math::Vec& getPos();
};

class PlayerMove : public MoveBase {
public:
	PlayerMove(const Math::Vec& pos, const float speed, const bool gravity);
	virtual void move();
};