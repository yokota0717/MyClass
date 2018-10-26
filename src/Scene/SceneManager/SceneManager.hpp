/**
* @file SceneManager.hpp
* @brief シーン管理を行うクラスを定義する
* @author yokota0717
* @date 2018.10.26
*/

#pragma once
#include <stack>
#include <unordered_map>

namespace Scene {
	/**
	* @brief シーン名、これでシーンを判別する
	*/
	enum class SceneName {
		NON,
		TITLE,
		GAME,
	};

	/**
	* @brief シーン遷移時に渡すパラメータ
	*/
	class Parameter final {
		Parameter() = default;

	};

	/**
	* @brief コールバックするインターフェイスクラス
	*/
	class IOnSceneChangeListener {
	public:
		IOnSceneChangeListener() = default;
		virtual ~IOnSceneChangeListener() = default;
		virtual void onSceneChanged(const SceneName scene, const Parameter& param, const bool stackClear) = 0;
	};
	/**
	* @brief シーンの基底クラス
	*/
	class AbstractScene {
	private:
		IOnSceneChangeListener * sceneLister_;
	public:
		AbstractScene(IOnSceneChangeListener* listener, const Parameter& param)
			:
			sceneLister_(listener)
		{}
		virtual ~AbstractScene() = default;
		virtual void update() = 0;
		virtual void render() = 0;
	};
	class SceneManager {
	private:
		//! シーンのスタック、作ったらここに積む
		std::stack<AbstractScene*> sceneStack;
	public:
	};
}
