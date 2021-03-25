/*  Buscaminas  */
/*  Programado por Eric V squez Mart¡nez  */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <graphics.h>
#define X 8
#define Y 8
#define B 10
int posx, posy,     /*  Casilla activa  */
    m1[Y+2][X+2],   /*  Posiciones de las bombas y donde ya paso  */
   	m2[Y][X],       /*  N£mero de bombas alrededor de cada posici¢n  */
	  nba,            /*  Numero de casillas abiertas  */
	  imp,uso;        /*  Controla la impresi¢n/no impresi¢n de las minas  */



/*  Inicializaci¢n del modo gr fico, devuelve 1 si no tiene un monitor
    tipo VGA o superior del alata resoluci¢n                            */
int ini_g(void)
{
  int gdriver=DETECT, gmode,errorcode;
  char c;

  initgraph(&gdriver,&gmode,"");
  if (gdriver==9 && gmode==2) return 0;
  errorcode = graphresult();
  if (errorcode != grOk)
  {
    printf("Error gr fico %s\n", grapherrormsg(errorcode));
    printf("Presiona una tecla para continuar");
    c=getch();
    if (c==0)
      c=getch();
    exit(1);
  }
  return 1;
}


/*  Establece el color del modo gr fico a C y el estilo de rellenado  */
void colfil(int c)
{
  setcolor(c);
  setfillstyle(1,c);
}

/*  Traza una flecha
    1) Arriba
    2) Abajo
    3) Derecha
    4) Izquierda       */
void fle(int x, int y, int t)
{
  setcolor(15);
  if (t==1)
  {
    line(x,y-5,x,y+5);
    line(x-5,y-2,x,y-5);
    line(x,y-5,x+5,y-2);
  }
  if (t==2)
  {
    line(x,y-5,x,y+5);
    line(x-5,y+2,x,y+5);
    line(x,y+5,x+5,y+2);
  }
  if (t==3)
  {
    line(x-5,y,x+5,y);
    line(x+2,y-5,x+5,y);
    line(x+5,y,x+2,y+5);
  }
  if (t==4)
  {
    line(x-5,y,x+5,y);
    line(x-2,y-5,x-5,y);
    line(x-5,y,x-2,y+5);
  }
}


/*  Traza una bandera en la posici¢n (X,Y)  */
void bandera(int x, int y)
{
  colfil(4);
  line(x-15,y-7,x,y-15);
  line(x-15,y-7,x,y);
  line(x,y,x,y-15);
  floodfill(x-1,y-5,4);
  setcolor(8);
  line(x,y-15,x,y+15);
  line(x+1,y-15,x+1,y+15);
  colfil(0);
  sector(x,y+15,0,180,15,7);
}


/*  Traza una bomba en la posici¢n (X,Y)  */
void bomba(int x, int y)
{
  colfil(0);
  fillellipse(x,y,10,10);
  line(x-15,y,x+15,y);
  line(x,y-15,x,y+15);
  line(x-10,y-10,x+10,y+10);
  line(x+10,y-10,x-10,y+10);
  colfil(7);
  fillellipse(x-3,y-3,2,2);
}


/*  Traza la cara:
     1) Feliz
     0) Normal
    -1) Triste   */
void car(int t)
{
  colfil(14);
  fillellipse(getmaxx()-120-40,39,20,20);
  colfil(0);
  if (t==1)
  {
    fillellipse(getmaxx()-120-48,32,5,5);
    fillellipse(getmaxx()-120-32,32,5,5);
    line(getmaxx()-120-48+5,32,getmaxx()-120-32-5,32);
    line(getmaxx()-120-48-5,31,getmaxx()-120-48-12,35);
    line(getmaxx()-120-32+5,31,getmaxx()-120-32+12,35);
    setcolor(4);
    arc(getmaxx()-120-40,40,180,360,12);
  }
  if (t==0)
  {
    fillellipse(getmaxx()-120-48,32,2,2);
    fillellipse(getmaxx()-120-32,32,2,2);
    colfil(4);
    sector(getmaxx()-120-40,40,180,360,12,12);
  }
  if (t==-1)
  {
    line(getmaxx()-120-48-3,34,getmaxx()-120-48+3,30);
    line(getmaxx()-120-48+3,34,getmaxx()-120-48-3,30);
    line(getmaxx()-120-32-3,34,getmaxx()-120-32+3,30);
    line(getmaxx()-120-32+3,34,getmaxx()-120-32-3,30);
    arc(getmaxx()-120-40,40+12,0,180,12);
  }
}


