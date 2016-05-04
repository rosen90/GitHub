#ifndef TILE_H_
#define TILE_H_

#include "SDL2/SDL.h"

struct Color {
	Uint8 red, green, blue, alpha;
};


class Tile {
public:

	Tile(int nNumber = 0, int nX = 0, int nY = 0, int width = 0, int height = 0);
	void SetColor(SDL_Color);
	void Draw(SDL_Renderer*);
	void SetPosition(int nX, int nY);
	const int GetNumber() const;
	void SetNumber(int);
	virtual ~Tile();
	int getNHeight() const;
	void setNHeight(int nHeight);
	int getNWidth() const;
	void setNWidth(int nWidth);
	int getNX() const;
	void setNX(int nX);
	int getNY() const;
	void setNY(int nY);

private:
		Color currentColor;
		const static Color InitialColor;
		SDL_Rect rect;
		SDL_Rect outline;
		int m_nNumber;

		int m_nX;
		int m_nY;
		int m_nWidth;
		int m_nHeight;
};


#endif
