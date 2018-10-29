/**
* @file ResourceManager.h
* @brief 画像およびサウンドのハンドルを管理するクラスを定義する
* @author yokota0717
* @date 2018.10.27
* @param history
- 2018.10.27 yokota0717
-# 単一画像と分割画像とを区別した
-# unordered_mapに変更
- 2018.10.29 yokota0717
-# サウンドの追加、ファイル名リネーム
-# ResourceManagerクラスを介する仕様に変更
*/

#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>
#include <unordered_map>
#include <string>


/**
* @brief リソースの管理を行う
*/
class ResourceManager {
private:
	/**
	* @brief 画像データのハンドルを管理する
	*/
	class GraphFactory {
		//! パス指定省略のため
		std::string path;
		//! ハンドルを保管しておくコンテナ、単一で使用する画像用
		std::unordered_map<std::string, int> singlePool_;
		//! ハンドルを保管しておくコンテナ、分割する画像用
		std::unordered_map<std::string, int*> divPool_;

		/**
		* @brief パスから新たに画像を読み込む
		* - 単一で使用する画像用
		* @param fileName 画像データの名前
		* @return int 画像データのハンドル
		*/
		int createGraph(const std::string& fileName);

		/**
		* @brief パスから新たに画像を読み込む
		* - 分割して使用する画像用
		* @param fileName 画像データの名前
		* @param allNum 画像の分割数
		* @param xNum 画像の横方向の分割数
		* @param yNum 画像の縦方向の分割数
		* @param xSize 画像の横方向のサイズ
		* @param ySize 画像の縦方向のサイズ
		* @return int* 画像データのハンドルを入れた配列の先頭アドレス
		*/
		int* createGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize);

	public:
		GraphFactory();
		~GraphFactory();

		/**
		* @brief 最初に必要な画像を読み込む
		*/
		void initLoad();

		/**
		* @brief パスから画像データのハンドルを返す、単一で使用する画像用
		* - 初めて読み込むデータは生成してプールしてから返す
		* - すでに読み込まれているデータはコンテナから検索して返す
		* @param fileName ほしい画像の名前
		* @return int 画像ハンドル
		*/
		int getGraph(const std::string& fileName);

		/**
		* @brief パスから画像データのハンドルを返す、分割して使用する画像用
		* - 初めて読み込むデータは生成してプールしてから返す
		* - すでに読み込まれているデータはコンテナから検索して返す
		* @param fileName ほしい画像の名前
		* @return int* 画像ハンドルが格納された配列の先頭アドレス
		*/
		int* getGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize);
	};

	class SoundFactory {
	private:
		//! パス指定省略のため
		std::string path;
		//! ハンドルを保管しておくコンテナ
		std::unordered_map<std::string, int> pool_;

		/**
		* @brief サウンドを読み込む
		* @param fileName サウンドデータの名前
		* @return 読み込んだサウンドのハンドル
		*/
		int loadSound(std::string& fileName);

		/**
		* @brief サウンドを非同期で読み込む
		* @param fileName サウンドデータの名前
		* @return 正常に読み込めたら1が返る
		* - すでに存在するデータを指定したらそのハンドルが返る
		*/
		int loadSoundAsync(std::string& fileName);

	public:
		SoundFactory();
		~SoundFactory();

		/**
		* @brief 最初に必要なサウンドを読み込む
		*/
		void initLoad();

		/**
		* @brief パスからサウンドのハンドルを返す
		* @param fileName 欲しいサウンドの名前
		* @return サウンドのハンドル
		*/
		int getSound(std::string& fileName);
	};


public:
	ResourceManager();
	~ResourceManager();

	/**
	* @brief アプリケーション開始時に必要なリソースをまとめて読み込む
	*/
	void init();

	/**
	* @brief GraphFactoryを返す
	*/
	static GraphFactory& getGraphFac();

	/**
	* @brief GraphFactoryを返す
	*/
	static SoundFactory& getSoundFac();
};

