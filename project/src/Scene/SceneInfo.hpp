/**
* @file SceneInfo.hpp
* @brief シーンの基底クラス、インターフェイスを定義する
* @author yokota0717
* @date 2018.10.26
*/


#pragma once
#include <unordered_map>
#include <any>

namespace Scene {
	/**
	* @brief シーン名、これでシーンを判別する
	*/
	enum class SceneName {
		NON,			//未定義
		TITLE,			//タイトル
		GAME,			//ゲーム本編
		BACK_SCENE,		//スタックに前のシーンが残っていれば戻る
	};

	/**
	* @brief シーン遷移時に渡すパラメータ
	*/
	class Parameter final {
	private:
		/**
		* @brief シーン遷移時に渡すパラメータのコンテナ
		*/
		std::unordered_map<std::string, std::any> map_;
	public:
		Parameter() = default;
		/**
		* @brief コンテナに要素を追加する
		* - テンプレート引数に挿入したい値を入れる
		* @param key キーとなる名前
		* @param value 挿入したい値
		*/
		template<typename ValueType>
		void add(const std::string& key, const ValueType value) {
			map[key] = value;
		}
		/**
		* @ brief コンテナにある指定したキーの値を取得する
		* - テンプレート引数で取得したい値を返す
		*/
		template<typename ValueType>
		[[nodiscard]] const ValueType get(const std::string& key) {
			try {
				auto it = map_.find(key);
				if (it == map_.end()) {
					throw "キーがありません";
				}
				return std::any_cast<ValueType>(it->second);
			}
			catch (std::string& errMsg) {
				std::cout << errMsg << std::endl;
			}
		}
	};

	/**
	* @brief シーン変更時に指定するシーン消去フラグ
	*/
	enum class StackPopFlag {
		POP,		//現在のシーンをポップする
		NON,		//現在のシーンをスタックしたままにする
		ALL_CLEAR,	//すべてのシーンを消去する
	};

	/**
	* @brief コールバックするインターフェイスクラス
	*/
	class IOnSceneChangedListener {
	public:
		IOnSceneChangedListener() = default;
		virtual ~IOnSceneChangedListener() = default;
		/**
		* @brief シーンを変更する関数
		* @param scene 次のシーン
		* @param param 次のシーンに渡すパラメータ
		* @param stackPopFlag 自身のスタックをクリアするか
		*/
		virtual void onSceneChanged(const SceneName& scene, const Parameter* param, const StackPopFlag stackPopFlag) = 0;
	};
	/**
	* @brief シーンの基底クラス
	*/
	class AbstractScene {
	private:
		IOnSceneChangedListener* sceneLister_;
	public:
		AbstractScene(IOnSceneChangedListener* listener)
			:
			sceneLister_(listener)
		{}
		virtual ~AbstractScene() = default;
		IOnSceneChangedListener& callBack() const { return *sceneLister_; }
		virtual void update() = 0;
		virtual void render() = 0;
	};
}