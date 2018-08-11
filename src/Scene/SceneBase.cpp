#include "SceneBase.h"



SceneBase::SceneBase(const std::string& name, GameObject::Status status)
	:
	GameObject(name, status)
{}


SceneBase::~SceneBase()
{
}

bool SceneBase::changeScene(const std::string& scene){
	//子供を含めて停止
	pauseAll();
	//次のシーンを起動
	return postMsg(getObjectFromRoot(scene), "changeScene");
}
