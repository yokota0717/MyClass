/**
* @file GraphFactory.cpp
* @brief 画像データのハンドル管理クラスの処理を記述する
* @author yokota0717
* @date 2018.10.27
*/

#include "GraphFactory.h"

GraphFactory::GraphFactory()
	:
	path("./data/image/")
{}

GraphFactory::~GraphFactory() {
	for (auto it = divPool_.begin(); it != divPool_.end(); ++it) {
		delete it->second;
		it->second = nullptr;
	}
	divPool_.clear();
}

void GraphFactory::initLoad() {

}

int GraphFactory::createGraph(const std::string& fileName) {
	int handle = LoadGraph(fileName.c_str());
	return handle;
}

int* GraphFactory::createGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize) {
	int* handle = new int[allNum];
	LoadDivGraph(fileName.c_str(), allNum, xNum, yNum, xSize, ySize, handle);
	return handle;
}

int GraphFactory::getGraph(const std::string& fileName) {
	std::string file = path + fileName;
	auto it = singlePool_.find(file);
	if (it != singlePool_.end()) {
		return it->second;
	}
	int newGraph = createGraph(file.c_str());
	singlePool_.insert(std::make_pair(file, newGraph));
	return newGraph;
}

int* GraphFactory::getGraphDiv(const std::string& fileName, const int allNum, const int xNum, const int yNum, const int xSize, const int ySize) {
	std::string file = path + fileName;
	auto it = divPool_.find(file);
	if (it != divPool_.end()) {
		return it->second;
	}
	int* newGraph = createGraphDiv(file.c_str(), allNum, xNum, yNum, xSize, ySize);
	divPool_.insert(std::make_pair(file, newGraph));
	return newGraph;
}