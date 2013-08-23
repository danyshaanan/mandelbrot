/*
 * File:   main.cpp
 * Author: dany
 * Created somewhen around year 1999
 *
 * TODO: rewrite all of it
 *
 */

#include <math.h>
#include <stdio.h>   	         //4.1.3   v2.1  tofix 'f'.
#include <stdlib.h>     /* malloc, free, rand */
// #include <iostream>


// #include <conio.h>
// #include <graphics.h>

int main(void);
int createImage(int w, int h, int maxIterations);
int iterationsToEscape(float x, float y, int maxIterations);

////////////////////

int main(void) {
    createImage(640,640, 100);
}

int createImage(int w, int h, int maxIterations) {

    FILE *f;
    unsigned char *img = NULL;
    int filesize = 54 + 3*w*h;
    if( img )
        free( img );
    img = (unsigned char *)malloc(3*w*h);
    // memset(img,0,sizeof(img));

    for(int px=0; px<w; px++) {
        for(int py=0; py<h; py++) {

            int r, g, b;

            double x = 4.0*px/w-2.0;
            double y = 4.0*py/h-2.0;

            int iterations = iterationsToEscape(x, y, maxIterations);
            if (iterations == -1) {
                r = 0;
                g = 0;
                b = 0;
            } else {
                r = 10*iterations%255;
                g = 255 - r;
                b = 0;
            }

            int loc = (px+py*w)*3;
            img[loc+2] = (unsigned char)(r);
            img[loc+1] = (unsigned char)(g);
            img[loc+0] = (unsigned char)(b);
        }
    }

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

    f = fopen("temp.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i=0; i<h; i++)
    {
        fwrite(img+(w*(h-i-1)*3),3,w,f);
        fwrite(bmppad,1,(4-(w*3)%4)%4,f);
    }
    fclose(f);
}


int iterationsToEscape(float x, float y, int maxIterations) {
    int i;
    float tempa;
    float a = 0;
    float b = 0;
    for (i = 0 ; i < maxIterations ; i++) {
        tempa = a*a - b*b + x;
        b = 2*a*b + y;
        a = tempa;
        if (a*a+b*b > 4) {

            return i;
        }
    }
    return -1;
}


// void draw(int fpix,int fpush) {

//     powrun = pow(2,run);
//     range = 4;

//     for(j=1 ; j<intrange ; j++) {
//         range=range/2;
//     }

//     for(j=0 ; j<fpix ; j++) {
//         sj[j] = y + j*range/fpix - range/2;
//     }

//     for(i=0 ; i<fpix ; i++) {
//         si = x + i*range/fpix - range/2;
//         for (j=0 ; j<fpix ; j++) {
//             za = 0;
//             zb = 0;
//             for (n=0 ; 4>za*za+zb*zb && n!=powrun ; n++) {
//                 temp=za;
//                 za = za*za - zb*zb + si;
//                 zb = 2*temp*zb + sj[j];
//             }
//             if (n!=powrun) {
//                 putpixel(i+fpush,j,cl[n%16]);
//             } else {
//                 putpixel(i+fpush,j,0);
//             }
//         }
//     }
// }




/////////////////////////////////////////////////////////////////////////////

// void draw(int,int);

// int
//     intrange = 1,
//     powrun,
//     run = 8,
//     cl[16],
//     n,
//     j,
//     i,
//     c = -1,
//     lsz = 1000;

// long double
//     x = 0,
//     y = 0,
//     range = 4,
//     temp,
//     si,
//     sj[480],
//     za,
//     zb;

// void putpixel(int i,int j,int c) {
//     if (j == 0) printf("\n");
//     printf("%i%i", c%10, c%10);
// }



// int mainDEP(void) {

//     // createImage(100,100);

//     // int gdriver = DETECT;
//     // int gmode;
//     // int errorcode;
//     // initgraph(&gdriver, &gmode, "");
//     // flushall();
//     cl[0]=15;
//     cl[1]= 7;
//     cl[2]=14;
//     cl[3]= 6;
//     cl[4]=13;
//     cl[5]= 5;
//     cl[6]=12;
//     cl[7]= 4;
//     cl[8]=11;
//     cl[9]= 3;
//     cl[10]=10;
//     cl[11]= 2;
//     cl[12]= 9;
//     cl[13]= 1;
//     cl[14]= 8;
//     cl[15]= 0;

//     printf("\n\n\n\n\n\n\n\n\tthis is a program of the mandelbrot group\n");
//     // printf("\t   a=left,d=right\n\t   w=up,s=down\n");
//     // printf("\t   z=zoonin,x=zoomout\n\t   r=+accuracy,e=-accuracy\n");
//     // printf("\t   o=from the start\n\t   Space=Redraw\n\n\t   q-quit\n");


//     // draw(lsz,80);

//     draw(50,40);

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



    //while (!kbhit() ) {} --------...?

// void draw(int fpix,int fpush) {

//     powrun = pow(2,run);
//     range = 4;

//     for(j=1 ; j<intrange ; j++) {
//         range=range/2;
//     }

//     for(j=0 ; j<fpix ; j++) {
//         sj[j] = y + j*range/fpix - range/2;
//     }

//     for(i=0 ; i<fpix ; i++) {
//         si = x + i*range/fpix - range/2;
//         for (j=0 ; j<fpix ; j++) {
//             za = 0;
//             zb = 0;
//             for (n=0 ; 4>za*za+zb*zb && n!=powrun ; n++) {
//                 temp=za;
//                 za = za*za - zb*zb + si;
//                 zb = 2*temp*zb + sj[j];
//             }
//             if (n!=powrun) {
//                 putpixel(i+fpush,j,cl[n%16]);
//             } else {
//                 putpixel(i+fpush,j,0);
//             }
//         }
//     }
// }

