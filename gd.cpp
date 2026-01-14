#include <iostream>
#include <windows.h>

class display50x50{
  private:
    COLORREF[50*50] displayStorage;
  public:
    bool setXY(int x,int y,char z){
      if(x<50&&x>-1&&y<50&&y>-1){
        displayStorage[y*50+x];
        return true;
      }
      return false;
    }
    char getXY(int x,int y){
      if(x<50&&x>-1&&y<50&&y>-1){
        return displayStorage[y*50+x];
      }
    }
    void print(){
      int rectSize=10;
      for(int y=0;y<500;y+=10){
        for(int x=0;x<500;x+=10){
          HBRUSH brush=CreateSolidBrush(getXY(x/10,y/10));
          SelectObject(hdc, brush);
          Rectangle(hdc,x,y,x+rectSize,y+rectSize);
        }
      }
    }
};

class charachter{
  private:
    int y;
    int x;
    int up;
  public:
    
};

int main(){
}
