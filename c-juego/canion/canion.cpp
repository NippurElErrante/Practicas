#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>
#include <bios.h>
#include <ctype.h>
#include <strstrea.h>
#include <fstream.h>

#define ventanax 580
#define ventanay 420

struct FECHA
{
int dia,mes,ano;
};

struct JUGADOR
{
 char nombre[31];
 int puntaje;
 FECHA f_juego;
};

int gdriver = DETECT, gmodo;
void inicializar(),menu();
void scores(),presentacion(),fin(),carita();
int vol=0,puntos,q,p,pos_canion;
void vaciar(char linea[]);
int vidas,balas;
void entrada(),salida();
JUGADOR nombres[5],puntajes,auxiliar,leer;
fstream comojugar;
fstream records;

void main()
{
	entrada();
	inicializar();
	presentacion();
	menu();
	fin();
	closegraph();
	salida();
}

void entrada()
{
 records.open("records.dat",ios::in);
 if (records.good())
	 {
	  for (q=0;q<5;q++)
	   {
	   records.read((unsigned char *) &puntajes,sizeof (puntajes));
	   nombres[q]=puntajes;
	   }
	 }
 records.close();
}

void salida()
{
 remove("records.dat");
 records.open("records.dat",ios::app);
 if (records.good())
 {
 for (q=0;q<5;q++)
   {
   puntajes=nombres[q];
   records.write((unsigned char *) &puntajes,sizeof(puntajes));
   }
 }
 records.close();
}

void inicializar()
{
 initgraph(&gdriver,&gmodo,"");
}

void menu()
{
void juego(),ayuda();
int a,col,fila;
char op, sale_op[3]=" ";
 do{
   cleardevice();
   setcolor(RED);
   setfillstyle(1,0);
   bar3d (180,170,460,310,0,0);
   a=1; col=210; fila=200;
   for (q=0;q<2;q++)
     {
     setcolor(a);
     settextstyle(0,HORIZ_DIR,5);
     outtextxy (col-4,fila-110,"CANION");
     settextstyle(0,HORIZ_DIR,2);
     outtextxy (col,fila,"1. ENTRAR");
     outtextxy (col,fila+25,"2. LOS MEJORES");
     outtextxy (col,fila+50,"3. COMO JUGAR");
     outtextxy (col,fila+75,"4. SALIR");
     a=15; col-=2; fila-=2;
     }
   outtextxy (210,333,"DISPARA: ");
   vaciar(sale_op);
   op=getch();
   ostrstream(sale_op,2)<<op;
   setcolor(15);
   settextstyle(0,HORIZ_DIR,2);
   outtextxy(350,333,sale_op);
   getch();
   if (op!='4')
    {
     switch (op)
       {
	case '1': puntos=0; balas=150; juego();  break;
	case '2': scores(); break;
	case '3': ayuda();  break;
	default:  setcolor(10);
		  outtextxy (90,360,"FATAL ERROR!!!");
		  delay(1000);
		  break;
       }
    }
  else vol=1;
 }while (vol!=1);
}

void presentacion()
{
int sony[2][5]={{500,700,600,300,0},
		{300,500,700,600,0}};
int duracion[2][5]={{500,500,500,500,800},
		    {500,500,500,500,900}};
randomize();
cleardevice();
carita();
for (p=0;p<2;p++)
   for (q=0;q<5;q++)
    {
    sound(sony[p][q]);
    delay (duracion[p][q]);
    nosound();
    }
   delay (50);
 settextstyle(0,HORIZ_DIR,8);
 setcolor(1);
 outtextxy(132,30,"CANION");
 setcolor(15);
 outtextxy(130,27,"CANION");
 setcolor(4);
 settextstyle(0,HORIZ_DIR,2);
 outtextxy(45,415,"Realizado por: JAVIER LOPEZ ERASO");
 delay (1500);
}

