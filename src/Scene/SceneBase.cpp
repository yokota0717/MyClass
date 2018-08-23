#include "SceneBase.h"



SceneBase::SceneBase(const std::string& name, Node::State state)
	:
	Node(name, state)
{}


SceneBase::~SceneBase()
{
}

bool SceneBase::changeScene(const std::string& scene){
	//�q�����܂߂Ē�~
	stopAll();
	//���̃V�[�����N��
	return postMsg(getObjectFromRoot(scene), "changeScene");
}
