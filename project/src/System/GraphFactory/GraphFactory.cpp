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

int GraphFactory::CreateGraph(const std::string& fileName) {
	int handle = LoadGraph(fileName.c_str());
	return handle;
}

int GraphFactory::GetGraph(const std::string& fileName) {
	std::string file = path + fileName;
	auto it = pool.find(file);
	if (it != pool.end())
		return it->second;
	int newGraph = CreateGraph(file.c_str());
	pool.insert(std::make_pair(file, newGraph));
	return newGraph;
}