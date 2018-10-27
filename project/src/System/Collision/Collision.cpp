#include "DxLib.h"
#include "../Collision/Collision.h"
#include<string>


namespace Math {
	//引数：左上の頂点のx、y座標、幅、高さ
	Box2DCollider::Box2DCollider(float x, float y, float w, float h) :
		col(x, y, w, h)
	{}

	//点との当たり判定
	//引数：点の座標
	bool Box2DCollider::Collision(Vec pos) {
		return (pos.x >= col.x
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
		Vec vertex[4] = { Vec(col.x,col.y),
							Vec(col.x + col.w,col.y),
							Vec(col.x + col.w,col.y + col.h),
							Vec(col.x,col.y + col.h) };
		//交差判定
		int table[] = { 0,1,2,3,0 };
		for (int i = 0; i < 4; ++i) {
			float ta = (v1.x - v2.x)*(vertex[table[i + 1]].y - v1.y) + (v1.y - v2.y)*(v1.x - vertex[table[i + 1]].x);
			float tb = (v1.x - v2.x)*(vertex[table[i]].y - v1.y) + (v1.y - v2.y)*(v1.x - vertex[table[i]].x);
			float tc = (vertex[table[i + 1]].x - vertex[table[i]].x)*(v1.y - vertex[table[i + 1]].y) + (vertex[table[i + 1]].y - vertex[table[i]].y)*(vertex[table[i + 1]].x - v1.x);
			float td = (vertex[table[i + 1]].x - vertex[table[i]].x)*(v2.y - vertex[table[i + 1]].y) + (vertex[table[i + 1]].y - vertex[table[i]].y)*(vertex[table[i + 1]].x - v2.x);
			if (ta*tb < 0 && tc*td < 0) return true;
		}

		//線分が矩形に完全に入っているか
		//すべての辺から見て始点と終点が右側にあるならtrue
		//矩形の4辺(上、右、下、左)
		Vec sides[4] = { vertex[1] - vertex[0],
							vertex[2] - vertex[1],
							vertex[3] - vertex[2],
							vertex[0] - vertex[3] };
		Vec toStart[4] = { v1 - vertex[0],
							v1 - vertex[1],
							v1 - vertex[2],
							v1 - vertex[3] };
		Vec toEnd[4] = { v2 - vertex[0],
							v2 - vertex[1],
							v2 - vertex[2],
							v2 - vertex[3] };
		for (int i = 0; i < 4; ++i) {
			float crossStart = Vec::GetCrossVec2(sides[i], toStart[i]);
			float crossEnd = Vec::GetCrossVec2(sides[i], toEnd[i]);
			if (crossStart <= 0 && crossEnd <= 0) return true;
		}
		return false;
	}

	bool Box2DCollider::Collision(Box2D b) {
		return (b.x <= col.x + col.w
			&&	b.x + b.w >= col.x
			&&	b.y <= col.y + col.h
			&&	b.y + b.h >= col.y);
	}

	bool Box2DCollider::Collision(Circle c) {
		return false;
	}

	CircleCollider::CircleCollider(float x, float y, float r) :
		col(x, y, 0.0f, r)
	{}

	bool CircleCollider::Collision(Vec v) {
		if (((col.center.x - v.x)*(col.center.x - v.x) + (col.center.y - v.y)*(col.center.y - v.y)) <= (col.r*col.r))
			return true;
		return false;
	}
	bool CircleCollider::Collision(Vec v1, Vec v2) {
		return false;
	}
	bool CircleCollider::Collision(Box2D b) {
		return false;
	}
	bool CircleCollider::Collision(Circle c) {
		return false;
	}


	TriangleCollider::TriangleCollider(Vec v1, Vec v2, Vec v3) :
		col(v1, v2, v3)
	{}

	bool TriangleCollider::Collision(Vec v) {
		return false;
	}
	bool TriangleCollider::Collision(Vec v1, Vec v2) {
		return false;
	}
	bool TriangleCollider::Collision(Box2D b) {
		return false;
	}
	bool TriangleCollider::Collision(Circle c) {
		return false;
	}


	OrvalCollider::OrvalCollider(float x, float y, float lr, float sr, float ang) :
		col(x, y, lr, sr, ang)
	{}

	bool OrvalCollider::Collision(Vec v) {
		Vec movedV;
		movedV.x = (v.x - col.x)*cos(col.angle / 360.0f * 2.0f * PI) + (v.y - col.y)*sin(col.angle / 360.0f*2.0f*PI);
		movedV.y = (v.y - col.y)*cos(col.angle / 360.0f * 2.0f * PI) - (v.x - col.x)*sin(col.angle / 360.0f*2.0f*PI);
		float orvalFormula = (movedV.x*movedV.x) / (col.lr*col.lr) + (movedV.y*movedV.y) / (col.sr*col.sr);
		if (orvalFormula <= 1)
			return true;
		return false;
	}

	bool OrvalCollider::Collision(Vec v1, Vec v2) {
		Vec movedV1;
		movedV1.x = (v1.x - col.x)*cos(col.angle / 360.0f * 2.0f * PI) + (v1.y - col.y)*sin(col.angle / 360.0f*2.0f*PI);
		movedV1.y = (col.lr / col.sr)*(v1.y - col.y)*cos(col.angle / 360.0f * 2.0f * PI) - (v1.x - col.x)*sin(col.angle / 360.0f*2.0f*PI);
		Vec movedV2;
		movedV2.x = (v2.x - col.x)*cos(col.angle / 360.0f * 2.0f * PI) + (v2.y - col.y)*sin(col.angle / 360.0f*2.0f*PI);
		movedV2.y = (col.lr / col.sr)*(v2.y - col.y)*cos(col.angle / 360.0f * 2.0f * PI) - (v2.x - col.x)*sin(col.angle / 360.0f*2.0f*PI);
		float a = (movedV2.y - movedV1.y) / (movedV2.x - movedV1.x);
		float b = movedV1.y - a * movedV1.x;
		Vec nearest;
		nearest.x = -1 * (a*b) / (1 + a * a);
		nearest.y = b / (1 + a * a);
		CircleCollider ccol(0.0f, 0.0f, col.lr);
		if (ccol.Collision(nearest))
			return true;
		return false;
	}

	bool OrvalCollider::Collision(Box2D b) {
		return false;
	}
	bool OrvalCollider::Collision(Circle c) {
		return false;
	}
}