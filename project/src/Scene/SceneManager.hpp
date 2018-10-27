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
#include "Scene/Title.h"
#include "Scene/Stage1.h"
#include "../Utility/Error.hpp"

namespace Scene {
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
		~SceneManager() {
			while (!sceneStack_.empty()) {
				deleteScene();
			}
		}
		void onSceneChanged(const SceneName& scene, [[maybe_unused]]const Parameter* param, const StackPopFlag stackPopFlag) override {
			switch (stackPopFlag) {
			case StackPopFlag::NON:
				break;
			case StackPopFlag::POP:
				deleteScene();
				break;
			case StackPopFlag::ALL_CLEAR:
				stackClear();
			}
			switch (scene) {
			case Scene::SceneName::TITLE:
				sceneStack_.push(new Title(this, *param));
				break;
			case Scene::SceneName::GAME:
				sceneStack_.push(new Stage1(this, *param));
				break;
			case Scene::SceneName::BACK_SCENE:
				break;
			case Scene::SceneName::NON:
				std::cout << "シーンなし" << std::endl;
			default:
				ERR("存在しないシーンが呼ばれました");
				break;
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
		* @brief スタックのトップにあるシーンのメモリを解放する
		*/
		void deleteScene() {
			delete sceneStack_.top();
			sceneStack_.top() = nullptr;
			sceneStack_.pop();
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