#include "DxLib.h"
#include "../Collision/Collision.h"



//引数：左上の頂点のx、y座標、幅、高さ
Box2DCollider::Box2DCollider(float x, float y, float w, float h):
	col(x,y,w,h)
{}

//点との当たり判定
//引数：点の座標
bool Box2DCollider::Collision(Vec pos) {
	return (	pos.x >= col.x
			&&	pos.y >= col.y
			&&	pos.x < col.x + col.w
			&&	pos.y < col.y + col.h);
}

//線分との当たり判定
//引数：線分の始点の座標、線分の終点の座標
//参考URL：http://www5d.biglobe.ne.jp/~tomoya03/shtml/algorithm/Intersection.htm
bool Box2DCollider::Collision(Vec v1, Vec v2) {
	//線分が矩形の4辺と交差しているか
	//矩形の4頂点(左上から時計回りに)
	Vec vertex[4] = {	Vec(col.x,col.y),
						Vec(col.x + col.w,col.y),
						Vec(col.x + col.w,col.y + col.h),
						Vec(col.x,col.y + col.h) };
	//交差判定
	int table[] = { 0,1,2,3,0 };
	for (int i = 0; i < 4; ++i) {
		float ta = (v1.x - v2.x)*(vertex[table[i+1]].y - v1.y) + (v1.y - v2.y)*(v1.x - vertex[table[i+1]].x);
		float tb = (v1.x - v2.x)*(vertex[table[i]].y - v1.y) + (v1.y - v2.y)*(v1.x - vertex[table[i]].x);
		float tc = (vertex[table[i + 1]].x - vertex[table[i]].x)*(v1.y - vertex[table[i + 1]].y) + (vertex[table[i + 1]].y - vertex[table[i]].y)*(vertex[table[i + 1]].x - v1.x);
		float td = (vertex[table[i + 1]].x - vertex[table[i]].x)*(v2.y - vertex[table[i + 1]].y) + (vertex[table[i + 1]].y - vertex[table[i]].y)*(vertex[table[i + 1]].x - v2.x);
		if (ta*tb < 0 && tc*td < 0) return true;
	}

	//線分が矩形に完全に入っているか
	//すべての辺から見て始点と終点が右側にあるならtrue

}

bool Box2DCollider::Collision(Box2D b) {
	return (	b.x <= col.x + col.w
			&&	b.x + b.w >= col.x
			&&	b.y <= col.y + col.h
			&&	b.y + b.h >= col.y);
}

bool Box2DCollider::Collision(Circle c) {

}
