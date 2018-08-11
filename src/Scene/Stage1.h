#pragma once
#include "SceneBase.h"

class Stage1 : public SceneBase
{
public:
	Stage1(const std::string& name, GameObject::Status status);
	~Stage1();

	void init() override;
	void update() override;
	void render() override;

	int receiveMsg(std::weak_ptr<GameObject> sender, const std::string& msg) override;
};

