#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Timer.h"
#include "Button.h"
#include "TileButton.h"
#include "Board.h"
#include "Animation.h"

const int NUMBER_OF_TILE = 15;
const int NUMBER_OF_BUTTON = 4;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BET = 10;
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
Texture gSceneTexture;
Button gButton[NUMBER_OF_BUTTON];
Timer gTimer;
TTF_Font* gFont = NULL;
Texture gHelpFirst;
Texture gHelpSecond;
bool lockButtons = false;
Texture* gPtrHelp = NULL;
Texture gGameOver;
Texture gYouWin;
Texture gYouLose;
Texture wordTime;
Texture wordMoves;
Texture wordMatches;
Texture wordAllGame;
Texture wordWinGame;
Texture wordLoseGame;
Texture wordWinRateGame;
Texture wordCredits;
Board board;
TileButton gTile[NUMBER_OF_TILE * 4];
std::map<int, int> tileMap;
std::vector<Tile> checkPair;
int coordI = 0;
int coordJ = 0;
bool choice = false;
tileCoord tempCoord;
std::vector<tileCoord> pairXY;
int gMoves = 0;
int gCredits = 100;
int gMatches = 0;
Mix_Music* gMusic = NULL;
Mix_Chunk *gThunder = NULL;
Mix_Chunk *gBombExploding = NULL;
Mix_Chunk *gExplosion = NULL;
Mix_Chunk *gLow = NULL;
bool chunk = false;
pairCoord lastPair;
std::stack<pairCoord> backSpace;
std::stack<Tile> returnPair;
bool gameOver = false;
bool youWin = false;
bool youLose = false;
int allGames;
int winGames;
Animation firstAnimation_1;
Animation secondAnimation_1;
Animation firstAnimation_2;
Animation secondAnimation_2;
Animation firstAnimation_3;
Animation secondAnimation_3;
Animation winAnimation;
Texture markTile;
int mark = 0;

bool init();
bool loadMedia();
void close();
void logicButtons(bool temp[]);
void startStopTimer();
void startStopSound();
void showHelp();
void drowGame(Board board);
int takeID(faceType);
void startStopGame();
void eraseTileMap();
faceType returnFace(int number);
void logicBoard();
void takePair();
bool endOfTheGame();
int availableMatches();
void unblockedBoard();
void generateTime();
void generateMoves();
void generateMatches();
void generateInfo();
void generateCredits();
void saveStatsFile(int, int);
void loadStatsFile();
void undo();
void bet();
void award(int multiply);
int calculate();
int calculateAward(int multiply);
bool theGameIsOver();
void saveGame(Board saveBoard);
void loadGame(Board &tempBoard);
faceType returnFaceType(int temp);
void musicVolumeControl();
void setToDefault();
void markSelectedTile();

int main(int argc, char* args[]) {

    bool temp[NUMBER_OF_BUTTON] = { false };
    bool quit = false;
    SDL_Event e;

    if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {
            loadStatsFile();

            musicVolumeControl();

			while (!quit) {
				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
					if(e.type == SDL_KEYDOWN)
					{
					    if(e.key.keysym.sym == SDLK_BACKSPACE)
                        {
                            if(board.isStarted() && !endOfTheGame())
                            {
                                undo();
                            }
                        }
					}
					for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
                        if(lockButtons)
                        {
                            temp[2] = gButton[2].handleEvent(e);
                            temp[3] = gButton[3].handleEvent(e);
                        }
                        else
                        {
                            temp[i] = gButton[i].handleEvent(e);
                        }
					}
					for (int i = 0; i < NUMBER_OF_TILE * 4; i++) {
						choice = gTile[i].handleEvent(e, coordI, coordJ);
						if (choice == true) {
                            mark++;
							if (!board.pile[coordI][coordJ].empty()) {
                                takePair();
								break;
							} else {
								choice = false;
							}
						}
					}

                }

				logicButtons(temp);
				logicBoard();

                drowGame(board);
			}
		}
	}
	close();
	return 0;
}

