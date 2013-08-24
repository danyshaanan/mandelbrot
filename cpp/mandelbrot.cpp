/*
 * File:   main.cpp
 * Author: dany
 * Created somewhen between 1999 and 2002
 *
 * 2013: rewriting...
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

////////////////////////////////////////////////////////////////////////////////

bool curses_started = false;

void endCurses() {
    if (curses_started && !isendwin()) endwin();
}

void startCurses() {
    if (curses_started) {
        refresh();
    } else {
        initscr();
        // cbreak();
        // noecho();
        intrflush(stdscr, false);
        keypad(stdscr, true);
        atexit(endCurses);
        curses_started = true;
    }
}

////////////////////////////////////////////////////////////////////////////////

const int MAX_WIDTH_HEIGHT = 2000;
const int HUE_PER_ITERATION = 2;

int iterationsToEscape(double x, double y, int maxIterations) {
    double tempa;
    double a = 0;
    double b = 0;
    for (int i = 0 ; i < maxIterations ; i++) {
        tempa = a*a - b*b + x;
        b = 2*a*b + y;
        a = tempa;
        if (a*a+b*b > 4) {
            return i;
        }
    }
    return -1;
}

int hue2rgb(int t){
    t = t%360;
    if (t < 60) return 255.*t/60.;
    if (t < 180) return 255;
    if (t < 240) return 255. * (4. - t/60.);
    return 0;
}

void writeImage(unsigned char *img, int w, int h) {
    int filesize = 54 + 3*w*h;
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};

    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);

    bmpinfoheader[ 4] = (unsigned char)(       w    );
    bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
    bmpinfoheader[ 6] = (unsigned char)(       w>>16);
    bmpinfoheader[ 7] = (unsigned char)(       w>>24);
    bmpinfoheader[ 8] = (unsigned char)(       h    );
    bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
    bmpinfoheader[10] = (unsigned char)(       h>>16);
    bmpinfoheader[11] = (unsigned char)(       h>>24);

    FILE *f;
    f = fopen("temp.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for (int i=0; i<h; i++) {
        fwrite(img+(w*(h-i-1)*3),3,w,f);
        fwrite(bmppad,1,(4-(w*3)%4)%4,f);
    }
    fclose(f);
}

unsigned char *createImage(double centerX, double centerY, double zoom, int maxIterations, int w, int h) {
    if (w > MAX_WIDTH_HEIGHT) w = MAX_WIDTH_HEIGHT;
    if (h > MAX_WIDTH_HEIGHT) h = MAX_WIDTH_HEIGHT;

    unsigned char r, g, b;
    unsigned char *img = NULL;
    if (img) free(img);
    img = (unsigned char *)malloc(3*w*h);

    double xs[MAX_WIDTH_HEIGHT], ys[MAX_WIDTH_HEIGHT];
    for (int px=0; px<w; px++) {
        xs[px] = (px - w/2)/zoom + centerX;
    }
    for (int py=0; py<h; py++) {
        ys[py] = (py - h/2)/zoom + centerY;
    }

    for (int px=0; px<w; px++) {
        for (int py=0; py<h; py++) {
            r = g = b = 0;
            int iterations = iterationsToEscape(xs[px], ys[py], maxIterations);
            if (iterations != -1) {
                int h = HUE_PER_ITERATION * iterations;
                r = hue2rgb(h + 120);
                g = hue2rgb(h);
                b = hue2rgb(h + 240);
            }
            int loc = (px+py*w)*3;
            img[loc+2] = (unsigned char)(r);
            img[loc+1] = (unsigned char)(g);
            img[loc+0] = (unsigned char)(b);
        }
    }
    return img;
}

////////////////////////////////////////////////////////////////////////////////

double centerX = -1.186340599860225;
double centerY = -0.303652988644423;
double zoom = 400;
int iterations = 100;
int w = 700;
int h = 700;

const bool DRAW_ON_KEY = true;

void draw(void) {
    unsigned char *img = createImage(centerX, centerY, zoom, iterations, w, h);
    writeImage(img, w, h);
}

void processChar(int ch) {
    if (ch == 101) {} //e
    else if (ch == 97)  centerX -= 100.0 / zoom; //a
    else if (ch == 100) centerX += 100.0 / zoom; //d
    else if (ch == 115) centerY += 100.0 / zoom; //s
    else if (ch == 119) centerY -= 100.0 / zoom; //w
    else if (ch == 114) zoom *= 2; //r
    else if (ch == 102) zoom /= 2; //f
    else if (ch == 116) iterations += 10; //t
    else if (ch == 103) iterations -= 10; //g
    // else printf("%i,", ch);
}

int main() {
    draw();
    int ch = 0;
    startCurses();
    timeout(25);
    while (ch != 111) { //o
        ch = getchar();
        if (ch != ERR && ch != -1) {
           processChar(ch);
           if (DRAW_ON_KEY || ch == 101) draw(); //e
        }
    }
    endCurses();
}






