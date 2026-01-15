#include <iostream>
#include <windows.h>

class display50x50{
  private:
    COLORREF displayStorage[50*50];
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
  void print(HDC hdc, HWND hwnd) {
        int rectSize = 10;
        PAINTSTRUCT ps;
        BeginPaint(hwnd, &ps);
        for (int y = 0; y < 50; ++y) { // Adjusted loop limit to 50
            for (int x = 0; x < 50; ++x) {
                HBRUSH brush = CreateSolidBrush(getXY(x, y));
                SelectObject(hdc, brush);
                Rectangle(hdc, x * rectSize, y * rectSize, (x + 1) * rectSize, (y + 1) * rectSize);
                DeleteObject(brush);
           }
      }
    EndPaint(hwnd, &ps);
  }
  void whitewash(){
    for (int i=0;i<50*50;i++){
      displayStorage[i]=RGB(50,50,50);
    }
  }
};

class charachter{
  private:
    int y;
    int x;
    int up;
  public:
    void refresh(HDC hdc, HWND hwnd,display50x50 display){
      display.print(hdc,hwnd);

    }
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE LPSTR,int nShowCmd){
  
  return 0;
}
