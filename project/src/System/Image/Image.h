/**
* @file		Image.h
* @brief	描画に関する処理をするクラス
* @details	生成時に画像のパスを指定
			各オブジェクトのrenderでdrawを呼ぶことで描画できる
*/

#pragma once
#include <string>
#include "DxLib.h"
#include "../Math/Math.h"


class Image
{
	//! 画像ハンドル
	int handle_;
public:
	/**
	* @brief 画像ハンドルを設定する
	* @param path 画像のパス
	*/
	Image(const std::string& path);
	~Image();

	/**
	* @brief 画像ハンドルを設定する
	* @param path 画像のパス
	*/
	void setHandle(const std::string& path);

	/**
	* @brief 描画関数
	* @param draw 描画する座標、サイズをBox2D型で指定する
	*/
	void draw(Math::Box2D& draw, Math::Box2D& src);
};

