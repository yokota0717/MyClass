/**
* @file GameManager.h
* @brief ゲームクラス、ルートクラスを定義する
*/

#pragma once
#include "../System/Input/Input.h"
#include "../System/ResourceManager/ResourceManager.h"
#include "../System/Node/Node.h"
#include "../Scene/SceneManager.hpp"
#include "../System/FPS/FPS.hpp"

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
	//! シーン管理用
	Scene::SceneManager* sceneManager_;
	//! FPS固定
	FPS fps_;
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
	ResourceManager* resManager_;

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