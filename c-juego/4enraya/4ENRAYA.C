/*nota: la configuracion de MS-DOS "mode co80, 50" es decir 80col x 50filas*/
/*                                            */
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
/*variables*/
int x=5; /*>5 >min 2 coordenadas de la esquina inferior izquierda del tablero*/
int y=45;/*>45>min 43*/
int ganador; /*1-2 indica quien comienza la partida marca el turno empieza con 1*/
int record1,record2;/*contador de partidas ganadas*/
int turno;/*1-2 indica el turno del jugador*/
int tabla [9][8];/*TABLA POSICION[012] 1-fichas(1),2-fichas(2)oCPU,0-vacio*/
int tabla2[9][8];/*TABLA LINEAS  [012] 1-fichas(1),2-fichas(2)oCPU,0-vacio*/
int cache[200];  /*TABLA CACHE contiene las posiciones de cada partida (cache[0]=1,2 (jugador que empieza)*/
char posicion;/*contiene la posicion de la jugada[1-7,Esc]*/
int modo;/*[1234]1-continuar,2-empezar,3-nuevo,4-salir*/
int sw=0;/*[0-1]marca si alguien ha ganado 0-no victoria 1-victoria*/
int num_jugadores;
int num_jugadas;/*numero total de jugadas por partida(se utiliza para la cache*/
int color1=7,color2=5;/*contiene el numero de color de cada jugador*/
int fondop=1,textop=7;/*contiene el numero de color del fondo y texto de pantalla*/
char jugador1[20]={"Jugador 1"},jugador2[20]={"Jugador 2"};/*contiene el nombre de cada jugador*/
int pos=4;/*posicion del cursor por defecto*/
int i,j,var;
struct datos {char jugador1[20],jugador2[20];int color1,color2,textop,fondop,ganador;};/*datos que se guardan/abren*/

/*funciones*/
void intro();
int  jugadores();
void opciones();
void fondo();
void mostrar();
void marcador();
char tecla();
void deshacer();
char IA();
void validar();
void comprobar();
void error1();
void error2();
void salir();
void cargar();
void guardar();

