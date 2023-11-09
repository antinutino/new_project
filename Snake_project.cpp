#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<SDL2/SDL.h>
using namespace std;
int foodX;
int foodY;
int dir=1;
int score=0;
 int recx=100;
int recy=100;
vector<pair<int,int>>v;
vector<pair<int,int>>v1;
 SDL_Window* window=SDL_CreateWindow("Moving Circle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
   
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
void snakefood() {
  cout<<"score:"<<score++<<endl;
    foodX = rand() % (790 /10 ) * 10;
    foodY = rand() % (590 / 10) * 10;
    if(dir==1)
    {
         v.push_back( make_pair(recx+10,recy) );
    }
    else if(dir==2)
    {
         v.push_back( make_pair(recx-10,recy) );
    }
    else if(dir==3)
    {
         v.push_back( make_pair(recx,recy+10) );
    }
    else if(dir==4)
    {
         v.push_back( make_pair(recx,recy-10) );
    }
}
void DrawRect(int x, int y) {
    SDL_Rect rect = { x, y, 10, 10};
    SDL_RenderFillRect(renderer, &rect);
}

int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        cout<<"SDL_Init Error"<<endl;
        return 1;
    }
int radius=10;
int rad; snakefood();
bool quit=false;
 v.push_back( make_pair(recx,recy) );
 v.push_back( make_pair(recx+10,recy) );
 recx+=10;
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
                        {dir=1;
                        break;}}

    } }
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
     SDL_RenderClear(renderer);
     SDL_SetRenderDrawColor(renderer,10,100,200,255);
    rad=radius;

    while(rad--)
    for(int angle=0;angle<360;angle++)
    {
        int x=foodX+rad*cos(angle*M_PI/180);
         int y=foodY+rad*sin(angle*M_PI/180);
         SDL_RenderDrawPoint(renderer,x,y);}

   if(((foodX-recx)<=20&&(foodX-recx)>=0)&&((recy-foodY)>=0&&(recy-foodY)<=10))
   { snakefood();

   }
  else if(((foodX-recx)<=20&&(foodX-recx)>=0)&&((foodY-recy)>=0&&(foodY-recy)<=20))
   { snakefood();
   }
  else if(((recx-foodX)<=10&&(recx-foodX)>=0)&&((foodY-recy)>=0&&(foodY-recy)<=20))
   { snakefood();
   }
   else if(((foodX-recx)<=10&&(foodX-recx)>=0)&&((foodY-recy)>=0&&(foodY-recy)<=20))
   { snakefood();
   }
   if(dir==1)
   { recx+=10;
   if(recx==800)
   recx=10;
   v1=v;
    v[v.size()-1].first=recx;
    v[v.size()-1].second=recy;
    DrawRect(v[v.size()-1].first,v[v.size()-1].second);
    for(int i=v.size()-1;i>0;i--)
    {  
       v[i-1]=v1[i];
        DrawRect(v[i].first,v[i].second);
    }
   }
  else if(dir==2)
   { recx-=10;
   if(recx==0)
   recx=790;
   v1=v;
    v[v.size()-1].first=recx;
    v[v.size()-1].second=recy;
    DrawRect(v[v.size()-1].first,v[v.size()-1].second);
    for(int i=v.size()-1;i>0;i--)
    { v[i-1]=v1[i];
        DrawRect(v[i].first,v[i].second);
    }
   }
   else if(dir==3)
   { recy+=10;
   if(recy==600)
   recy=10;
   v1=v;
    v[v.size()-1].first=recx;
    v[v.size()-1].second=recy;
    DrawRect(v[v.size()-1].first,v[v.size()-1].second);
    for(int i=v.size()-1;i>0;i--)
    { v[i-1]=v1[i];
        DrawRect(v[i].first,v[i].second);
    }
   }
   else if(dir==4)
   { recy-=10;
   if(recy==0)
   recy=590;
   v1=v;
    v[v.size()-1].first=recx;
    v[v.size()-1].second=recy;
    DrawRect(v[v.size()-1].first,v[v.size()-1].second);
    for(int i=v.size()-1;i>0;i--)
    {  v[i-1]=v1[i];
        DrawRect(v[i].first,v[i].second);
    }
    }
          SDL_RenderPresent(renderer);
          if(score<=10)
          SDL_Delay(50);
          else if(score>10&&score<=20)
          SDL_Delay(40);
       else if(score>20&&score<=30)
          SDL_Delay(30);
          else if(score>30&&score<=40)
          SDL_Delay(20);
          else
          SDL_Delay(10);
          
          }
 
 SDL_DestroyRenderer(renderer);
 SDL_DestroyWindow(window);
 SDL_Quit();
 return 0;


}