bool init() {
	bool success = true;
	if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		gWindow = SDL_CreateWindow( "Mahjong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true;
    if (!markTile.loadFromFile("images/mark.png")) {
        printf("Failed to load mark texture!\n");
        success = false;
    }
    if (!winAnimation.loadAnimationFromFile("images/firework_")) {
        printf("Failed to load animation texture!\n");
        success = false;
    }
    if (!firstAnimation_1.loadAnimationFromFile("images/explosprite_")) {
        printf("Failed to load animation texture!\n");
        success = false;
    }
    if (!secondAnimation_1.loadAnimationFromFile("images/explosprite_")) {
        printf("Failed to load animation texture!\n");
        success = false;
    }
    if (!firstAnimation_2.loadAnimationFromFile("images/explosion_")) {
        printf("Failed to load animation texture!\n");
        success = false;
    }
    if (!secondAnimation_2.loadAnimationFromFile("images/explosion_")) {
        printf("Failed to load animation texture!\n");
        success = false;
    }
        if (!firstAnimation_3.loadAnimationFromFile("images/lightning_")) {
        printf("Failed to load animation texture!\n");
        success = false;
    }
    if (!secondAnimation_3.loadAnimationFromFile("images/lightning_")) {
        printf("Failed to load animation texture!\n");
        success = false;
    }

	if (!gSceneTexture.loadFromFile("images/window.png")) {
		printf("Failed to load window texture!\n");
		success = false;
	}
	if (!gGameOver.loadFromFile("images/game_over.png")) {
		printf("Failed to load Game over texture!\n");
		success = false;
	}
    if (!gYouWin.loadFromFile("images/you_win.png")) {
		printf("Failed to load You win texture!\n");
		success = false;
	}
    if (!gYouLose.loadFromFile("images/you_lose.png")) {
		printf("Failed to load You lose texture!\n");
		success = false;
	}
	gFont = TTF_OpenFont("text/MAGNETOB.ttf", 18);
	if (gFont == NULL) {
		printf("Failed to load MAGNETOB font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	if (!gHelpFirst.loadFromFile("images/help_0.png")) {
		printf("Unable to render help texture!\n");
	}
	if (!gHelpSecond.loadFromFile("images/help_1.png")) {
		printf("Unable to render help texture!\n");
	}
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		std::stringstream path;
		path.str("");
		path << "images/button_" << i << ".png";
		if (!gButton[i].loadFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << ".png";
		if (!gButton[i].loadBaseFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_up.png";
		if (!gButton[i].loadMotionFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_down.png";
		if (!gButton[i].loadDownFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/button_" << i << "_up.png";
		if (!gButton[i].loadUpFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
	}
	for (int i = 0; i < NUMBER_OF_TILE * 4; ++i) {
		std::stringstream path;
		path.str("");
		path << "images/tile_" << i / 4 << ".png";
		if (!gTile[i].loadFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << ".png";
		if (!gTile[i].loadBaseFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_up.png";
		if (!gTile[i].loadMotionFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_down.png";
		if (!gTile[i].loadDownFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
		path.str("");
		path << "images/tile_" << i / 4 << "_up.png";
		if (!gTile[i].loadUpFromFile(path.str().c_str())) {
			printf("Failed to load image texture!\n");
			success = false;
		}
	}
	gMusic = Mix_LoadMUS( "sounds/background.mp3" );
	if( gMusic == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
    gThunder = Mix_LoadWAV( "sounds/thunder.wav" );
	if( gThunder == NULL )
	{
		printf( "Failed to load thunder sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
	}
    gBombExploding = Mix_LoadWAV( "sounds/bombExploding.wav" );
	if( gBombExploding == NULL )
	{
		printf( "Failed to load bombExploding sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
	}
    gExplosion = Mix_LoadWAV( "sounds/explosion.wav" );
	if( gExplosion == NULL )
	{
		printf( "Failed to load explosion sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
	}
    gLow = Mix_LoadWAV( "sounds/low.wav" );
	if( gLow == NULL )
	{
		printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
	}
	return success;
}

void close() {
    markTile.free();
    winAnimation.freeAnimation();
    firstAnimation_1.freeAnimation();
    secondAnimation_1.freeAnimation();
    firstAnimation_2.freeAnimation();
    secondAnimation_2.freeAnimation();
    firstAnimation_3.freeAnimation();
    secondAnimation_3.freeAnimation();

	gSceneTexture.free();
	gGameOver.free();
	gYouWin.free();
	gYouLose.free();
	gHelpFirst.free();
	gHelpSecond.free();
	gPtrHelp = NULL;
	board.freeBoard();
	tileMap.clear();
	checkPair.clear();
	pairXY.clear();

	for (int i = 0; i < NUMBER_OF_TILE * 4; ++i) {
		gTile[i].freeButton();
	}
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		gButton[i].freeButton();
	}
	TTF_CloseFont(gFont);
	gFont = NULL;
    Mix_FreeMusic( gMusic );
	gMusic = NULL;
	Mix_FreeChunk( gThunder);
	gThunder = NULL;
    Mix_FreeChunk( gBombExploding);
	gBombExploding = NULL;
    Mix_FreeChunk( gExplosion);
	gExplosion = NULL;
    Mix_FreeChunk( gLow);
	gLow = NULL;

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void logicButtons(bool temp[]) {
	for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
		if (temp[i] == true) {
			switch (i) {
			case 0:
			    if(!lockButtons)
                {
                    startStopGame();
                }
				temp[i] = false;
				break;
			case 1:
			    if(!lockButtons)
                {
                    setToDefault();
                    loadGame(board);
                    if(availableMatches() == 0)
                    {
                        startStopGame();
                    }
                }
				temp[i] = false;
				break;
			case 2:
				showHelp();
				temp[i] = false;
				break;
			case 3:
				startStopSound();
				temp[i] = false;
				break;
			}
		}
	}
}

void startStopTimer() {
	if (gTimer.isStarted()) {
		gTimer.stop();
	} else {
		gTimer.start();
	}
}

void startStopSound()
{
    if( Mix_PlayingMusic() == 0 )
    {
        Mix_PlayMusic( gMusic, -1 );
        chunk = true;
    }
    else
    {
        if( Mix_PausedMusic() == 1 )
        {
            Mix_ResumeMusic();
            chunk = true;
        }
        else
        {
            Mix_PauseMusic();
            chunk = false;
        }
    }
}

void showHelp() {
    lockButtons = true;
	if (gPtrHelp == NULL) {
		gPtrHelp = &gHelpFirst;
	} else if(gPtrHelp == &gHelpFirst){
		gPtrHelp = &gHelpSecond;
	} else {
	    lockButtons = false;
	    gPtrHelp = NULL;
	}
}

void startStopGame() {
	if (board.isStarted()) {
		board.stop();
		startStopTimer();
		setToDefault();
    }
    else {
        if(!theGameIsOver())
        {
            board.start();
            startStopTimer();
            bet();
            setToDefault();
        }
        else
        {
            gameOver = true;
        }
	}
}

void drowGame(Board board) {
	int x = 200;
	int y = 100;
	int moveY = 0;
	int temp = 0;

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    gSceneTexture.render(0, 0);

    if (gPtrHelp == NULL)
    {

        for (int i = 0; i < NUMBER_OF_BUTTON; ++i) {
            if(i == 3)
            {
                gButton[i].setPosition(760, 5);
            }
            else
            {
                gButton[i].setPosition(650, 50 + 40 * i);
            }
            gButton[i].renderButton();
        }

        if (board.isStarted())
        {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (!board.pile[i][j].empty()) {
                        temp = takeID(board.pile[i][j].top().getFace());
                        gTile[temp].setFace(board.pile[i][j].top().getFace());
                        gTile[temp].setBlocked(!board.pile[i][j].top().getBlocked());
                        gTile[temp].coordinates.i = i;
                        gTile[temp].coordinates.j = j;
                        moveY = 0;
                        for (size_t z = 0; z < board.pile[i][j].size(); z++){
                            gTile[temp].setPosition(x, y + moveY);
                            gTile[temp].renderButton();
                            moveY -= 3;
                        }
                    }
                    x += gTile[temp].getWidth();
                }
                y += (gTile[temp].getHeight()+4);
                x = 200;
            }
        }
        if(gameOver)
        {
            gGameOver.render((SCREEN_WIDTH - gGameOver.getWidth())/2, (SCREEN_HEIGHT - gGameOver.getHeight())/2);
        }
        if(youWin)
        {
            gYouWin.render((SCREEN_WIDTH - gGameOver.getWidth())/2, (SCREEN_HEIGHT - gGameOver.getHeight())/2);
        }
        if(youLose)
        {
            gYouLose.render((SCREEN_WIDTH - gGameOver.getWidth())/2, (SCREEN_HEIGHT - gGameOver.getHeight())/2);
        }
    }
    else
    {
        gPtrHelp->render(25, 50);
        gButton[2].setPosition(25 + gPtrHelp->getWidth() / 2 - gButton[2].getWidth() / 2, gPtrHelp->getHeight());
        gButton[2].renderButton();
        gButton[3].setPosition(760, 5);
        gButton[3].renderButton();
    }

    markSelectedTile();

    generateTime();
    wordTime.render(20, 550);

    generateMoves();
    wordMoves.render(20, 530);

    generateMatches();
    wordMatches.render(20, 510);

    generateCredits();
    wordCredits.render(630, 470);

    generateInfo();
    wordAllGame.render(630, 490);
    wordWinGame.render(630, 510);
    wordLoseGame.render(630, 530);
    wordWinRateGame.render(630, 550);

    firstAnimation_1.renderAnimation();
    secondAnimation_1.renderAnimation();
    firstAnimation_2.renderAnimation();
    secondAnimation_2.renderAnimation();
    firstAnimation_3.renderAnimation();
    secondAnimation_3.renderAnimation();
    winAnimation.renderAnimation();

    SDL_RenderPresent(gRenderer);
}

int takeID(faceType type) {
	for (int i = FIRST; i < NONE; ++i) {
		if (i == type) {
			int temp = tileMap[i];
			if (temp < 4) {
				tileMap[i] = temp + 1;
				return i * 4 + temp;
			} else {
				tileMap[i] = 0;
				return i * 4;
			}
		}
	}
	return 0;
}

void eraseTileMap() {
    for(int i = 0; i < NUMBER_OF_TILE * 4; ++i)
    {
        gTile[i].setPosition(0, 0);
    }
	for (int i = FIRST; i < NONE; ++i) {
		tileMap[i] = 0;
	}
}

void logicBoard() {
	eraseTileMap();
    unblockedBoard();

	if(endOfTheGame() && board.isStarted())
    {
        youWin = true;
        winGames++;
        allGames++;
        award(calculateAward(calculate()));
        saveStatsFile(allGames, winGames);
        board.stop();
        gTimer.stop();
        winAnimation.startAnimation(50, 50);
    }
    if(availableMatches() == 0 && board.isStarted())
    {
        youLose = true;
        allGames++;
        saveStatsFile(allGames, winGames);
        board.stop();
        gTimer.stop();
    }
}

void takePair()
{
    if(pairXY.size() == 0)
    {
        tempCoord.x = coordI;
        tempCoord.y = coordJ;
        pairXY.push_back(tempCoord);
        checkPair.push_back(board.pile[coordI][coordJ].top());
    }
    else if(pairXY.size() == 1)
    {
        if(pairXY.back().x == coordI && pairXY.back().y == coordJ)
        {
            pairXY.clear();
            checkPair.clear();
        }
        else
        {
            tempCoord.x = coordI;
            tempCoord.y = coordJ;
            pairXY.push_back(tempCoord);
            checkPair.push_back(board.pile[coordI][coordJ].top());
        }

    }
    if(checkPair.size()==2)
    {
        if(checkPair[0].getFace() == checkPair[1].getFace() && !board.pile[pairXY[0].x][pairXY[0].y].top().getBlocked() && !board.pile[pairXY[1].x][pairXY[1].y].top().getBlocked() )
        {
            gMoves++;
            backSpace.push(lastPair);
            backSpace.top().first.x = pairXY[0].x;
            backSpace.top().first.y = pairXY[0].y;
            backSpace.top().second.x = pairXY[1].x;
            backSpace.top().second.y = pairXY[1].y;
            returnPair.push( board.pile[pairXY[0].x][pairXY[0].y].top());
            returnPair.push( board.pile[pairXY[1].x][pairXY[1].y].top());
            board.pile[pairXY[0].x][pairXY[0].y].pop();
            board.pile[pairXY[1].x][pairXY[1].y].pop();
            pairXY.clear();
            checkPair.clear();
            if(returnPair.top().getFace() < SIXTH)
            {
                firstAnimation_1.startAnimation(200 + pairXY[0].y * firstAnimation_1.getWidth(), 100 + pairXY[0].x * firstAnimation_1.getHeight());
                secondAnimation_1.startAnimation(200 + pairXY[1].y * secondAnimation_1.getWidth(), 100 + pairXY[1].x * secondAnimation_1.getHeight());
                if(chunk)
                {
                    Mix_PlayChannel( -1, gExplosion, 0 );
                }
            }
            else if(returnPair.top().getFace() < EVELENTH)
            {
                firstAnimation_2.startAnimation(200 + pairXY[0].y * firstAnimation_2.getWidth(), 100 + pairXY[0].x * firstAnimation_2.getHeight());
                secondAnimation_2.startAnimation(200 + pairXY[1].y * secondAnimation_2.getWidth(), 100 + pairXY[1].x * secondAnimation_2.getHeight());
                if(chunk)
                {
                    Mix_PlayChannel( -1, gBombExploding, 0 );
                }
            }
            else if(returnPair.top().getFace() < NONE)
            {
                firstAnimation_3.startAnimation(200 + pairXY[0].y * firstAnimation_3.getWidth(), 100 + pairXY[0].x * firstAnimation_3.getHeight());
                secondAnimation_3.startAnimation(200 + pairXY[1].y * secondAnimation_3.getWidth(), 100 + pairXY[1].x * secondAnimation_3.getHeight());
                if(chunk)
                {
                    Mix_PlayChannel( -1, gThunder, 0 );
                }
            }
            saveGame(board);
        }
        else
        {
            pairXY.clear();
            checkPair.clear();
        }
    }
}

bool endOfTheGame()
{
    bool endGame = true;
    for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			if(!board.pile[i][j].empty())
            {
                endGame = false;
                break;
            }
		}
	}
	return endGame;
}

int availableMatches()
{
    int result = 0;
    std::multiset<faceType> temp;
    unblockedBoard();

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (!board.pile[i][j].empty() && !board.pile[i][j].top().getBlocked())
            {
                temp.insert(board.pile[i][j].top().getFace());
            }
        }
    }

    for(size_t i = FIRST; i < NONE; ++i)
    {
        faceType face = static_cast<faceType> (i);
        result += temp.count(face)/2;
    }
    return result;
}

void unblockedBoard()
{
    for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			board.unblock(i, j);
		}
	}
}

void generateTime()
{
    std::stringstream text;
    SDL_Color textColor = { 255, 255, 255, 255 };
    text.str("");
    text << "Time: " << std::fixed << std::setprecision(0)
            << gTimer.getTicks() / 1000.f;
    if (!wordTime.loadFromRenderedText(text.str().c_str(),
            textColor)) {
        printf("Unable to render time texture!\n");
    }
}

void generateMoves()
{
    std::stringstream text;
    SDL_Color textColor = { 255, 255, 255, 255 };
    text.str("");
    text << "Moves: " << gMoves;
    if (!wordMoves.loadFromRenderedText(text.str().c_str(),
            textColor)) {
        printf("Unable to render time texture!\n");
    }
}

void generateMatches()
{
    std::stringstream text;
    SDL_Color textColor = { 255, 255, 255, 255 };
    text.str("");
    gMatches = availableMatches();
    text << "Available matches: " << gMatches;
    if (!wordMatches.loadFromRenderedText(text.str().c_str(),
            textColor)) {
        printf("Unable to render time texture!\n");
    }
}

void generateCredits()
{
    std::stringstream text;
    SDL_Color textColor = { 255, 255, 255, 255 };
    text.str("");
    text << "Credits: " << gCredits;
    if (!wordCredits.loadFromRenderedText(text.str().c_str(),
            textColor)) {
        printf("Unable to render time texture!\n");
    }
}

void generateInfo()
{
    std::stringstream text;
    SDL_Color textColor = { 255, 255, 255, 255 };
    text.str("");
    text << "All games: " << allGames;
    if (!wordAllGame.loadFromRenderedText(text.str().c_str(), textColor)) {
        printf("Unable to render time texture!\n");
    }
    text.str("");
    text << "Win games: " << winGames;
    if (!wordWinGame.loadFromRenderedText(text.str().c_str(), textColor)) {
        printf("Unable to render time texture!\n");
    }
    text.str("");
    text << "Lose game: " << allGames - winGames;
    if (!wordLoseGame.loadFromRenderedText(text.str().c_str(), textColor)) {
        printf("Unable to render time texture!\n");
    }
    text.str("");
    text << std::fixed << std::setprecision(1) << "Win rate: " << ((double)winGames / (double)allGames*100.0) << "%";
    if (!wordWinRateGame.loadFromRenderedText(text.str().c_str(), textColor)) {
        printf("Unable to render time texture!\n");
    }
}

void undo()
{
    if(!returnPair.empty())
    {
        board.pile[backSpace.top().first.x][backSpace.top().first.y].push(returnPair.top());
        board.block(backSpace.top().first.x, backSpace.top().first.y);
        returnPair.pop();
        board.pile[backSpace.top().second.x][backSpace.top().second.y].push(returnPair.top());
        board.block(backSpace.top().second.x, backSpace.top().second.y);
        returnPair.pop();
        backSpace.pop();
        saveGame(board);
    }
}

void bet()
{
    gCredits -= BET;
}

void award(int multiply)
{
    gCredits += (multiply * BET);
}

bool theGameIsOver()
{
    return ((gCredits - BET) < 0);
}

int calculate()
{
    if(gMoves == 30)
    {
        return 2;
    }
    else if(gMoves < 40)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int calculateAward(int multiply)
{
    int time = gTimer.getTicks() / 1000.f;
    if(time < 60)
    {
        return multiply + 3;
    }
    else if(time < 90)
    {
        return multiply + 2;
    }
    else if(time < 120)
    {
        return multiply + 1;
    }
    return multiply;
}

void saveGame(Board saveBoard){
    std::vector<int> temp;
    unsigned sizeOfStack;
    int element;
    Uint32 time = gTimer.getTicks() / 1000.f;
    std::ofstream file ("files/recovery.dat", std::ios::out | std::ios::binary);

    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(&gMoves),sizeof(int));
        file.write(reinterpret_cast<const char*>(&gCredits),sizeof(int));
        file.write(reinterpret_cast<const char*>(&time),sizeof(Uint32));
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                temp.clear();
                sizeOfStack = saveBoard.pile[i][j].size();
                file.write(reinterpret_cast<const char*>(&sizeOfStack),sizeof(unsigned));
                while(!saveBoard.pile[i][j].empty())
                {
                    element = saveBoard.pile[i][j].top().getFace();
                    temp.push_back(element);
                    saveBoard.pile[i][j].pop();
                }
                while(!temp.empty())
                {
                    element = temp.back();
                    file.write(reinterpret_cast<char*>(&element),sizeof(int));
                    temp.pop_back();
                }
            }
        }
        file.close();
    }
    else
    {
        printf("recovery.dat can't be open for write!");
    }
}

void loadGame(Board &tempBoard){
    Tile tempTile;
    int temp;
    unsigned sizeOfStack;
    Uint32 time;

    std::ifstream file;
    file.open("files/recovery.dat", std::ios::in | std::ios::binary);

    tempBoard.freeBoard();

    if(file.is_open()){
        file.read(reinterpret_cast<char*>(&gMoves),sizeof(int));
        file.read(reinterpret_cast<char*>(&gCredits),sizeof(int));
        file.read(reinterpret_cast<char*>(&time),sizeof(Uint32));
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 6; ++j)
            {
                file.read(reinterpret_cast<char*>(&sizeOfStack),sizeof(unsigned));
                while(tempBoard.pile[i][j].size() < sizeOfStack)
                {
                    file.read(reinterpret_cast<char*>(&temp),sizeof(int));
                    tempTile.setFace(returnFaceType(temp));
                    tempBoard.pile[i][j].push(tempTile);
                }
            }
        }
        gTimer.loadTime(time);
        tempBoard.startGame = true;
        file.close();
    }else{
        printf("recovery.dat can't be open for read");
    }
}

