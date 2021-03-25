/***************************************************/
/*  Victor Hugo Zamora Herrarte                     */
/*  Carn‚: 200010805                                */
/*  Introducci¢n a la programaci¢n y computaci¢n 1  */
/*  Secci¢n: "A"                                    */
/*  Aux.: Alfredo Val‚z                             */
/*                                                  */
/*                   _\\\|///_                      */
/*                   (` o-o ï)                      */
/*                --ooO-(_)-Ooo--                   */
/****************************************************/

#include <graphics.h>  //declaracion de directivas
#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <stdio.h>     //fin de declaraci¢n de directivas

//declaraci¢n de variables globales
int tablero[20][10]; //declaraci¢n de la matriz para el  rea de juego
int marcar[20][10];  //declaraci¢n de la matriz para eliminaci¢n
int bola1,bola2,bola3,cambio;
int i,j;
int nivel,espera;
char nivel1[2];
int contar_rojas,contar_verdes,contar_azules,contar_blancas,contar_amarillas;
char contar_rojas1[4];
char contar_verdes1[4];
char contar_azules1[4];
char contar_blancas1[4];
char contar_amarillas1[4];
unsigned int punteo,puntos_rojas,puntos_verdes,puntos_azules;
unsigned int puntos_blancas,puntos_amarillas;
char puntos_rojas1[5];
char puntos_verdes1[5];
char puntos_azules1[5];
char puntos_blancas1[5];
char puntos_amarillas1[5];
char punteo1[6];
int next1,next2,next3,primeravez;
clock_t start, end;
int gran_total,total_minutos,total_segundos;
char minutos[3];
char segundos[3];
int tecla1,tecla2;
void *area_cubierta;
int elimino=0;
int sonido=1;
int tecleo;
int salida=1;           //fin de declaraci¢n de variables  globales

void limpiar_ventanas();

void inicializar()  //inicializa variables
{
 int b,r;
 punteo=0;
 gran_total=contar_rojas=contar_verdes=contar_azules=0;
 contar_blancas=contar_amarillas=0;
 primeravez=0;
 area_cubierta=0;
 for(b=0;b<20;b++)
    {
     for(r=0;r<10;r++)
	{
	 tablero[b][r]=0;
	}//fin for 2
    }//fin for 1
}//fin de inicializar variables

void inicializar_marcar()   //inicializa la matriz para eliminac¢n
{
 int b,r;
 for(b=0;b<20;b++)
    {
     for(r=0;r<10;r++)
	{
	 marcar[b][r]=0;
	}//fin for 2
    }//fin for 1
}//fin de inicializar matriz para eliminaci¢n

void red(int x, int y)   //procedimiento para dibujar pelota roja
{
 setfillstyle(1,LIGHTRED);
 setcolor(YELLOW);
 fillellipse(x*17+8,y*17+8,8,8);
 setlinestyle(0,0,3);
 line(x*17,y*17+8,x*17+16,y*17+8);
 setlinestyle(0,0,1);
}//fin de procedimiento para dibujar pelota roja

void green(int x, int y) //procedimiento para dibujar pelota verde
{
 setfillstyle(1,LIGHTGREEN);
 setcolor(LIGHTRED);
 fillellipse(x*17+8,y*17+8,8,8);
 line(x*17+8,y*17,x*17+8,y*17+16);
 line(x*17,y*17+8,x*17+16,y*17+8);
 setlinestyle(0,0,1);
}//fin de procedimiento para dibujar pelota verde

void blue(int x, int y)  //procedimiento para dibujar pelota azul
{
 setfillstyle(1,BLUE);
 setcolor(YELLOW);
 fillellipse(x*17+8,y*17+8,8,8);
 arc(x*17+8,y*17+8,0,90,5);
}//fin de procedimiento para dibujar pelota azul

void white(int x, int y)  //procedimiento para dibujar pelota blanca
{
 setfillstyle(1,WHITE);
 setcolor(YELLOW);
 fillellipse(x*17+8,y*17+8,8,8);
 setfillstyle(1,LIGHTBLUE);
 fillellipse(x*17+8,y*17+8,2,2);
 fillellipse(x*17+3,y*17+6,2,2);
 setfillstyle(1,LIGHTGREEN);
 fillellipse(x*17+6,y*17+12,2,2);
 fillellipse(x*17+11,y*17+4,2,2);
 setfillstyle(1,LIGHTRED);
 fillellipse(x*17+5,y*17+3,2,2);
 fillellipse(x*17+11,y*17+11,2,2);
}//fin de procedimiento para dibujar pelota blanca

void yellow(int x, int y)  //procedimiento para dibujar pelota amarilla
{
 setfillstyle(1,YELLOW);
 setcolor(YELLOW);
 fillellipse(x*17+8,y*17+8,8,8);
 setcolor(BLACK);
 circle(x*17+8,y*17+8,7);
 circle(x*17+8,y*17+8,5);
 circle(x*17+8,y*17+8,3);
 circle(x*17+8,y*17+8,1);
}//fin de procedimiento para dibujar pelota amarilla

void destruir(int x, int y, int color) //dibuja una bola negra con rayas
{
 setfillstyle(7,color);
 setcolor(LIGHTGRAY);
 fillellipse(x*17+8,y*17+8,8,8);
}//fin de dibujar una bola negra con rayas

void clear(int x, int y)    //procedimiento que dibuja una pelota negra que
{                           //se utiliza para limpiar la pantalla y coloca un
 setfillstyle(1,BLACK);     //0 en esa posici¢n
 setcolor(BLACK);
 fillellipse(x*17+8,y*17+8,8,8);
 if(x>=0&&y>=0)tablero[y][x]=0;
}//fin de procedimiento que dibuja pelota negra

