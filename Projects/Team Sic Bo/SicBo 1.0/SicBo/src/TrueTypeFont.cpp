/*
 * TrueTypeFont.cpp
 *
 *  Created on: 2.10.2014 �.
 *      Author: msi
 */

#include "TrueTypeFont.h"

TrueTypeFont::TrueTypeFont() {}

TrueTypeFont::~TrueTypeFont()
{
	closeFont();
}


void TrueTypeFont::load()
{
	if (TTF_Init() == -1)
	{
		printf("Unable to initialize SDL_ttf: %s \n", TTF_GetError());
		exit(1);
	}
	else
	{
		gFont = loadfont("Chinese Takeaway.ttf", 23);
		statisticFont = loadfont("Chinese Takeaway.ttf",31);
	}
}

TTF_Font* TrueTypeFont::loadfont(string file,int size)
{
	TTF_Font* tempFont = TTF_OpenFont(file.c_str(),size);
	if(tempFont == NULL)
	{
		printf("Unable to load font: %s %s \n", file.c_str(), TTF_GetError());
	}
	return tempFont;
}

SDL_Surface* TrueTypeFont::createImageFromString(TTF_Font* font, string text)
{
	SDL_Color white = {255,255,255};
	result = TTF_RenderText_Blended(gFont,text.c_str(),white);
	return result;
}


void TrueTypeFont::printStatisticData()
{
    printStatistic.readDataFromFile(fullStatisticData);
    SDL_Surface* tempDataSurface = NULL;

	tempDataSurface = createImageFromString(statisticFont,fullStatisticData[0]);
	SDL_Rect dataRect = {190,80,0,0};
	SDL_BlitSurface(tempDataSurface, NULL, getSurface(), &dataRect);
	SDL_FreeSurface(tempDataSurface);
	tempDataSurface = NULL;

    int y = 110;
    for(int i = 1;i<16;i++,y+=30)
    {
    	tempDataSurface = createImageFromString(statisticFont,fullStatisticData[i]);
		SDL_Rect dataRect = {300,y,0,0};
		SDL_BlitSurface(tempDataSurface, NULL, getSurface(), &dataRect);
		SDL_FreeSurface(tempDataSurface);
		tempDataSurface = NULL;
    }
}

void TrueTypeFont::drawAllTTF()
{
	for(size_t i = 0;i<buttonImages.size();++i)
	{
		if(buttonImages[i].getBet() != 0)
		{
			drawBetText(i);
		}
	}
	onScreenBet();
	onScreenWin(player);
	onScreenCredit(player);
	onHighScore(record);
	recordHighScore(checkHighScore());
}

void TrueTypeFont::drawBetText(int i)
{
	int choiceBetType = choiceChipBetbyColor(buttonImages[i].getBet());
	string text = static_cast<ostringstream*>(&(ostringstream() << choiceBetType))->str();
	SDL_Surface* stringImage = createImageFromString(gFont, text);

	choiceChipColor(i);
	loadChipText(i,stringImage);

	SDL_FreeSurface(stringImage);
	stringImage = NULL;
}

int TrueTypeFont::choiceChipBetbyColor(int bet)
{
	if(bet < 100)
	{
		return bet;
	}
	else if (bet >= 100 && bet < 1000)
	{
		bet = bet / 10;
		return bet;
	}
	else
	{
		bet = bet / 100;
		return bet;
	}
}
void TrueTypeFont::choiceChipColor(int i)
{
	int choiceColor = buttonImages[i].getBet();
	if(choiceColor < 100)
	{
		loadBlueChip(i);

	}
	else if (choiceColor >= 100 && choiceColor < 1000)
	{
		loadYellowChip(i);
	}
	else
	{
		loadRedChip(i);
	}
}
void TrueTypeFont::loadChipText(int i,SDL_Surface* stringImage)
{
	SDL_Rect textRect = buttonImages[i].getButtonRect();
	if(buttonImages[i].getBet() == 5) {
		textRect.x += (textRect.w/2) - 4;
		textRect.y += (textRect.h/2) - 11;
	}
	else {
		textRect.x += (textRect.w/2) - 9;
		textRect.y += (textRect.h/2) - 11;
	}

	SDL_BlitSurface(stringImage, NULL, getSurface(), &textRect);
}

void TrueTypeFont::loadYellowChip(int i)
{
	SDL_Rect chipRect = buttonImages[i].getButtonRect();
	chipRect.x += (chipRect.w/2) - 15;
	chipRect.y += (chipRect.h/2) - 17;
	SDL_SetColorKey(yellowChip, SDL_TRUE, SDL_MapRGB(yellowChip->format, 255, 255, 255));
	SDL_BlitSurface(yellowChip, NULL, getSurface(),&chipRect);
}
void TrueTypeFont::loadBlueChip(int i)
{
	SDL_Rect chipRect = buttonImages[i].getButtonRect();
	chipRect.x += (chipRect.w/2) - 15;
	chipRect.y += (chipRect.h/2) - 17;
	SDL_SetColorKey(blueChip, SDL_TRUE, SDL_MapRGB(blueChip->format, 255, 255, 255));
	SDL_BlitSurface(blueChip, NULL, getSurface(),&chipRect);
}
void TrueTypeFont::loadRedChip(int i)
{
	SDL_Rect chipRect = buttonImages[i].getButtonRect();
	chipRect.x += (chipRect.w/2) - 15;
	chipRect.y += (chipRect.h/2) - 17;
	SDL_SetColorKey(redChip, SDL_TRUE, SDL_MapRGB(redChip->format, 255, 255, 255));
	SDL_BlitSurface(redChip, NULL, getSurface(),&chipRect);
}