void juego()
{
int niv,retardo=16,control=0,c2=0,c3=0,tiro,pump;
int z,m,n,r,s,t,xi=260,yi=325,xb,yb,v=150,x,y;
int posicion[5][10],band,vivos=0,victimas=0;
int pos_invaders[5][10]={{30,80,130,180,230,280,330,380,430,480},
			 {55,105,155,205,255,305,355,405,455,505},
			 {30,80,130,180,230,280,330,380,430,480},
			 {5,55,105,155,205,255,305,355,405,455},
			 {30,80,130,180,230,280,330,380,430,480}};
int beg[5]={3,12,21,30,39};
char armo[15]=" ";
char puntajes[15]=" ";
char si;
int stars=0;
void explota(int &xi,int &yi);
void explota1(int &xb,int &yb);
void city(int &stars);
struct date hoy;
randomize();
vidas=3; niv=1;
cleardevice();
randomize();
while (vidas>0)
 {
 if (niv>0)
     {
     control++;
     if (niv>5)
       {
       if (retardo>=4) retardo-=4;
       niv=1;
       }
     }
 for(q=0;q<niv;q++) for (p=0;p<10;p++) posicion[q][p]=0;
 setcolor(1);
 setfillstyle(1,0);
 bar3d(58,9,ventanax+2,41,0,0);
 bar3d(58,59,ventanax+2,ventanay+1,0,0);
 setcolor(1);
 settextstyle(0,HORIZ_DIR,3);
 outtextxy(240,17,"CANION");
 setcolor(15);
 settextstyle(0,HORIZ_DIR,1);
 outtextxy(230,46,"Presiona ESC para salir");
 settextstyle(0,HORIZ_DIR,3);
 outtextxy(237,14,"CANION");
 setviewport(60,60,ventanax,ventanay,1);
    do{
    if (bioskey(1)!=0) t=bioskey(0);
    x=0,y=0; int tri=0;
      do{
	int canions[8]={x,y+10,x+5,y,x+10,y+10,x,y+10};
	setcolor(0);
	setfillstyle(1,14);
	fillpoly(3,canions);
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(x+5,y+6,2,2);
	x+=15;
	tri++;
      }while (tri<vidas);
    setcolor(15);
    settextstyle(0,HORIZ_DIR,1);
    vaciar(armo);
    ostrstream(armo,14)<<"Munici¢n:  "<<balas;
    outtextxy(0,25,armo);
    vaciar(puntajes);
    ostrstream(puntajes,14)<<"Puntos:   "<<puntos;
    outtextxy(0,35,puntajes);
    for (m=0;m<niv;m++)
      {
       for(n=0;n<10;n++)
	{
	if (posicion[m][n]==0)
	 {
	  setcolor(0);
	  settextstyle(0,HORIZ_DIR,1);
	  outtextxy(pos_invaders[m][n],beg[m]-6,"");
	  setcolor(10);
	  outtextxy(pos_invaders[m][n],beg[m]-5,"");
	 }
	}
      }
    delay(retardo);
    if (control>0)
     {
      control=0;
      if (beg[niv-1]<180) tiro=random(9);
      else tiro=10;
     }
    switch(tiro)
       {
       case 10: break;
       default: if (c2==0)
		{
		pump=beg[niv-1];
		c2=1;
		}
		if(pump<366) c2=1;
		else
		 {
		 c2=0;
		 control=1;
		 }
		if (c2==1)
		{
		setcolor(0);
		setfillstyle(1,0);
		bar(pos_invaders[niv-1][tiro]-6,pump-9,pos_invaders[niv-1][tiro]+6,pump-3);
		setfillstyle(1,10);
		fillellipse(pos_invaders[niv-1][tiro],pump,2,6);
		pump+=4;
		}
		break;
       }
    city(stars);
    int canion[8]={xi,yi+30,xi+5,yi+20,xi+10,yi+30,xi,yi+30};
    setcolor(0);
    setfillstyle(1,14);
    fillpoly(3,canion);
    setfillstyle(1,0);
    fillellipse(xi+5,yi+26,2,2);
    switch(t)
	  {
	  case 19200: xi-=8; break;
	  case 19712: xi+=8; break;
	  case 20480: if (yi<330) yi+=8;  break;
	  case 18432: if (yi>330) yi-=8;  break;
	  case 14624: if (balas>0)
		       {
		       balas--; yb=yi; xb=xi;
		       sound(400);
		       delay(30);
		       nosound();
			do{
			setcolor(0);
			setfillstyle(1,15);
			bar3d(xb+2,yb+5,xb+5,yb+15,0,0);
			r=0;
			 do{
			 for(s=0;s<10;s++)
			  {
			  if(xb>=pos_invaders[r][s]-7 && xb<=pos_invaders[r][s]+6)
			    {
			    if(yb<=beg[r]+5 && yb>=beg[r])
			      {
			      if (posicion[r][s]==0)
			       {
			       posicion[r][s]=1;
			       setcolor(0);
			       setfillstyle(1,0);
			       fillellipse(xb+4,yb+2,15,15);
			       puntos+=2;
			       s=10; r=niv; yb=-15;
			       sound(800);
			       delay(30);
			       nosound();
			       }
			      }
			    }
			  if(xb>=pos_invaders[niv-1][tiro]-6 && xb<=pos_invaders[niv-1][tiro]+4)
			    {
			    if(yb<=pump+2 && yb>=pump-2)
			      {
			       puntos+=4;
			       s=10; r=niv;
			       xb=pos_invaders[niv-1][tiro];
			       yb=pump;
			       pump=366;
			       explota1(xb,yb);
			       yb=-15;
			      }
			    }
			  }
			 r++;
			 }while(r<niv);
			yb--;
			}while(yb>=-15);
			t=random(2);
			if (t==0) t=19200;
			else t=19712;
		       }
		       break;
	   case 283: vidas=0; beg[0]=360; break;
	  }
    if (pos_invaders[niv-1][tiro]>=canion[0]-3 && pos_invaders[niv-1][tiro]<=canion[4]+3)
    if (pump>=canion[3] && pump<=canion[1])
    if (c3!=1)
      {
      if (vidas>0) vidas--;
      beg[0]=360; niv--;
      pump=366; stars=0;
      explota(xi,yi);
      c3=1;
      }
    if(xi>=580) xi=0;
    else if (xi<=-5) xi=580;
    for (z=0;z<niv;z++) beg[z]++;
    if (puntos>v)
     {
     vidas++; v+=150;
     }
    if (pump>362 && pump<366) victimas+=20;
    if (victimas>80)
      {
       vidas--;
       victimas=0;
       explota(xi,yi);
       setcolor(15);
       settextstyle(6,HORIZ_DIR,3);
       outtextxy(160,120,"DEMASIADAS VICITMAS");
       delay(2000);
       setcolor(0);
       setfillstyle(1,0);
       bar(150,120,400,155);
       stars=0;
       clearviewport();
      }
   setfillstyle(1,0);
   bar(0,20,200,70);
   }while(beg[0]<360);
  int suma=1;
  for (z=0;z<5;z++)
    {
    beg[z]=3*suma;
    suma=suma+3;
    }
  stars=0;
  for(q=0;q<niv;q++) for (p=0;p<10;p++) if (posicion[q][p]==0) vivos++;
  balas=150;
  if (vivos>=1 && c3==0)
     {
     if (vidas>0) vidas--;
     explota(xi,yi);
     setcolor(15);
     settextstyle(6,HORIZ_DIR,3);
     outtextxy(180,120,"I N V A S I O N");
     delay(2000);
     setcolor(0);
     setfillstyle(1,0);
     fillellipse(xi,yi,17,17);
     niv--; suma=1;
     for (z=0;z<5;z++)
       {
       beg[z]=3*suma;
       suma=suma+3;
       }
     vivos=0;
     }
  setviewport(0,0,getmaxx()-1,getmaxy()-1,0);
  if (vidas==0)
   {
   for(q=0;q<5;q++)
     {
      if (puntos>nombres[q].puntaje)
	{
	 int car,i,cc;
	 char mostrar[2]=" ";
	 char L;
	 cleardevice();
	 getdate (&hoy);
	 setcolor(10);
	 setfillstyle(1,0);
	 settextstyle(0,HORIZ_DIR,1);
	 bar3d(160,260,480,290,0,0);
	 outtextxy (160,230,"TIENES UN RECORD");
	 outtextxy (160,250,"Digita aqu¡ tu nombre:");
	 i=0; cc=180;
	 do{
	 L=getch();
	 car=L;
	 if (car!=13)
	   {
	     if (car!=8)
	       {
	       vaciar(mostrar);
	       setcolor(15);
	       settextstyle(0,HORIZ_DIR,2);
	       ostrstream(mostrar,1)<<L;
	       outtextxy(cc,265,mostrar);
	       leer.nombre[i]=L;
	       cc+=15; i++;
	       }
	     else
	       {
		if (i>0)
		  {
		  i--; cc-=15;
		  outtextxy(cc,265," ");
		  }
		else outtextxy(180,265," ");
	       }
	   }
	 }while(car!=13);
	 leer.puntaje=puntos;
	 leer.f_juego.dia=hoy.da_day;
	 leer.f_juego.mes=hoy.da_mon;
	 leer.f_juego.ano=hoy.da_year;
	 for (p=q;p<6;p++)
	   {
	    auxiliar=nombres[p];
	    nombres[p]=leer;
	    leer=auxiliar;
	   }
	 scores();
	}
     }
   cleardevice();
   setcolor (1);
   settextstyle (0,HORIZ_DIR,4);
   outtextxy (180,195,"GAME OVER");
   settextstyle (0,HORIZ_DIR,1);
   outtextxy(198,281,"Quieres jugar otra vez ?(s/n):");
   setcolor (15);
   settextstyle (0,HORIZ_DIR,4);
   outtextxy (175,190,"GAME OVER");
   settextstyle (0,HORIZ_DIR,1);
   outtextxy(195,278,"Quieres jugar otra vez ?(s/n):");
   gotoxy (57,18);
   cin>>si;
   si=tolower (si);
   if (si=='s')
     {
     t=0; niv=0; vidas=3; puntos=0; retardo=16; v=150; control=0;
     xi=260; yi=325; victimas=0;
     suma=1;
     for (z=0;z<5;z++)
       {
       beg[z]=3*suma;
       suma=suma+3;
       }
     }
   else vidas=0;
   }
 c3=0;
 niv++;
 }
}

