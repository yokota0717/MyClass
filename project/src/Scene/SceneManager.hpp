/**
* @file SceneManager.hpp
* @brief シーン管理を行うクラスを定義する
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include <iostream>
#include <stack>
#include "SceneInfo.hpp"
#include "Title.h"

namespace Scene{
	/**
	* @brief シーン管理を行う
	*/
	class SceneManager : public IOnSceneChangedListener {
	private:
		//! シーンのスタック、作ったらここに積む
		std::stack<AbstractScene*> sceneStack_;
	public:
		SceneManager() {
			Parameter param;
			sceneStack_.push(new Title(this, param));		//最初のシーンを設定(タイトル)
		}

		void onSceneChange(const SceneName& scene, Parameter& param, const StackPopFlag stackPopFlag) {
			switch (stackPopFlag) {
			case StackPopFlag::NON:
				break;
			case StackPopFlag::POP:
				

			}
		}

		/**
		* @brief スタックされているシーンをすべて消去する
		*/
		void stackClear() {
			while (!sceneStack_.empty()) {
				sceneStack_.pop();
			}
		}
		/**
		* @brief スタックのトップにあるシーンを更新する
		*/
		void updateTopScene() {
			sceneStack_.top()->update();
		}
		/**
		* @brief スタックのトップにあるシーンの描画をする
		*/
		void renderTopScene() {
			sceneStack_.top()->render();
		}
	};
}