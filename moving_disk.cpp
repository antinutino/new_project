#include<iostream>
#include<math.h>
#include<SDL2/SDL.h>
using namespace std;
int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        cout<<"SDL_Init Error"<<endl;
        return 1;
    }
    SDL_Window* window=SDL_CreateWindow("Moving Circle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
    if(window==nullptr)
    {
        cout<<"SDL_CreateWindow Error"<<endl;
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer==nullptr)
    {
        cout<<"SDL_CreateRenderer Error"<<endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;

    }
    int circleX=0;
    int circleY=300;
int radius=50;
int rad;
bool quit=false;
while(quit!=true)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
{
    quit=true;
}

    }   SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    rad=radius;
    while(rad--)
    for(int angle=0;angle<360;angle++)
    {
        int x=circleX+rad*cos(angle*M_PI/180);
         int y=circleY+rad*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}
        SDL_RenderPresent(renderer);
    SDL_Delay(10);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    circleX+=3;
 if(circleX>850)
    circleX=0;

}

 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;


}