#include "Title.h"
#include "../Actor/Player.h"


Title::Title(const std::string& name)
	:
	SceneBase(name)
{}


Title::~Title(){}

void Title::init() {
	insertAsChild(new Player("scene1.jpg"));
}

void Title::update()
{
}

void Title::render()
{
}
