#include "Image.h"
#include "../../Scene/GameManager.h"


Image::Image()
{
}

Image::~Image()
{}

void Image::setHandle(const std::string& path) {
	handle_ = game->grafac->getGraph(path);
}
void Image::setHandleDiv(const std::string& path, const int allNum, const int xNun, const int yNun, const int xSize, const int ySize) {
	handleDiv_ = game->grafac->getGraphDiv(path, allNum, xNun, yNun, xSize, ySize);
}

void Image::draw(const Math::Vec& draw, const bool isCenter) {
	if (isCenter) {
		int w, h;
		GetGraphSize(handle_, &w, &h);
		Math::Vec pivot{ draw.x + w,draw.x + h };
		DrawGraphF(pivot.x, pivot.y, handle_, true);
	}
	else {
		DrawGraphF(draw.x, draw.y, handle_, true);
	}
}

void Image::draw(const Math::Vec& draw, const int index, const bool isCenter) {
	if (isCenter) {
		int w, h;
		GetGraphSize(handle_, &w, &h);
		Math::Vec pivot{ draw.x + w,draw.x + h };
		DrawGraphF(pivot.x, pivot.y, handleDiv_[index], true);
	}
	else {
		DrawGraphF(draw.x, draw.y, handleDiv_[index], true);
	}
}