void presentacion()     //realiza la presentaci¢n al iniciar el programa
{
 int xy,tf,c;
 setviewport(0,0,639,479,1);
 for(xy=10,tf=1;xy<=90,tf<=10;xy=xy+10,tf++)
    {
     setcolor(15);
     settextstyle(GOTHIC_FONT,0,tf);
     outtextxy(xy,xy,"Columns");
     delay(150);
    }//fin for
 for(xy=10,tf=1;xy<=90,tf<=10;xy=xy+10,tf++)
    {
     setcolor(0);
     settextstyle(GOTHIC_FONT,0,tf);
     outtextxy(xy,xy,"Columns");
     delay(100);
    }//fin for
 do
   {
    c=1+random(15);
    setcolor(c);
    settextstyle(GOTHIC_FONT,0,10);
    outtextxy(100,100,"Columns");
    delay(100);
   }while(!kbhit());
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,0,0);
 clearviewport();
}//fin de presentaci¢n

void salir()            //presenta una despedida al terminar el programa
{
 int c;
 setviewport(0,0,639,479,1);
 cleardevice();
 setcolor(WHITE);
 settextstyle(SMALL_FONT,0,8);
 outtextxy(140,220,"Derechos Reservados 2001");
 do
   {
    c=1+random(15);
    setcolor(c);
    settextstyle(GOTHIC_FONT,0,10);
    outtextxy(90,90,"Columns");
    delay(100);
   }while(!kbhit());
}//fin de despedida

void sound()       //Muestra el estado del sonido en pantalla
{
 setviewport(0,0,639,479,1);
 setfillstyle(1,DARKGRAY);
 bar(50,368,225,398);
 settextstyle(TRIPLEX_FONT,0,1);
 if(sonido==1)
   {
    setcolor(LIGHTGREEN);
    outtextxy(55,370,"Sonido Activado");
   }
 if(sonido==0)
   {
    setcolor(LIGHTGRAY);
    outtextxy(55,370,"Sonido Desactivado");
   }
 setviewport(234,69,403,408,1);
}//fin de mostrar estado de sonido

void save_screen(int x, int y, int x1, int y1)//guarda una imagen
{                                             //de la pantalla en la memoria
 int size;
 settextstyle(GOTHIC_FONT,0,0);
 setviewport(0,0,639,479,1);
 size=imagesize(x,y,x1,y1);
 area_cubierta=malloc(size);
 getimage(x,y,x1,y1,area_cubierta);
 setviewport(234,69,403,408,1);
}//fin de guardar imagen

void restore_screen(int x, int y)//restaura la imagen guardada en la memoria
{
 setviewport(0,0,639,479,1);
 putimage(x,y,area_cubierta,COPY_PUT);
 free(area_cubierta);
 area_cubierta=NULL;
 setviewport(234,69,403,408,1);
}//fin de restaurar imagen

