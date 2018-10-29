/**
* @file ResourceManager.cpp
* @brief �摜�f�[�^�̃n���h���Ǘ��N���X�̏������L�q����
* @author yokota0717
* @date 2018.10.27
* @param history
- 2018.10.29 yokota0717
-# �T�E���h�̒ǉ�
-# ResourceManager�ǉ��ɔ����ύX
-# DX���C�u�����̃n���h�����������ǉ�
*/

#include "ResourceManager.h"

//---------------------------------------------------------------------------------------------

void ResourceManager::GraphFactory::initLoad() {
	//�������A�v���P�[�V�����J�n���ɓǂݍ��݂����摜�͂����Ń��[�h���遚����
}
void ResourceManager::SoundFactory::initLoad() {
	//�������A�v���P�[�V�����J�n���ɓǂݍ��݂����T�E���h�͂����Ń��[�h���遚����
}

//---------------------------------------------------------------------------------------------

ResourceManager::GraphFactory::GraphFactory()
	:
	path("./data/image/")
{}

ResourceManager::GraphFactory::~GraphFactory() {
	for (auto it = divPool_.begin(); it != divPool_.end(); ++it) {
		if (it->second) {
			delete it->second;
		}
		it->second = nullptr;
	}
	divPool_.clear();
	InitGraph();
}

int ResourceManager::GraphFactory::createGraph(const std::string& fileName) {
	int handle = LoadGraph(fileName.c_str());
	return handle;
}

int* ResourceManager::GraphFactory::createGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize) {
	int* handle = new int[allNum];
	LoadDivGraph(fileName.c_str(), allNum, xNum, yNum, xSize, ySize, handle);
	return handle;
}

int ResourceManager::GraphFactory::getGraph(const std::string& fileName) {
	std::string file = path + fileName;
	auto it = singlePool_.find(file);
	if (it != singlePool_.end()) {
		return it->second;
	}
	int newGraph = createGraph(file.c_str());
	if (newGraph != -1) {
		singlePool_.insert(std::make_pair(file, newGraph));
	}
	return newGraph;
}

int* ResourceManager::GraphFactory::getGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize) {
	std::string file = path + fileName;
	auto it = divPool_.find(file);
	if (it != divPool_.end()) {
		return it->second;
	}
	int* newGraph = createGraphDiv(file.c_str(), allNum, xNum, yNum, xSize, ySize);
	if (*newGraph != -1) {
		divPool_.insert(std::make_pair(file, newGraph));
	}
	return newGraph;
}

//---------------------------------------------------------------------------------------------

ResourceManager::SoundFactory::SoundFactory()
	:
	path("./data/sound/")
{}	

ResourceManager::SoundFactory::~SoundFactory()
{
	InitSoundMem();
}

int ResourceManager::SoundFactory::loadSound(std::string& fileName) {
	int handle = LoadSoundMem(fileName.c_str());
	return handle;
}

int ResourceManager::SoundFactory::loadSoundAsync(std::string& fileName) {
	SetUseASyncLoadFlag(true);	//�񓯊��ǂݍ��݃t���O��true��
	int handle = LoadSoundMem(fileName.c_str());
	SetUseASyncLoadFlag(false);
	return 1;
}

int ResourceManager::SoundFactory::getSound(const std::string& fileName) {
	std::string file = path + fileName;
	auto it = pool_.find(file);
	if(it != pool_.end()){
		return it->second;
	}
	int newSound = loadSound(file);
	if (newSound != -1) {	//�ǂݍ��݂Ɏ��s���Ă��Ȃ�������R���e�i�ɒǉ�
		pool_.insert(std::make_pair(file, newSound));
	}
	return newSound;
}

//---------------------------------------------------------------------------------------------

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {}

void ResourceManager::init() {
	static std::unique_ptr<GraphFactory> graphfac_ = std::make_unique<GraphFactory>();
	static std::unique_ptr<SoundFactory> soundfac_ = std::make_unique<SoundFactory>();
	graphfac_->initLoad();
	soundfac_->initLoad();
}

ResourceManager::GraphFactory& ResourceManager::getGraphFac() {
	static std::unique_ptr<GraphFactory> graphfac_ = std::make_unique<GraphFactory>();
	return *graphfac_;
}

ResourceManager::SoundFactory& ResourceManager::getSoundFac() {
	static std::unique_ptr<SoundFactory> soundfac_ = std::make_unique<SoundFactory>();
	return *soundfac_;
}
