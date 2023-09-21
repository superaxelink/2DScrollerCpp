#include "background.h"

Background::Background(GameScreen& gameScreen) : gameScreen(gameScreen){

  background1 = NULL;
  background2 = NULL;
  background3 = NULL;
  background4 = NULL;
  background5 = NULL;
  width = 0;
  height = 0;
  //Load media
}

//bool Background::loadMedia(SDL_Renderer* &gRenderer){
bool Background::loadMedia(){

  //Loading success flag;
  bool success = true;
  //Load splash image
  background1 = utils.loadTexture("../../res/background/layerCity1.png", gameScreen.gRenderer, width, height);
  background2 = utils.loadTexture("../../res/background/layerCity2.png", gameScreen.gRenderer, width, height);
  background3 = utils.loadTexture("../../res/background/layerCity3.png", gameScreen.gRenderer, width, height);
  background4 = utils.loadTexture("../../res/background/layerCity4.png", gameScreen.gRenderer, width, height);
  background5 = utils.loadTexture("../../res/background/layerCity5.png", gameScreen.gRenderer, width, height);
	if( background5 == NULL ){
	  printf("Failed to load PNG image!\n");
	  success = false;
  }
  return success;
}

void Background::draw(){
	//Set rendering space and render to screen
  utils.render(0, 0, width, height, gameScreen.gRenderer, background1);
  utils.render(0, 0, width, height, gameScreen.gRenderer, background2);
  utils.render(0, 0, width, height, gameScreen.gRenderer, background3);
  utils.render(0, 0, width, height, gameScreen.gRenderer, background4);
  utils.render(0, 0, width, height, gameScreen.gRenderer, background5);
}

void Background::close(){
  SDL_DestroyTexture(background1);
  SDL_DestroyTexture(background2);
  SDL_DestroyTexture(background3);
  SDL_DestroyTexture(background4);
  SDL_DestroyTexture(background5);
  background1 = NULL;
  background2 = NULL;
  background3 = NULL;
  background4 = NULL;
  background5 = NULL;
}

Background::~Background(){}