void pausa()  //muestra que el juego se encuentra en pausa
{
 int c;
 setviewport(0,0,639,479,1);
 setviewport(238,210,398,260,1);
 setfillstyle(1,BLACK);
 bar(0,0,160,50);
 setcolor(WHITE);
 rectangle(0,0,160,50);
 do
   {
    c=1+random(15);
    setcolor(c);
    settextstyle(SMALL_FONT,0,10);
    outtextxy(25,0,"PAUSA");
    delay(50);
   }while(!kbhit());
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de mostrar pausa

void help()    //muestra la ayuda del programa
{
 int at;
 setviewport(0,0,639,479,1);
 setviewport(219,139,419,339,1);
 setfillstyle(1,BLUE);
 bar(0,0,200,200);              //inicio de primera ventana
 setcolor(WHITE);
 rectangle(0,0,200,200);
 setcolor(YELLOW);
 settextstyle(GOTHIC_FONT,0,6);
 outtextxy(8,10,"Columns");
 settextstyle(GOTHIC_FONT,0,3);
 outtextxy(80,80,"por");
 settextstyle(GOTHIC_FONT,0,4);
 outtextxy(7,125,"Victor Zamora");
 getch();                       //fin de primera ventana
 bar(0,0,200,200);              //inicio de segunda ventana
 setcolor(WHITE);
 rectangle(0,0,200,200);
 setcolor(YELLOW);
 settextstyle(SMALL_FONT,0,4);
 at=1+textheight("H");
 outtextxy(5,5,"La meta es hacer desaparecer las");
 outtextxy(5,5+at,"piezas del mismo tipo alineandolas");
 outtextxy(5,5+2*at,"horizontalmente o verticalmente.");
 outtextxy(5,5+4*at,"Cuando 3 o m s piezas del mismo");
 outtextxy(5,5+5*at,"tipo estan alineadas, estas desa-");
 outtextxy(5,5+6*at,"parecen.");
 outtextxy(5,5+8*at,"La velocidad con que caen las");
 outtextxy(5,5+9*at,"piezas (nivel) incrementa cada");
 outtextxy(5,5+10*at,"1000 puntos.");
 setcolor(LIGHTGREEN);
 outtextxy(5,5+12*at,"Las teclas utilizadas son:");
 setcolor(LIGHTCYAN);
 line(5,2+15*at,15,2+15*at);  //dibuja flecha hacia la izquierda
 line(8,15*at-3,5,2+15*at);
 line(5,2+15*at,8,15*at+7);  //fin de dibuja flecha hacia la izquierda
 line(5,2+16*at,15,2+16*at);  //dibuja flecha hacia la derecha
 line(12,16*at-3,15,2+16*at);
 line(15,2+16*at,12,16*at+7);  //fin de dibuja flecha hacia la derecha
 line(10,17*at-3,10,17*at+7);  //dibuja flecha hacia arriba
 line(5,17*at,10,17*at-3);
 line(10,17*at-3,15,17*at);  //fin de dibuja flecha hacia arriba
 line(10,18*at-3,10,18*at+7);  //dibuja flecha hacia abajo
 line(5,18*at+4,10,18*at+7);
 line(10,18*at+7,15,18*at+4);  //fin de dibuja flecha hacia abajo
 setcolor(YELLOW);
 outtextxy(20,5+14*at,": Izquierda");
 outtextxy(20,5+15*at,": Derecha");
 outtextxy(20,5+16*at,": Rotar");
 outtextxy(20,5+17*at,": Abajo");
 getch();                       //fin de segunda ventana
 bar(0,0,200,200);              //inicio de tercera ventana
 setcolor(WHITE);
 rectangle(0,0,200,200);
 setcolor(LIGHTCYAN);
 outtextxy(5,5,"P");
 outtextxy(5,5+4*at,"F2");
 outtextxy(5,5+9*at,"S");
 outtextxy(5,5+11*at,"Esc");
 setcolor(YELLOW);
 outtextxy(15,5,": Hace una pausa, presiona");
 outtextxy(15,5+1*at,"  cualquier tecla para");
 outtextxy(15,5+2*at,"  continuar.");
 outtextxy(19,5+4*at,": Inicia un juego nuevo, si no");
 outtextxy(19,5+5*at,"  hay otro activo. Si hay un");
 outtextxy(19,5+6*at,"  juego acitivo lo termina y");
 outtextxy(19,5+7*at,"  muestra los resultados.");
 outtextxy(15,5+9*at,": Activa\\Desactiva el sonido");
 outtextxy(25,5+11*at,": Termina el programa.");
 outtextxy(27,5+17*at,"Derechos Reservados 2001");
 outtextxy(73,5+14*at,"_\\\\\\|///_"); //dibuja la carita
 setcolor(LIGHTCYAN);
 outtextxy(72,5+15*at,"(  o-o  )");
 outtextxy(60,5+16*at,"--ooO(_)Ooo--");  //termina de dibuja carita
 getch();                       //fin de tercera ventana
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de mostrar ayuda en pantalla

void seguridad()  //pregunta si se desesa salir del programa al presinar Esc
{
 int salida3=1;
 setviewport(0,0,639,479,1);
 setviewport(238,210,398,260,1);
 setfillstyle(1,BLACK);
 bar(0,0,160,50);
 setcolor(WHITE);
 rectangle(0,0,160,50);
 settextstyle(SMALL_FONT,0,5);
 outtextxy(40,5,"Desea salir?");
 outtextxy(10,23,"Si: Enter   No: Esc");
 do
   {
    tecla1=getch();
    switch(tecla1)
	  {
	   case 13: salir();       //sale del programa
		    closegraph();
		    exit(1);
		    break;
	   case 27: salida3=0;     //continua el programa
		    break;
	  }//fin switch
   }while(salida3!=0);
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de pregunta si desea salir

void resultados()   //muestra los resultados despu‚s de finalizar un juego
{
 int at;
 int salida1=1;
 setviewport(0,0,639,479,1);
 setviewport(219,129,419,349,1);
 clearviewport();
 setcolor(WHITE);
 rectangle(0,0,200,220);
 setcolor(LIGHTRED);
 settextstyle(SMALL_FONT,0,5);
 at=1+textheight("H");
 outtextxy(60,5,"RESULTADOS");
 setcolor(WHITE);
 //calculos para bola roja
 puntos_rojas=10*contar_rojas;
 itoa(contar_rojas,contar_rojas1,10);
 itoa(puntos_rojas,puntos_rojas1,10);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 outtextxy(44,8+2*at,contar_rojas1);
 outtextxy(156,8+2*at,puntos_rojas1);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(50,7+2*at,"x");
 outtextxy(98,8+2*at,"=");
 outtextxy(160,8+2*at,"pts.");
 //fin calculos para bola roja
 //calculos para bola verde
 puntos_verdes=10*contar_verdes;
 itoa(contar_verdes,contar_verdes1,10);
 itoa(puntos_verdes,puntos_verdes1,10);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 outtextxy(44,12+3*at,contar_verdes1);
 outtextxy(156,12+3*at,puntos_verdes1);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(50,11+3*at,"x");
 outtextxy(98,12+3*at,"=");
 outtextxy(160,12+3*at,"pts.");
 //fin calculos para bola verde
 //calculos para bola azul
 puntos_azules=10*contar_azules;
 itoa(contar_azules,contar_azules1,10);
 itoa(puntos_azules,puntos_azules1,10);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 outtextxy(44,16+4*at,contar_azules1);
 outtextxy(156,16+4*at,puntos_azules1);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(50,15+4*at,"x");
 outtextxy(98,16+4*at,"=");
 outtextxy(160,16+4*at,"pts.");
 //fin calculos para bola azul
 //calculos para bola blanca
 puntos_blancas=10*contar_blancas;
 itoa(contar_blancas,contar_blancas1,10);
 itoa(puntos_blancas,puntos_blancas1,10);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 outtextxy(44,20+5*at,contar_blancas1);
 outtextxy(156,20+5*at,puntos_blancas1);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(50,19+5*at,"x");
 outtextxy(98,20+5*at,"=");
 outtextxy(160,20+5*at,"pts.");
 //fin calculos para bola blanca
 //calculos para bola amarilla
 puntos_amarillas=10*contar_amarillas;
 itoa(contar_amarillas,contar_amarillas1,10);
 itoa(puntos_amarillas,puntos_amarillas1,10);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 outtextxy(44,24+6*at,contar_amarillas1);
 outtextxy(156,24+6*at,puntos_amarillas1);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(50,23+6*at,"x");
 outtextxy(98,24+6*at,"=");
 outtextxy(160,24+6*at,"pts.");
 //fin calculos para bola amarilla
 setcolor(YELLOW);
 line(115,27+7*at,184,27+7*at);
 setcolor(LIGHTRED);
 outtextxy(52,29+7*at,"TOTAL");
 outtextxy(98,28+7*at,"=");
 itoa(punteo,punteo1,10);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 outtextxy(156,29+7*at,punteo1);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(160,29+7*at,"pts.");
 outtextxy(20,25+9*at,"Tiempo jugado:");
 setcolor(WHITE);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 itoa(total_minutos,minutos,10);
 outtextxy(36,25+10*at,minutos);
 itoa(total_segundos,segundos,10);
 outtextxy(120,25+10*at,segundos);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 outtextxy(44,25+10*at,"minutos");
 outtextxy(128,25+10*at,"segundos");
 setcolor(LIGHTGREEN);
 outtextxy(20,25+12*at,"Enter: Continuar");
 outtextxy(20,25+13*at,"Esc: Salir");
 red(4,2);
 green(4,3);
 blue(4,4);
 white(4,5);
 yellow(4,6);
 do
   {
    tecla1=getch();
    switch(tecla1)
	  {
	   case 27: salir();       //sale del programa
		    closegraph();
		    exit(1);
		    break;
	   case 13: salida1=0;     //continua el programa
		    break;
	  }//fin switch
   }while(salida1!=0);
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
 limpiar_ventanas();
}//fin de mostrar resultados

void cheat()               //muestra un men£ que ayuda a hacer trampa
{
 int at;
 int salida2=1;
 setviewport(0,0,639,479,1);
 setviewport(19,139,219,339,1);
 clearviewport();
 setcolor(WHITE);
 rectangle(0,0,200,200);
 setcolor(LIGHTRED);
 settextstyle(SMALL_FONT,0,4);
 at=1+textheight("H");
 outtextxy(60,5,"CHEAT MENU");
 setcolor(WHITE);
 outtextxy(10,2*at,"Esta opci¢n permite cambiar los");
 outtextxy(10,3*at,"colores de las bolas que van");
 outtextxy(10,4*at,"cayendo. Seleccione el n£mero");
 outtextxy(10,5*at,"que corresponde.");
 outtextxy(10,7*at,"1 =");
 outtextxy(80,7*at,"2 =");
 outtextxy(148,7*at,"3 =");
 outtextxy(45,4+10*at,"4 =");
 outtextxy(111,4+10*at,"5 =");
 red(2,4);
 green(6,4);
 blue(10,4);
 white(4,6);
 yellow(8,6);
 setcolor(WHITE);
 outtextxy(10,37+10*at,"Color de la primera bola:");
 do
   {
    tecla1=getch();
    switch(tecla1)
	  {
	   case 49: red(10,8);
		    bola3=1;
		    salida2=0;
		    break;
	   case 50: green(10,8);
		    bola3=2;
		    salida2=0;
		    break;
	   case 51: blue(10,8);
		    bola3=3;
		    salida2=0;
		    break;
	   case 52: white(10,8);
		    bola3=4;
		    salida2=0;
		    break;
	   case 53: yellow(10,8);
		    bola3=5;
		    salida2=0;
		    break;
	   }//fin switch
   }while(salida2!=0);
 setcolor(WHITE);
 outtextxy(10,25+13*at,"Color de la segunda bola:");
 salida2=1;
 do
   {
    tecla1=getch();
    switch(tecla1)
	  {
	   case 49: red(10,9);
		    bola2=1;
		    salida2=0;
		    break;
	   case 50: green(10,9);
		    bola2=2;
		    salida2=0;
		    break;
	   case 51: blue(10,9);
		    bola2=3;
		    salida2=0;
		    break;
	   case 52: white(10,9);
		    bola2=4;
		    salida2=0;
		    break;
	   case 53: yellow(10,9);
		    bola2=5;
		    salida2=0;
		    break;
	  }//fin switch
   }while(salida2!=0);
 setcolor(WHITE);
 outtextxy(10,2+17*at,"Color de la tercera bola:");
 salida2=1;
 do
   {
    tecla1=getch();
    switch(tecla1)
	  {
	   case 49: red(10,10);
		    bola1=1;
		    salida2=0;
		    break;
	   case 50: green(10,10);
		    bola1=2;
		    salida2=0;
		    break;
	   case 51: blue(10,10);
		    bola1=3;
		    salida2=0;
		    break;
	   case 52: white(10,10);
		    bola1=4;
		    salida2=0;
		    break;
	   case 53: yellow(10,10);
		    bola1=5;
		    salida2=0;
		    break;
	  }//fin switch
   }while(salida2!=0);
 getche();
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de men£ que ayuda a hacer trampa

void nextpiece()  //dibuja una vista preliminar de la columna siguiente
{
 setviewport(0,0,639,479,1);
 setviewport(159,204,175,254,1);
 if(next1==1) red(0,2);
 if(next1==2) green(0,2);
 if(next1==3) blue(0,2);
 if(next1==4) white(0,2);
 if(next1==5) yellow(0,2);
 if(next2==1) red(0,1);
 if(next2==2) green(0,1);
 if(next2==3) blue(0,1);
 if(next2==4) white(0,1);
 if(next2==5) yellow(0,1);
 if(next3==1) red(0,0);
 if(next3==2) green(0,0);
 if(next3==3) blue(0,0);
 if(next3==4) white(0,0);
 if(next3==5) yellow(0,0);
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de dibujar vista preliminar

void time_o() //toma el tiempo al comenzar un juego
{
 start=clock();
}//fin de toma tiempo al comenzar un juego

void time_f() //toma el tiempo al finalizar un juego
{
 end = clock();
 gran_total=gran_total+(end - start)/CLK_TCK;
 total_minutos=gran_total/60;
 total_segundos=gran_total%60;
}//fin de toma tiempo al finalizar un juego

void score()  //lleva un registro de los puntos acumulados
{
 setviewport(0,0,639,479,1);
 setviewport(135,116,197,137,1);
 clearviewport();
 setcolor(LIGHTRED);
 settextstyle(TRIPLEX_FONT,0,1);
 settextjustify(RIGHT_TEXT,TOP_TEXT);
 punteo=10*contar_rojas+10*contar_verdes+10*contar_azules+
		    10*contar_blancas+10*contar_amarillas;
 itoa(punteo,punteo1,10);
 outtextxy(65,0,punteo1);
 settextjustify(LEFT_TEXT,TOP_TEXT);
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de registro de puntos acumulados

void level()      //muestra y cambia el nivel de dificultad
{
 setviewport(0,0,639,479,1);
 setviewport(159,316,175,337,1);
 clearviewport();
 setcolor(LIGHTCYAN);
 settextstyle(TRIPLEX_FONT,0,1);
 if(punteo<1000) {nivel=0;espera=550;}
 if(punteo>=1000&&punteo<2000) {nivel=1;espera=500;}
 if(punteo>=2000&&punteo<3000) {nivel=2;espera=450;}
 if(punteo>=3000&&punteo<4000) {nivel=3;espera=400;}
 if(punteo>=4000&&punteo<5000) {nivel=4;espera=350;}
 if(punteo>=5000&&punteo<6000) {nivel=5;espera=300;}
 if(punteo>=6000&&punteo<7000) {nivel=6;espera=250;}
 if(punteo>=7000&&punteo<8000) {nivel=7;espera=200;}
 if(punteo>=8000&&punteo<9000) {nivel=8;espera=150;}
 if(punteo>=9000) {nivel=9;espera=100;}
 itoa(nivel,nivel1,10);
 outtextxy(4,0,nivel1);
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de muestra y cambia nivel de dificultad

void limpiar_ventanas()  //borra la ventana de punteo, siguiente y nivel
{
 contar_rojas=contar_verdes=contar_azules=contar_blancas=contar_amarillas=0;
 nivel=0;
 score();
 level();
 setviewport(0,0,639,479,1);
 setviewport(159,204,175,254,1);
 clearviewport();
 setviewport(0,0,639,479,1);
 setviewport(234,69,403,408,1);
}//fin de borrar ventanas

void llenar_tablero()     //llena el  rea de juego con bolas aleatorias
{
 int k;
 for(i=19;i>=0;i--)
    {
     for(j=9;j>=0;j--)
	{
	 k=1+random(5);
	 if(k==1) blue(j,i);
	 if(k==2) red(j,i);
	 if(k==3) green(j,i);
	 if(k==4) white(j,i);
	 if(k==5) yellow(j,i);
	 tablero[i][j]=k;
	 delay(2);
	}//fin for 2
    }//fin for 1
}//fin de llenar tablero

void verificar_eliminar() //procedimiento que verifica cuales bolas
{                         //son iguales y las elimina
 inicializar_marcar();
 //inicia ciclo que revisa fila por fila
 for(i=19;i>=0;i--)
    {
     for(j=0;j<=7;j++)
	{
	 if(tablero[i][j]!=0)
		{
		 if(tablero[i][j]==tablero[i][j+1]&&tablero[i][j]==tablero[i][j+2]
		    &&tablero[i][j]==1)
		   {
		    destruir(j,i,LIGHTRED);
		    destruir(j+1,i,LIGHTRED);
		    destruir(j+2,i,LIGHTRED);
		    marcar[i][j]=1;
		    marcar[i][j+1]=1;
		    marcar[i][j+2]=1;
		    elimino=1;
		   }
		 if(tablero[i][j]==tablero[i][j+1]&&tablero[i][j]==tablero[i][j+2]
		    &&tablero[i][j]==2)
		   {
		    destruir(j,i,LIGHTGREEN);
		    destruir(j+1,i,LIGHTGREEN);
		    destruir(j+2,i,LIGHTGREEN);
		    marcar[i][j]=2;
		    marcar[i][j+1]=2;
		    marcar[i][j+2]=2;
		    elimino=1;
		   }
		 if(tablero[i][j]==tablero[i][j+1]&&tablero[i][j]==tablero[i][j+2]
		    &&tablero[i][j]==3)
		   {
		    destruir(j,i,LIGHTBLUE);
		    destruir(j+1,i,LIGHTBLUE);
		    destruir(j+2,i,LIGHTBLUE);
		    marcar[i][j]=3;
		    marcar[i][j+1]=3;
		    marcar[i][j+2]=3;
		    elimino=1;
		   }
		 if(tablero[i][j]==tablero[i][j+1]&&tablero[i][j]==tablero[i][j+2]
		    &&tablero[i][j]==4)
		   {
		    destruir(j,i,WHITE);
		    destruir(j+1,i,WHITE);
		    destruir(j+2,i,WHITE);
		    marcar[i][j]=4;
		    marcar[i][j+1]=4;
		    marcar[i][j+2]=4;
		    elimino=1;
		   }
		 if(tablero[i][j]==tablero[i][j+1]&&tablero[i][j]==tablero[i][j+2]
		    &&tablero[i][j]==5)
		   {
		    destruir(j,i,YELLOW);
		    destruir(j+1,i,YELLOW);
		    destruir(j+2,i,YELLOW);
		    marcar[i][j]=5;
		    marcar[i][j+1]=5;
		    marcar[i][j+2]=5;
		    elimino=1;
		   }
		}//fin if no anidado
	}//fin for 2
    }//fin for 1
 //finaliza ciclo que revisa fila por fila
 //inicia ciclo que revisa columna por columna
 for(j=0;j<=9;j++)
    {
     for(i=0;i<=17;i++)
	{
	 if(tablero[i][j]!=0)
	   {
	    if(tablero[i][j]==tablero[i+1][j]&&tablero[i][j]==tablero[i+2][j]
	       &&tablero[i][j]==1)
	      {
	       destruir(j,i,LIGHTRED);
	       destruir(j,i+1,LIGHTRED);
	       destruir(j,i+2,LIGHTRED);
	       marcar[i][j]=1;
	       marcar[i+1][j]=1;
	       marcar[i+2][j]=1;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i+1][j]&&tablero[i][j]==tablero[i+2][j]
	       &&tablero[i][j]==2)
	      {
	       destruir(j,i,LIGHTGREEN);
	       destruir(j,i+1,LIGHTGREEN);
	       destruir(j,i+2,LIGHTGREEN);
	       marcar[i][j]=2;
	       marcar[i+1][j]=2;
	       marcar[i+2][j]=2;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i+1][j]&&tablero[i][j]==tablero[i+2][j]
	       &&tablero[i][j]==3)
	      {
	       destruir(j,i,LIGHTBLUE);
	       destruir(j,i+1,LIGHTBLUE);
	       destruir(j,i+2,LIGHTBLUE);
	       marcar[i][j]=3;
	       marcar[i+1][j]=3;
	       marcar[i+2][j]=3;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i+1][j]&&tablero[i][j]==tablero[i+2][j]
	       &&tablero[i][j]==4)
	      {
	       destruir(j,i,WHITE);
	       destruir(j,i+1,WHITE);
	       destruir(j,i+2,WHITE);
	       marcar[i][j]=4;
	       marcar[i+1][j]=4;
	       marcar[i+2][j]=4;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i+1][j]&&tablero[i][j]==tablero[i+2][j]
	       &&tablero[i][j]==5)
	      {
	       destruir(j,i,YELLOW);
	       destruir(j,i+1,YELLOW);
	       destruir(j,i+2,YELLOW);
	       marcar[i][j]=5;
	       marcar[i+1][j]=5;
	       marcar[i+2][j]=5;
	       elimino=1;
	      }
	   }//fin if no anidado
	}//fin for 2
    }//fin for 1
 //finaliza ciclo que revisa columna por columna
 //inicia ciclo que revisa diagonales de izquierda a derecha
 for(i=19;i>=2;i--)
    {
     for(j=0;j<=7;j++)
	{
	 if(tablero[i][j]!=0)
	   {
	    if(tablero[i][j]==tablero[i-1][j+1]&&tablero[i][j]==tablero[i-2][j+2]
	       &&tablero[i][j]==1)
	      {
	       destruir(j,i,LIGHTRED);
	       destruir(j+1,i-1,LIGHTRED);
	       destruir(j+2,i-2,LIGHTRED);
	       marcar[i][j]=1;
	       marcar[i-1][j+1]=1;
	       marcar[i-2][j+2]=1;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j+1]&&tablero[i][j]==tablero[i-2][j+2]
	       &&tablero[i][j]==2)
	      {
	       destruir(j,i,LIGHTGREEN);
	       destruir(j+1,i-1,LIGHTGREEN);
	       destruir(j+2,i-2,LIGHTGREEN);
	       marcar[i][j]=2;
	       marcar[i-1][j+1]=2;
	       marcar[i-2][j+2]=2;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j+1]&&tablero[i][j]==tablero[i-2][j+2]
	       &&tablero[i][j]==3)
	      {
	       destruir(j,i,LIGHTBLUE);
	       destruir(j+1,i-1,LIGHTBLUE);
	       destruir(j+2,i-2,LIGHTBLUE);
	       marcar[i][j]=3;
	       marcar[i-1][j+1]=3;
	       marcar[i-2][j+2]=3;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j+1]&&tablero[i][j]==tablero[i-2][j+2]
	       &&tablero[i][j]==4)
	      {
	       destruir(j,i,WHITE);
	       destruir(j+1,i-1,WHITE);
	       destruir(j+2,i-2,WHITE);
	       marcar[i][j]=4;
	       marcar[i-1][j+1]=4;
	       marcar[i-2][j+2]=4;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j+1]&&tablero[i][j]==tablero[i-2][j+2]
	       &&tablero[i][j]==5)
	      {
	       destruir(j,i,YELLOW);
	       destruir(j+1,i-1,YELLOW);
	       destruir(j+2,i-2,YELLOW);
	       marcar[i][j]=5;
	       marcar[i-1][j+1]=5;
	       marcar[i-2][j+2]=5;
	       elimino=1;
	      }
	   }//fin if no anidado
	}//fin for 2
    }//fin for 1
 //finaliza ciclo que revisa diagonales de izquierda a derecha
 //inicia ciclo que revisa diagonales de derecha a izquierda
 for(i=19;i>=2;i--)
    {
     for(j=9;j>=2;j--)
	{
	 if(tablero[i][j]!=0)
	   {
	    if(tablero[i][j]==tablero[i-1][j-1]&&tablero[i][j]==tablero[i-2][j-2]
	       &&tablero[i][j]==1)
	      {
	       destruir(j,i,LIGHTRED);
	       destruir(j-1,i-1,LIGHTRED);
	       destruir(j-2,i-2,LIGHTRED);
	       marcar[i][j]=1;
	       marcar[i-1][j-1]=1;
	       marcar[i-2][j-2]=1;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j-1]&&tablero[i][j]==tablero[i-2][j-2]
	       &&tablero[i][j]==2)
	      {
	       destruir(j,i,LIGHTGREEN);
	       destruir(j-1,i-1,LIGHTGREEN);
	       destruir(j-2,i-2,LIGHTGREEN);
	       marcar[i][j]=2;
	       marcar[i-1][j-1]=2;
	       marcar[i-2][j-2]=2;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j-1]&&tablero[i][j]==tablero[i-2][j-2]
	       &&tablero[i][j]==3)
	      {
	       destruir(j,i,LIGHTBLUE);
	       destruir(j-1,i-1,LIGHTBLUE);
	       destruir(j-2,i-2,LIGHTBLUE);
	       marcar[i][j]=3;
	       marcar[i-1][j-1]=3;
	       marcar[i-2][j-2]=3;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j-1]&&tablero[i][j]==tablero[i-2][j-2]
	       &&tablero[i][j]==4)
	      {
	       destruir(j,i,WHITE);
	       destruir(j-1,i-1,WHITE);
	       destruir(j-2,i-2,WHITE);
	       marcar[i][j]=4;
	       marcar[i-1][j-1]=4;
	       marcar[i-2][j-2]=4;
	       elimino=1;
	      }
	    if(tablero[i][j]==tablero[i-1][j-1]&&tablero[i][j]==tablero[i-2][j-2]
	       &&tablero[i][j]==5)
	      {
	       destruir(j,i,YELLOW);
	       destruir(j-1,i-1,YELLOW);
	       destruir(j-2,i-2,YELLOW);
	       marcar[i][j]=5;
	       marcar[i-1][j-1]=5;
	       marcar[i-2][j-2]=5;
	       elimino=1;
	      }
	   }//fin if no anidado
	}//fin for 2
    }//fin for 1
 //finaliza ciclo que revisa diagonales de derecha a izquierda
 //inicia ciclo que revisa cada celda de la matriz para eliminar
 for(i=0;i<=19;i++)
    {
     for(j=0;j<=9;j++)
	{
	 if(marcar[i][j]==1)
	   {
	    delay(85);
	    clear(j,i);
	    contar_rojas++;
	    score();
	   }
	 if(marcar[i][j]==2)
	   {
	    delay(85);
	    clear(j,i);
	    contar_verdes++;
	    score();
	   }
	 if(marcar[i][j]==3)
	   {
	    delay(85);
	    clear(j,i);
	    contar_azules++;
	    score();
	   }
	 if(marcar[i][j]==4)
	   {
	    delay(85);
	    clear(j,i);
	    contar_blancas++;
	    score();
	   }
	 if(marcar[i][j]==5)
	   {
	    delay(85);
	    clear(j,i);
	    contar_amarillas++;
	    score();
	   }
	}//fin for 2
    }//fin for 1
 if(elimino==1&&sonido==1)
   {
    sound(200);
    delay(50);
    sound(300);
    delay(50);
    nosound();
   }
}//fin de procedimiento verificar y eliminar

