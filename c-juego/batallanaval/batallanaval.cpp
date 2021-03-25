//LIBRERIAS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>


//VARIABLES
int matriz1[21][11],matriz2[21][11],matriz3[21][11],matriz4[21][11];
int x,y,i,j;
int cdba=0,cdbb=0,cdbha=0,cdbhb=0;
char op1 , op2 , op3 , op4 , op5 , op6 , ota , otb ;
int tiradaa,tiradab;
int cdbpc=0,cdbhpc=0;
int cona1=0,cona2;
int conb1=0,conb2;
int v;

//FUNCIONES
void conjb1(void);
void conjb2(void);
void conja1(void);
void conja2(void);
void conja3(void);
void conjb3(void);
void diceganador(void);

//MUESTRAN UN MENU
void menu(void);  void menu2(void);  void menu3(void);  void comienso(void);
//CONFIGURACION
void tja(void);  void tjb(void);  void tjpc(void);  void tjapc(void);
//VISUALIZACION
void verta(void);  void vertb(void);  void vertpc(void);  void vertapc(void);
void vertabla(void);
//ESTRATEGIA
void tiroa(void);  void tirob(void);  void tiropc(void);  void tiroapc(void);
//INTERFACE
void barcohun(void);  void barcohun1(void);  void creditos(void);
void musica(void);    void loading(void);    void presentacion(void);
void reglamento(void);  void coordenadas(int);
void boton(void);

//SORTEO DEL PRIMER TIRO
void dadosa(void);      void dadosb(void);       void tirada(void);
//ADVIERTE EL GANADOR DEL JUEGO
void diceganavspc(void); void sefijaencdb (void);



//DECLARACION DE LA MATRIZ DEL JUGADOR 1 CON EL TABLEO EN '0'
void iniciomatriz1(void)
{
for(x=0;x<=20;x++)
	{
	for(y=0;y<=10;y++)
		{
		matriz1[x][y] = 0;
		}
	}
}


//DECLARACION DE LA MATRIZ DEL JUGADOR 2 CON EL TABLEO EN '0'
void iniciomatriz2(void)
{
for(x=0;x<=20;x++)
	{
	for(y=0;y<=10;y++)
		{
		matriz2[x][y] = 0;
		}
	}
}


//DECLARACION DE LA MATRIZ DEL COMPUTADOR CON EL TABLEO EN '0'
void iniciomatriz3()
{
for(x=0;x<=20;x++)
	{
	for(y=0;y<=10;y++)
		{
		matriz3[x][y]=0;
		}}}


//DECLARACION DE LA MATRIZ PARA QUE EL COMPUTADOR TIRE SOLO UNA VES EN CADA LUGAR
//ES PARA QUE GUERDE EL LUGAR DONDE TIRO Y NO LO REPITA
void iniciomatriz4()
{
for(x=0;x<=20;x++)
	{
	for(y=0;y<=10;y++)
		{
		matriz4[x][y]=0;
		}}}

//FINCION PRINCIPAL
void main()
{
_setcursortype(_NOCURSOR);
textbackground(0);
clrscr();
textbackground(1);
textcolor(13);gotoxy(15,10);cprintf(" 1");textcolor(0); cprintf("- Ver presentacion ");
textcolor(14);gotoxy(40,10);cprintf(" 2");textcolor(0); cprintf("- Empezar a jugar ");
op1 = getch();
switch(op1)
	{
	case '1': boton();
			presentacion();    //SE VE LA PRESENTACION DEL JUEGO
			break;

	case '2': boton();
			menu();    //TE LLEVA AL MENU PRINCIPAL
			break;
	}
}



void menu(void)     //MENU PRINCIPAL
{
cdba=0;
cdbb=0;
cdbha=0;
cdbhb=0;
cdbpc=0;
cdbhpc=0;
cona1=0;
cona2=0;
iniciomatriz3();
iniciomatriz4();
_setcursortype(_NOCURSOR);
do
{
clrscr();
textbackground(0);
clrscr();
textcolor(14 + BLINK);
gotoxy(9,1);	cprintf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(9,2);	cprintf("К                                                               К");
gotoxy(9,3);	cprintf("К                                                               К");
gotoxy(9,4);	cprintf("К                                                               К");
gotoxy(9,5);	cprintf("К                                                               К");
gotoxy(9,6);	cprintf("К                                                               К");
gotoxy(9,7);	cprintf("К                                                               К");
gotoxy(9,8);	cprintf("К                                                               К");
gotoxy(9,9);	cprintf("К                                                               К");
gotoxy(9,10);	cprintf("К                                                               К");
gotoxy(9,11);	cprintf("К                                                               К");
gotoxy(9,12);	cprintf("К                                                               К");
gotoxy(9,13);	cprintf("К                                                               К");
gotoxy(9,14);	cprintf("К                                                               К");
gotoxy(9,15);	cprintf("К                                                               К");
gotoxy(9,16);	cprintf("К                                                               К");
gotoxy(9,17);	cprintf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textcolor(14 + BLINK);
gotoxy(11,2);	cprintf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(11,3);	cprintf("К                                                           К");
gotoxy(11,4);	cprintf("К                                                           К");
gotoxy(11,5);	cprintf("К                                                           К");
gotoxy(11,6);	cprintf("К                                                           К");
gotoxy(11,5);	cprintf("К                                                           К");
gotoxy(11,6);	cprintf("К                                                           К");
gotoxy(11,7);	cprintf("К                                                           К");
gotoxy(11,8);	cprintf("К                                                           К");
gotoxy(11,9);	cprintf("К                                                           К");
gotoxy(11,10);	cprintf("К                                                           К");
gotoxy(11,11);	cprintf("К                                                           К");
gotoxy(11,12);	cprintf("К                                                           К");
gotoxy(11,13);	cprintf("К                                                           К");
gotoxy(11,14);	cprintf("К                                                           К");
gotoxy(11,15);	cprintf("К                                                           К");
gotoxy(11,16);	cprintf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textbackground(1);
textcolor(15);
delay(100);
gotoxy(12,3);	cprintf("                                                           ");
gotoxy(12,4);	cprintf("  BBBB   AAAAAA  TTTTTTT  AAAAAA  L       L       AAAAAAA  ");
gotoxy(12,5);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");
gotoxy(12,6);	cprintf("  BBBB   AAAAAA     T     AAAAAA  L       L       AAAAAAA  ");
gotoxy(12,7);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");
gotoxy(12,8);	cprintf("  BBBB   A    A     T     A    A  LLLLLL  LLLLLL  A     A  ");
gotoxy(12,9);	cprintf("                                                           ");
gotoxy(12,10); 	cprintf("         NN   N  AAAAAA   V      V  AAAAAA  L              ");
gotoxy(12,11); 	cprintf("         NN   N  A    A   V      V  A    A  L              ");
gotoxy(12,12);	cprintf("         N N  N  AAAAAA   V      V  AAAAAA  L              ");
gotoxy(12,13);	cprintf("         N  N N  A    A    V    V   A    A  L              ");
gotoxy(12,14);	cprintf("         N   NN  A    A      VV     A    A  LLLLLL         ");
gotoxy(12,15);	cprintf("                                                           ");

textbackground(0);
gotoxy(4,19);
textcolor(14);
cprintf("MENU");
gotoxy(11,19);
textcolor(2);
cprintf("1 JUGAR");
gotoxy(11,20);
cprintf("2 REGLAMENTO");
gotoxy(11,21);
cprintf("3 VER PRESENTACION");
gotoxy(11,22);
cprintf("4 CREDITOS");
gotoxy(11,23);
cprintf("0 SALIR DEL BATALLA NAVAL");
gotoxy(4,24);
textcolor(14);
cprintf("OPCION:");
op2 = getch();
switch(op2)
	{
	case '1':      	boton();
			menu2();    //TE LLEVA AL MENU DE TIPOS DE JUEGO
			break;

	case '2':	boton();
			reglamento();   //TE MUESTRA EL REGLAMENTO DEL JUEGO
			break;

	case '3':      	boton();
			presentacion();     //TE MUESTRA LA PRESENTACION
			break;

	case '4':      	boton();
			creditos();     //TE MUESTRA LOS NOMBRES DE LOS
			break;          //CREADORES DE JUEGO
	}
}

while (op2!='0');
exit(0);

}


