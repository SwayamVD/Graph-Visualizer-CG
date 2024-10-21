#include <graphics.h>
#include <conio.h>  

void drawBarGraph(int values[], int numBars, int maxValue) {
    int barWidth = 50;  //width of bar
    int gap = 20;       //space between bars
    int x = 100;        
    int yBase = 400;    //bottom of the graph

    int colors[] = {RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN, WHITE};

    setcolor(BLACK);
    //x-axis line
    line(80, yBase, 600, yBase);
    //y-axis line
    line(80, yBase, 80, 50);   
    outtextxy(600, yBase, "X");
    outtextxy(80, 50, "Y");

    outtextxy(300, 450, "Subjects");
    outtextxy(115, 405, "CG");
    outtextxy(185, 405, "DS");
    outtextxy(255, 405, "DEL");
    outtextxy(325, 405, "OS");
    outtextxy(395, 405, "DM");

    outtextxy(10, 200, "Marks");
    outtextxy(60, 400, "0");
    outtextxy(60, 330, "5");
    outtextxy(60, 250, "10");
    outtextxy(60, 170, "15");
    outtextxy(60, 90, "20");
    

    for (int i = 0; i < numBars; i++) {
        int barHeight = (values[i] * 300) / maxValue;  
        int x1 = x + (i * (barWidth + gap));           
        int y1 = yBase - barHeight; 
        if(values[i] < 8){
        setcolor(colors[0]); 
        rectangle(x1, yBase, x1 + barWidth, y1);
        delay(300);
        setfillstyle(SOLID_FILL , colors[0]);
        floodfill(x1 + barWidth / 2, yBase - 1, colors[0]);
        delay(200);
        }
        else{
        setcolor(colors[1]); 
        rectangle(x1, yBase, x1 + barWidth, y1);
        delay(300);
        setfillstyle(SOLID_FILL , colors[1]);
        floodfill(x1 + barWidth / 2, yBase - 1, colors[1]);
        delay(200);
        }

    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    cleardevice(); 

    int values[5] = {15, 10, 7, 20, 10};
    int numBars = sizeof(values) / sizeof(values[0]);
    int maxValue = 20;
    drawBarGraph(values, numBars, maxValue);
    getch();
    closegraph();
    return 0;
}