void bajar_bolas() //procedimiento que baja las bolas despu‚s de eliminar
{
 int k,seguir=0;
 for(i=0;i<=19;i++)
    {
     for(j=0;j<=9;j++)
	{
	 if(tablero[i][j]!=0)
	   {
	    seguir=1;
	   }
	 if(tablero[i][j]==0 && seguir==1)
	   {
	    for(k=i;k>0;k--)
	       {
		tablero[k][j]=tablero[k-1][j];
		if(tablero[k][j]==1) red(j,k);
		if(tablero[k][j]==2) green(j,k);
		if(tablero[k][j]==3) blue(j,k);
		if(tablero[k][j]==4) white(j,k);
		if(tablero[k][j]==5) yellow(j,k);
		if(tablero[k][j]==0) clear(j,k);
	       }
	    clear(j,0);
	   }//fin if
	}//fin for 2
    }//fin for 1
 elimino=0;
}//fin de bajar bolas

void mover()      //lee una tecla y realiza la accion indicada
{
 tecla1=getch();
 if(tecla1==0)
   {
    tecla2=getch();
    switch(tecla2)
	  {
	   case 75: if(j>0&&tablero[i][j-1]==0)//mueve hacia la izquierda
		      {
		       j=j-1;
		       if(i>2&&tecleo==1)
			 {
			  i--;
			 }
		       if(bola1==1) red(j,i);
		       if(bola1==2) green(j,i);
		       if(bola1==3) blue(j,i);
		       if(bola1==4) white(j,i);
		       if(bola1==5) yellow(j,i);
		       if(bola2==1) red(j,i-1);
		       if(bola2==2) green(j,i-1);
		       if(bola2==3) blue(j,i-1);
		       if(bola2==4) white(j,i-1);
		       if(bola2==5) yellow(j,i-1);
		       if(bola3==1) red(j,i-2);
		       if(bola3==2) green(j,i-2);
		       if(bola3==3) blue(j,i-2);
		       if(bola3==4) white(j,i-2);
		       if(bola3==5) yellow(j,i-2);
		       clear(j,i-3);
		       clear(j+1,i);
		       clear(j+1,i-1);
		       clear(j+1,i-2);
		       tecleo=0;
		       delay(150);
		      }
		    break;
	   case 77: if(j<9&&tablero[i][j+1]==0)  //mueve hacia la derecha
		      {
		       j=j+1;
		       if(i>2&&tecleo==1)
			 {
			  i--;
			 }
		       if(bola1==1) red(j,i);
		       if(bola1==2) green(j,i);
		       if(bola1==3) blue(j,i);
		       if(bola1==4) white(j,i);
		       if(bola1==5) yellow(j,i);
		       if(bola2==1) red(j,i-1);
		       if(bola2==2) green(j,i-1);
		       if(bola2==3) blue(j,i-1);
		       if(bola2==4) white(j,i-1);
		       if(bola2==5) yellow(j,i-1);
		       if(bola3==1) red(j,i-2);
		       if(bola3==2) green(j,i-2);
		       if(bola3==3) blue(j,i-2);
		       if(bola3==4) white(j,i-2);
		       if(bola3==5) yellow(j,i-2);
		       clear(j,i-3);
		       clear(j-1,i);
		       clear(j-1,i-1);
		       clear(j-1,i-2);
		       tecleo=0;
		       delay(150);
		      }
		    break;
	   case 72: cambio=bola1;	//rota las figuras (cursor hacia arriba)
		    bola1=bola3;
		    bola3=bola2;
		    bola2=cambio;
		    break;
	   case 80: espera=50;	//mueve la columna mas rapido hacia abajo
		    break;
	   case 59: time_f();  //muestra ayuda en pantalla
		    save_screen(219,139,419,339);
		    help();
		    restore_screen(219,139);
		    time_o();
		    break;
	   case 60: for(i=19;i>=0;i--)   //termina el juego
			for(j=9;j>=0;j--)
			   {
			    tablero[i][j]=10;
			   }
		    break;
	  }//fin switch
   }//fin if
 else
     {
      switch(tecla1)
	    {
	     case 27: time_f();            //sale del programa
		      save_screen(238,210,398,260);
		      seguridad();
		      restore_screen(238,210);
		      time_o();
		      break;
	     case 112:
	     case 80: time_f();      //hace una pausa en el programa
		      save_screen(238,210,398,260);
		      pausa();
		      restore_screen(238,210);
		      time_o();
		      break;
	     case 115:               //activa\desactvia el sonido
	     case 83: if(sonido==1)
			{
			 sonido=0;
			 sound();
			 break;
			}
		      if(sonido==0)
			{
			 sonido=1;
			 sound();
			 break;
			}
	     case 116:
	     case 84: time_f();            //muestra menu para hacer trampa
		      save_screen(19,139,219,339);
		      cheat();
		      restore_screen(19,139);
		      time_o();
		      break;
	    }
     }
}//fin de lee tecla

