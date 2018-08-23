#include "SceneBase.h"



SceneBase::SceneBase(const std::string& name, Node::State state)
	:
	Node(name, state)
{}


SceneBase::~SceneBase()
{
}

bool SceneBase::changeScene(const std::string& scene){
	//子供を含めて停止
	stopAll();
	//次のシーンを起動
	return postMsg(getObjectFromRoot(scene), "changeScene");
}
