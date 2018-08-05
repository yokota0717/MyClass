/**
* @file		Player.h
* @brief	プレイヤクラス
* @details	生成時に画像のパスを指定
			各オブジェクトのrenderでdrawを呼ぶことで描画できる
*/

#pragma once
#include "../Object/Object.h"
#include "../Image/Image.h"


class Player : public GameObject
{
	Image image_;
public:
	Player(const std::string& path);
	~Player();

	void init() override;
	void update() override;
	void render() override;
	void fin();
};