faceType returnFaceType(int temp)
{
    for(int i = FIRST; i < NONE; ++i)
    {
        if(i == temp)
        {
            faceType face = static_cast<faceType> (i);
            return face;
        }
    }
    return NONE;
}

void saveStatsFile(int all, int win){
    std::ofstream file ("files/statsFile.bin", std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(&all),sizeof(int));
        file.write(reinterpret_cast<const char*>(&win),sizeof(int));
        file.close();
    }
    else
    {
        printf("statsFile.bin can't be open!");
    }
}

void loadStatsFile(){
    std::ifstream file;
    file.open("files/statsFile.bin");
    if(file.is_open()){
        file.read(reinterpret_cast<char*>(&allGames),sizeof(int));
        file.read(reinterpret_cast<char*>(&winGames),sizeof(int));
        file.close();
    }else{
        printf("statsFile.bin can't be open!");
    }
}

void musicVolumeControl()
{
    Mix_VolumeChunk(gLow, 50);
    Mix_VolumeChunk(gExplosion, 10);
    Mix_VolumeChunk(gBombExploding, 50);
    Mix_VolumeChunk(gThunder, 80);
    Mix_VolumeMusic(30);
}

void setToDefault()
{
    mark = 0;
    youWin = false;
    youLose = false;
    gMoves = 0;
    while(!returnPair.empty())
    {
        returnPair.pop();
    }
    while(!backSpace.empty())
    {
        backSpace.pop();
    }
    pairXY.clear();
    checkPair.clear();
}

void markSelectedTile()
{
    if (board.pile[coordI][coordJ].size() == 3)
    {

        if(mark<2)
        {
            if(mark==1)
            {
                markTile.render(200 + coordJ * markTile.getWidth(), 100 + coordI * (markTile.getHeight() + 4) - 6);
            }
        }
        else
        {
            mark = 0;
        }
    }
    else if (board.pile[coordI][coordJ].size() == 2)
    {

        if(mark<2)
        {
            if(mark==1)
            {
                markTile.render(200 + coordJ * markTile.getWidth(), 100 + coordI * (markTile.getHeight() + 4) - 3);
            }
        }
        else
        {
            mark = 0;
        }
    }
    else
    {

        if(mark<2)
        {
            if(mark==1)
            {
                markTile.render(200 + coordJ * markTile.getWidth(), 100 + coordI * (markTile.getHeight() + 4));
            }
        }
        else
        {
            mark = 0;
        }
    }
}
