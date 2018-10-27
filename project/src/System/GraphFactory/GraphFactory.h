#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>

/**
* @file GraphFactory.h
* @brief 画像データのハンドルを管理するクラスを定義する
* @author yokota0717
* @date 2018.10.27
*/


#include <map>
#include <string>

/**
* @brief 画像データのハンドルを管理する
*/
class GraphFactory {
	//! パス指定省略のため
	std::string path;
	//! ハンドルを保管しておくコンテナ
	std::map<std::string, int> pool;

	/**
	* @brief パスから新たに画像を読み込む
	* @param fileName 画像データのパス
	* @return int 画像データのハンドル
	*/
	int CreateGraph(const std::string& fileName);

public:
	GraphFactory();
	/**
	* @brief パスから画像データのハンドルを返す
	* - 初めて読み込むデータは生成してプールしてから返す
	* - すでに読み込まれているデータはコンテナから検索して返す
	*/
	int GetGraph(const std::string& fileName);
};