//MENU PARA LA CONFIGURACION DE BARCOS DE LOS JUGADORES
void menu3(void)
{
_setcursortype(_NOCURSOR);
do
{
textbackground(0);
clrscr();
textcolor(14);
gotoxy(4,4);
cprintf("MENU");
textcolor(2);
gotoxy(11,5);
cprintf("1 BARCOS JUGADOR A");
gotoxy(11,6);
cprintf("2 BARCOS JUGADOR B");
textcolor(7);
gotoxy(11,7);
cprintf("3 COMIENSO");
textcolor(15);
gotoxy(11,10);
cprintf("0 VOLVER");
textcolor(14);
gotoxy(4,12);
cprintf("OPCION:");
op3=getch();
switch(op3)
	{
	case '1':	boton();
			conja3();
			break;

	case '2':	boton();
			conjb3();
			break;

	case '3': boton();
			sefijaencdb();
			break;
	}
}

while(op3!='0');
menu();
}

void vertabla(void)
{
_setcursortype(_NOCURSOR);
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(CYAN);
		cprintf(" ");
		}
	}
}







//TABLA DEL JUGADOR A

void tja(void)
{

iniciomatriz1(); //LLAMO A LA FUNCION INICIOMARTIZ1 QUE ME INICIALIZA LAS
cdba=0;		 // POSICIONES 'X' 'Y' TODAS EN EL VALOR 0 (cero)
textbackground(0);
clrscr();
coordenadas(22);
textcolor(15);
gotoxy(30,3);
cprintf("JUGADOR A:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
cprintf(" m");textcolor(10);cprintf("  Colocar barco ");
gotoxy(30,6); 		    cprintf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,7);
cprintf(" d");textcolor(10);cprintf("  Borrar barco  ");
gotoxy(30,8); 		    cprintf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,9);
cprintf(" V");textcolor(10);cprintf("olver           ");
gotoxy(30,10);	printf("Debe colocar 10 barcos");

vertabla();

gotoxy(1,1);
x=1;
y=1;

_setcursortype(_SOLIDCURSOR);
do
{
ota = getch();
switch(ota)
	{
     case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;


	case 'm':
		if ((cdba<10) && (matriz1[x][y]!=1))
		{
		{
		textcolor(BLUE);
		cprintf("");
		cdba = cdba + 1;
		}
		if (x < 20)
			{
			matriz1[x][y]=1;
			x=x+1;
			}

		else
			{
			gotoxy(20,y);
			matriz1[x][y]=1;
			}
		}
		break;

	case'D':case 'd':if(matriz1[x][y]!=0)
		{
		if (x<20)
		{
		textcolor(WHITE);
		cprintf(" ");
		cdba = cdba - 1;
		matriz1[x][y]=0;
		x=x+1;
		}
		else
		if (x==20)
			{
			textcolor(WHITE);
			cprintf(" ");
			cdba = cdba - 1;
			matriz1[20][y]=0;
			gotoxy(20,y);
			}

		}
		else
			x=x;

		break;
	}
}
while(ota!='v' && ota!='V');
conja1();
}



//TABLA DEL JUGADOR B
void tjb(void)
{

iniciomatriz2();
cdbb=0;
textbackground(0);
clrscr();
coordenadas(22);
textcolor(15);
gotoxy(30,3);
cprintf("JUGADOR B:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
cprintf(" m");textcolor(10);cprintf("  Colocar barco ");
gotoxy(30,6); 		    cprintf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,7);
cprintf(" d");textcolor(10);cprintf("  Borrar barco  ");
gotoxy(30,8); 		    cprintf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,9);
cprintf(" V");textcolor(10);cprintf("olver           ");
gotoxy(30,10);	printf("Debe colocar 10 barcos");

vertabla();

gotoxy(1,1);
x=1;
y=1;

_setcursortype(_SOLIDCURSOR);
do
{
otb = getch();
switch(otb)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

		case 'm':
		if ((cdbb<10) && (matriz2[x][y]!=1))
		{
		{
		textcolor(BLUE);
		cprintf("");
		cdbb = cdbb + 1;
		}
		if (x < 20)
			{
			matriz2[x][y] = 1;
			x = x+1;
			}

		else
			{
			gotoxy(20,y);
			matriz2[x][y] = 1;
			}
		}
		break;

	case'D':case 'd':if(matriz2[x][y]!=0)
			{
		if (x<20)
		{
		textcolor(WHITE);
		cprintf(" ");
		cdbb = cdbb - 1;
		matriz2[x][y]=0;
		x=x+1;
		}
		else
		if (x==20)
			{
			textcolor(WHITE);
			cprintf(" ");
			cdbb = cdbb - 1;
			matriz2[20][y]=0;
			gotoxy(20,y);
			}
		    }
	    else
		   x=x;


		break;
	}
}
while(otb!='v' && otb!='V');
conjb1();
}
void boton(void)
{
sound(560);
delay(100);
nosound();
}



//COMIENSO DEL JUEGO TIPO H VS H
void comienzo(void)
{
_setcursortype(_NOCURSOR);
do

{
textbackground(0);
clrscr();
textcolor(14);	gotoxy(6,3);	cprintf("MENU");
textcolor(2);	gotoxy(10,5);	cprintf("1 - Ataque jugador A\n");
textcolor(10);	gotoxy(10,6);	cprintf("2 - Ataque jugador B\n");
textcolor(2);	gotoxy(10,7);	cprintf("3 - Consultar barcos jugador A\n");
textcolor(10);	gotoxy(10,8);	cprintf("4 - Consultar barcos jugador B\n");
textcolor(2);	gotoxy(10,10);	cprintf("0 - Volver al menЃ principal\n");
textcolor(14);	gotoxy(3,12);	cprintf("OpciЂn:");
op4=getch();
switch(op4)
	{
	case '1':     	boton();
				tiroa();
				break;

	case '2':     	boton();
				tirob();
				break;

	case '3':     	boton();
				conja2();
				break;

	case '4':		boton();
				conjb2();
				break;

	case '0':      boton();
			     textcolor(10);
			     gotoxy(3,15);cprintf("DECEAN SALIR DEL JUEGO? s/n");
			     op6=getch();
				switch(op6)
			     	{
			     	case'S':case 's':	boton();
			     					menu();
			     					break;

			     	case 'n':      	boton();
			     					comienzo();
			     					break;
			     	}
			     break;
	}
}

while((cdbb !=0) && (cdba !=0));
diceganador();
}