void columnas()      //dibuja y mueve las columnas
{
 while(tablero[2][4]==0)
      {
       i=2;
       j=4;
       level();
       while(primeravez<1)
	    {
	     bola1=1+random(5);
	     bola2=1+random(5);
	     bola3=1+random(5);
	     primeravez++;
	    }
       next1=1+random(5);
       next2=1+random(5);
       next3=1+random(5);
       nextpiece();
       while(i<=19&&tablero[i][j]==0)
	    {
	     if(kbhit())
	       {
		mover();
	       }
	     else
		 {
		  tecleo=1;
		  tablero[i][j]=bola1;
		  if(bola1==1) red(j,i);
		  if(bola1==2) green(j,i);
		  if(bola1==3) blue(j,i);
		  if(bola1==4) white(j,i);
		  if(bola1==5) yellow(j,i);
		  tablero[i-1][j]=bola2;
		  if(bola2==1) red(j,i-1);
		  if(bola2==2) green(j,i-1);
		  if(bola2==3) blue(j,i-1);
		  if(bola2==4) white(j,i-1);
		  if(bola2==5) yellow(j,i-1);
		  tablero[i-2][j]=bola3;
		  if(bola3==1) red(j,i-2);
		  if(bola3==2) green(j,i-2);
		  if(bola3==3) blue(j,i-2);
		  if(bola3==4) white(j,i-2);
		  if(bola3==5) yellow(j,i-2);
		  clear(j,i-3);
		  delay(espera);
		  i++;
		 }
	    }
       verificar_eliminar();
       while(elimino==1)
	    {
	     bajar_bolas();
	     verificar_eliminar();
	    }
       bola1=next1;
       bola2=next2;
       bola3=next3;
      }
}//fin de dibuja y mueve las columanas