void city(int &stars)
{
 int ciudad[44]={0,360,0,220,55,220,55,320,100,320,100,300,145,300,145,330,165,330,165,210,175,200,185,210,185,340,380,340,380,245,420,245,420,330,460,330,460,190,520,190,520,360,0,360};
 int cantidad,en_x,en_y;
 if (stars!=1)
  {
  for (cantidad=1;cantidad<=150;cantidad++)
   {
    en_x=random(520);
    en_y=random(320);
    setcolor(0);
    setfillstyle(1,15);
    fillellipse(en_x,en_y,1,1);
   }
  stars=1;
  }
 setcolor(15);
 setfillstyle(1,1);
 fillpoly(21,ciudad);
}

void explota(int &xi,int &yi)
{
int ini,fin;
fin=15;
for (ini=3;ini<=fin;ini++)
 {
 setcolor(12);
 setfillstyle(1,0);
 fillellipse(xi+5,yi+26,ini,ini);
 sound(400+(ini*5));
 delay(10);
 }
ini=3;
for(fin=15;fin>=ini;fin--)
 {
 setcolor(14);
 setfillstyle(1,0);
 fillellipse(xi+5,yi+26,fin,fin);
 sound(650-(fin*5));
 delay(10);
 }
nosound();
setcolor(0);
setfillstyle(1,0);
fillellipse(xi+5,yi+26,15,15);
}

