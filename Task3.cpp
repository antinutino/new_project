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
int circlex=50;int circley=50;
while(quit!=true)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
{
    quit=true;
}
           else if (event.type == SDL_KEYDOWN) 
                {switch (event.key.keysym.sym) 
                    {case SDLK_UP:
                        {if(circley>=60)
                        {circley-=10;
                        break;}
                        else
                        break;
                        }
                    case SDLK_DOWN:
                        { if(circley<=540)
                            {circley +=10;
                        break;}
                        else
                        break;
                        }
                    case SDLK_LEFT:
                      {if(circlex>=60)
                        {circlex-=10;
                        break;}
                        else
                        break;}
                    case SDLK_RIGHT:
                    {if(circlex<=740)
                         {circlex+=10;
                        break;}
                        else
                        break;}

    } }
    }
   int a=circlex,b=circley,c=circleX,d=circleY;
   int p=(a-c)*(a-c);
   int q=(b-d)*(b-d);
   if(p+q<=100*100)
   { cout<<"GAME IS OVER"<<endl;
     SDL_SetRenderDrawColor(renderer,100,0,200,255);
    SDL_RenderClear(renderer);
     SDL_RenderPresent(renderer); 
    SDL_Delay(1000);
    quit=true;
    continue;
   }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
     SDL_RenderClear(renderer);
     SDL_SetRenderDrawColor(renderer,10,100,200,255);
    rad=radius;
    while(rad--)
    for(int angle=0;angle<360;angle++)
    {
        int x=circlex+rad*cos(angle*M_PI/180);
         int y=circley+rad*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}
         rad=radius;
        while(rad--)
    for(int angle=0;angle<360;angle++)
    {
        int x=circleX+rad*cos(angle*M_PI/180);
         int y=circleY+rad*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}
          SDL_RenderPresent(renderer);
          SDL_Delay(1);
    circleX+=3;
 if(circleX>850)
    circleX=0;
  rad=radius;

}

 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;


}