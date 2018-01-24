#include "DxLib.h"
#include "../Collision/Collision.h"



//�����F����̒��_��x�Ay���W�A���A����
Box2DCollider::Box2DCollider(float x, float y, float w, float h):
	col(x,y,w,h)
{}

//�_�Ƃ̓����蔻��
//�����F�_�̍��W
bool Box2DCollider::Collision(Vec pos) {
	return (	pos.x >= col.x
			&&	pos.y >= col.y
			&&	pos.x < col.x + col.w
			&&	pos.y < col.y + col.h);
}

//�����Ƃ̓����蔻��
//�����F�����̎n�_�̍��W�A�����̏I�_�̍��W
//�Q�lURL�Fhttp://www5d.biglobe.ne.jp/~tomoya03/shtml/algorithm/Intersection.htm
bool Box2DCollider::Collision(Vec v1, Vec v2) {
	//��������`��4�ӂƌ������Ă��邩
	//��`��4���_(���ォ�玞�v����)
	Vec vertex[4] = {	Vec(col.x,col.y),
						Vec(col.x + col.w,col.y),
						Vec(col.x + col.w,col.y + col.h),
						Vec(col.x,col.y + col.h) };
	//��������
	int table[] = { 0,1,2,3,0 };
	for (int i = 0; i < 4; ++i) {
		float ta = (v1.x - v2.x)*(vertex[table[i+1]].y - v1.y) + (v1.y - v2.y)*(v1.x - vertex[table[i+1]].x);
		float tb = (v1.x - v2.x)*(vertex[table[i]].y - v1.y) + (v1.y - v2.y)*(v1.x - vertex[table[i]].x);
		float tc = (vertex[table[i + 1]].x - vertex[table[i]].x)*(v1.y - vertex[table[i + 1]].y) + (vertex[table[i + 1]].y - vertex[table[i]].y)*(vertex[table[i + 1]].x - v1.x);
		float td = (vertex[table[i + 1]].x - vertex[table[i]].x)*(v2.y - vertex[table[i + 1]].y) + (vertex[table[i + 1]].y - vertex[table[i]].y)*(vertex[table[i + 1]].x - v2.x);
		if (ta*tb < 0 && tc*td < 0) return true;
	}

	//��������`�Ɋ��S�ɓ����Ă��邩
	//���ׂĂ̕ӂ��猩�Ďn�_�ƏI�_���E���ɂ���Ȃ�true

}

bool Box2DCollider::Collision(Box2D b) {
	return (	b.x <= col.x + col.w
			&&	b.x + b.w >= col.x
			&&	b.y <= col.y + col.h
			&&	b.y + b.h >= col.y);
}

bool Box2DCollider::Collision(Circle c) {

}