void explota1(int &xb,int &yb)
{
int ini,fin;
fin=15;
for (ini=3;ini<=fin;ini++)
 {
 setcolor(11);
 setfillstyle(1,0);
 fillellipse(xb,yb,ini,ini);
 sound(650-(ini*5));
 delay(10);
 }
ini=3;
for(fin=15;fin>=ini;fin--)
 {
 setcolor(15);
 setfillstyle(1,0);
 fillellipse(xb,yb,fin,fin);
 sound(500+(fin*5));
 delay(10);
 }
nosound();
setcolor(0);
setfillstyle(1,0);
fillellipse(xb,yb,15,15);
}

void scores()
{
  char num[18]=" ";
  char score[6]=" ";
  char fechas[11]=" ";
  int L=102,C=55;
  cleardevice();
  settextstyle (0,HORIZ_DIR,3);
  setcolor(1);
  outtextxy (148,3,"MEJORES CA¥ONES");
  setcolor(15);
  outtextxy (145,0,"MEJORES CA¥ONES");
  setcolor(1);
  setfillstyle(1,0);
  bar3d(35,60,80,75,0,0);
  bar3d(100,60,350,75,0,0);
  bar3d(370,60,480,75,0,0);
  bar3d(500,60,600,75,0,0);
  bar3d(35,85,80,ventanay-60,0,0);
  bar3d(100,85,350,ventanay-60,0,0);
  bar3d(370,85,480,ventanay-60,0,0);
  bar3d(500,85,600,ventanay-60,0,0);
  setcolor(14);
  settextstyle (0,HORIZ_DIR,1);
  outtextxy (38,65,"LUGAR");
  outtextxy (200,65,"NOMBRE");
  outtextxy (400,65,"PUNTAJE");
  outtextxy (530,65,"FECHA");
  for (q=0;q<5;q++)
     {
      vaciar(num); vaciar(score); vaciar (fechas);
      ostrstream(num,17) << q+1 <<"   "<<nombres[q].nombre;
      ostrstream(score,5) <<nombres[q].puntaje;
      ostrstream(fechas,10)<<nombres[q].f_juego.dia<<"/"<<nombres[q].f_juego.mes<<"/"<<nombres[q].f_juego.ano;
      settextstyle (0,HORIZ_DIR,2);
      setcolor(1);
      outtextxy(C,L,num);
      outtextxy(C+322,L,score);
      settextstyle (0,HORIZ_DIR,1);
      outtextxy(C+452,L,fechas);
      setcolor(15);
      settextstyle (0,HORIZ_DIR,2);
      outtextxy(C-2,L-2,num);
      outtextxy(C+320,L-2,score);
      settextstyle (0,HORIZ_DIR,1);
      outtextxy(C+450,L-2,fechas);
      L+=55;
     }
settextstyle (0,HORIZ_DIR,2);
outtextxy (40,440,"Presiona una tecla para continuar...");
getch();
}