void diceganador(void)
{
_setcursortype(_NOCURSOR);
clrscr();
textbackground(0);
if (cdbb==0)
	{
	textbackground(1);
	textcolor(15 + BLINK);
	cprintf("                                                    ");
	cprintf("                                                    ");
	cprintf("     Ha ganado el jugador A!!                       ");
	cprintf("                                                    ");
	cprintf("                                ");
	textbackground(0);
	textcolor(15);
	gotoxy(19,7);   	cprintf("ЩЭЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(19,8);		cprintf("К A К   К BARCOS HUNDIDOS К");
	gotoxy(19,9);   	cprintf("ЬЭЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
	gotoxy(19,10);		cprintf("К B К   К BARCOS HUNDIDOS К");
	gotoxy(19,11);   	cprintf("ШЭЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	textcolor(10 + BLINK);
	gotoxy(25,8);	cprintf("%d", cdbha);
	textcolor(13);
	gotoxy(25,10);	cprintf("%d", cdbhb);
	getch();
	menu();
	}
if (cdba==0)
	{
	textbackground(1);
	textcolor(15 + BLINK);
	cprintf("                                                    ");
	cprintf("                                                    ");
	cprintf("     Ha ganado el jugador B!!                       ");
	cprintf("                                                    ");
	cprintf("                                ");
	textbackground(0);
	textcolor(15);
	gotoxy(19,7);   	cprintf("ЩЭЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(19,8);		cprintf("К A К   К BARCOS HUNDIDOS К");
	gotoxy(19,9);   	cprintf("ЬЭЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
	gotoxy(19,10);		cprintf("К B К   К BARCOS HUNDIDOS К");
	gotoxy(19,11);   	cprintf("ШЭЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	textcolor(13);
	gotoxy(25,8);	cprintf("%d", cdbha);
	textcolor(10 + BLINK);
	gotoxy(25,10);	cprintf("%d", cdbhb);
	getch();
	menu();
	}
}


//TIRO DEL JUGADOR A A LOS BARCOS DEL JUGADOR B
void tiroa(void)
{
textbackground(0);
clrscr();
textbackground(0);
				textcolor(WHITE);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(CYAN);
						if (matriz2[x][y] == 3)
							{
							textcolor(RED);
							cprintf("X");
							}
						else
							if (matriz2[x][y] == 2)
								{
								textcolor(BLACK);
								cprintf("*");
								}
							else
								cprintf(" ");
						}
					}
coordenadas(22);
textcolor(15);
gotoxy(30,3);
cprintf("JUGADOR A:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
cprintf(" t");textcolor(10);cprintf("  Tira una bomba");
_setcursortype(_SOLIDCURSOR);
gotoxy(1,1);
x=1;
y=1;

do
{
ota = getch();
switch(ota)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

	case'T':case 't':
				if (matriz2[x][y] == 1)
				{
				textbackground(0);
				textcolor(15);	gotoxy(3,13);  cprintf("Hundido!!!");
				barcohun1();
				sound(580);delay(300);nosound();
				sound(700);delay(300);nosound();
				sound(800);delay(200);nosound();
				sound(950);delay(300);nosound();
				sound(800);delay(200);nosound();
				sound(950);delay(500);nosound();
				matriz2[x][y] = 3;
				cdbb = cdbb - 1;
				cdbha = cdbha + 1;
				if((cdba!=0) && (cdbb!=0))
				{
				tiroa();
				}
				else
				diceganador();
				}
			else
				{
				textbackground(0);
				textcolor(3);	gotoxy(3,13);	cprintf("Agua");
				matriz2[x][y] = 2;
				textbackground(0);
				textcolor(WHITE);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(CYAN);
						if (matriz2[x][y] == 3)
							{
							textcolor(RED);
							cprintf("X");
							}
						else
							if (matriz2[x][y] == 2)
								{
								textcolor(BLACK);
								cprintf("*");
								}
							else
								cprintf(" ");
						}
					}
				getch();
				comienzo();
				}
			break;
	}
}
while(ota!='v' && ota!='V');
comienzo();
}



//TIRO DEL JUGADOR B A LOS BARCOS DEL JUGADOR A
void tirob(void)
{
textbackground(0);
clrscr();
textbackground(0);
				textcolor(WHITE);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(CYAN);
						if (matriz1[x][y] == 3)
							{
							textcolor(RED);
							cprintf("X");
							}
						else
							if (matriz1[x][y] == 2)
								{
								textcolor(BLACK);
								cprintf("*");
								}
							else
								cprintf(" ");
						}
					}
coordenadas(22);
textcolor(15);
gotoxy(30,3);
cprintf("JUGADOR B:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
cprintf(" t");textcolor(10);cprintf("  Tira una bomba");
_setcursortype(_SOLIDCURSOR);
gotoxy(1,1);
x=1;
y=1;

do
{
otb = getch();
switch(otb)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

	case'T':case 't':  if (matriz1[x][y] == 1)
				{
				textbackground(0);
				textcolor(15);	gotoxy(3,13);  cprintf("Hundido!!!");
				barcohun1();
				sound(580);delay(300);nosound();
				sound(700);delay(300);nosound();
				sound(800);delay(200);nosound();
				sound(950);delay(300);nosound();
				sound(800);delay(200);nosound();
				sound(950);delay(500);nosound();
				matriz1[x][y] = 3;
				cdba = cdba - 1;
				cdbhb = cdbhb + 1;
				if((cdba!=0) && (cdbb!=0))
				{
				tirob();
				}
				else
				diceganador();
				}
			else
				{
				textbackground(0);
				textcolor(3);	gotoxy(3,13);	cprintf("Agua");
				matriz1[x][y] = 2;
				textbackground(0);
				textcolor(WHITE);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(CYAN);
						if (matriz1[x][y] == 3)
							{
							textcolor(RED);
							cprintf("X");
							}
						else
							if (matriz1[x][y] == 2)
								{
								textcolor(BLACK);
								cprintf("*");
								}
							else
								cprintf(" ");
						}
					}
				getch();
				comienzo();
				}
			break;
	}
}
while(otb!='v' && otb!='V');
comienzo();
}




//VISUALIZA LA TABLA DEL JUGADOR A
void verta(void)
{
textbackground(0);
textcolor(WHITE);
clrscr();
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(CYAN);
		if (matriz1[x][y] == 1)
			{
			textcolor(BLUE + BLINK);
			cprintf("");
			}
		else
			if (matriz1[x][y] == 3)
				{
				textcolor(RED);
				cprintf("X");
				}
			else
				if (matriz1[x][y] == 2)
					{
					textcolor(BLACK);
					cprintf("*");
					}
				else
					cprintf(" ");
		}
	}
	coordenadas(22);
	getch();
	comienzo();
}




//VISUALIZA LA TABLA DEL JUGADOR B
void vertb(void)
{
textbackground(0);
textcolor(WHITE);
clrscr();
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(CYAN);
		if (matriz2[x][y] == 1)
			{
			textcolor(BLUE + BLINK);
			cprintf("");
			}
		else
			if (matriz2[x][y] == 3)
				{
				textcolor(RED);
				cprintf("X");
				}
			else
				if (matriz2[x][y] == 2)
					{
					textcolor(BLACK);
					cprintf("*");
					}
				else
					cprintf(" ");
		}
	}
	coordenadas(22);
	getch();
	comienzo();
}




