/**
* @file Node.h
* @brief 全てのオブジェクトの基底クラスを定義
* @detail 親子関係構築、自身の駆動状態、メッセージ送受信機能を持つ
* @date 2018.8.8　開始
*/

#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <assert.h>
using namespace std;

/**
* @brief 全てのオブジェクトの基底クラス
*		 親子関係構築、自身の駆動状態を持つ
*		 駆動状態によって呼び出す更新・描画処理を変える
*/
class Node
{
	/**
	* @brief  駆動状態
	*		　状態に応じて呼び出す更新・描画処理を変える
	*/
	enum class State {
		Non,		//未定義
		Run,		//通常
		Stop,		//停止
		Sleep,		//指定フレーム後にRunに移行
		Destroy,	//削除予約
		Dead,		//削除済み
	};
public:
	//------------------------------------------------------
	//生成
	//------------------------------------------------------
	Node(const string& name, State state);
	virtual ~Node();
	//------------------------------------------------------
	//親にオブジェクトを追加
	//------------------------------------------------------
	/** 
	* @brief 通常状態で親に子供を追加
	* @param Ptr* obj 追加する子供オブジェクトのポインタ
	* @return Node* 追加した子供オブジェクトのポインタ
	*/
	template<typename Ptr>
	Node* insertToParent(Ptr* obj);
	/**
	* @brief 停止状態で親に子供を追加
	* @param Ptr* obj 追加する子供オブジェクトのポインタ
	* @return Node* 追加した子供オブジェクトのポインタ
	*/
	template<typename Ptr>
	Node* insertToParentStop(Ptr* obj);
	/**
	* @brief Sleep状態で親に子供を追加
	* @param Ptr* obj 追加する子供オブジェクトのポインタ
	* @param int sleepCnt 寝かせるフレーム数
	* @return Node* 追加した子供オブジェクトのポインタ
	*/
	template<typename Ptr>
	Node* insertToParentSleep(Ptr* obj, int sleepCnt);
	//------------------------------------------------------
	//子にオブジェクトを追加
	//------------------------------------------------------
	/**
	* @brief 通常状態で子にオブジェクトを追加
	* @param Ptr* obj 追加する子供オブジェクトのポインタ
	* @return Node* 追加した子供オブジェクトのポインタ
	*/
	template<typename Ptr>
	Node* insertAsChild(Ptr* obj);
	/**
	* @brief 停止状態で子にオブジェクトを追加
	* @param Ptr* obj 追加する子供オブジェクトのポインタ
	* @return Node* 追加した子供オブジェクトのポインタ
	*/
	template<typename Ptr>
	Node* insertAsChildStop(Ptr* obj);
	/**
	* @brief Sleep状態で子にオブジェクトを追加
	* @param Ptr* obj 追加する子供オブジェクトのポインタ
	* @param int sleepCnt 寝かせるフレーム数
	* @return Node* 追加した子供オブジェクトのポインタ
	*/
	template<typename Ptr>
	Node* insertAsChildSleep(Ptr* obj, int sleepCnt);
	//------------------------------------------------------
	//ポインタ関連
	//------------------------------------------------------
	/** @brief 自身のポインタを取得する */
	Node* selfPtr() const;
	/** @brief 自身のポインタを設定する(ルート以外で呼ぶ必要はない) */
	void setSelfPtr(Node* selfPtr);
	/** @brief 親のポインタを取得する */
	Node* getParentPtr() const;
	/** @brief 親のポインタを設定する(調整中) */
	void setParentPtr(Node* parentPtr);
	/** @brief ルートオブジェクトのポインタを取得する */
	Node* getRootPtr() const;
	//------------------------------------------------------
	//オブジェクト取得関連
	//------------------------------------------------------
	/** @brief 全子供オブジェクトを取得 */
	vector<Node*> getChildren() const;
	/**
	* @brief objectの名前にfindNamesが含まれているか、findNotNamesが含まれていない場合にtrueを返す
	* @param Node* object 調べる対象のオブジェクトのポインタ
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	* @return bool objectの名前にfindNamesが含まれているか、findNotNamesが含まれていない場合にtrue
	*/
	bool findObject(Node* object, const vector<string>& findNames, const vector<string>& findNotNames) const;
	/**
	* @brief 子供オブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトのポインタを取得する
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	* @return vector<Node*> 名前にfindNamesが含まれているか、findNotNamesが含まれていないオブジェクトのポインタのvector
	*/
	vector<Node*> getObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {}) const;
	/**
	* @brief ルートオブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトのポインタを取得する
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	* @return vector<Node*> 名前にfindNamesが含まれているか、findNotNamesが含まれていないオブジェクトのポインタのvector
	*/
	vector<Node*> getObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {}) const;
	/**
	* @brief 子供オブジェクトから指定した名前のオブジェクトを取得する
	* @param string name 見つけるオブジェクトの名前
	* @return Node* オブジェクトのポインタ
	*/
	Node* getObjectFromChildren(const string& name) const;
	/**
	* @brief ルートオブジェクトから指定した名前のオブジェクトを取得する
	* @param string name 見つけるオブジェクトの名前
	* @return Node* オブジェクトのポインタ
	*/
	Node* getObjectFromRoot(const string& name) const;
	/**
	* @brief 子供オブジェクトから指定したIDのオブジェクトを取得する
	* @param int id 見つけるオブジェクトのID
	* @return Node* オブジェクトのポインタ
	*/
	Node* getObjectFromChildren(int id) const;
	/**
	* @brief ルートオブジェクトから指定したIDのオブジェクトを取得する
	* @param int id 見つけるオブジェクトのID
	* @return Node* オブジェクトのポインタ
	*/
	Node* getObjectFromRoot(int id) const;
	//------------------------------------------------------
	//オブジェクト名前関連
	//------------------------------------------------------
	/** @brief 引数の名前と自身の名前が一致していればtrueを返す */
	bool matchingName(const string& name) const;
	/** @brief 指定の文字列が自身の名前に含まれていればtrueを返す */
	bool findName(const string& name) const;
	/** 
	* @brief 名前を変更する 
	* @param string name 変更後の名前
	* @return string 変更前の名前
	*/
	string changeName(const string& name);
	/** @brief 名前の\0以降に指定の文字列を追加 */
	void appendName(const string& append);
	//------------------------------------------------------
	//オブジェクトID関連
	//------------------------------------------------------
	/** @brief 自身のユニークなIDが引数と一致しているならtrueを返す */
	bool matchingID(int id) const;
	/** @brief 引数のオブジェクトが自身と一致しているならtrueを返す */
	bool isSame(Node* obj) const;
	//------------------------------------------------------
	//オブジェクト駆動状態変更関連
	//------------------------------------------------------
	//オブジェクト破棄予約------------------------------------
	virtual void kill();
	/** @brief 指定した名前のオブジェクトを子供から探して破棄予約 */
	void killFromChildren(const string& name);
	/** @brief 指定した名前のオブジェクトをルートから探して破棄予約 */
	void killFromRoot(const string& name);
	/**
	* @brief 子供オブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトの破棄予約をする
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	*/
	void killObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {});
	/**
	* @brief ルートオブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトの破棄予約をする
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	*/
	void killObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {});
	//オブジェクト駆動---------------------------------------
	virtual void run();
	/** @brief 子供を含めた駆動 */
	virtual void runAll();
	/** @brief 指定した名前のオブジェクトを子供から探して駆動 */
	void runFromChildren(const string& name);
	/** @brief 指定した名前のオブジェクトをルートから探して駆動 */
	void runFromRoot(const string& name);
	/**
	* @brief 子供オブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトを駆動
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	*/
	void runObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {});
	/**
	* @brief ルートオブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトを駆動
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	*/
	void runObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {});
	//オブジェクト停止----------------------------------------
	virtual void stop();
	/** @brief 子供を含めた停止 */
	void stopAll();
	/** @brief 指定した名前のオブジェクトを子供から探して停止 */
	void stopFromChildren(const string& name);
	/** @brief 指定した名前のオブジェクトをルートから探して停止 */
	void stopFromRoot(const string& name);
	/**
	* @brief 子供オブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトを停止
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	*/
	void stopObjectsFromChildren(const vector<string>& findNames, const vector<string>& findNotNames = {});
	/**
	* @brief ルートオブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトを停止
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	*/
	void stopObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames = {});
	//オブジェクトを寝かせる----------------------------------
	virtual void sleep(int sleepCnt);
	/** @brief 子供を含めたスリープ */
	void sleepAll(int sleepCnt);
	/** @brief 指定した名前のオブジェクトを子供から探してスリープ */
	void sleepFromChildren(const string& name, int sleepCnt);
	/** @brief 指定した名前のオブジェクトをルートから探してスリープ */
	void sleepFromRoot(const string& name, int sleepCnt);
	/**
	* @brief 子供オブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトをスリープ
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	* @param int sleepCnt 寝かせるフレーム数
	*/
	void sleepObjectsFromChildren(const vector<string>& findNames, const  vector<string>& findNotNames, int sleepCnt);
	/**
	* @brief ルートオブジェクトから、findNamesが含まれているか、findNotNamesが含まれていないオブジェクトをスリープ
	* @param vector<string> findNames 含まれる名前のvector
	* @param vector<string> findNotNames 含まれない名前のvector
	* @param int sleepCnt 寝かせるフレーム数
	*/
	void sleepObjectsFromRoot(const vector<string>& findNames, const vector<string>& findNotNames, int sleepCnt);
	/** @brief スリープからの復帰保証用 */
	virtual void resume();
	//------------------------------------------------------
	//アクセサ
	//------------------------------------------------------
	int ID() const;
	int priority() const;
	const string& name() const;
	State state() const;
	bool isRunning() const;
	bool isStop() const;
	bool isSleep() const;
	bool isDestroy() const;
	bool isDead() const;
	void changePriority(int priority);
	//-----------------------------------------------------------------------
	//比較用叙述関数
	//-----------------------------------------------------------------------
	static bool greaterPriority(const Node* lh, const Node* rh)
	{
		return lh->priority() > rh->priority();
	}
	static bool lessPriority(const Node* lh, const Node* rh)
	{
		return lh->priority() < rh->priority();
	}
	//-----------------------------------------------------------------------
	//メッセージ送受信
	//-----------------------------------------------------------------------
	virtual int receiveMsg(Node* sender, const string& msg);
	virtual int postMsg(Node* receiver, const string& msg);

