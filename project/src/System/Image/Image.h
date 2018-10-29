/**
* @file Image.h
* @brief 画像描画に関するクラスを定義する
* @author yokota0717
* @date 2018.10.27
*/

#pragma once
#include <string>
#include <vector>
#include "DxLib.h"
#include "../Math/Math.h"


class Image
{
	//! 画像ハンドル
	int handle_;
	int* handleDiv_;
public:
	/**
	* @brief 画像ハンドルを設定する
	*/
	Image();
	~Image();

	/**
	* @brief 画像ハンドルを設定する
	* - 単一で使う画像の読み込みに使う
	* @param path 画像のパス
	*/
	void setHandle(const std::string& path);

	/**
	* @brief
	* - 分割して使う画像の読み込みに使う
	* @param path 画像のパス
	*/
	void setHandleDiv(const std::string& path, const int allNum, const int xNun, const int yNun, const int xSize, const int ySize);

	/**
	* @brief 単一で読み込んだ画像の描画関数、アニメーションはしない
	* @param draw 描画する座標
	* @param center ピボットを画像の中心にする
	* - trueならピボットが中央
	* - falseならピボットが左上
	*/
	void draw(const Math::Vec& draw, const bool isCenter);

	/**
	* @brief 分割して読み込んだ画像の描画関数、アニメーションはしない
	* @param draw 描画する座標
	* @param index 描画する画像のインデックス
	* @param center ピボットを画像の中心にする
	* - trueならピボットが中央
	* - falseならピボットが左上
	*/
	void draw(const Math::Vec& draw, const int index, const bool isCenter);
};