void sefijaencdb(void)
{

int m;
int er;

_setcursortype(_NOCURSOR);
textbackground(1);
clrscr();
textbackground(7);
textcolor(1);
gotoxy(13,12);	cprintf(" ERROR BARCOS DESCONOCIDOS PRODUCEN ERROR DESCONOCIDO ");
textbackground(1);
textcolor(15);
gotoxy(11,14);	cprintf("Detalles:");
gotoxy(11,15);	cprintf("DESCONOCIDO HUNDIRA ALEATORIAMENTE LOS BARCOS DESCONOCIDOS");
gotoxy(11,16);	cprintf("PARA UN JUEGO LIMPIO Y SIN ERRORES");
textcolor(15);
gotoxy(12,18);
cprintf("PRECIONE Entrar PARA Hundirlos O Esc PARA Volver:Aceptar");
textcolor(15);
gotoxy(61,18);
do
{
if(cdba>cdbb)
		{
          er=getch();
          if(er==13)
                    {
                    gotoxy(15,21); cprintf("ESTO TARDARA UN TIEMPO");
                    gotoxy(15,22); cprintf("HAY   BARCOS DE MAS ES EL TABLERO A");
                    do
		          {
                    for(x=1;x<=20;x++)
                         {
					for(y=1;y<=10;y++)
					      {
					      if(cdba!=cdbb)
					           {
					           if(matriz4[x][y]!=1)
					                 {
							       if(matriz1[x][y]==1)
							            {
							            gotoxy(18,22); textcolor(14); cprintf(" %d ",cdba-cdbb);
							            matriz1[x][y]=0;
							            cdba=cdba - 1;
							            }
							        else
							            {
							            matriz4[x][y]=1;
							            }
							       }
						      }
					      }
				     delay(1000);
				     }
			     }
                    while(cdba!=cdbb);
		          gotoxy(18,22); textcolor(14); cprintf(" %d ",cdbb-cdba);
		          gotoxy(25,23); cprintf("LA CANTIDAD DE BARCOS AHORA ES LA MISMA");
		          gotoxy(25,24); cprintf("  PRESIONE UNA TECLA PARA CONTINUAR");
		          getch();
		          }
          if(er==27)
                    {
                    textcolor(14 +BLINK);
                    gotoxy(15,21); cprintf("DESCONOCIDO SE CERRARA");
                    getch();
                    exit(0);
                    }
          }
	     else
if(cdba<cdbb)
		{
		er=getch();
          if(er==13)
                    {
                    gotoxy(15,21); cprintf("ESTO TARDARA UN TIEMPO");
                    gotoxy(15,22); cprintf("HAY   BARCOS DE MAS ES EL TABLERO B");
                    do
		          {
                    for(x=1;x<=20;x++)
                         {
				     for(y=1;y<=10;y++)
					      {
					      if(cdba!=cdbb)
					           {
					           if(matriz4[x][y]!=1)
					                 {
							       if(matriz2[x][y]==1)
							            {
							            gotoxy(18,22); textcolor(14); cprintf(" %d ",cdbb-cdba);
							            matriz2[x][y]=0;
							            cdbb=cdbb - 1;
							            }
							        else
							            {
							            matriz4[x][y]=1;
							            }
							       }
						      }
					      }
				     delay(1000);
				     }
			     }
                    while(cdba!=cdbb);
		          gotoxy(18,22); textcolor(14); cprintf(" %d ",cdbb-cdba);
		          gotoxy(25,23); cprintf("LA CANTIDAD DE BARCOS AHORA ES LA MISMA");
		          gotoxy(25,24); cprintf("  PRESIONE UNA TECLA PARA CONTINUAR");
		          getch();
		          }
          if(er==27)
                    {
                    textcolor(14 +BLINK);
                    gotoxy(15,21); cprintf("DESCONOCIDO SE CERRARA");
                    getch();
                    exit(0);
                    }
          }
}
while(cdba!=cdbb);
m=rand() %2;
if(m==0)
	{
	dadosa();
	}
if(m==1)
	{
	dadosb();
	}
}


//ACA COMIENZA LA INTERFACE




