/**
* @file Game.h
* @brief ゲームクラス、ルートクラスを定義する
*/

#pragma once
#include "../Input/Input.h"
#include "../GraphFactory/GraphFactory.h"
#include "../Object/Object.h"


/**
* @brief ルートクラス
*/
class Root :public GameObject {
public:
	Root();
	~Root();
	void init(std::shared_ptr<GameObject> thisptr);
	void update() override;
	void render() override;

	/**
	* @brief 経過フレーム数を返す
	*/
	int frame();

	/**
	* @brief シーン切り替え用メッセージ関数
	*/
	int receiveMsg(std::weak_ptr<GameObject> sender, const std::string& msg);

private:
	//! 経過フレーム数を格納する
	int frame_;
};


/**
* @brief ゲーム管理クラス
*/
class Game {
	//! デバッグモード切替用
	bool debug_;
public:
	Game();
	~Game();
	void fin();

	//!入力関連
	Keyboard kb;
	Mouse mouse;
	GPad pad;
	//! ルートオブジェクト
	std::shared_ptr<Root> root;
	//! 画像ハンドルを管理するファクトリ
	std::unique_ptr<GraphFactory> grafac;

	/**
	* @brief ループでこれを呼ぶと全オブジェクトの更新、描画を行う
	*/
	void doAll();

	/**
	* @brief 現在デバッグモードが起動中かを返す
	* @return bool デバッグモード起動中かどうか
	*/
	bool DebugMode();
};

//! ゲーム管理オブジェクト
extern std::unique_ptr<Game> game;