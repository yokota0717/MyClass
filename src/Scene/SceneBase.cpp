#include "SceneBase.h"



SceneBase::SceneBase(const std::string& name, GameObject::Status status)
	:
	GameObject(name, status)
{}


SceneBase::~SceneBase()
{
}

bool SceneBase::changeScene(const std::string& scene){
	//�q�����܂߂Ē�~
	pauseAll();
	//���̃V�[�����N��
	return postMsg(getObjectFromRoot(scene), "changeScene");
}
