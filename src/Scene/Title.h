#pragma once
#include "SceneBase.h"
class Title : public SceneBase
{
public:
	Title(const std::string& name, GameObject::Status status);
	~Title();

	void init() override;
	void update() override;
	void render() override;

	int receiveMsg(std::weak_ptr<GameObject> sender, const std::string& msg) override;
};

