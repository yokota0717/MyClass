#include "DxLib.h"
#include "../Collision/Collision.h"



Box2DCollider::Box2DCollider(float x, float y, float w, float h):
	col(x,y,w,h)
{}

bool Box2DCollider::Collision(Vec pos) {
	return (	pos.x >= col.x
			&&	pos.y >= col.y
			&&	pos.x < col.x + col.w
			&&	pos.y < col.y + col.h);
}

bool Box2DCollider::Collision(Vec v1, Vec v2) {

}
bool Box2DCollider::Collision(Box2D b) {
	
}
bool Box2DCollider::Collision(Circle c) {

}