/*  Traza la caratula del juego  */
void caratula(void)
{
  int a,b;

  colfil(1);
  rectangle(119,0,getmaxx()-120,getmaxy()-400);
  floodfill(120,1,1);
  setcolor(15);
  rectangle(119,0,getmaxx()-120,getmaxy());
  settextstyle(4,0,5);
  outtextxy(135,10,"BUSCAMINAS");
  car(0);
  colfil(7);
  rectangle(119,79,119+50*7+50,79+50+50*7);
  floodfill(119+1,79+1,7);
  for (a=0; a<8; a++)
    for (b=0; b<8; b++)
    {
      setcolor(15);
      rectangle(119+(50*b),79+(50*a),119+50+(50*b),79+50+(50*a));
    }
  fle(17,40,1);
  fle(17,60,2);
  fle(18,80,3);
  fle(17,100,4);
  settextstyle(2,0,0);
  setcolor(8);
  outtextxy(1,470,"Eric V squez Mtz.");
  setcolor(14);
  outtextxy(0,10,"Tecla  Funci¢n");
  setcolor(15);
  outtextxy(1,120,"Inicio");
  outtextxy(1,140,"Re pag");
  outtextxy(1,160," Fin  ");
  outtextxy(1,180,"Av pag");
  outtextxy(1,200,"Enter");
  outtextxy(1,240," Esc  ");
  outtextxy(1,270,"  F1  ");
  outtextxy(1,290,"  F2  ");
  setcolor(7);
  outtextxy(42,36,"Arriba");
  outtextxy(42,56,"Abajo");
  outtextxy(42,76,"Izquierda");
  outtextxy(42,96,"Derecha");
  outtextxy(42,120,"Arriba-Izquie");
  outtextxy(42,140,"Arriba-Derech");
  outtextxy(42,160,"Abajo-Izquier");
  outtextxy(42,180,"Abajo-Derecha");
  outtextxy(42,200,"Destapa la");
  outtextxy(42,210,"posici¢n");
  outtextxy(42,220,"seleccionada");
  outtextxy(42,240,"Salir del");
  outtextxy(42,250,"juego");
  outtextxy(42,270,"Juego nuevo");
  outtextxy(42,290,"Mapa de las");
  outtextxy(42,300,"minas");
  setcolor(8);
  outtextxy(1,460,"Programado por");
}


/*  Presenta/"Borra" el mapa de las minas  */
void tablita(void)
{
  int a,b;
  char num[2];

  if (imp==0) setcolor(0);
  else setcolor(7);
  settextstyle(2,0,4);
  for (a=0; a<Y; a++)
  for (b=0; b<X; b++)
    {
      itoa(m1[a+1][b+1],num,10);
      if (num[0]=='9') num[0]='0';
      outtextxy(getmaxx()-104+(b*13),(a*13),num);
    }
  if (imp==0) setcolor(0);
  else setcolor(11);
  itoa(m1[posy+1][posx+1],num,10);
  if (num[0]=='9') num[0]='0';
  outtextxy(getmaxx()-104+(posx*13),(posy*13),num);
  if ((m1[posy+1][posx+1]==9 || m1[posy+1][posx+1]==0) && imp==1) setcolor(11);
  else
  if (imp==1) setcolor(7);
  else setcolor(0);
  outtextxy(getmaxx()-106,120,"0. No es una mina");
  if (m1[posy+1][posx+1]==1 && imp==1) setcolor(11);
  else
  if (imp==1) setcolor(7);
  else setcolor(0);
  outtextxy(getmaxx()-106,135,"1. Es una mina");
}


/*  Traza un cuadro con color C en la posici¢n (X,Y)  */
void lim_cua(int c,int x,int y)
{
  colfil(c);
  rectangle(x,y,x+50,y+50);
  floodfill(x+1,y+1,c);
  setcolor(15);
  rectangle(x,y,x+50,y+50);
}


/*  Traza el n£mero de bombas N alrededor de la posici¢n (X,Y)  */
void lim_num(int n, int x, int y)
{
  char num[2];

  itoa(n,num,10);
  lim_cua(0,x,y);
  setcolor(16-n);
  settextstyle(1,0,4);
  outtextxy(x+17,y+2,num);
}

/*  Escribe dos textos verticales y espera hasta que se presione una tecla  */
void texto(char t1[20], char t2[20], int x, int y)
{
  int c=15;

  while(!(kbhit()))
  {
    setcolor(c);
    settextjustify(0,1);
    settextstyle(3,2,3);
    outtextxy(x,y,t1);
    settextstyle(3,2,4);
    outtextxy(x+50,y,t2);
    if (c==0) c=16;
    c--;
    delay(100);
    settextjustify(0,2);
    settextstyle(2,0,0);
    if (c%2==0) setcolor(15);
    else setcolor(0);
    outtextxy(getmaxx()-110,getmaxy()-30,"Presiona una tecla");
    outtextxy(getmaxx()-110,getmaxy()-20,"  para continuar  ");
  }
}


/*  Pone todas las bombas/banderas  */
void pon(int poner)
{
  int a,b;

  for (a=0; a<Y; a++)
    for (b=0; b<X; b++)
      if (m1[a+1][b+1]==1)
        if (poner==1) bomba(119+25+(50*b),79+25+(50*a));
        else bandera(119+25+(50*b),79+25+(50*a));
}


