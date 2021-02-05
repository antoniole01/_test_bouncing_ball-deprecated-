#include <iostream>

#include <sdl.h>
#include <sdl_ttf.h>

#include "c:\z\_MI\Window.h"
#include "c:\z\_MI\defines.h"
#include "c:\z\_MI\drawshapes.h"
#include "c:\z\_MI\colors.h"

#undef main

SDL_Renderer*  renderer;
SDL_Window*    window;
SDL_Event      e;

SDL_Texture*	solidTexture;
SDL_Texture*	text;
SDL_Rect			solidRect;
TTF_Font*		gFont;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

float FPS =    1000/33.3f;

bool running = true;

void input()
{
   if(POLLEVENT)
   {
      if(QUIT){exit(0);}
      if(UPPRESS)
      {
         if(ESCAPE){exit(0);}
      }
   }
}

void balldraw(int ballx,int bally,int ballw,int ballh)
{
	drawFillRect(ballx, bally,ballw,ballh,CYAN);
}

void ballcollision(int ballx, int bally, int ballw, int ballh, int &dx, int &dy)
{
	if(ballx < 0 || ballx > SCREEN_WIDTH - ballw)
	{
		dx = -dx;
	}
	if(bally < 0 || bally > SCREEN_HEIGHT - ballh)
	{
		dy = -dy;
	}
}

void ballupdate(int &ballx, int &bally, int dx, int dy)
{
	ballx += dx;
   bally -= dy;
}

void ballinit()
{
	static int ballx = SCREEN_WIDTH  / 2;
	static int bally = SCREEN_HEIGHT - 30;

	int scale = 20;
	int ballw = scale;
	int ballh = scale;

	int speed = 15;
	static int dx = speed;
	static int dy = speed;
	
	balldraw     ( ballx, bally, ballw, ballh         );
	ballcollision( ballx, bally, ballw, ballh, dx, dy );
	ballupdate   ( ballx, bally, dx, dy               );
}

void ball_original()
{
	static int ballx = SCREEN_WIDTH  / 2;
	static int bally = SCREEN_HEIGHT - 30;

	int scale = 20;
	int ballw = scale;
	int ballh = scale;

	int speed = 15;
	static int dx = speed;
	static int dy = speed;

	if(ballx < 0 || ballx > SCREEN_WIDTH - ballw)
	{
		dx = -dx;
	}
	if(bally < 0 || bally > SCREEN_HEIGHT - ballh)
	{
		dy = -dy;
	}

	ballx += dx;
	bally -= dy;	
	
	drawFillRect(ballx, bally,ballw,ballh,CYAN);
}

void draw()
{
	SDL_SetRenderDrawColor(renderer,PURPLE);
	SDL_RenderClear(renderer);

	ballinit();
	//ball_original();
	
	
	SDL_RenderPresent(renderer);
}

int main()
{
	init_Window(200,200,SCREEN_WIDTH,SCREEN_HEIGHT,0,1);
	
	while(running)
	{
		input();
		draw();
		
		SDL_Delay(1000/33);
	}
		
	return(0);
}