void ayuda()
{
 char filas[72]=" ";
 int linea=62;
  cleardevice();
  setcolor(1);
  bar3d(40,40,630,ventanay,0,0);
  settextstyle (0,HORIZ_DIR,3);
  outtextxy (125,15,"AYUDA SOBRE CANION");
  setcolor (15);
  outtextxy (120,10,"AYUDA SOBRE CANION");
  setcolor(15);
  settextstyle(0,HORIZ_DIR,1);
  comojugar.open("naves.txt",ios::in);
  if (comojugar.good())
   {
   for(q=0;q<52;q++)
      {
       comojugar.getline(filas,71);
       outtextxy(60,linea,filas);
       linea+=12;
      }
   }
  comojugar.close();
  settextstyle (0,HORIZ_DIR,2);
  outtextxy (40,440,"Presiona una tecla para continuar...");
  getch();
}

void fin()
{
 int son=100;
 cleardevice();
 carita();
 setcolor (1);
 settextstyle (0,HORIZ_DIR,4);
 outtextxy (180,95,"GAME OVER");
 setcolor(15);
 outtextxy (175,90,"GAME OVER");
 sound(son*2);
 delay (500);
 nosound();
 sound(son);
 delay (1000);
 nosound();
 delay(800);
}

void carita()
{
int cara[8]={218,307,308,160,398,307,218,307};
 setcolor(14);
 setfillstyle(1,14);
 fillpoly(3,cara);
 setcolor(0);
 setfillstyle(1,0);
 fillellipse(308,245,35,35);
 setcolor(15);
 settextstyle(0,HORIZ_DIR,2);
 outtextxy(238,330,"JAVIERAZO");
 outtextxy(182,355,"Inc. Productions");
}

void vaciar(char linea[])
{
 int i=0;
 while (linea[i]!='\0')
  {
   linea[i]=' ';
   i++;
  }
linea[0]='\0';
}