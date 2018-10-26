#include "Image.h"
#include "../Actor/Game.h"


Image::Image(const std::string& path)
{
	handle_ = game->grafac->GetGraph(path);
}

Image::~Image()
{}

void Image::setHandle(const std::string& path) {
	handle_ = game->grafac->GetGraph(path);
}

void Image::draw(Math::Box2D& draw, Math::Box2D& src) {
	DrawRectExtendGraphF(draw.x, draw.y, draw.x + draw.w, draw.y + draw.h, int(src.x), int(src.y), int(src.w), int(src.h), handle_, true);
}
