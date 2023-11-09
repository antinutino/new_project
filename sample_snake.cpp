#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<SDL2/SDL.h>
using namespace std;
int foodX;
int foodY;
int dir=1;
int score=0;
vector<pair<int,int>>v;
 SDL_Window* window=SDL_CreateWindow("Moving Circle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
   
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
void snakefood() {
  cout<<"score:"<<score++<<endl;
    foodX = rand() % (800 /10 ) * 10;
    foodY = rand() % (600 / 10) * 10;
}
void DrawRect(int x, int y) {
    SDL_Rect rect = { x, y, 10, 10 };
    SDL_RenderFillRect(renderer, &rect);
}

int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        cout<<"SDL_Init Error"<<endl;
        return 1;
    }
    int recx=100;
    int recy=100;
int radius=7;
int rad; snakefood();
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
     else if (event.type == SDL_KEYDOWN) 
                {switch (event.key.keysym.sym) 
                    {case SDLK_UP:
                          { if(dir==3)
                          continue;
                          else
                            {dir=4;
                          break;}}
                    case SDLK_DOWN:
                        { if(dir==4)
                        continue;
                        else
                        {dir=3;
                        break;}
                        }
                    case SDLK_LEFT:
                     { if(dir==1)
                     continue;
                     else
                        {dir=2;
                     break;}}
                    case SDLK_RIGHT:
                    { if(dir==2)
                    continue;
                    else
                        {dir=1;break;}}

    } }
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
     SDL_RenderClear(renderer);
     SDL_SetRenderDrawColor(renderer,10,100,200,255);
     if(score%10==0)
     rad=radius+10;
     else
    rad=radius;

    while(rad--)
    for(int angle=0;angle<360;angle++)
    {
        int x=foodX+rad*cos(angle*M_PI/180);
         int y=foodY+rad*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}

   if(((foodX-recx)<=17&&(foodX-recx)>0)&&((recy-foodY)>0&&(recy-foodY)<=7))
   { snakefood();

   }
  else if(((foodX-recx)<=17&&(foodX-recx)>0)&&((foodY-recy)>0&&(foodY-recy)<=17))
   { snakefood();
   }
  else if(((recx-foodX)<=7&&(recx-foodX)>0)&&((foodY-recy)>0&&(foodY-recy)<=7))
   { snakefood();
   }
   else if(((foodX-recx)<=7&&(foodX-recx)>0)&&((foodY-recy)>0&&(foodY-recy)<=17))
   { snakefood();
   }
    if(dir==2)
    {if(recx<=0)
    recx=800;
    else
    recx-=1;
        DrawRect(recx,recy);
        }

       else if(dir==1)
    {if(recx>=800)
    recx=10;
    else
    recx+=1;
        DrawRect(recx,recy);}
       else if(dir==3)
    {if(recy>=600)
    recy=10;
    else
    recy+=1;
        DrawRect(recx,recy);}
     else if(dir==4)
    {if(recy<=0)
    recy=600;
    else
    recy-=1;
    DrawRect(recx,recy);

    }
          SDL_RenderPresent(renderer);
          SDL_Delay(5);

}
 
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;


}