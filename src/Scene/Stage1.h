#pragma once
#include "SceneBase.h"

class Stage1 : public SceneBase
{
public:
	Stage1(const std::string& name, Node::State state);
	~Stage1();

	void init() override;
	void update() override;
	void render() override;

	int receiveMsg(Node* sender, const std::string& msg) override;
};

