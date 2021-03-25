/****************************************************************************
* Este programa fu‚ realizado por Manuel Ram¡rez Alvarez                    *
* E-mail: herty@starmedia.com                                               *
* Espero que lo disfrutes y te muestre como usar algunas instrucci¢nes de   *
* gr ficos, sonidos e instrucciones de Ms-Dos.                              *
* Descargado de C WORLD: http://www.biosys.net/cworld                                                                          *
*****************************************************************************/
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#define BEEP sound(1000);delay(25);nosound();
#define LOSE sound(90);delay(100);sound(30);delay(250);nosound();
#define POING sound(500);delay(25);nosound();

void juego(void);

void main (void){
	int tarj,modo;
	detectgraph(&tarj,&modo);
	initgraph(&tarj,&modo,"c:\\tc\\bgi");
	juego();
	restorecrtmode();
}

void juego(void){
	int m,n,mi,nj,vidas=3;
	char t;
	float x,y,xb,yb,ang,rad=.4,inc=.5;
int s[6][20]={0,0,0,0,5,1,2,3,4,5,1,2,3,4,5,1,0,0,0,0,
		      0,0,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,0,0,
		      4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,
			  0,0,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,0,0,
			  0,0,0,0,5,1,2,3,4,5,1,2,3,4,5,1,0,0,0,0};

	cleardevice();

	do{
	setfillstyle(0,0);
	x=290;y=469;xb=320;yb=464;
	bar(x,y,x+60,y+10);
	for (m=0;m<=5;m++){
		for (n=0;n<=19;n++){
			if (s[m][n]>0){
				setcolor(s[m][n]+8);
				setfillstyle(1,s[m][n]);
				bar3d(32*n,100+(16*m),30+(32*n),115+(16*m),1,1);}
		}
	}

	setcolor(0);
	ang=1.32582;
	do
	{
		t=inport(0x60);
		switch(t)
		{
			case 75:
				setfillstyle(0,0);
				bar(x,y,x+60,y+10);
				x=x-inc;  /* Cursor izquierda */
				if (x<0){x=x+inc;}
				break;
			case 77:
				setfillstyle(0,0);
				bar(x,y,x+60,y+10);
				x=x+inc;  /* Cursor derecha */
				if (x>580){x=x-inc;}
				break;
		}
		setfillstyle(1,2);
		bar(x,y,x+60,y+10);
		setfillstyle(0,0);
		fillellipse(xb,yb,4,4);
		xb=xb+(rad*cos(ang));
		yb=yb-(rad*sin(ang));
		setfillstyle(1,14);
		fillellipse(xb,yb,4,4);


		for(mi=0;mi<=5;mi++){
			if(yb>=100+(16*mi) && yb<116+(16*mi)){m=mi;}
		}
		for(nj=0;nj<=19;nj++){
			if(xb>=32*nj && xb<32*(nj+1)){n=nj;}
		}

		if(xb<4 || xb>636){ang=3.1416-ang;BEEP}
		if(yb<4){ang=6.2832-ang;BEEP}

		if(yb>=100 && yb<196 && s[m][n]>0){
			setfillstyle(0,0);
			bar(32*n,100+(16*m),31+(32*n),115+(16*m));
			s[m][n]=0;
			if(fabs(yb-115-(16*m))<1 || fabs(yb-100-(16*m))<1){
				 ang=6.283185307-ang;}
			else{ang=3.141592654-ang;}
			sound(150);delay(50);nosound();
		}

		if(yb>=465 && xb>=x+20 && xb<=x+30){ang=1.81577;yb=464;POING}
		if(yb>=465 && xb>x+30  && xb<=x+40){ang=1.32582;yb=464;POING}
		if(yb>=465 && xb>=x+10 && xb<x+30){ang=2.034;yb=464;POING}
		if(yb>=465 && xb>x+30  && xb<=x+50){ang=1.11;yb=464;POING}
		if(yb>=465 && xb>=x    && xb<x+30){ang=2.5;yb=464;POING}
		if(yb>=465 && xb>x+30  && xb<=x+60){ang=0.64;yb=464;POING}
		if(yb>484){vidas--;LOSE}

		*(char far *) MK_FP(0x40,0x1a)=*(char far *) MK_FP(0x40,0x1c);
	}while(yb<=484 && t!=1);                /* las teclas sean diferentes de ESC  */
	delay(90);
	}while(vidas>0 && t!=1);
}