FILE *archivo;
/*-------------------------*/
main()
{
 cargar();
 NUEVO:
 intro();/*mostramos pantalla de presentacion*/
 num_jugadores=jugadores();/*seleccionamos modo de juego 1 o 2 jugadores*/

 clrscr();/*comienza el juego*/
 ganador=1;/*por defecto empieza el primer jugador*/
 record1=-1;record2=0;/*iniciamos contadores de victorias*/
 do/*a partir de aqui se puede continuar la partida*/
 {
  modo=0;
  if (ganador==1){record1++;turno=1;}
  if (ganador==2){record2++;turno=2;}
  EMPEZAR:
  pos=4;/*posicion del cursor por defecto*/
  num_jugadas=0;/*inicializa la cache[num_jugadas] a 0*/
  /*rellena las tablas a 0*/for(i=0;i<9;i++){for(j=0;j<8;j++){tabla[i][j]=0;tabla2[i][j]=0;}}
			    for(i=0;i<200;i++){cache[i]=0;}
  do/*cada turno*/
  {
   CONTINUAR:
   ganador=0;
      modo=0;
	sw=0;

    clrscr();
    fondo();
    mostrar();/*dibuja las fichas contenidas en la tabla*/
    marcador();/*muestra partidas ganadas y turno del jugador*/
	   if(num_jugadores==1 && turno==2) {posicion=IA();goto AUTO;}
    posicion=tecla();/*recibe la posicion(char) y pos(int) de la jugada*/
		      /*menu salir*/
		      if(strcmp(posicion,27)==0) salir();
		      if(modo==1) goto CONTINUAR;
		      if(modo==2) {deshacer();goto CONTINUAR;}
		      if(modo==3) goto EMPEZAR;
		      if(modo==4) goto NUEVO;
		      if(modo==5) {opciones();goto CONTINUAR;}
		      if(modo==6) {guardar();exit(0);}
    AUTO:
    validar();/*validamos la posicion y la marcamos en la tabla*/

    mostrar();/*dibuja las fichas contenidas en la tabla*/
    /*error*/ if(tabla[pos][8]==5) {error1();goto CONTINUAR;}/*columna llena*/
	      var=0;
	      for(i=1;i<=7;i++){for(j=1;j<=7;j++) {if(tabla[i][j]==0)var=1;} }
	      if(var==0) {error2();goto EMPEZAR;}/*tabla llena*/

    comprobar();/*comprobamos resultado de la jugada y dibujamos la linea/s*/
		if(sw==1)
		 {
		  textcolor(textop);
		  gotoxy(x+46,y-25);cprintf("                           ");
		  gotoxy(x+46,y-24);cprintf("                           ");
		  gotoxy(x+46,y-23);cprintf("                           ");
		  gotoxy(x+46,y-22);cprintf("                           ");
		  gotoxy(x+46,y-21);cprintf("                           ");
		  if(ganador==1){gotoxy(x+48,y-22);cprintf("gana ");textcolor(color1);cprintf("%s",jugador1);gotoxy(1,1);}
		  if(ganador==2){if(num_jugadores==1){gotoxy(x+48,y-22);cprintf("GAME OVER");}
				 else{gotoxy(x+48,y-22);cprintf("gana ");textcolor(color2);cprintf("%s",jugador2);gotoxy(1,1);}
		  }
		  getch();getch();
		 }
		if(sw==0)
		 {
		  /*almacenamos la jugada en la tabla cache*/
		  num_jugadas++; cache[num_jugadas]=pos;/*printf("num_jugadas__%d\ncache[num_jugadas__%d",num_jugadas,cache[num_jugadas]);getch();*/
		 }

   /*cambio de turno*/if(turno==1)turno=2; else{if(turno==2)turno=1;}
  }while(sw==0);
 }while(1);
}/*finprograma*/
/*=========================================================================*/
void cargar()
{
 struct datos dat;

 if((archivo=fopen(".\\4ENRAYA.cfg","rb"))==NULL)/*si no lo abre*/
  {
   if((archivo=fopen(".\\4ENRAYA.cfg","wb"))==NULL)/*lo crea*/
	{clrscr();printf("Error al crear el fichero \"4ENRAYA.cfg\"");getch();exit(1);}
   else archivo=fopen(".\\4ENRAYA.cfg","wb");
  }
  else
  {
   archivo=fopen(".\\4ENRAYA.cfg","rb");/*abre como lectura*/
   fread(&dat,sizeof(struct datos),1,archivo);

   strcpy(jugador1,dat.jugador1);
   strcpy(jugador2,dat.jugador2);
   color1=dat.color1;
   color2=dat.color2;
   textop=dat.textop;
   fondop=dat.fondop;
   ganador=dat.ganador;
  }
   fclose(archivo);
}
/*--------------------------------------------------------------------------*/
void guardar()
{
 struct datos dat;

 if((archivo=fopen(".\\4ENRAYA.cfg","rb"))!=NULL)/*si lo abre*/
  {
   archivo=fopen(".\\4ENRAYA.cfg","wb");

   strcpy(dat.jugador1,jugador1);
   strcpy(dat.jugador2,jugador2);
   dat.color1=color1;
   dat.color2=color2;
   dat.textop=textop;
   dat.fondop=fondop;
   dat.ganador=ganador;

   fwrite(&dat,sizeof(struct datos),1,archivo);fclose(archivo);
  }
}
/*--------------------------------------------------------------------------*/
void deshacer()
{
 if(cache[num_jugadas]!=0)
 {for(i=1;i<=7;i++)
  {if(tabla[cache[num_jugadas]][i]==0)
   {tabla[cache[num_jugadas]][i-1]=0;goto fin;}
  }
 }else goto fin2;/*no cambia de turno*/
 fin:
 num_jugadas--;/*cambio de turno*/if(turno==1)turno=2; else{if(turno==2)turno=1;}
 fin2:
}
/*-------------------------------------------------------------------------*/
void comprobar()
{
   int posx,posy;
   int ii,jj;
   int cont=0;
do
{
 cont++;
   /*comprueba las lineas  '-'  */
   for (i=1;i<5;i++)
   {for(j=1;j<8;j++)
    {
     if   (tabla[i][j]  ==turno)
     {if  (tabla[i+1][j]==turno)
      {if (tabla[i+2][j]==turno)
       {if(tabla[i+3][j]==turno)
	{
	 sw=1;ganador=turno;
	 tabla2[i]  [j]=(turno);
	 tabla2[i+1][j]=(turno);
	 tabla2[i+2][j]=(turno);
	 tabla2[i+3][j]=(turno);
   }}}}}}
   /*comprueba las columnas  '|'  */
   for (i=1;i<8;i++)
   {for(j=1;j<5;j++)
    {
     if   (tabla[i][j]  ==turno)
     {if  (tabla[i][j+1]==turno)
      {if (tabla[i][j+2]==turno)
       {if(tabla[i][j+3]==turno)
	{
	 sw=1;ganador=turno;
	 tabla2[i][j]  =(turno);
	 tabla2[i][j+1]=(turno);
	 tabla2[i][j+2]=(turno);
	 tabla2[i][j+3]=(turno);
   }}}}}}
   /*comprueba las diagonales   /  */
   for (i=1;i<5;i++)
   {for(j=1;j<5;j++)
    {
     if   (tabla[i]  [j]  ==turno)
     {if  (tabla[i+1][j+1]==turno)
      {if (tabla[i+2][j+2]==turno)
       {if(tabla[i+3][j+3]==turno)
	{
	 sw=1;ganador=turno;
	 tabla2[i]  [j]  =(turno);
	 tabla2[i+1][j+1]=(turno);
	 tabla2[i+2][j+2]=(turno);
	 tabla2[i+3][j+3]=(turno);
   }}}}}}
   /*comprueba las diagonales  \  */
   for (i=7;i>0;i--)
   {for(j=0;j<7;j++)
    {
     if   (tabla[i]  [j]  ==turno)
     {if  (tabla[i-1][j+1]==turno)
      {if (tabla[i-2][j+2]==turno)
       {if(tabla[i-3][j+3]==turno)
	{
	 sw=1;ganador=turno;
	 tabla2[i]  [j]  =(turno);
	 tabla2[i-1][j+1]=(turno);
	 tabla2[i-2][j+2]=(turno);
	 tabla2[i-3][j+3]=(turno);
   }}}}}}
 /*-----------------------------------*/
 /*dibuja las lineas donde hacen linea*/
 if(ganador==1){textcolor(color1+BLINK);textbackground(fondop);}
 if(ganador==2){textcolor(color2+BLINK);textbackground(fondop);}

 if(sw==1)
 {
  for(i=1;i<8;i++)
  {
   for(j=1;j<8;j++)
   {
     if(tabla2[i][j]==1 || tabla2[i][j]==2)
     {
      posx=(x+(i*6))-6;
      posy=(y-(j*6))+6;
      gotoxy(posx,posy);  cprintf("      ");
      gotoxy(posx,posy-1);cprintf("  €€  ");
      gotoxy(posx,posy-2);cprintf(" €€€€ ");
      gotoxy(posx,posy-3);cprintf(" €€€€ ");
      gotoxy(posx,posy-4);cprintf("  €€  ");
      gotoxy(posx,posy-5);cprintf("      ");
     }
   }
  }
 }

}while(cont<100);/*para que realice mas comprobaciones*/
 textcolor(textop);textbackground(fondop);
}
/*-------------------------------------------------------------------------*/
void validar()
{
 for(i=1;i<=7;i++)
 {
  if(turno==1) {if(tabla[pos][i]==0){tabla[pos][i]=1;goto fin;}}
  if(turno==2) {if(tabla[pos][i]==0){tabla[pos][i]=2;goto fin;}}

  if(tabla[pos][7]!=0) tabla[pos][8]=5;/*error columna llena*/
 }
 fin:
}
/*-------------------------------------------------------------------------*/
char tecla()
{
 char cad;
 int  columna;
 do
 {
    textcolor(textop);textbackground(fondop);
    gotoxy(x-1,y+2);cprintf("                                            ");cprintf("                   ");
    gotoxy(x-1,y+3);cprintf("    1     2     3     4     5     6     7   ");
    gotoxy(x-1,y+4);cprintf("                                            ");cprintf("                   ");
    if(turno==1){textcolor(color1);columna=y+2;}
    if(turno==2){textcolor(color2);columna=y+4;}
    if(pos==1){gotoxy(x,   columna);cprintf("€€€€€€");}
    if(pos==2){gotoxy(x+6, columna);cprintf("€€€€€€");}
    if(pos==3){gotoxy(x+12,columna);cprintf("€€€€€€");}
    if(pos==4){gotoxy(x+18,columna);cprintf("€€€€€€");}
    if(pos==5){gotoxy(x+24,columna);cprintf("€€€€€€");}
    if(pos==6){gotoxy(x+30,columna);cprintf("€€€€€€");}
    if(pos==7){gotoxy(x+36,columna);cprintf("€€€€€€");}
	       gotoxy(x+42,columna);if(turno==1){cprintf(" %s",jugador1);}
				    if(turno==2){cprintf(" %s",jugador2);}
  gotoxy(1,1);textcolor(fondop);textbackground(fondop);/*para que no se vea el cursor*/

  cad=getche();

  if(cad==27) goto fin;
  if(cad=='1')pos=1;
  if(cad=='2')pos=2;
  if(cad=='3')pos=3;
  if(cad=='4')pos=4;
  if(cad=='5')pos=5;
  if(cad=='6')pos=6;
  if(cad=='7')pos=7;
  if(cad=='K') {if(pos==1)pos=7;else pos--;}
  if(cad=='M') {if(pos==7)pos=1;else pos++;}

 }while(cad!=13&&cad!=' '&&cad!='1'&&cad!='2'&&cad!='3'&&cad!='4'&&cad!='5'&&cad!='6'&&cad!='7');

 if(cad==13&&cad==' ')/*si pulsamos enter devolvemos el valor de pos(int) a cad(char)*/
 {if(pos==1)cad='1';if(pos==2)cad='2';if(pos==3)cad='3';if(pos==4)cad='4';if(pos==5)cad='5';if(pos==6)cad='6';if(pos==7)cad='7';}

 fin:
 textcolor(textop);textbackground(fondop);
 return(cad);
}
/*-------------------------------------------------------------------------*/
void marcador()
{
 textcolor(textop);
 gotoxy(x+46,y-42);cprintf("…VICTORIASÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
 gotoxy(x+46,y-41);cprintf("∫                         ∫");
 gotoxy(x+46,y-40);cprintf("∫                         ∫");
 gotoxy(x+46,y-39);cprintf("∫                         ∫");
 gotoxy(x+46,y-38);cprintf("∫                         ∫");
 gotoxy(x+46,y-37);cprintf("∫                         ∫");
 gotoxy(x+46,y-36);cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
 gotoxy(x+46,y-25);cprintf("…TURNOÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
 gotoxy(x+46,y-24);cprintf("∫                         ∫");
 gotoxy(x+46,y-23);cprintf("∫                         ∫");
 gotoxy(x+46,y-22);cprintf("∫                         ∫");
 gotoxy(x+46,y-21);cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
 gotoxy(x+48,y-40);cprintf("%3d :",record1);
 gotoxy(x+48,y-38);cprintf("%3d :",record2);
 textcolor(color1);gotoxy(x+54,y-40);cprintf("%s",jugador1);
 textcolor(color2);gotoxy(x+54,y-38);cprintf("%s",jugador2);
 if(turno==1)
  {
   textcolor(color1);
   gotoxy(x+47,y-24);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€");
   gotoxy(x+47,y-23);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€");
   gotoxy(x+47,y-22);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€");
  }
 if(turno==2)
  {
   textcolor(color2);
   gotoxy(x+47,y-24);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€");
   gotoxy(x+47,y-23);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€");
   gotoxy(x+47,y-22);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€");
  }
 textcolor(textop);gotoxy(1,1);
}
/*-------------------------------------------------------------------------*/
void mostrar()
{
 int posx,posy;
 int ii,jj;
 for(i=1;i<8;i++)
 {
  for(j=1;j<8;j++)
  {
   if(tabla[i][j]==1)/*jugador1*/
   {
    textcolor(color1);
    posx=(x+(i*6))-6;
    posy=(y-(j*6))+6;
    gotoxy(posx,posy);  cprintf("      ");
    gotoxy(posx,posy-1);cprintf("  €€  ");
    gotoxy(posx,posy-2);cprintf(" €€€€ ");
    gotoxy(posx,posy-3);cprintf(" €€€€ ");
    gotoxy(posx,posy-4);cprintf("  €€  ");
    gotoxy(posx,posy-5);cprintf("      ");
   }
   if(tabla[i][j]==2)/*jugador2*/
   {
    textcolor(color2);
    posx=(x+(i*6))-6;
    posy=(y-(j*6))+6;
    gotoxy(posx,posy);  cprintf("      ");
    gotoxy(posx,posy-1);cprintf("  €€  ");
    gotoxy(posx,posy-2);cprintf(" €€€€ ");
    gotoxy(posx,posy-3);cprintf(" €€€€ ");
    gotoxy(posx,posy-4);cprintf("  €€  ");
    gotoxy(posx,posy-5);cprintf("      ");
   }
  }
 }
}
/*-------------------------------------------------------------------------*/
void fondo()
{
 textcolor(textop);
 gotoxy(x-1,y-42);cprintf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
 gotoxy(x-1,y-41);cprintf("∫                                          ∫");
 gotoxy(x-1,y-40);cprintf("∫                                          ∫");
 gotoxy(x-1,y-39);cprintf("∫                                          ∫");
 gotoxy(x-1,y-38);cprintf("∫                                          ∫");
 gotoxy(x-1,y-37);cprintf("∫                                          ∫");
 gotoxy(x-1,y-36);cprintf("∫                                          ∫");
 gotoxy(x-1,y-35);cprintf("∫                                          ∫");
 gotoxy(x-1,y-34);cprintf("∫                                          ∫");
 gotoxy(x-1,y-33);cprintf("∫                                          ∫");
 gotoxy(x-1,y-32);cprintf("∫                                          ∫");
 gotoxy(x-1,y-31);cprintf("∫                                          ∫");
 gotoxy(x-1,y-30);cprintf("∫                                          ∫");
 gotoxy(x-1,y-29);cprintf("∫                                          ∫");
 gotoxy(x-1,y-28);cprintf("∫                                          ∫");
 gotoxy(x-1,y-27);cprintf("∫                                          ∫");
 gotoxy(x-1,y-26);cprintf("∫                                          ∫");
 gotoxy(x-1,y-25);cprintf("∫                                          ∫");
 gotoxy(x-1,y-24);cprintf("∫                                          ∫");
 gotoxy(x-1,y-23);cprintf("∫                                          ∫");
 gotoxy(x-1,y-22);cprintf("∫                                          ∫");
 gotoxy(x-1,y-21);cprintf("∫                                          ∫");
 gotoxy(x-1,y-20);cprintf("∫                                          ∫");
 gotoxy(x-1,y-19);cprintf("∫                                          ∫");
 gotoxy(x-1,y-18);cprintf("∫                                          ∫");
 gotoxy(x-1,y-17);cprintf("∫                                          ∫");
 gotoxy(x-1,y-16);cprintf("∫                                          ∫");
 gotoxy(x-1,y-15);cprintf("∫                                          ∫");
 gotoxy(x-1,y-14);cprintf("∫                                          ∫");
 gotoxy(x-1,y-13);cprintf("∫                                          ∫");
 gotoxy(x-1,y-12);cprintf("∫                                          ∫");
 gotoxy(x-1,y-11);cprintf("∫                                          ∫");
 gotoxy(x-1,y-10);cprintf("∫                                          ∫");
 gotoxy(x-1,y-9); cprintf("∫                                          ∫");
 gotoxy(x-1,y-8); cprintf("∫                                          ∫");
 gotoxy(x-1,y-7); cprintf("∫                                          ∫");
 gotoxy(x-1,y-6); cprintf("∫                                          ∫");
 gotoxy(x-1,y-5); cprintf("∫                                          ∫");
 gotoxy(x-1,y-4); cprintf("∫                                          ∫");
 gotoxy(x-1,y-3); cprintf("∫                                          ∫");
 gotoxy(x-1,y-2); cprintf("∫                                          ∫");
 gotoxy(x-1,y-1); cprintf("∫                                          ∫");
 gotoxy(x-1,y);   cprintf("∫                                          ∫");
 gotoxy(x-1,y+1); cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");

 gotoxy(x-1,y+3); cprintf("    1     2     3     4     5     6     7   ");
}
/*------------------------------------------------------------------------*/
int jugadores()
{
 char tecla;
 int  modo;

 inicio:
 textbackground(fondop);textcolor(textop);
 clrscr();

 modo=2;/*opcion por defecto*/
 do
 {
  textbackground(fondop);textcolor(textop);
	      gotoxy(33,24);cprintf("  1 jugador    ");
	      gotoxy(33,25);cprintf("  2 jugadores  ");
	      gotoxy(33,27);cprintf("   Opciones    ");

  textbackground(textop);textcolor(fondop);
  if(modo==1){gotoxy(33,24);cprintf("  1 jugador    ");}
  if(modo==2){gotoxy(33,25);cprintf("  2 jugadores  ");}
  if(modo==3){gotoxy(33,27);cprintf("   Opciones    ");}

  do{textcolor(fondop);textbackground(fondop);gotoxy(1,1);tecla=getche();
    }while(tecla!='H'&&tecla!='P'&&tecla!='1'&&tecla!='2'&&tecla!='3'&&tecla!=' '&&tecla!=13&&tecla!=27);

  if(tecla=='H')
    {
     if(modo==1)modo=3;
     else       modo--;
    }
  if(tecla=='P')
    {
     if(modo==3)modo=1;
     else       modo++;
    }
  if(tecla=='1'){modo=1;tecla=13;}
  if(tecla=='2'){modo=2;tecla=13;}
  if(tecla=='3'){modo=3;tecla=13;}

 }while(tecla!=' '&&tecla!=13&&tecla!=27);/*barra espaciadora,Enter,Esc*/

 if(modo==3){opciones();goto inicio;}/*llama al menu de opciones*/
 textcolor(textop);textbackground(fondop);clrscr();
 return modo;
}
/*-------------------------------------------------------------------------*/
void salir()  /*se abre venatana de menu*/
{
 char tecla;
 modo=1;/*por defecto continuar*/
 do
 {
  textcolor(fondop);textbackground(textop);
	      gotoxy(30,15);cprintf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
	      gotoxy(30,16);cprintf("∫    CONTINUAR     ∫");
	      gotoxy(30,17);cprintf("∫ DESHACER  JUGADA ∫");
	      gotoxy(30,18);cprintf("∫ volver a empezar ∫");
	      gotoxy(30,19);cprintf("∫  nueva  partida  ∫");
	      gotoxy(30,20);cprintf("∫    Opciones      ∫");
	      gotoxy(30,21);cprintf("∫      SALIR       ∫");
	      gotoxy(30,22);cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
  textcolor(textop);textbackground(fondop);
  if(modo==1){gotoxy(31,16);cprintf("    CONTINUAR     ");}
  if(modo==2){gotoxy(31,17);cprintf(" DESHACER  JUGADA ");}
  if(modo==3){gotoxy(31,18);cprintf(" volver a empezar ");}
  if(modo==4){gotoxy(31,19);cprintf("  nueva  partida  ");}
  if(modo==5){gotoxy(31,20);cprintf("    Opciones      ");}
  if(modo==6){gotoxy(31,21);cprintf("      SALIR       ");}

  do{textcolor(fondop);textbackground(fondop);gotoxy(1,1);tecla=getche();
     if(tecla==27) {tecla=13;modo=1;}
    }while(tecla!='H'&&tecla!='P'&&tecla!=13);

  if(tecla=='H')
    {
     if(modo==1)modo=6;
     else       modo--;
    }
  if(tecla=='P'||tecla=='2')
    {
     if(modo==6)modo=1;
     else       modo++;
    }
 }while(tecla!=13);/*Enter*/
 textcolor(textop);textbackground(fondop);
}
/*------------------------------------------------------------------------*/
void opciones()
{
 char tecla,cad[20];
 int  modo,var;
 modo=8;/*opcion por defecto*/
 inicio:
 do
 {
  textcolor(textop);textbackground(fondop);clrscr();
  gotoxy(33,2); cprintf("       OPCIONES≥");
  gotoxy(33,3); cprintf("       ƒƒƒƒƒƒƒƒŸ");
  gotoxy(33,10);cprintf("        JUGADOR 1");
  gotoxy(33,12);cprintf("nombre: %s    ",jugador1);
  gotoxy(33,13);cprintf("color   ");textcolor(color1);cprintf("€€€€€€€€€€");textcolor(textop);
  gotoxy(33,14);cprintf("ficha         ");
  gotoxy(33,21);cprintf("        JUGADOR 2");
  gotoxy(33,23);cprintf("nombre: %s    ",jugador2);
  gotoxy(33,24);cprintf("color   ");textcolor(color2);cprintf("€€€€€€€€€€");textcolor(textop);
  gotoxy(33,25);cprintf("ficha         ");
  gotoxy(33,32);cprintf("  COLORES PANTALLA");
  gotoxy(33,34);cprintf("fondo     texto   ");
  gotoxy(33,37);cprintf("   SALIR (Esc)");

  textcolor(fondop);textbackground(textop);
  if(modo==1){gotoxy(33,12);cprintf("nombre: ");}
  if(modo==2){gotoxy(33,13);cprintf("color   ");}
  if(modo==3){gotoxy(33,14);cprintf("ficha   ");}
  if(modo==4){gotoxy(33,23);cprintf("nombre: ");}
  if(modo==5){gotoxy(33,24);cprintf("color   ");}
  if(modo==6){gotoxy(33,25);cprintf("ficha   ");}
  if(modo==7){gotoxy(33,34);cprintf("fondo     texto   ");}
  if(modo==8){gotoxy(33,37);cprintf("   SALIR (Esc)    ");}

  do{textcolor(fondop);textbackground(fondop);gotoxy(1,1);cprintf(" ");tecla=getche();
     if(tecla==27) {tecla=13;modo=8;}
    }while(tecla!='H'&&tecla!='P'&&tecla!=13);
    if(tecla=='H') {if(modo==1)modo=8;else modo--;}
    if(tecla=='P') {if(modo==8)modo=1;else modo++;}

 }while(tecla!=13);/*Enter*/

 /*ejecucion de las opciones*/textcolor(textop);textbackground(fondop);
  if(modo==1){gotoxy(33,12);cprintf("nombre: __________");gotoxy(41,12);gets(cad);if(strcmp(cad,"")!=0) {strcpy(jugador1,cad);}}
  if(modo==4){gotoxy(33,23);cprintf("nombre: __________");gotoxy(41,23);gets(cad);if(strcmp(cad,"")!=0) {strcpy(jugador2,cad);}}

  if(modo==2)
   {gotoxy(33,13);textcolor(textop);cprintf("color ");textcolor(textop+BLINK);cprintf("");
   textcolor(color1);cprintf(" €€€€€€€€€€");
    do{
       textcolor(fondop);gotoxy(1,1);tecla=getche();
       if(tecla=='H') {if(color1<=0)color1=15;else color1--;if(fondop==color1)color1--;if(color2==color1)color1--;}
       if(tecla=='P') {if(color1>=15)color1=0;else color1++;if(fondop==color1)color1++;if(color2==color1)color1++;}
       textcolor(color1);gotoxy(41,13);cprintf("€€€€€€€€€€");
      }while(tecla!=13 && tecla!=27);textcolor(textop);
   }
  if(modo==5)
   {gotoxy(33,24);textcolor(textop);cprintf("color ");textcolor(textop+BLINK);cprintf("");
   textcolor(color2);cprintf(" €€€€€€€€€€");
    do{
       textcolor(fondop);gotoxy(1,1);tecla=getche();
       if(tecla=='H') {if(color2<=0)color2=15;else color2--;if(fondop==color2)color2--;if(color1==color2)color2--;}
       if(tecla=='P') {if(color2>=15)color2=0;else color2++;if(fondop==color2)color2++;if(color1==color2)color2++;}
       textcolor(color2);gotoxy(41,24);cprintf("€€€€€€€€€€");
      }while(tecla!=13 && tecla!=27);textcolor(textop);
   }

  if(modo==3){gotoxy(33,14);cprintf("ficha         ");}
  if(modo==6){gotoxy(33,25);cprintf("ficha         ");}

  if(modo==7)/*color del fondo*/
   {gotoxy(33,34);textcolor(textop);textbackground(fondop);
    cprintf("fondo[ ]  texto[ ]");textcolor(textop+BLINK);gotoxy(39,34);cprintf("");gotoxy(49,34);cprintf("");
    do{textcolor(fondop);gotoxy(1,1);tecla=getche();
       if(tecla=='H') {if(fondop<=0) fondop=7; else fondop--;if(fondop==textop)fondop--;}
       if(tecla=='P') {if(fondop>=7) fondop=0; else fondop++;if(fondop==textop)fondop++;}
       if(tecla=='K') {if(textop<=0) textop=15;else textop--;if(fondop==textop)textop--;}
       if(tecla=='M') {if(textop>=15)textop=0; else textop++;if(fondop==textop)textop++;}
	gotoxy(33,34);textcolor(textop);textbackground(fondop);
	cprintf("fondo[ ]  texto[ ]");textcolor(textop+BLINK);gotoxy(39,34);cprintf("");gotoxy(49,34);cprintf("");
      }while(tecla!=13 && tecla!=27);textcolor(textop);
   }

 if(modo!=8) {goto inicio;}
 textcolor(textop);textbackground(fondop);
}
/*----------------------------------------------------------------------------------------------*/
void error1()
{

}
/*----------------------------------------------------------------------------------------------*/
void error2()
{

}
/*--------------------------------------------------------------------------*/
void intro()
{
 clrscr();
}
/*                                            */
/*--------------------------------------------------------------------------*/
char IA()
{
 char cad;
 int CPU=2;/*es el valor de la tabla que contiene las fichas de la maquina*/

 int busca=0;/*1-busca posicion,2-ya esta buscada*/
 int grado=0;/*grado de inportancia [0123]*/
 int cont;

 VOLVER_A_PENSAR:
 cont=0;
 PENSAR1:
 cont++;
   for (i=1;i<5;i++)/*comprueba las lineas  '-'  */
   {for(j=1;j<8;j++)
    {
     if   (tabla[i][j]  ==CPU)
     {if  (tabla[i+1][j]==CPU)
      {if (tabla[i+2][j]==CPU)
       {if(tabla[i+3][j]!=CPU)
	{
	 grado=3;pos=i+3;
	 if(tabla[pos][7]!=0) grado=0;
	}
	else;
   }}}}}
 PENSAR2:
   for (i=1;i<8;i++)/*comprueba las columnas  '|'  */
   {for(j=1;j<5;j++)
    {
     if   (tabla[i][j]  ==CPU)
     {if  (tabla[i][j+1]==CPU)
      {if (tabla[i][j+2]==CPU)
       {if(tabla[i][j+3]!=CPU)
	{ grado=3;pos=i+3;
	  if(tabla[pos][7]!=0) grado=0;
   }}}}}}
 PENSAR3:
   for (i=1;i<5;i++)/*comprueba las diagonales   /  */
   {for(j=1;j<5;j++)
    {
     if   (tabla[i]  [j]  ==CPU)
     {if  (tabla[i+1][j+1]==CPU)
      {if (tabla[i+2][j+2]==CPU)
       {if(tabla[i+3][j+3]!=CPU)
	{ grado=3;pos=i+3;
	  if(tabla[pos][7]!=0) grado=0;
   }}}}}}
 PENSAR4:
   for (i=7;i>0;i--)/*comprueba las diagonales  \  */
   {for(j=0;j<7;j++)
    {
     if   (tabla[i]  [j]  ==CPU)
     {if  (tabla[i-1][j+1]==CPU)
      {if (tabla[i-2][j+2]==CPU)
       {if(tabla[i-3][j+3]!=CPU)
	{ grado=3;pos=i+3;
	  if(tabla[pos][7]!=0) grado=0;
   }}}}}}
   /*----------------------------------------------------------------*/
 if(grado<3&&busca==0)
 {
  if(CPU==2){CPU=1;busca=1;}
  else      {CPU=2;}

  goto PENSAR1;
 }
 else
 {
  if(grado==3) goto FIN;
 }

 if(cont>100)
  {
   randomize();
   pos=random(7)+1;
  }

 FIN:
 if(tabla[pos][7]!=0) goto VOLVER_A_PENSAR;
 if(pos==1)cad='1';if(pos==2)cad='2';if(pos==3)cad='3';if(pos==4)cad='4';if(pos==5)cad='5';if(pos==6)cad='6';if(pos==7)cad='7';
 return cad;
}
/*-------------------------------------------------------------------------*/