void inicio()   //men£ principal del juego
{
do
{
 tecla1=getch();
 if(tecla1==0)
   {
    tecla2=getch();
    switch(tecla2)
	{
	 case 60: clearviewport();  //inicia un juego nuevo
		  inicializar();
		  time_o();
		  columnas();
		  time_f();
		  llenar_tablero();
		  save_screen(219,129,419,349);
		  resultados();
		  restore_screen(219,129);
		  clearviewport();
		  break;
	 case 59: save_screen(219,139,419,339);// muestra ayuda en pantalla
		  help();
		  restore_screen(219,139);
		  break;
		}//fin switch
	}//fin if
 else
     {
 switch(tecla1)
		 {
	case 27: save_screen(238,210,398,260); //sale del programa
		 seguridad();
		 restore_screen(238,210);
		 break;
	case 115:               //activa\desactvia el sonido
	case 83: if(sonido==1)
		   {
		    sonido=0;
		    sound();
		    break;
		   }
		 if(sonido==0)
		   {
		    sonido=1;
		    sound();
		    break;
		   }
		 }//fin switch
      }
}while(salida!=0);
}//fin de men£ principal

void main(void) //cuerpo principal del programa
{
 int gdriver = DETECT, gmode; //inicializa el modo grafico
 initgraph(&gdriver, &gmode, ""); //fin de inicializar m.g.
 randomize();
 presentacion();             //muestra presentaci¢n del juego
 setviewport(0,0,639,479,1);
 setfillstyle(SOLID_FILL,DARKGRAY);
 rectangle(232,67,405,410);   //limita el area de juego
 rectangle(133,114,199,139);  //limita el area de punteo
 rectangle(157,202,177,256);  //limita el area de sig. pieza
 rectangle(157,314,177,339);  //limita el area de nivel
 floodfill(1,1,WHITE);
 setcolor(LIGHTGRAY);
 setlinestyle(0,1,3);
 rectangle(1,1,638,478);      //dibuja el recuadro del margen de la pantalla
 rectangle(232,67,405,410);   //dibuja el recuadro del area de juego
 rectangle(133,114,199,139);  //dibuja el recuadro del area de punteo
 rectangle(157,202,177,256);  //dibuja el recuadro del area de sig. pieza
 rectangle(157,314,177,339);  //dibuja el recuadro del area de nivel
 setlinestyle(0,1,0);
 setcolor(LIGHTBLUE);                //dibuja la carita
 outtextxy(280,32,"_\\\\\\|///_");
 setcolor(LIGHTCYAN);
 outtextxy(281,46,"(  o-o  )");
 outtextxy(264,60,"--ooO(_)Ooo--");  //termina de dibuja carita
 setlinestyle(0,1,3);         //dibujar los botones
 for(int m=75,n=9,p=1;m<=398,n<=12,p<=4;m=m+100,n++,p++)
    {
     setfillstyle(1,n);
     setcolor(p);
     bar3d(425,m,480,m+30,3,1);
    }
 setcolor(BLACK);
 settextstyle(TRIPLEX_FONT,0,1);
 outtextxy(443,77,"F2");
 outtextxy(448,177,"P");
 outtextxy(443,277,"F1");
 outtextxy(439,377,"Esc");    //fin de dibuja botones
 setlinestyle(0,1,0);
 setcolor(YELLOW);                //escribe descripciones
 outtextxy(490,75,"Juego Nuevo");
 outtextxy(490,175,"Pausa");
 outtextxy(490,275,"Ayuda");
 outtextxy(490,375,"Salir");
 setcolor(LIGHTGREEN);
 outtextxy(55,115,"Punteo");
 outtextxy(55,215,"Siguiente");
 outtextxy(55,315,"Nivel");       //fin de escribir descripciones
 setcolor(WHITE);
 settextstyle(GOTHIC_FONT,0,7);
 outtextxy(199,400,"Columns");
 settextstyle(TRIPLEX_FONT,0,1);
 setviewport(234,69,403,408,1);
 score();
 level();
 sound();
 inicio();
 closegraph();
}//fin del programa