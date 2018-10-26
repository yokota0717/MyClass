/**
* @file Game.h
* @brief ゲームクラス、ルートクラスを定義する
*/

#pragma once
#include "../Input/Input.h"
#include "../GraphFactory/GraphFactory.h"
#include "../Object/Node.h"


/**
* @brief ルートクラス
*/
class Root :public Node {
public:
	Root();
	~Root();
	void init(Node* thisptr);
	void update() override;
	void render() override;

	/**
	* @brief 経過フレーム数を返す
	*/
	int frame();

	/**
	* @brief シーン切り替え用メッセージ関数
	*/
	int receiveMsg(Node* sender, const std::string& msg);

private:
	//! 経過フレーム数を格納する
	int frame_;
};


/**
* @brief ゲーム管理クラス
*/
class GameManager {
	//! デバッグモード切替用
	bool debug_;
public:
	GameManager();
	~GameManager();
	void fin();

	//!入力関連
	Keyboard kb;
	Mouse mouse;
	GPad pad;
	//! ルートオブジェクト
	Root* root;
	//! 画像ハンドルを管理するファクトリ
	GraphFactory* grafac;

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
extern GameManager* game;