private:
	//------------------------------------------------------
	//メンバ変数
	//------------------------------------------------------
	static int		uid_;			//! ユニークID、生成するとインクリメント
	int				id_;			//! オブジェクトID、検索用
	int				hierarchy_;		//! 階層、ルートが1、子供になるにつれ+1
	float			priority_;		//! 描画優先順位、高いほど手前に描画
	State			state_;			//! 駆動状態
	string			name_;			//!	名前、検索用
	int				sleepCnt_;		//! 寝かせるフレーム数、通常時は0

	Node*			selfPtr_;		//!	自身のポインタ
	Node*			parentPtr_;		//!	親のポインタ
	vector<Node*>	children_;		//!	子供オブジェクト
	vector<Node*>	insert_;		//! 子供に追加するオブジェクト
	//------------------------------------------------------

	//------------------------------------------------------
	//親子関係構築用
	//------------------------------------------------------
	/** @brief 生成時にユニークIDを設定 */
	void initID();
	//------------------------------------------------------
	/** @brief 親子関係を構築する	*/
	virtual void init();
	/** @brief 追加するオブジェクトを子供に追加 */
	void insert();

	//------------------------------------------------------
	//update関連
	//------------------------------------------------------
	/** @brief Runの時に呼ばれる*/
	virtual void update();
	/** @brief Stopの時に呼ばれる */
	virtual void updateStop();
	/** @brief Sleepの時に呼ばれる */
	virtual void updateSleep();
	/** @brief Destroyの時に呼ばれる */
	virtual void updateDestroy();
	/** @brief 子供を含めた更新処理 */
	virtual void updateChildObjects();
	/** @brief Runの時に呼ばれる子供を含めた更新処理 */
	void updateWithChildrenRun();
	/** @brief Stopの時に呼ばれる子供を含めた更新処理 */
	void updateWithChildrenStop();
	/** @brief Sleepの時に呼ばれる子供を含めた更新処理 */
	void updateWithChildrenSleep();
	/** @brief Destroyの時に呼ばれる子供を含めた更新処理 */
	void updateWithChildrenDestroy();
	/** @brief 自身の駆動状態に応じて呼び出す更新処理を切り替える */
	virtual void updateSelect();
	/** @brief ルートのみで呼ぶこと */
	void updateWithChildren();
	//-----------------------------------------------------------------------
	//render関連
	//-----------------------------------------------------------------------
	/** @brief Runの時に呼ばれる*/
	virtual void render();
	/** @brief Stopの時に呼ばれる */
	virtual void renderStop();
	/** @brief Sleepの時に呼ばれる */
	virtual void renderSleep();
	/** @brief Destroyの時に呼ばれる */
	virtual void renderDestroy();
	/** @brief 子供を含めた描画処理 */
	virtual void renderChildObjects();
	/** @brief Runの時に呼ばれる子供を含めた描画処理 */
	void renderWithChildrenRun();
	/** @brief Stopの時に呼ばれる子供を含めた描画処理 */
	void renderWithChildrenStop();
	/** @brief Sleepの時に呼ばれる子供を含めた描画処理 */
	void renderWithChildrenSleep();
	/** @brief Destroyの時に呼ばれる子供を含めた描画処理 */
	void renderWithChildrenDestroy();
	/** @brief 自身の駆動状態に応じて呼び出す描画処理を切り替える */
	virtual void renderSelect();
	/** @brief ルートのみで呼ぶこと */
	virtual void renderWithChildren();

public:
};

template<typename Ptr>
inline Node* Node::insertToParent(Ptr * obj){
	auto parent = getParentPtr();
	if (!parent) { assert(!"親のポインタがありません"); }
	parent->insertAsChild(obj);
	return obj;
}

template<typename Ptr>
inline Node * Node::insertToParentStop(Ptr * obj) {
	insertToParent(obj);
	obj->stop();
	return obj;
}

template<typename Ptr>
inline Node * Node::insertToParentSleep(Ptr * obj, int sleepCnt){
	insertToParent(obj);
	obj->sleep(sleepCnt);
	return obj;
}

template<typename Ptr>
inline Node * Node::insertAsChild(Ptr * obj) {
	obj->setSelfPtr(obj);
	obj->setParentPtr(selfPtr());
	obj->hierarchy_ = hierarchy_ + 1;
	insert_.push_back(obj);
	return obj;
}

template<typename Ptr>
inline Node * Node::insertAsChildStop(Ptr * obj){
	insertAsChild(obj);
	obj->stop();
	return obj;
}

template<typename Ptr>
inline Node * Node::insertAsChildSleep(Ptr * obj, int sleepCnt) {
	insertAsChild(obj);
	obj->sleep(sleepCnt);
	return obj;
}
