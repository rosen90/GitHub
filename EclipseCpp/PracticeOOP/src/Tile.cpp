
#include "Tile.h"

const Color Tile::InitialColor = { 102, 147, 203, 128 };

Tile::Tile(int nNumber, int nX, int nY, int width, int height) {
	SetNumber(nNumber);
	this->m_nNumber = nNumber;
	SetPosition(nX, nY);
	rect.w = width;
	rect.h = height;
	outline.w = width;
	outline.h = height;

}

void Tile::SetColor(SDL_Color tileColor) {
	this->currentColor.red = tileColor.r;
	this->currentColor.green = tileColor.g;
	this->currentColor.blue = tileColor.b;
	this->currentColor.alpha = tileColor.a;
}

void Tile::Draw(SDL_Renderer* gRenderer) {
	SDL_SetRenderDrawColor(gRenderer, currentColor.red, currentColor.green,currentColor.blue, currentColor.alpha);
	SDL_RenderFillRect(gRenderer, &rect);
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, InitialColor.alpha);
	SDL_RenderDrawRect(gRenderer, &outline);
}

void Tile::SetPosition(int nX, int nY) {
	this->rect.x = nX;
	this->rect.y = nY;
	this->outline.x = nX;
	this->outline.y = nY;
}

const int Tile::GetNumber() const {
	return m_nNumber;
}

void Tile::SetNumber(int nNumber) {
	this->m_nNumber = nNumber;
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

int Tile::getNHeight() const {
	return rect.h;
}

void Tile::setNHeight(int nHeight) {
	rect.h = nHeight;
	outline.h = nHeight;
}

int Tile::getNWidth() const {
	return rect.w;
}

void Tile::setNWidth(int nWidth) {
	rect.w = nWidth;
	outline.w = nWidth;
}

int Tile::getNX() const {
	return rect.x;
}

void Tile::setNX(int nX) {
	rect.x = nX;
	outline.x = nX;
}

int Tile::getNY() const {
	return rect.y;
}

void Tile::setNY(int nY) {
	rect.y = nY;
	outline.y = nY;
}