void TrueTypeFont::onScreenBet()
{
	int bet = 0;
	for(size_t i = 0;i<buttonImages.size();++i)
	{
		bet += buttonImages[i].getBet();
	}
	string betText = static_cast<ostringstream*>(&(ostringstream() << bet))->str();
	SDL_Surface* tempSurface = createImageFromString(gFont, betText);
	SDL_Rect bet_rect = { 260, 604, 100, 50 };
	SDL_BlitSurface(tempSurface, NULL, getSurface(), &bet_rect);
	SDL_FreeSurface(tempSurface);
	tempSurface = NULL;
}
void TrueTypeFont::onScreenWin(Player &ob)
{
	int win = ob.getShowWin();
	string betText = static_cast<ostringstream*>(&(ostringstream() << win))->str();
	SDL_Surface* tempSurface = createImageFromString(gFont, betText);
	SDL_Rect win_rect = { 260, 632, 100, 50 };
	SDL_BlitSurface(tempSurface, NULL, getSurface(), &win_rect);
	SDL_FreeSurface(tempSurface);
	tempSurface = NULL;
}
void TrueTypeFont::onScreenCredit(Player &ob)
{
	int credit = ob.showCredit();
	string betText = static_cast<ostringstream*>(&(ostringstream() << credit))->str();
	SDL_Surface* tempSurface = createImageFromString(gFont, betText);
	SDL_Rect credit_rect = { 80, 626, 100, 50 };
	SDL_BlitSurface(tempSurface, NULL, getSurface(), &credit_rect);
	SDL_FreeSurface(tempSurface);
	tempSurface = NULL;
}
void TrueTypeFont::onHighScore(Recovery &high)
{
	int maxWin = high.highScore();
	string highScore =
			static_cast<ostringstream*>(&(ostringstream() << maxWin))->str();
	SDL_Surface* highS = createImageFromString(gFont, highScore);
	SDL_Rect highRect = { 447, 625, 100, 50 };
	SDL_BlitSurface(highS, NULL, getSurface(), &highRect);

	SDL_FreeSurface(highS);
	highS = NULL;
}

void TrueTypeFont::dicesVisual()
{
	//3 dices visual
	SDL_Surface* dices[6];

	dices[0] = rollDiceOne;
	dices[1] = rollDiceTwo;
	dices[2] = rollDiceThree;
	dices[3] = rollDiceFour;
	dices[4] = rollDiceFive;
	dices[5] = rollDiceSix;

	SDL_Rect firstDice = {730, 0, 60, 60};
	SDL_Rect secondDice = {790, 0, 60, 60};
	SDL_Rect thirdDice = {850, 0, 60, 60};

	SDL_BlitSurface(dices[testDice.getFirstDice() - 1], NULL, getSurface(), &firstDice);
	SDL_BlitSurface(dices[testDice.getSecondDice() - 1], NULL, getSurface(), &secondDice);
	SDL_BlitSurface(dices[testDice.getThirdDice() - 1], NULL, getSurface(), &thirdDice);

}

void TrueTypeFont::fakeDiceRoll()
{
	SDL_Surface* fakeDices[6];

	SDL_Surface* fakeFirstDiceRoll = NULL;
	SDL_Surface* fakeSecondDiceRoll = NULL;
	SDL_Surface* fakeThirdDiceRoll = NULL;

	SDL_Rect fakeFirstDice = {730, 0, 60, 60};
	SDL_Rect fakeSecondDice = {790, 0, 60, 60};
	SDL_Rect fakeThirdDice= {850, 0, 60, 60};

	fakeDices[0] = rollDiceOne;
	fakeDices[1] = rollDiceTwo;
	fakeDices[2] = rollDiceThree;
	fakeDices[3] = rollDiceFour;
	fakeDices[4] = rollDiceFive;
	fakeDices[5] = rollDiceSix;

	int p = 200;

	for( int i = 0; i < 10; i++ )
	{
		mouseCursor();
		int random = rand() % 6 + 1;
		fakeFirstDiceRoll = fakeDices[random - 1];
		random = rand() % 6 + 1;
		fakeSecondDiceRoll = fakeDices[random - 1];
		random = rand() % 6 + 1;
		fakeThirdDiceRoll = fakeDices[random - 1 ];

		SDL_BlitSurface(fakeFirstDiceRoll, NULL, getSurface(), &fakeFirstDice);
		SDL_BlitSurface(fakeSecondDiceRoll, NULL, getSurface(), &fakeSecondDice);
		SDL_BlitSurface(fakeThirdDiceRoll, NULL, getSurface(), &fakeThirdDice);
		SDL_SetColorKey(fakeFirstDiceRoll, SDL_TRUE, SDL_MapRGB(fakeFirstDiceRoll->format, 0, 0, 0));
		SDL_SetColorKey(fakeSecondDiceRoll, SDL_TRUE, SDL_MapRGB(fakeSecondDiceRoll->format, 0, 0, 0));
		SDL_SetColorKey(fakeThirdDiceRoll, SDL_TRUE, SDL_MapRGB(fakeThirdDiceRoll->format, 0, 0, 0));
		SDL_UpdateWindowSurface(window);
		SDL_Delay(p);
		p -= 5;
	}
}

void TrueTypeFont::closeFont()
{
	SDL_FreeSurface(result);
	result = NULL;

	TTF_CloseFont(gFont);
	gFont = NULL;

	TTF_CloseFont(statisticFont);
	statisticFont = NULL;

	TTF_Quit();
}