//SEGUNDA ANIMACION DEL BARCO HUNDIDO
void barcohun1(void)
{
_setcursortype(_NOCURSOR);
sound(240);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("             лл                       л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                                    ллллл                  ");
     		gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
sound(110);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("              лл                      л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                                    ллллл                  ");
     		gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(220);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("               лл                     л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                                    ллллл                  ");
     		gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(210);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                лл                    л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                                    ллллл                  ");
     		gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(200);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                 лл                   л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                                    ллллл                  ");
     		gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(190);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                  лл                  л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                                    ллллл                  ");
     		gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(180);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                   лл                 л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                                    ллллл                  ");
     		gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(170);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                    лл                л                    ");
		     gotoxy(1,19);	cprintf("                                     ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
		     gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(160);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                     лл               л                    ");
		     gotoxy(1,19);	cprintf("                                     ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
	          gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(150);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                      лл              л                    ");
		     gotoxy(1,19);	cprintf("                                     ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
		     gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(140);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                       лл             л                    ");
		     gotoxy(1,19);	cprintf("                                     ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
		     gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(130);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                        лл            л                    ");
		     gotoxy(1,19);	cprintf("                                     ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
		     gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(120);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                         лл           л                    ");
		     gotoxy(1,19);	cprintf("                                     ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
	          gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(110);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                          лл          л                    ");
		     gotoxy(1,19);	cprintf("                                     ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
		     gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(100);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                           л          л                     ");
		     gotoxy(1,19);	cprintf("                            л        ллл                   ");
		     gotoxy(1,20);	cprintf("                                    ллллл                  ");
		     gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
		     gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(90);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
		     gotoxy(1,19);	cprintf("                            л        ллл                   ");
		     gotoxy(1,20);	cprintf("                             л      ллллл                  ");
		     gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
		     gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(80);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
     		gotoxy(1,19);	cprintf("                                     ллл                   ");
     		gotoxy(1,20);	cprintf("                             л      ллллл                  ");
     		gotoxy(1,21);	cprintf("                              л   ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
     		gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
     		gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(70);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                              л   ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллл ллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            лллл лллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            лллл  ллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            лллл  ллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллл ллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллл  лллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            лллл  ллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллл  лллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                                           ");
textcolor(15);	gotoxy(1,19);	cprintf("                                                           ");
textcolor(15);	gotoxy(1,20);	cprintf("                                      л                    ");
     		gotoxy(1,21);	cprintf("                                     ллл                   ");
     		gotoxy(1,22);	cprintf("                                    ллллл                  ");
     		gotoxy(1,23);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,24);	cprintf("                          ллллл  лллллллллллллллллл        ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,20);	cprintf("                                                           ");
textcolor(15);	gotoxy(1,21);	cprintf("                                                           ");
textcolor(15);	gotoxy(1,22);	cprintf("                                      л                    ");
     		gotoxy(1,23);	cprintf("                                     ллл                   ");
     		gotoxy(1,24);	cprintf("                                    ллллл                  ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,22);	cprintf("                                                           ");
textcolor(15);	gotoxy(1,23);	cprintf("                                      л                    ");
     		gotoxy(1,24);	cprintf("                                     ллл                   ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,23);	cprintf("                                                           ");
textcolor(15);	gotoxy(1,24);	cprintf("                                      л                    ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(50);
gotoxy(1,20);
textcolor(15);	gotoxy(1,24);	cprintf("                                                           ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(1000);
nosound();
}




//ANIMACION DEL LOADING
void loading(void)
{
_setcursortype(_NOCURSOR);

textbackground(0);

clrscr();

gotoxy(30,12); textcolor(7); cprintf("лллллллллллллллллллл");

textcolor(RED+BLINK); gotoxy(31,10); cprintf("CARGANDO ANIMACION");
gotoxy(40,12); textcolor(RED); textbackground(7); cprintf("0%");
gotoxy(30,12); delay(1000); cprintf("л");
gotoxy(31,12); delay(1000); cprintf("л");
gotoxy(39,12); textbackground(7); cprintf("10%");
gotoxy(32,12); delay(1000); cprintf("л");
gotoxy(33,12); delay(1000); cprintf("л");
gotoxy(39,12); textbackground(7); cprintf("20%");
gotoxy(34,12); delay(1000); cprintf("л");
gotoxy(35,12); delay(1000); cprintf("л");
gotoxy(39,12); textbackground(7); cprintf("30%");
gotoxy(36,12); delay(1000); cprintf("л");
gotoxy(37,12); delay(1000); cprintf("л");
gotoxy(39,12); textbackground(7); cprintf("40%");
gotoxy(38,12); delay(1000); cprintf("л");
gotoxy(39,12); delay(1000); cprintf("л");
gotoxy(39,12); textbackground(RED); textcolor(7); cprintf("5");
textcolor(RED); textbackground(7); cprintf("0%");
gotoxy(40,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(40,12); textbackground(RED); textcolor(7); cprintf("0");
gotoxy(41,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(39,12); textcolor(7); textbackground(RED); cprintf("60%");
gotoxy(42,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(43,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(39,12); textcolor(7); textbackground(RED); cprintf("70%");
gotoxy(44,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(45,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(39,12); textcolor(7); textbackground(RED); cprintf("80%");
gotoxy(46,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(47,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(39,12); textcolor(7); textbackground(RED); cprintf("90%");
gotoxy(48,12); textcolor(RED); delay(1000); cprintf("л");
gotoxy(49,12); textcolor(RED); delay(2000); cprintf("л");
gotoxy(38,12); textbackground(RED); textcolor(7); cprintf("100%");

delay(2400);
}


//PRIMERA ANIMACION DEL BARCO HUNDIENDOSE
void barcohun(void)
{
_setcursortype(_NOCURSOR);
clrscr();
textbackground(0);
clrscr();
textcolor(14 + BLINK);
gotoxy(9,1);	cprintf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(9,2);	cprintf("К                                                               К");
gotoxy(9,3);	cprintf("К                                                               К");
gotoxy(9,4);	cprintf("К                                                               К");
gotoxy(9,5);	cprintf("К                                                               К");
gotoxy(9,6);	cprintf("К                                                               К");
gotoxy(9,7);	cprintf("К                                                               К");
gotoxy(9,8);	cprintf("К                                                               К");
gotoxy(9,9);	cprintf("К                                                               К");
gotoxy(9,10);	cprintf("К                                                               К");
gotoxy(9,11);	cprintf("К                                                               К");
gotoxy(9,12);	cprintf("К                                                               К");
gotoxy(9,13);	cprintf("К                                                               К");
gotoxy(9,14);	cprintf("К                                                               К");
gotoxy(9,15);	cprintf("К                                                               К");
gotoxy(9,16);	cprintf("К                                                               К");
gotoxy(9,17);	cprintf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textcolor(14 + BLINK);
gotoxy(11,2);	cprintf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(11,3);	cprintf("К                                                           К");
gotoxy(11,4);	cprintf("К                                                           К");
gotoxy(11,5);	cprintf("К                                                           К");
gotoxy(11,6);	cprintf("К                                                           К");
gotoxy(11,5);	cprintf("К                                                           К");
gotoxy(11,6);	cprintf("К                                                           К");
gotoxy(11,7);	cprintf("К                                                           К");
gotoxy(11,8);	cprintf("К                                                           К");
gotoxy(11,9);	cprintf("К                                                           К");
gotoxy(11,10);	cprintf("К                                                           К");
gotoxy(11,11);	cprintf("К                                                           К");
gotoxy(11,12);	cprintf("К                                                           К");
gotoxy(11,13);	cprintf("К                                                           К");
gotoxy(11,14);	cprintf("К                                                           К");
gotoxy(11,15);	cprintf("К                                                           К");
gotoxy(11,16);	cprintf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textbackground(0);
textcolor(13);
delay(100);
gotoxy(12,3);	cprintf("                                                           ");delay(100);
gotoxy(12,4);	cprintf("  BBBB   AAAAAA  TTTTTTT  AAAAAA  L       L       AAAAAAA  ");delay(100);
gotoxy(12,5);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
gotoxy(12,6);	cprintf("  BBBB   AAAAAA     T     AAAAAA  L       L       AAAAAAA  ");delay(100);
gotoxy(12,7);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
gotoxy(12,8);	cprintf("  BBBB   A    A     T     A    A  LLLLLL  LLLLLL  A     A  ");delay(100);
gotoxy(12,9);	cprintf("                                                           ");delay(100);
gotoxy(12,10); 	cprintf("         NN   N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
gotoxy(12,11); 	cprintf("         NN   N  A    A   V      V  A    A  L              ");delay(100);
gotoxy(12,12);	cprintf("         N N  N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
gotoxy(12,13);	cprintf("         N  N N  A    A    V    V   A    A  L              ");delay(100);
gotoxy(12,14);	cprintf("         N   NN  A    A      VV     A    A  LLLLLL         ");delay(100);
gotoxy(12,15);	cprintf("                                                           ");delay(100);

textbackground(1);
textcolor(15);
delay(100);
gotoxy(12,15);	cprintf("                                                           ");delay(100);
gotoxy(12,14);	cprintf("         N   NN  A    A      VV     A    A  LLLLLL         ");delay(100);
gotoxy(12,13);	cprintf("         N  N N  A    A    V    V   A    A  L              ");delay(100);
gotoxy(12,12);	cprintf("         N N  N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
gotoxy(12,11); 	cprintf("         NN   N  A    A   V      V  A    A  L              ");delay(100);
gotoxy(12,10); 	cprintf("         NN   N  AAAAAA   V      V  AAAAAA  L              ");delay(100);
gotoxy(12,9);	cprintf("                                                           ");delay(100);
gotoxy(12,8);	cprintf("  BBBB   A    A     T     A    A  LLLLLL  LLLLLL  A     A  ");delay(100);
gotoxy(12,7);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
gotoxy(12,6);	cprintf("  BBBB   AAAAAA     T     AAAAAA  L       L       AAAAAAA  ");delay(100);
gotoxy(12,5);	cprintf("  B   B  A    A     T     A    A  L       L       A     A  ");delay(100);
gotoxy(12,4);	cprintf("  BBBB   AAAAAA  TTTTTTT  AAAAAA  L       L       AAAAAAA  ");delay(100);
gotoxy(12,3);	cprintf("                                                           ");delay(100);


textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                   л                    ");
		gotoxy(1,19);	cprintf("                  ллл                   ");
		gotoxy(1,20);	cprintf("                 ллллл                  ");
		gotoxy(1,21);	cprintf("               ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("       ллллллллллллллллллллллллл        ");
		gotoxy(1,23);	cprintf("         ллллллллллллллллллллл          ");
		gotoxy(1,24);	cprintf("           ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                    л                    ");
		gotoxy(1,19);	cprintf("                   ллл                   ");
		gotoxy(1,20);	cprintf("                  ллллл                  ");
		gotoxy(1,21);	cprintf("                ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("        ллллллллллллллллллллллллл        ");
		gotoxy(1,23);	cprintf("          ллллллллллллллллллллл          ");
		gotoxy(1,24);	cprintf("            ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                     л                    ");
		gotoxy(1,19);	cprintf("                    ллл                   ");
		gotoxy(1,20);	cprintf("                   ллллл                  ");
		gotoxy(1,21);	cprintf("                 ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("         ллллллллллллллллллллллллл        ");
		gotoxy(1,23);	cprintf("           ллллллллллллллллллллл          ");
		gotoxy(1,24);	cprintf("             ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                      л                    ");
		gotoxy(1,19);	cprintf("                     ллл                   ");
		gotoxy(1,20);	cprintf("                    ллллл                  ");
		gotoxy(1,21);	cprintf("                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("          ллллллллллллллллллллллллл        ");
		gotoxy(1,23);	cprintf("            ллллллллллллллллллллл          ");
		gotoxy(1,24);	cprintf("              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                       л                    ");
		gotoxy(1,19);	cprintf("                      ллл                   ");
		gotoxy(1,20);	cprintf("                     ллллл                  ");
		gotoxy(1,21);	cprintf("                   ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("           ллллллллллллллллллллллллл        ");
		gotoxy(1,23);	cprintf("             ллллллллллллллллллллл          ");
		gotoxy(1,24);	cprintf("               ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                        л                    ");
		gotoxy(1,19);	cprintf("                       ллл                   ");
		gotoxy(1,20);	cprintf("                      ллллл                  ");
		gotoxy(1,21);	cprintf("                    ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("            ллллллллллллллллллллллллл        ");
		gotoxy(1,23);	cprintf("              ллллллллллллллллллллл          ");
		gotoxy(1,24);	cprintf("                ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                         л                    ");
			gotoxy(1,19);	cprintf("                        ллл                   ");
			gotoxy(1,20);	cprintf("                       ллллл                  ");
			gotoxy(1,21);	cprintf("                     ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("             ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("               ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                 ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                          л                    ");
			gotoxy(1,19);	cprintf("                         ллл                   ");
			gotoxy(1,20);	cprintf("                        ллллл                  ");
			gotoxy(1,21);	cprintf("                      ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("              ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                  ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                           л                    ");
			gotoxy(1,19);	cprintf("                          ллл                   ");
			gotoxy(1,20);	cprintf("                         ллллл                  ");
			gotoxy(1,21);	cprintf("                       ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("               ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                 ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                   ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                            л                    ");
			gotoxy(1,19);	cprintf("                           ллл                   ");
			gotoxy(1,20);	cprintf("                          ллллл                  ");
			gotoxy(1,21);	cprintf("                        ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                  ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                    ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                             л                    ");
			gotoxy(1,19);	cprintf("                            ллл                   ");
			gotoxy(1,20);	cprintf("                           ллллл                  ");
			gotoxy(1,21);	cprintf("                         ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                 ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                   ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                     ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                              л                    ");
			gotoxy(1,19);	cprintf("                             ллл                   ");
			gotoxy(1,20);	cprintf("                            ллллл                  ");
			gotoxy(1,21);	cprintf("                          ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                  ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                    ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                      ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                               л                    ");
			gotoxy(1,19);	cprintf("                              ллл                   ");
			gotoxy(1,20);	cprintf("                             ллллл                  ");
			gotoxy(1,21);	cprintf("                           ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                   ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                     ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                       ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                л                    ");
			gotoxy(1,19);	cprintf("                               ллл                   ");
			gotoxy(1,20);	cprintf("                              ллллл                  ");
			gotoxy(1,21);	cprintf("                            ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                    ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                      ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                        ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                 л                    ");
			gotoxy(1,19);	cprintf("                                ллл                   ");
			gotoxy(1,20);	cprintf("                               ллллл                  ");
			gotoxy(1,21);	cprintf("                             ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                     ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                       ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                         ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                  л                    ");
			gotoxy(1,19);	cprintf("                                 ллл                   ");
			gotoxy(1,20);	cprintf("                                ллллл                  ");
			gotoxy(1,21);	cprintf("                              ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                      ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                        ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                          ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                   л                    ");
			gotoxy(1,19);	cprintf("                                  ллл                   ");
			gotoxy(1,20);	cprintf("                                 ллллл                  ");
			gotoxy(1,21);	cprintf("                               ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                       ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                         ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                           ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                    л                    ");
			gotoxy(1,19);	cprintf("                                   ллл                   ");
			gotoxy(1,20);	cprintf("                                  ллллл                  ");
			gotoxy(1,21);	cprintf("                                ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                        ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                          ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                            ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                     л                    ");
			gotoxy(1,19);	cprintf("                                    ллл                   ");
			gotoxy(1,20);	cprintf("                                   ллллл                  ");
			gotoxy(1,21);	cprintf("                                 ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                         ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                           ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                             ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("                                      л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
sound(380);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("л                                     л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(370);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("лл                                    л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
textbackground(0);
sound(360);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf(" лл                                   л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(350);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("  лл                                  л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(340);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("   лл                                 л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(330);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("    лл                                л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(320);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("     лл                               л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(310);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("      лл                              л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(300);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("       лл                             л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(290);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("        лл                            л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(280);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("         лл                           л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(270);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("          лл                          л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(260);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("           лл                         л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
delay(100);
nosound();
textbackground(0);
sound(250);
gotoxy(1,20);
textcolor(15);	gotoxy(1,18);	cprintf("            лл                        л                    ");
			gotoxy(1,19);	cprintf("                                     ллл                   ");
			gotoxy(1,20);	cprintf("                                    ллллл                  ");
			gotoxy(1,21);	cprintf("                                  ллллллллл                ");
textcolor(6);	gotoxy(1,22);	cprintf("                          ллллллллллллллллллллллллл        ");
			gotoxy(1,23);	cprintf("                            ллллллллллллллллллллл          ");
			gotoxy(1,24);	cprintf("                              ллллллллллллллллл            ");
textcolor(3);	gotoxy(1,25);	cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
}




//MUSICA DEL JUEGO "POPEYE"
void musica(void)
{
sound(500);delay(300);nosound();
sound(600);delay(300);nosound();
sound(600);delay(300);nosound();
sound(600);delay(300);nosound();
sound(540);delay(300);nosound();
sound(500);delay(300);nosound();
sound(600);delay(300);nosound();
sound(600);delay(300);nosound();
sound(700);delay(300);nosound();
sound(550);delay(300);nosound();
sound(700);delay(300);nosound();
sound(850);delay(300);nosound();
sound(700);delay(300);nosound();
sound(600);delay(300);nosound();
sound(600);delay(300);nosound();
sound(780);delay(300);nosound();
sound(700);delay(300);nosound();
sound(800);delay(300);nosound();
sound(840);delay(300);nosound();
sound(800);delay(300);nosound();
sound(700);delay(300);nosound();
sound(600);delay(300);nosound();
sound(700);delay(300);nosound();
sound(600);delay(300);nosound();
sound(500);delay(300);nosound();
sound(600);delay(300);nosound();
sound(600);delay(300);nosound();
sound(600);delay(300);nosound();
sound(600);delay(300);nosound();
sound(700);delay(300);nosound();
sound(800);delay(300);nosound();
sound(850);delay(300);nosound();
}




//MUESTRA LOS NOMBRES DE LOS CREADORES
void creditos(void)
{
_setcursortype(_NOCURSOR);
clrscr();
barcohun1();
gotoxy(1,10); 	printf("Juan Pablo Martinez");
gotoxy(1,10); 	printf("   Juan Pablo Martinez");
gotoxy(1,10); 	printf("      Juan Pablo Martinez");
gotoxy(1,10); 	printf("         Juan Pablo Martinez");
gotoxy(1,10); 	printf("            Juan Pablo Martinez");
gotoxy(1,10); 	printf("               Juan Pablo Martinez");
gotoxy(1,10); 	printf("                  Juan Pablo Martinez");
gotoxy(1,10); 	printf("                     Juan Pablo Martinez");
gotoxy(1,10); 	printf("                        Juan Pablo Martinez");
gotoxy(1,10); 	printf("                           Juan Pablo Martinez");
gotoxy(1,10); 	printf("                              Juan Pablo Martinez");
gotoxy(1,10); 	printf("                                 Juan Pablo Martinez");
gotoxy(1,10); 	printf("                                    Juan Pablo Martinez ");
gotoxy(1,10); 	printf("                                   Juan Pablo Martinez ");
gotoxy(1,10); 	printf("                                  Juan Pablo Martinez ");
getch();
menu();
}




//MUESTRA EL REGLAMENTO DEL JUEGO
void reglamento(void)
{
_setcursortype(_NOCURSOR);
clrscr();
textcolor(6);
gotoxy(33,2);
cprintf("REGLAMENTO");
textcolor(9);
gotoxy(2,4);
cprintf("Bienbenidos al juego Batalla Naval!!");
gotoxy(1,6);
cprintf("El juego consiste en hundir todos los barcos del oponente antes que hundan los  ");
cprintf("nuestros. Cada jugador tendr  una tabla donde colocar sus barcos y otra para    ");
cprintf("hundir los de su contrincante. Una vez dentro de la tabla deber n ingresar la   ");
cprintf("misma cantidad de barcos los dos jugadores para que el juego se desarrolle de    ");
cprintf("forma normal sin que intervenga el juez derribando los barcos que sobran de uno ");
cprintf("El juego termina cuando uno de los jugadores elimina todos los barcos del otro. ");
cprintf("En tal caso el juez decidira quien fue el ganador del juego.                    ");
cprintf("El juez les desea suerte a el o los jugadores y no hagan trampa!!               ");
gotoxy(28,15);
getch();
textcolor(14+BLINK);
cprintf("LOS ESTARE VIJILANDO!!");


getch();
}



//PRESENTACION RESUMIDA EN FUNCIONES
void presentacion(void)
{
loading();
barcohun();
barcohun1();
musica();
menu();
}




//MUESTRA LA TABLA DE COORDENADAS X , Y
void coordenadas(int v)
{
_setcursortype(_NOCURSOR);
textbackground(0);
textcolor(14);
gotoxy(v,1);	cprintf("1");
gotoxy(v,2);	cprintf("2");
gotoxy(v,3);	cprintf("3");
gotoxy(v,4);	cprintf("4");
gotoxy(v,5);	cprintf("5");
gotoxy(v,6);	cprintf("6");
gotoxy(v,7);	cprintf("7");
gotoxy(v,8);	cprintf("8");
gotoxy(v,9);	cprintf("9");
gotoxy(v,10);	cprintf("10");
gotoxy(v-21,11);	cprintf("12345678911111111112");
gotoxy(1,12);	cprintf("         01234567890");
}


//ACA COMIENZA EL JUEGO JUGADOR VS PC


//MENU SECUNDARIO DE TIPOS DE JUEGO
void menu2(void)
{
_setcursortype(_NOCURSOR);
do
{
textbackground(0);
clrscr();
textcolor(14);    gotoxy(4,4);      cprintf("MENU");
textcolor(2);     gotoxy(11,5);     cprintf("1 JUGADOR");
		  gotoxy(11,6);     cprintf("2 JUGADORES ");
textcolor(15);    gotoxy(11,8);     cprintf("0 VOLVER");
textcolor(14);    gotoxy(4,10);     cprintf("OPCION:");

op5=getch();
switch(op5)
	   {
	   case '1':	boton();
			tjapc();
			break;
	   case '2':    boton();
			menu3();
			break;
	   }
}
while(op5!='0');
exit(0);
}



//TABLA DEL JUGADOR A VS PC
void tjapc(void)
{

iniciomatriz1();

clrscr();
coordenadas(22);
textcolor(15);
gotoxy(30,3);
cprintf("JUGADOR A:\n");
textcolor(12);
textbackground(1);
gotoxy(30,5);
cprintf(" m");textcolor(10);cprintf("  Colocar barco ");
gotoxy(30,6); 		    cprintf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,7);
cprintf(" d");textcolor(10);cprintf("  Borrar barco  ");
gotoxy(30,8); 		    cprintf("                  ");
textcolor(12);
textbackground(1);
gotoxy(30,9);
cprintf(" V");textcolor(10);cprintf("olver           ");

for(x=1;x<=20;x++)
{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(CYAN);
		cprintf(" ");
		}
}

gotoxy(1,1);
x=1;
y=1;

_setcursortype(_SOLIDCURSOR);
do
{
ota = getch();
switch(ota)
	{
     case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

	case 'm':
		if ((cdba<10) && (matriz1[x][y]!=1))
		{
		{
		textcolor(BLUE);
		cprintf("");
		cdba = cdba + 1;
		}
		if (x < 20)
			{
			matriz1[x][y] = 1;
			x = x+1;
			}

		else
			{
			gotoxy(x,y);
			matriz1[x][y] = 1;
			}
		}
	else    if(cdba==6)
		{
		x = x + 1;
		}


		break;

	case'D':case 'd':if(matriz1[x][y]!=0)
		{
		if (x<20)
		{
		textcolor(WHITE);
		cprintf(" ");
		cdba = cdba - 1;
		matriz1[x][y]=0;
		x=x+1;
		}
		else
		if (x==20)
			{
			textcolor(WHITE);
			cprintf(" ");
			cdba = cdba - 1;
			matriz1[20][y]=0;
			gotoxy(20,y);
			}

		}
		else
			x=x;

		break;
	}
}
while(ota!='v' && ota!='V');
tjpc(); //iniciallizo la matriz de la pc
tiroapc();
}



//TIRO DEL PC
void tiroapc(void)
{
textbackground(0);
clrscr();
vertapc();
textbackground(0);
				textcolor(WHITE);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(CYAN);
						if (matriz3[x][y] == 3)
							{
							textcolor(RED);
							cprintf("X");
							}
						else
							if (matriz3[x][y] == 2)
								{
								textcolor(BLACK);
								cprintf("*");
								}
							else
								cprintf(" ");
						}
					}
coordenadas(22);
textcolor(15);
gotoxy(4,14); cprintf("Tabla del PC");
textcolor(15);
gotoxy(24,3);
cprintf("JUGADOR A:\n");
textcolor(12);
textbackground(1);
gotoxy(24,5);
cprintf("t");textcolor(10);cprintf("  Tirar bomba");
textcolor(12);
textbackground(1);
gotoxy(24,9);
cprintf("S");textcolor(10);cprintf("alir del juego");
gotoxy(1,1);
x=1;
y=1;
_setcursortype(_SOLIDCURSOR);
do
{
ota = getch();
switch(ota)
	{
	case 77: if (x<20)
				{
				x = x + 1;
				gotoxy(x,y);
				}
			else
				if(y!=10)
					{
					y=y+1;
					x=1;
					}
				else
				if((y==10) && (x==20))
					{
					x=x-20;
					y=y;
					}
		break;

	case 75: if (x>1)
				{
				x = x - 1;
				gotoxy(x,y);
				}
			else
				if(y!=1)
					{
					y=y-1;
					x=20;
					}
				else
				if((x==1) && (y==1))
					{
					x=x+20;
					y=y;
					}
		break;

	case 72: if (y > 1)
				{
				y = y - 1;
				gotoxy(x,y);
				}
			else
				if(y==1)
					{
					y=y+9;
					x=x;
					}
			break;

	case 80: if (y < 10)
				{
				y = y + 1;
				gotoxy(x,y);
				}
			else
				if(y==10)
					{
					y=y-9;
					x=x;
					}
		break;

	case 'T':case 't':  if (matriz3[x][y] == 1)
				{
				textcolor(15);	gotoxy(3,13);  cprintf("Hundido!!!");
				barcohun1();
			sound(580);delay(300);nosound();
			sound(700);delay(300);nosound();
			sound(800);delay(200);nosound();
			sound(950);delay(300);nosound();
			sound(800);delay(200);nosound();
			sound(950);delay(500);nosound();
				matriz3[x][y] = 3;
				cdbpc = cdbpc - 1;
				cdbha = cdbha + 1;
				diceganavspc();
				tiroapc();
				}
			else
				{
				textcolor(3);	gotoxy(3,13);	cprintf("Agua");
				matriz3[x][y] = 2;
				textbackground(0);
				textcolor(WHITE);
				for(x=1;x<=20;x++)
					{
					for(y=1;y<=10;y++)
						{
						gotoxy(x,y);
						textbackground(CYAN);
						if (matriz3[x][y] == 3)
							{
							textcolor(RED);
							cprintf("X");
							}
						else
							if (matriz3[x][y] == 2)
								{
								textcolor(BLACK);
								cprintf("*");
								}
							else
								cprintf(" ");
						}
					}
				getch();
				tiropc();
				}
			break;
	}
}
while(ota!='s' && ota!='S');
boton();
textbackground(0);
textcolor(10);
gotoxy(3,15);cprintf("DECEA SALIR DEL JUEGO? s/n");
op6=getch();
switch(op6)
	{
	case'S':case 's':	boton();
					menu();
					break;

	case 'n': 	     boton();
					tiroapc();
					break;
	}
}



//VISUALIZA LA TABLA DEL JUGADOR A VS PC
void vertapc(void)
{
textbackground(0);
textcolor(WHITE);
clrscr();
for(x=40;x<60;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(CYAN);
		if (matriz1[x-39][y] == 1)
			{
			textcolor(BLUE + BLINK);
			cprintf("");
			}
		else
			if (matriz1[x-39][y] == 3)
				{
				textcolor(RED);
				cprintf("X");
				}
			else
				if (matriz1[x-39][y] == 2)
					{
					textcolor(BLACK);
					cprintf("*");
					}
				else
					cprintf(" ");
		}
	}
	coordenadas(61);
	textcolor(15);
	gotoxy(42,14); cprintf("Tabla del Jugador");
	}





//TABLA DEL PC
void tjpc(void)
{

iniciomatriz3(); //Inicializo tablero jugador 3

for (x=3;x<=17;x++)
	{
	for (y=2;y<=9;y++)
		{
		gotoxy(x,y);
		textbackground(3);
		if(cdbpc<=cdba)
			{
			gotoxy(x,y);
			matriz3[x][y]=rand() % 2;
			if(matriz3[x][y]==1)
				{
				textcolor(1);
				cprintf("");
				cdbpc=cdbpc+1;
				}
			else
				{
				textcolor(0);
				cprintf(" ");
				matriz3[x][y]=0;
				}
			}
		else
			{
			textcolor(0);
			cprintf(" ");
			matriz3[x][y]=0;
			}
		}
	}
coordenadas(22);
}



//TIRO DEL PC VS JUGADOR A
void tiropc(void)
{
textbackground(0);
textcolor(WHITE);
clrscr();
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(CYAN);
		if (matriz1[x][y] == 3)
			{
			textcolor(RED);
			cprintf("X");
			}
		else
			if (matriz1[x][y] == 2)
				{
				textcolor(BLACK);
				cprintf("*");
				}
			else
				cprintf(" ");
		}
	}
coordenadas(22);
textbackground(0);
textcolor(6);	gotoxy(30,12);	cprintf("PC\n\n");


x=rand() % 21;
y=rand() % 11;


if (matriz4[x][y] == 0)// 0 NUNCA TIRO    1 YA TIRO
	{
	if (matriz1[x][y] == 1)
		{
		textcolor(5);	gotoxy(3,13);	cprintf("Hundido!!!");

		matriz1[x][y] = 3;
		matriz4[x][y] = 1;

		cdba = cdba - 1;
		cdbhpc=cdbhpc + 1;


		sound(580);delay(300);nosound();
		sound(700);delay(300);nosound();
		sound(800);delay(200);nosound();
		sound(950);delay(300);nosound();
		sound(800);delay(200);nosound();
		sound(950);delay(500);nosound();
		getch();
		diceganavspc();
		tiropc();
		}

	else
		{

		matriz1[x][y] = 2;
		matriz4[x][y] = 1;
		tiroapc();
		}
	}
else
tiropc();
}





//VISUALIZA LA TABLA DEL PC VS JUGADOR A
void vertpc(void)
{

textbackground(0);
textcolor(WHITE);
for(x=1;x<=20;x++)
	{
	for(y=1;y<=10;y++)
		{
		gotoxy(x,y);
		textbackground(CYAN);
			if (matriz3[x][y] == 3)
				{
				textcolor(RED);
				cprintf("X");
				}
			else
				if (matriz3[x][y] == 2)
					{
					textcolor(BLACK);
					cprintf("*");
					}
				else
				cprintf(" ");
		}
	}
}



//DICE EL GANADOR DEL JUEGO H VS PC
void diceganavspc(void)
{
clrscr();
textbackground(0);
if (cdbpc==0)
	{

	textbackground(1);
	textcolor(15 + BLINK);
cprintf("                                                    ");
cprintf("                                                    ");
cprintf("     Ha ganado el jugador A!!                       ");
cprintf("                                                    ");
cprintf("                                ");

textcolor(15);
gotoxy(19,7);   	cprintf("ЩЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(19,8);		cprintf("К  К   К               К");
gotoxy(19,9);   	cprintf("ЬЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
gotoxy(19,10);		cprintf("К  К   К               К");
gotoxy(19,11);   	cprintf("ШЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textbackground(0);
textcolor(15);
gotoxy(20,8);	cprintf("A К  %dКbarcos hundidos", cdbha);
gotoxy(20,10);	cprintf("pcК  %dКbarcos hundidos", cdbhpc);
getch();
menu();
	}
if (cdba==0)
	{

	textbackground(1);
	textcolor(15 + BLINK);
cprintf("                                                    ");
cprintf("                                                    ");
cprintf("     Ha ganado el computador!!                       ");
cprintf("                                                    ");
cprintf("                                ");


textcolor(15);
gotoxy(19,9);   	cprintf("ЩЭЭЫЭЭЭЫЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
gotoxy(19,10);		cprintf("К  К   К               К");
gotoxy(19,11);   	cprintf("ЬЭЭЮЭЭЭЮЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЙ");
gotoxy(19,12);		cprintf("К  К   К               К");
gotoxy(19,13);   	cprintf("ШЭЭЪЭЭЭЪЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");

textbackground(0);
textcolor(15);
gotoxy(20,10);	cprintf("A К  %dКbarcos hundidos", cdbha);
gotoxy(20,12);	cprintf("pcК  %dКbarcos hundidos", cdbhpc);

getch();
menu();
}
}




//ACA COMIENZA LA PARTE DEL AZAR DE LOS JUGADORES

void conja1(void) /* Simula una clave de acceso */
{
   _setcursortype(_NOCURSOR);
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&cona1);
   menu3();
}


void conja2(void) /* Simula una clave de acceso */
{
   _setcursortype(_NOCURSOR);
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&cona2);
   if(cona1==cona2)
	{
	 verta();
	 }
   else
	 {
	 printf("Acceso denegado\n");
	 getch();
	 comienzo();
	 }
}

void conjb1(void) /* Simula una clave de acceso */
{
   _setcursortype(_NOCURSOR);
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&conb1);
   menu3();
}


void conjb2(void) /* Simula una clave de acceso */
{
   _setcursortype(_NOCURSOR);
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Introduce tu clave: ");
   scanf("%d",&conb2);
   if(conb1==conb2)
	{
	 vertb();
	 }
   else
	 {
	 printf("Acceso denegado\n");
	 getch();
	 comienzo();
	  }
}

void conja3(void) /* Simula una clave de acceso */
{
   _setcursortype(_NOCURSOR);
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Si es la primera vez que entras digita 0\n\n");
   printf("Introduce tu clave: ");
   scanf("%d",&cona2);
   if(cona1==cona2)
	{
	tja();
	}
   else
	 {
	 printf("Acceso denegado. Digite su nueva contraseЄa!!\n");
	 getch();
	 menu3();
	 }
}


void conjb3(void) /* Simula una clave de acceso */
{
   _setcursortype(_NOCURSOR);
   textbackground(1);
   textcolor(14);
   clrscr();
   printf("Si es la primera vez que entras digita 0\n\n");
   printf("Introduce tu clave: ");
   scanf("%d",&conb2);
   if(conb1==conb2)
	{
	tjb();
	}
   else
	 {
	 printf("Acceso denegado. Digite su nueva contraseЄa!!");
      getch();
	 menu3();
	 }
}



//TIRA LOS DADOS EL JUGADOR A
void dadosa(void)
{
int n1,n2;

clrscr();
randomize();
n1=rand() % 6;
printf("\tJuagador A:\n");
printf("Del 1 al 5,que nЃmero crees que pienso?? ");
scanf("%d",&n2);
if(n1==n2)
	{
	printf("\n\n%d\n\n",n1);
	printf("\n\nGanaste, empiezas tirando");
	delay(1500);
	tiroa();
	}
else
	{
	printf("\n\nPerdiste, el numero en el que pensaba era %d",n1);
	getch();
	dadosb();
	}
}

//TIRA LOS DADOS EL JUGADOR B
void dadosb(void)
{
int n1,n2;

clrscr();
randomize();
n1=rand() % 6;
printf("\tJuagador B:\n");
printf("Del 1 al 5,que nЃmero crees que pienso?? ");
scanf("%d",&n2);
if(n1==n2)
	{
	printf("\n\n%d\n\n",n1);
	printf("\n\nGanaste, empiezas tirando");
	delay(1500);
	tirob();
	}
else
	{
	printf("\n\nPerdiste, el numero en el que pensaba era %d",n1);
	getch();
	dadosa();
	}
}

