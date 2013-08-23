/*
 * File:   main.cpp
 * Author: dany
 * Created somewhen between 1999 and 2002
 *
 * 2013: rewriting...
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int maxSize = 2000;


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

int createImage(double centerX, double centerY, double zoom, int maxIterations, int w, int h) {
    if (w > maxSize) w = maxSize;
    if (h > maxSize) h = maxSize;

    unsigned char r, g, b;
    unsigned char *img = NULL;
    if (img) free(img);
    img = (unsigned char *)malloc(3*w*h);

    double xs[maxSize], ys[maxSize];
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
                int h = 360.0 * iterations/maxIterations;
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
    writeImage(img, w, h);
}


int main(void) {
    double centerX = -1.186340599860225;
    double centerY = -0.303652988644423;
    double zoom = 40000;
    int iterations = 300;
    createImage(centerX, centerY, zoom, iterations, 700, 700);
}

/////////////////////////////////////////////////////////////////////////////

// int mainDEP(void) {

//     printf("\n\n\n\n\n\n\n\n\tthis is a program of the mandelbrot group\n");
//     // printf("\t   a=left,d=right\n\t   w=up,s=down\n");
//     // printf("\t   z=zoonin,x=zoomout\n\t   r=+accuracy,e=-accuracy\n");
//     // printf("\t   o=from the start\n\t   Space=Redraw\n\n\t   q-quit\n");

//     // while (c!='q') {
//     //         if (c==32) {
//     //             draw(480,80);
//     //         } else {
//     //             switch (c) {
//     //                 case 'a': x=x-range/5; break;
//     //                 case 'd': x=x+range/5; break;
//     //                 case 'w': y=y-range/5; break;
//     //                 case 's': y=y+range/5; break;
//     //                 case 'z': intrange++;  break;
//     //                 case 'x': if (intrange>=1) intrange--;  break;
//     //                 case 'r': run++;       break;
//     //                 case 'e': run--;       break;
//     //                 case 't': lsz=lsz+10;  break;
//     //                 case 'g': lsz=lsz-10;  break;
//     //                 case 'b': lsz=120;     break;
//     //                 case 'v': lsz=480;     break;
//     //                 case 'c': for(i=0;i<640;i++) for(j=0;j<480;putpixel(i,j,0),j++); break;
//     //                 case 'f': printf("\t   x=%lf  y=%lf\n",x,y); printf("\t   range=2^%d run=2^%d\n",2-intrange,run); break;
//     //                 case 'o': lsz=120;run=8;x=0;y=0;intrange=1;
//     //             }
//     //             draw(lsz,80);
//     //         }
//     //         c=getch();
//     // }
// }

