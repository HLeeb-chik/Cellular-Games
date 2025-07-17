#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib> 
#include "windows.h"

using namespace std;

int main() {
    int width = 120;
    int height = 30;
    int life = 0;
    int putSym;
    bool fileOpen = true;
    string fileFiled = "life.txt";

    char screen[width*height+1] {'.'};
    screen[width*height] = '\0';

    char screen2[width*height+1] {'.'};
    screen2[width*height] = '\0';

    ifstream fileLifeFiled(fileFiled);
    if(!fileLifeFiled) {
        cout << "Error open file";
        fileOpen = false;
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            char cell;
            if(fileLifeFiled >> cell && fileOpen) screen[j+i * width] = cell;
            else screen[j+i * width] = '.';
            
        }
        
    }
    fileLifeFiled.close();
    int center = (width*height) / 2 + width/2;

    
    // screen[center] = '@';
    // screen[center +1 -width] = '@';
    // screen[center +2 -width] = '@';
    // screen[center +2] = '@';
    // screen[center + width +2] = '@';
    // for(int i = 0; i<100;i++){
    //     screen[1600+rand()%500] = '@';
    // }

    printf_s(screen);
    for(int t = 0; t < 10000; t++) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                int curPixel = i*width +j;
                
                if(screen[clamp(curPixel + 1, 0, width*height-1)] == '@') life++;
                if(screen[clamp(curPixel - 1, 0, width*height-1)] == '@') life++;
                if(screen[clamp(curPixel + width, 0, width*height-1)] == '@') life++;
                if(screen[clamp(curPixel - width, 0, width*height-1)] == '@') life++;
                if(screen[clamp(curPixel + width +1, 0, width*height-1)] == '@') life++;
                if(screen[clamp(curPixel + width -1, 0, width*height-1)] == '@') life++;
                if(screen[clamp(curPixel - width +1, 0, width*height-1)] == '@') life++;
                if(screen[clamp(curPixel - width -1, 0, width*height-1)] == '@') life++;

                if(life == 2) {
                    screen2[clamp(curPixel, 0, width*height-1)] =  screen[clamp(curPixel, 0, width*height-1)];
                }
                else if(life == 3) {
                    screen2[clamp(curPixel, 0, width*height-1)] = '@';
                } else {
                    screen2[clamp(curPixel, 0, width*height-1)] = '.';
                }
                
                life = 0;
                
                
            }
            
        }
        printf_s(screen2);

        copy(screen2,screen2+width*height, screen);
        Sleep(120);

    }

    return 0;
}
int clamp(int value, int ma, int mi) {return max(min(ma, value), mi);}