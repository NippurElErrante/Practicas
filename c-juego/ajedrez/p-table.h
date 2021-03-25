/*
  dejar puesto el tablero, las lineas los cuadros, etc.

  "Omega_Chess" Ver. 1.0 es un programa que simula un tablero
  para jugar ajedrez, entre 2 personas. propiedad de Omar Rodriguez Arce.
  sian@correoweb.com
  Ver archivo anexo: leeme.txt
*/


//*******************************************************************

void gra(void)/*toda  la  siguiente funcion es para utilizar
					 graficos y realmente no se para que sirva(la
					 copie de la ayuda  del compilador) pero  la
					 necesita el programa para funcionar*/
{
/* request auto detection */
int gdriver = DETECT, gmode, errorcode;
int xmax, ymax;

/* initialize graphics and local variables */
initgraph(&gdriver, &gmode, "");

/* read result of initialization */
errorcode = graphresult();
/* an error occurred */
if (errorcode != grOk)
{
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);
}
}


//*******************************************************************


void pre(void)
{
int inv, aux,basex,basex1, basey,basey1, x, x1, y, y1;
ret=999;
/*Definicion de color de fondo y linea*/
/*setbkcolor(15);
setcolor(16);*/

/*Inicio de el procedimiento para la presentacion*/
delay(ret);
line(5,5,5,470);      /*Linea vertical*/
delay(ret);
line(5,470,470,470);  /*Linea horizontal*/
delay(ret);
line(635,5,165,5);      /*Linea vertical1*/
delay(ret);
line(635,5,635,470);  /*Linea horizontal1*/

delay(ret);
basex=5;
basey=470;
basex1=635;
basey1=5;
aux=49;
/*Ciclos para realizar la malla*/
while(aux>8)
	  {
	  delay(ret);
	  for(x=5,y=15,y1=470,x1=635;x<630 && y<465;x++,y++,y1--,x1--)
		  {
		  line(basex,y,x,basey);
		  line(basex1,y1,x1,basey1);
		  x=x+aux;
		  y=y+aux;
		  y1=y1-aux;
		  x1=x1-aux;
		  }
	  aux=aux-10;/*10*/
	  }
line(165,5,635,15);
/*Poner titulos aqui*/
gotoxy(3,1);
printf("- OMEGA_CORP (c)-");
gotoxy(38,13);
printf("AJEDREZ");
gotoxy(20,15);
printf("® O M A R    R O D R I G U E Z   A R C E  ¯");
gotoxy(12,17);
printf("® LO UNICO QUE NUNCA PODRAN QUITARNOS SON NUESTRAS MENTES. ¯");

/*Espera para que lean los titulos*/
getch();
			/*9*/
/*setbkcolor(8);*/
/*setcolor();*/
/*Rellenar la malla con la siguiente funcion*/

	  setcolor(15);
          for(x=5,y=15,y1=470,x1=635;x<630 && y<465;x++,y++,y1--,x1--)
	  {
	  delay(3);
          line(basex,y,x,basey); 
          line(basex1,y1,x1,basey1);          
          } 



	  setcolor(16);
          for(x=5,y=15,y1=470,x1=635;x<630 && y<465;x++,y++,y1--,x1--)
	  {
	  delay(3);
          line(basex,y,x,basey); 
          line(basex1,y1,x1,basey1);          
          } 



	  setcolor(15);
          for(x=5,y=15,y1=470,x1=635;x<630 && y<465;x++,y++,y1--,x1--)
	  {
	  delay(3);
          line(basex,y,x,basey); 
          line(basex1,y1,x1,basey1);          
          } 


/*tiempo de espera final*/
delay(ret*2);
ret=100;
/*closegraph();*/
}


//*******************************************************************


void tablero(void)
{
int aux=0;
x=156;
y=20;
delay(ret*20);
/*lineas horizontales*/
while(aux!=9)
{
delay(ret);
line(x,y,x+328,y);
y=y+41;
aux++;
}
/*lineas verticales*/
aux=0;
x=156;
y=20;
while(aux!=9)
{
delay(ret);
line(x,y,x,y+328);
x=x+41;
aux++;
}
/*laterales de las coordenadas*/
gotoxy(19,2);
printf("A");
gotoxy(19,5);
printf("B");
gotoxy(19,8);
printf("C");
gotoxy(19,10);
printf("D");
gotoxy(19,13);
printf("E");
gotoxy(19,16);
printf("F");
gotoxy(19,18);
printf("G");
gotoxy(19,21);
printf("H");
/*numeros superiores*/
gotoxy(24,1);
printf("1");
gotoxy(29,1);
printf("2");
gotoxy(34,1);
printf("3");
gotoxy(39,1);
printf("4");
gotoxy(44,1);
printf("5");
gotoxy(49,1);
printf("6");
gotoxy(54,1);
printf("7");
gotoxy(59,1);
printf("8");
}

//*******************************************************************