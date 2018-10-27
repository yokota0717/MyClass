/**
* @file FPS.hpp
* @brief FPS固定の処理を記述する
* - 参考URL：https://dixq.net/g/03_14.html
* @author yokota0717
* @date 2018.10.27
*/

#pragma once
#include <iostream>
#include "DxLib.h"
#include "../../Utility/Utility.hpp"

/**
* @brief FPS固定の処理をするクラス
*/
class FPS {
private:
	//! 測定開始時刻
	int startTime_;
	//! カウンタ
	int counter_;
	//! 現在のFPS
	float fps_;
	//! 平均をとるサンプル数
	static const int SAMPLE_NUM = 60;
	//! 指定FPS
	static const int SETTING_FPS = 60;
public:
	FPS()
		:
		counter_(0),
		fps_(0)
	{
		startTime_ = GetNowCount();
	}
	~FPS() {};
	/**
	* @brief FPS計算の処理を行う
	*/
	void update() {
		if (++counter_ > SAMPLE_NUM) {
			int now = GetNowCount();
			fps_ = 1000.f / ((now - startTime_) / (float)SAMPLE_NUM);
			counter_ = 0;
			startTime_ = now;
			outputFPS();
		}
	}
	/**
	* @brief FPSが指定の値を超えた場合にスリープをかける
	* - この関数をメインループの最後に呼ぶこと
	*/
	void wait() {
		int tookTime = GetNowCount() - startTime_;
		int waitTime = counter_ * 1000 / SETTING_FPS - tookTime;
		if (waitTime > 0) {
			Sleep(waitTime);
		}
	}
	/**
	* @brief デバッグ用FPS出力関数
	*/
	void outputFPS() {
		DOUT << "FPS：" << fps_ << std::endl;
	}
};