/* Limpia el area alrededor del la posici¢n (y,x)  */
void limpia(int y,  int x)
{
  if (y<0 || x<0 || y>7 || x>7 || m1[y+1][x+1]==9) return;
  m1[y+1][x+1]=9;
  nba++;
  if (m2[y][x]==0)
  {
    lim_cua(0,119+(50*(x)),79+(50*(y)));
    limpia(y-1,x-1);
    limpia(y-1,x);
    limpia(y-1,x+1);
    limpia(y,x-1);
    limpia(y,x+1);
    limpia(y+1,x-1);
    limpia(y+1,x);
    limpia(y+1,x+1);
  }
  else lim_num(m2[y][x],119+(50*(x)),79+(50*(y)));
}


/*  Controla el movimiento de las celdas  */
int mov(void)
{
  char ch1,ch2;

  ch2=ch1=' ';
  setcolor(13);
  rectangle(119+(50*posx),79+(50*posy),119+50+(50*posx),79+50+(50*posy));
  while (!(ch1==27 || ch1=='\r' || ch2==';'))
  {
    while (!(ch1==27 || ch1=='\r'|| ch2=='H' || ch2=='M' ||ch2=='P' ||
             ch2=='K' || ch2==';'  || ch2=='G' || ch2=='I' || ch2=='O' ||
             ch2=='Q' || ch2=='<'))
    {
      ch1=getch();
      if (ch1==0)
      {
        ch2=getch();
        ch1=' ';
      }
    }
    if (ch2=='H' || ch2=='M' || ch2=='K' || ch2=='P' || ch2=='G' ||
        ch2=='I' || ch2=='O' || ch2=='Q')
    {
      setcolor(15);
      rectangle(119+(50*posx),79+(50*posy),169+(50*posx),129+(50*posy));
      if (ch2=='H' || ch2=='G' || ch2=='I') posy=posy-1;
      if (ch2=='M' || ch2=='I' || ch2=='Q') posx=posx+1;
      if (ch2=='P' || ch2=='O' || ch2=='Q') posy=posy+1;
      if (ch2=='K' || ch2=='G' || ch2=='O') posx=posx-1;
      if (posy==-1) posy=7;
      if (posx==-1) posx=7;
      if (posy==8) posy=0;
      if (posx==8) posx=0;
      setcolor(13);
      rectangle(119+(50*posx),79+(50*posy),169+(50*posx),129+(50*posy));
    }
    if (ch2=='<')
    {
      uso=1;
      if (imp==0) imp=1;
      else imp=0;
    }
    tablita();
    if (ch2!=';') ch2=' ';
  }
  if (ch1=='\r') return 0;
  else
    if (ch1==27) return 1;
    else
      if (ch2==';') return 2;
      else return -1;
}


/*  Genera las posiciones de las bombas y cuenta el n£mero de bombas
    alrededor de cada posici¢n                                        */
void gen_bom(void)
{
  int a,b,c=0;

  for (a=0; a<Y+2; a++)
    for (b=0; b<X+2; b++)
      m1[a][b]=0;
  while (!(c==B))
  {
    a=random(Y)+1;
    b=random(X)+1;
    if (m1[a][b]==0)
    {
      m1[a][b]=1;
      c++;
    }
    for (a=1; a<Y+1; a++)
      for (b=1; b<X+1; b++)
        m2[a-1][b-1]=m1[a-1][b-1]+m1[a-1][b]+m1[a-1][b+1]+m1[a][b-1]+m1[a][b]+
                    m1[a][b+1]+m1[a+1][b-1]+m1[a+1][b]+m1[a+1][b+1];
  }
}


/*  Ejecuta el juego  */
int juego(void)
{
  int exi=0,aux,a,b,c;
  char ch;

  caratula();
  gen_bom();
  while (exi==0)
  {
    aux=mov();
    if (aux==2) return 1;
    if (aux==1) return 2;
    if (m1[posy+1][posx+1]==1)
    {
      lim_cua(4,119+(50*posx),79+(50*posy));
      pon(1);
      car(-1);
      texto("­Lo siento!","PERDISTE",getmaxx()-100,300);
      exi=1;
      ch=getch();
      if (ch==27) exi=2;
      if (ch==0) ch=getch();
    }
    else limpia(posy,posx);
    if (nba == X*Y-B)
    {
      pon(0);
      car(1);
      if (uso==0)  texto("­Felicidades!","GANASTE",getmaxx()-100,300);
      else texto("No uses el mapa,tramposo","GANASTE",getmaxx()-100,295);
      exi=1;
      ch=getch();
      if (ch==27) exi=2;
      if (ch==0) ch=getch();
    }
  }
  return exi;
}


void main()
{
  int sp,i=0;

  randomize();
  sp=ini_g();
  if (sp==0)
  {
    while (i!=2)
    {
      nba=posx=posy=imp=uso=0;
      i=juego();
      cleardevice();
    }
    closegraph();
  }
  else printf("Necesitas un monitor VGA o superior con 16 o m s colores");
}