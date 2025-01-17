#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"C:\\MinGW\\BGI");
    line(100,100,100,200);
    getch();
    closegraph();

    return 0;
}
