#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdlib> 
#include <locale>
#include <cmath>
#include "windows.h"


using namespace std;

int main() {
    int width = 120;
    int height = 30;

    char antAnim[] = {'{', '}'};
    char celerColor = '*';
    int antRotation = 0, moveTo = 0;
    

    char screen[width*height+1] {'.'};
    screen[width*height] = '\0';

    

    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            screen[j+i * width] = '*'; 
        }
        
    }
    
    int center = (width*height) / 2 + width/2;

    screen[center] = '{';
    moveTo = center;

    printf_s(screen);
    getchar();
    for(int t = 0; t < 1000000; t++) {
        
        screen[moveTo] = ((celerColor == '*') ? ' ' : '*');
        switch (antRotation)
        {
            case 0:
                moveTo-=width;
                break;
            case 1:
                moveTo+=1;
                break;
            case 2:
                moveTo+=width;
                break;
            case 3:
                moveTo-=1;
                break;    
            default:
                moveTo = 0;
                
        }
        celerColor = screen[moveTo];
        if(celerColor == '*') antRotation++;
        else antRotation--;
        if(antRotation<0) antRotation = 3;
        if(antRotation>3) antRotation = 0;
        antRotation%=4;
        if(moveTo >= width*height) moveTo -= width*height-1;
        if(moveTo < 0) moveTo += width*height-1;
        screen[moveTo] = antAnim[t%2];
        printf_s(screen);
        Sleep(2);

    }
    getchar();

    return 0;
}
