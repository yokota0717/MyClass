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
	string file = path + fileName;
	auto it = pool.find(file);
	if (it != pool.end())
		return it->second;
	int newGraph = CreateGraph(file.c_str());
	pool.insert(make_pair(file, newGraph));
	return newGraph;
}