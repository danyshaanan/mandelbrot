/*
 * File:   main.cpp
 * Author: dany
 * Created somewhen around year 1999
 */

#include <math.h>
#include <stdio.h>   	         //4.1.3   v2.1  tofix 'f'.
#include <conio.h>
#include <graphics.h>

void draw(int,int);
int intrange=1,powrun,run=8,cl[16],n,j,i,c=-1,lsz=120;
long double x=0,y=0,range=4,temp,si,sj[480],za,zb;

void main(void) {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    flushall();
    cl[0]=15;
    cl[1]= 7;
    cl[2]=14;
    cl[3]= 6;
    cl[4]=13;
    cl[5]= 5;
    cl[6]=12;
    cl[7]= 4;
    cl[8]=11;
    cl[9]= 3;
    cl[10]=10;
    cl[11]= 2;
    cl[12]= 9;
    cl[13]= 1;
    cl[14]= 8;
    cl[15]= 0;

    printf("\n\n\n\n\n\n\n\n\t   this is a program of the mandelbrot group\n");
    printf("\t   a=left,d=right\n\t   w=up,s=down\n");
    printf("\t   z=zoonin,x=zoomout\n\t   r=+accuracy,e=-accuracy\n");
    printf("\t   o=from the start\n\t   Space=Redraw\n\n\t   q-quit\n");

    while (c!='q') {
            if (c==32) {
                draw(480,80);
            } else {
                switch (c) {
                    case 'a': x=x-range/5; break;
                    case 'd': x=x+range/5; break;
                    case 'w': y=y-range/5; break;
                    case 's': y=y+range/5; break;
                    case 'z': intrange++;  break;
                    case 'x': if (intrange>=1) intrange--;  break;
                    case 'r': run++;       break;
                    case 'e': run--;       break;
                    case 't': lsz=lsz+10;  break;
                    case 'g': lsz=lsz-10;  break;
                    case 'b': lsz=120;     break;
                    case 'v': lsz=480;     break;
                    case 'c': for(i=0;i<640;i++) for(j=0;j<480;putpixel(i,j,0),j++); break;
                    case 'f': printf("\t   x=%lf  y=%lf\n",x,y); printf("\t   range=2^%d run=2^%d\n",2-intrange,run); break;
                    case 'o': lsz=120;run=8;x=0;y=0;intrange=1;
                }
                draw(lsz,80);
            }
            c=getch();
    }
}
    //while (!kbhit() ) {} --------...?

void draw(int fpix,int fpush) {
    for(j=1,range=4;j<intrange;range=range/2,j++);
    powrun=pow(2,run);
    for(j=0;j<fpix;sj[j]=(y+(j*range/fpix)-(range/2)),j++);
    for(i=0;i<fpix;i++)
            {
            si=(x+(i*range/fpix)-(range/2));
            for(j=0;j<fpix;j++)
                    {
                    for(za=0,zb=0,n=0;(4>za*za+zb*zb&&n!=powrun);n++)
                            {
                            temp=za;
                            za=(za*za)-(zb*zb)+si;
                            zb=2*temp*zb+sj[j];
                            }
                    if (n!=powrun) putpixel(i+fpush,j,cl[n%16]);
                    else putpixel(i+fpush,j,0);
                    }
            }
    }

