/*
  Biblioteca para realizar las piezas.

  "Omega_Chess" Ver. 1.0 es un programa que simula un tablero
  para jugar ajedrez, entre 2 personas. propiedad de Omar Rodriguez Arce.
  sian@correoweb.com
  Ver archivo anexo: leeme.txt
*/


//*******************************************************************
/*variables para las funciones de las piezas y sus posiciones*/
int ret=100/*controla la velocidad de el juego*//*100*/,
	 estilo=0/*de que manera se rellena las cosas*/,
	 x=156, y=20;/*variables que rigen la posicion de las piezas*/


void torren(void)
{
/*rellenar la torre de color negro*/
estilo=1;
setfillstyle(estilo,16);

bar(x+13,y+13,x+17,y+21);  /*brazo izquierdo de la torre*/
bar(x+22,y+13,x+28,y+15); /*cabeza de la torre*/
bar(x+33,y+13,x+37,y+21); /*brazo derecho de latorre*/
bar(x+19,y+16,x+31,y+37);  /*cuerpo de la torre*/
bar(x+13,y+32,x+18,y+37);  /*base izquierda*/
bar(x+32,y+32,x+37,y+37); /*base derecha*/
/*como falta un poco a cada lado de los brazos de la torre para
  rellenarlos por completo */
bar(x+16,y+16,x+34,y+21); /*complemento*/

/*lineas que delimitan latorre */
setcolor(15);
line(x+12,y+12,x+18,y+12);
delay(ret);
line(x+18,y+12,x+18,y+15);
delay(ret);
line(x+18,y+15,x+21,y+15);
delay(ret);
line(x+21,y+15,x+21,y+12);
delay(ret);
line(x+21,y+12,x+29,y+12);
delay(ret);
line(x+29,y+12,x+29,y+15);
delay(ret);
line(x+29,y+15,x+32,y+15);
delay(ret);
line(x+32,y+15,x+32,y+12);
delay(ret);
line(x+32,y+12,x+38,y+12);
delay(ret);
line(x+38,y+12,x+38,y+22);
delay(ret);
line(x+38,y+22,x+32,y+22);
delay(ret);
line(x+32,y+22,x+32,y+31);
delay(ret);
line(x+32,y+31,x+38,y+31);
delay(ret);
line(x+38,y+31,x+38,y+38);
delay(ret);
line(x+38,y+38,x+12,y+38);
delay(ret);
line(x+12,y+38,x+12,y+31);
delay(ret);
line(x+12,y+31,x+18,y+31);
delay(ret);
line(x+18,y+31,x+18,y+22);
delay(ret);
line(x+18,y+22,x+12,y+22);
delay(ret);
line(x+12,y+22,x+12,y+12);
delay(ret);

}
//*******************************************************************
void torreb(void)
{

/*rellenar la torre de color negro*/
estilo=1;
setfillstyle(estilo,15);

bar(x+13,y+13,x+17,y+21);  /*brazo izquierdo de la torre*/
bar(x+22,y+13,x+28,y+15); /*cabeza de la torre*/
bar(x+33,y+13,x+37,y+21); /*brazo derecho de latorre*/
bar(x+19,y+16,x+31,y+37);  /*cuerpo de la torre*/
bar(x+13,y+32,x+18,y+37);  /*base izquierda*/
bar(x+32,y+32,x+37,y+37); /*base derecha*/
/*como falta un poco a cada lado de los brazos de la torre para
  rellenarlos por completo */
bar(x+16,y+16,x+34,y+21); /*complemento*/

/*lineas que delimitan latorre */
setcolor(16);
line(x+12,y+12,x+18,y+12);
delay(ret);
line(x+18,y+12,x+18,y+15);
delay(ret);
line(x+18,y+15,x+21,y+15);
delay(ret);
line(x+21,y+15,x+21,y+12);
delay(ret);
line(x+21,y+12,x+29,y+12);
delay(ret);
line(x+29,y+12,x+29,y+15);
delay(ret);
line(x+29,y+15,x+32,y+15);
delay(ret);
line(x+32,y+15,x+32,y+12);
delay(ret);
line(x+32,y+12,x+38,y+12);
delay(ret);
line(x+38,y+12,x+38,y+22);
delay(ret);
line(x+38,y+22,x+32,y+22);
delay(ret);
line(x+32,y+22,x+32,y+31);
delay(ret);
line(x+32,y+31,x+38,y+31);
delay(ret);
line(x+38,y+31,x+38,y+38);
delay(ret);
line(x+38,y+38,x+12,y+38);
delay(ret);
line(x+12,y+38,x+12,y+31);
delay(ret);
line(x+12,y+31,x+18,y+31);
delay(ret);
line(x+18,y+31,x+18,y+22);
delay(ret);
line(x+18,y+22,x+12,y+22);
delay(ret);
line(x+12,y+22,x+12,y+12);
delay(ret);
}
//*******************************************************************
void noeln(void)
{
/*rellenar al noel de color negro*/
estilo=1;
setfillstyle(estilo,16);
/*barras para la base y cuerpo*/
bar(x+15,y+33,x+35,y+38);
bar(x+22,y+28,x+28,y+38);
/*lo que falta*/
bar(x+20,y+15,x+27,y+28);
bar(x+26,y+17,x+32,y+21);
bar(x+16,y+16,x+17,y+20);
bar(x+17,y+16,x+19,y+22);
bar(x+28,y+25,x+29,y+29);
setcolor(16);
line(x+21,y+12,x+21,y+15);
line(x+20,y+14,x+25,y+14);
line(x+19,y+15,x+19,y+17);
line(x+18,y+23,x+28,y+16);
line(x+19,y+23,x+19,y+26);

/*lineas que delimitan al noel*/
setcolor(15);
line(x+21,y+11,x+22,y+13);
delay(ret);
line(x+22,y+13,x+26,y+14);
delay(ret);
line(x+26,y+14,x+32,y+17);
delay(ret);
line(x+32,y+17,x+32,y+21);
delay(ret);
line(x+32,y+21,x+27,y+21);
delay(ret);
line(x+27,y+21,x+27,y+22);
delay(ret);
line(x+27,y+22,x+31,y+28);
delay(ret);
line(x+31,y+28,x+28,y+29);
delay(ret);
line(x+28,y+29,x+28,y+33);
delay(ret);
line(x+28,y+33,x+35,y+33);
delay(ret);
line(x+35,y+33,x+35,y+38);
delay(ret);
line(x+35,y+38,x+15,y+38);
delay(ret);
line(x+15,y+38,x+15,y+33);
delay(ret);
line(x+15,y+33,x+22,y+33);
delay(ret);
line(x+22,y+33,x+22,y+29);
delay(ret);
line(x+22,y+29,x+19,y+28);
delay(ret);
line(x+19,y+28,x+16,y+20);
delay(ret);
line(x+16,y+20,x+16,y+16);
delay(ret);
line(x+16,y+16,x+20,y+13);
delay(ret);
line(x+20,y+13,x+21,y+11);
}
//*******************************************************************
void noelb(void)
{
/*rellenar al noel de color blanco*/
estilo=1;
setfillstyle(estilo,15);
/*barras para la base y cuerpo*/
bar(x+15,y+33,x+35,y+38);
bar(x+22,y+28,x+28,y+38);
/*lo que falta*/
bar(x+20,y+15,x+27,y+28);
bar(x+26,y+17,x+32,y+21);
bar(x+16,y+16,x+17,y+20);
bar(x+17,y+16,x+19,y+22);
bar(x+28,y+25,x+29,y+29);
setcolor(15);
line(x+21,y+12,x+21,y+15);
line(x+20,y+14,x+25,y+14);
line(x+19,y+15,x+19,y+17);
line(x+18,y+23,x+28,y+16);
line(x+19,y+23,x+19,y+26);

/*lineas que delimitan al noel*/
setcolor(16);
line(x+21,y+11,x+22,y+13);
delay(ret);
line(x+22,y+13,x+26,y+14);
delay(ret);
line(x+26,y+14,x+32,y+17);
delay(ret);
line(x+32,y+17,x+32,y+21);
delay(ret);
line(x+32,y+21,x+27,y+21);
delay(ret);
line(x+27,y+21,x+27,y+22);
delay(ret);
line(x+27,y+22,x+31,y+28);
delay(ret);
line(x+31,y+28,x+28,y+29);
delay(ret);
line(x+28,y+29,x+28,y+33);
delay(ret);
line(x+28,y+33,x+35,y+33);
delay(ret);
line(x+35,y+33,x+35,y+38);
delay(ret);
line(x+35,y+38,x+15,y+38);
delay(ret);
line(x+15,y+38,x+15,y+33);
delay(ret);
line(x+15,y+33,x+22,y+33);
delay(ret);
line(x+22,y+33,x+22,y+29);
delay(ret);
line(x+22,y+29,x+19,y+28);
delay(ret);
line(x+19,y+28,x+16,y+20);
delay(ret);
line(x+16,y+20,x+16,y+16);
delay(ret);
line(x+16,y+16,x+20,y+13);
delay(ret);
line(x+20,y+13,x+21,y+11);
}

//*******************************************************************
void alfiln(void)
{
/*rellenar el alfil de color negro*/
estilo=1;
setfillstyle(estilo,16);


bar(x+23,y+13,x+27,y+34); /*cuerpo*/
bar(x+16,y+34,x+34,y+37); /*base*/
setcolor(16);
/*iniciando solapa superior*/
								  /*parte izquierda*/
line(x+23,y+15,x+21,y+13);
line(x+23,y+15,x+22,y+13);
line(x+23,y+15,x+23,y+13);
								  /*parte derecha*/
line(x+27,y+15,x+27,y+13);
line(x+27,y+15,x+28,y+13);
line(x+27,y+15,x+29,y+13);

/*iniciando solapa inferior*/
								  /*parte izquierda*/
line(x+23,y+24,x+19,y+19);
line(x+23,y+24,x+20,y+19);
line(x+23,y+24,x+21,y+19);
line(x+23,y+24,x+22,y+19);
line(x+23,y+24,x+23,y+19);
line(x+23,y+24,x+24,y+19);
								  /*parte derecha*/
line(x+27,y+24,x+31,y+19);
line(x+27,y+24,x+30,y+19);
line(x+27,y+24,x+29,y+19);
line(x+27,y+24,x+28,y+19);
line(x+27,y+24,x+27,y+19);
line(x+27,y+24,x+26,y+19);


setcolor(15);
/*lineas que delimitan el alfil */
line(x+20,y+12,x+30,y+12);
delay(ret);
line(x+30,y+12,x+28,y+15);
delay(ret);
line(x+28,y+15,x+28,y+18);
delay(ret);
line(x+28,y+18,x+32,y+18);
delay(ret);
line(x+32,y+18,x+28,y+24);
delay(ret);
line(x+28,y+24,x+28,y+33);
delay(ret);
line(x+28,y+33,x+35,y+33);
delay(ret);
line(x+35,y+33,x+35,y+38);
delay(ret);
line(x+35,y+38,x+15,y+38);
delay(ret);
line(x+15,y+38,x+15,y+33);
delay(ret);
line(x+15,y+33,x+22,y+33);
delay(ret);
line(x+22,y+33,x+22,y+24);
delay(ret);
line(x+22,y+24,x+18,y+18);
delay(ret);
line(x+18,y+18,x+22,y+18);
delay(ret);
line(x+22,y+18,x+22,y+15);
delay(ret);
line(x+22,y+15,x+20,y+12);
delay(ret);
}
//*******************************************************************
void alfilb(void)
{
/*rellenar el alfil de color blanco*/
estilo=1;
setfillstyle(estilo,15);

bar(x+23,y+13,x+27,y+34); /*cuerpo*/
bar(x+16,y+34,x+34,y+37); /*base*/
setcolor(15);
/*iniciando solapa superior*/
								  /*parte izquierda*/
line(x+23,y+15,x+21,y+13);
line(x+23,y+15,x+22,y+13);
line(x+23,y+15,x+23,y+13);
								  /*parte derecha*/
line(x+27,y+15,x+27,y+13);
line(x+27,y+15,x+28,y+13);
line(x+27,y+15,x+29,y+13);

/*iniciando solapa inferior*/
								  /*parte izquierda*/
line(x+23,y+24,x+19,y+19);
line(x+23,y+24,x+20,y+19);
line(x+23,y+24,x+21,y+19);
line(x+23,y+24,x+22,y+19);
line(x+23,y+24,x+23,y+19);
line(x+23,y+24,x+24,y+19);
								  /*parte derecha*/
line(x+27,y+24,x+31,y+19);
line(x+27,y+24,x+30,y+19);
line(x+27,y+24,x+29,y+19);
line(x+27,y+24,x+28,y+19);
line(x+27,y+24,x+27,y+19);
line(x+27,y+24,x+26,y+19);


setcolor(16);
/*lineas que delimitan el alfil */
line(x+20,y+12,x+30,y+12);
delay(ret);
line(x+30,y+12,x+28,y+15);
delay(ret);
line(x+28,y+15,x+28,y+18);
delay(ret);
line(x+28,y+18,x+32,y+18);
delay(ret);
line(x+32,y+18,x+28,y+24);
delay(ret);
line(x+28,y+24,x+28,y+33);
delay(ret);
line(x+28,y+33,x+35,y+33);
delay(ret);
line(x+35,y+33,x+35,y+38);
delay(ret);
line(x+35,y+38,x+15,y+38);
delay(ret);
line(x+15,y+38,x+15,y+33);
delay(ret);
line(x+15,y+33,x+22,y+33);
delay(ret);
line(x+22,y+33,x+22,y+24);
delay(ret);
line(x+22,y+24,x+18,y+18);
delay(ret);
line(x+18,y+18,x+22,y+18);
delay(ret);
line(x+22,y+18,x+22,y+15);
delay(ret);
line(x+22,y+15,x+20,y+12);
delay(ret);
}
//*******************************************************************
void claun(void)
{
/*rellenar a la dama de color negro*/
setcolor(16);
/*pico 1*/
line(x+14,y+12,x+20,y+38);
line(x+14,y+12,x+21,y+38);
line(x+14,y+12,x+19,y+29);
/*pico 2 */
line(x+22,y+12,x+19,y+29);
line(x+22,y+12,x+20,y+29);
line(x+22,y+12,x+21,y+29);
line(x+22,y+12,x+22,y+29);
line(x+22,y+12,x+23,y+29);
line(x+22,y+12,x+24,y+29);
line(x+22,y+12,x+25,y+29);
/*pico3*/
line(x+28,y+12,x+25,y+29);
line(x+28,y+12,x+26,y+29);
line(x+28,y+12,x+27,y+29);
line(x+28,y+12,x+28,y+29);
line(x+28,y+12,x+29,y+29);
line(x+28,y+12,x+30,y+29);
line(x+28,y+12,x+31,y+29);
/*pico4*/
line(x+36,y+12,x+30,y+38);
line(x+36,y+12,x+29,y+38);
line(x+36,y+12,x+31,y+29);
/*cuerpo*/

estilo=1;
setfillstyle(estilo,16);
bar(x+20,y+29,x+30,y+38);
/*line(x+,y+,x+,y+);*/


/*lineas que delimitan a la dama*/
setcolor(15); /*cambio de color a blanco*/
line(x+14,y+12,x+19,y+29);
delay(ret);
line(x+19,y+29,x+22,y+12);
delay(ret);
line(x+22,y+12,x+25,y+29);
delay(ret);
line(x+25,y+29,x+28,y+12);
delay(ret);
line(x+28,y+12,x+31,y+29);
delay(ret);
line(x+31,y+29,x+36,y+12);
delay(ret);
line(x+36,y+12,x+30,y+38);
delay(ret);
line(x+30,y+38,x+20,y+38);
delay(ret);
line(x+20,y+38,x+14,y+12);
delay(ret);
}

//*******************************************************************

void claub(void)
{
/*rellenar a la dama de color blanco*/
setcolor(15);
/*pico 1*/
line(x+14,y+12,x+20,y+38);
line(x+14,y+12,x+21,y+38);
line(x+14,y+12,x+19,y+29);
/*pico 2 */
line(x+22,y+12,x+19,y+29);
line(x+22,y+12,x+20,y+29);
line(x+22,y+12,x+21,y+29);
line(x+22,y+12,x+22,y+29);
line(x+22,y+12,x+23,y+29);
line(x+22,y+12,x+24,y+29);
line(x+22,y+12,x+25,y+29);
/*pico3*/
line(x+28,y+12,x+25,y+29);
line(x+28,y+12,x+26,y+29);
line(x+28,y+12,x+27,y+29);
line(x+28,y+12,x+28,y+29);
line(x+28,y+12,x+29,y+29);
line(x+28,y+12,x+30,y+29);
line(x+28,y+12,x+31,y+29);
/*pico4*/
line(x+36,y+12,x+30,y+38);
line(x+36,y+12,x+29,y+38);
line(x+36,y+12,x+31,y+29);
/*cuerpo*/

estilo=1;
setfillstyle(estilo,15);
bar(x+20,y+29,x+30,y+38);

/*line(x+,y+,x+,y+);*/

/*lineas que delimitan a la dama*/
setcolor(16); /*cambio de color a negro*/
line(x+14,y+12,x+19,y+29);
delay(ret);
line(x+19,y+29,x+22,y+12);
delay(ret);
line(x+22,y+12,x+25,y+29);
delay(ret);
line(x+25,y+29,x+28,y+12);
delay(ret);
line(x+28,y+12,x+31,y+29);
delay(ret);
line(x+31,y+29,x+36,y+12);
delay(ret);
line(x+36,y+12,x+30,y+38);
delay(ret);
line(x+30,y+38,x+20,y+38);
delay(ret);
line(x+20,y+38,x+14,y+12);
delay(ret);
}

//*******************************************************************

void reyn(void)
{

/*rellenar al rey de color negro*/
estilo=1;
setfillstyle(estilo,16);

bar(x+23,y+11,x+27,y+27);
bar(x+19,y+15,x+31,y+19);
bar(x+11,y+24,x+14,y+27);
bar(x+17,y+24,x+20,y+27);
bar(x+30,y+24,x+33,y+27);
bar(x+36,y+24,x+39,y+27);
bar(x+11,y+27,x+39,y+39);

/*lineas que delimitan al rey*/
setcolor(15);
line(x+23,y+11,x+27,y+11);
delay(ret);
line(x+27,y+11,x+27,y+15);
delay(ret);
line(x+27,y+15,x+31,y+15);
delay(ret);
line(x+31,y+15,x+31,y+19);
delay(ret);
line(x+31,y+19,x+27,y+19);
delay(ret);
line(x+27,y+19,x+27,y+27);
delay(ret);
line(x+27,y+27,x+30,y+27);
delay(ret);
line(x+30,y+27,x+30,y+24);
delay(ret);
line(x+30,y+24,x+33,y+24);
delay(ret);
line(x+33,y+24,x+33,y+27);
delay(ret);
line(x+33,y+27,x+36,y+27);
delay(ret);
line(x+36,y+27,x+36,y+24);
delay(ret);
line(x+36,y+24,x+39,y+24);
delay(ret);
line(x+39,y+24,x+39,y+39);
delay(ret);
line(x+39,y+39,x+11,y+39);
delay(ret);
line(x+11,y+39,x+11,y+24);
delay(ret);
line(x+11,y+24,x+14,y+24);
delay(ret);
line(x+14,y+24,x+14,y+27);
delay(ret);
line(x+14,y+27,x+17,y+27);
delay(ret);
line(x+17,y+27,x+17,y+24);
delay(ret);
line(x+17,y+24,x+20,y+24);
delay(ret);
line(x+20,y+24,x+20,y+27);
delay(ret);
line(x+20,y+27,x+23,y+27);
delay(ret);
line(x+23,y+27,x+23,y+19);
delay(ret);
line(x+23,y+19,x+19,y+19);
delay(ret);
line(x+19,y+19,x+19,y+15);
delay(ret);
line(x+19,y+15,x+23,y+15);
delay(ret);
line(x+23,y+15,x+23,y+11);
delay(ret);

/*simbolo de OMEGA*/
line(x+17,y+35,x+19,y+37);
delay(ret);
line(x+19,y+37,x+24,y+37);
delay(ret);
line(x+24,y+37,x+22,y+36);
delay(ret);
line(x+22,y+36,x+20,y+34);
delay(ret);
line(x+20,y+34,x+20,y+32);
delay(ret);
line(x+20,y+32,x+22,y+30);
delay(ret);
line(x+22,y+30,x+24,y+29);
delay(ret);
line(x+24,y+29,x+26,y+29);
delay(ret);
line(x+26,y+29,x+28,y+30);
delay(ret);
line(x+28,y+30,x+30,y+32);
delay(ret);
line(x+30,y+32,x+30,y+34);
delay(ret);
line(x+30,y+34,x+28,y+36);
delay(ret);
line(x+28,y+36,x+26,y+37);
delay(ret);
line(x+26,y+37,x+31,y+37);
delay(ret);
line(x+31,y+37,x+33,y+35);
delay(ret);
}

//*******************************************************************

void reyb(void)
{

/*rellenar al rey de color blanco*/
estilo=1;
setfillstyle(estilo,15);

bar(x+23,y+11,x+27,y+27);
bar(x+19,y+15,x+31,y+19);
bar(x+11,y+24,x+14,y+27);
bar(x+17,y+24,x+20,y+27);
bar(x+30,y+24,x+33,y+27);
bar(x+36,y+24,x+39,y+27);
bar(x+11,y+27,x+39,y+39);

/*lineas que delimitan al rey*/
setcolor(16);
line(x+23,y+11,x+27,y+11);
delay(ret);
line(x+27,y+11,x+27,y+15);
delay(ret);
line(x+27,y+15,x+31,y+15);
delay(ret);
line(x+31,y+15,x+31,y+19);
delay(ret);
line(x+31,y+19,x+27,y+19);
delay(ret);
line(x+27,y+19,x+27,y+27);
delay(ret);
line(x+27,y+27,x+30,y+27);
delay(ret);
line(x+30,y+27,x+30,y+24);
delay(ret);
line(x+30,y+24,x+33,y+24);
delay(ret);
line(x+33,y+24,x+33,y+27);
delay(ret);
line(x+33,y+27,x+36,y+27);
delay(ret);
line(x+36,y+27,x+36,y+24);
delay(ret);
line(x+36,y+24,x+39,y+24);
delay(ret);
line(x+39,y+24,x+39,y+39);
delay(ret);
line(x+39,y+39,x+11,y+39);
delay(ret);
line(x+11,y+39,x+11,y+24);
delay(ret);
line(x+11,y+24,x+14,y+24);
delay(ret);
line(x+14,y+24,x+14,y+27);
delay(ret);
line(x+14,y+27,x+17,y+27);
delay(ret);
line(x+17,y+27,x+17,y+24);
delay(ret);
line(x+17,y+24,x+20,y+24);
delay(ret);
line(x+20,y+24,x+20,y+27);
delay(ret);
line(x+20,y+27,x+23,y+27);
delay(ret);
line(x+23,y+27,x+23,y+19);
delay(ret);
line(x+23,y+19,x+19,y+19);
delay(ret);
line(x+19,y+19,x+19,y+15);
delay(ret);
line(x+19,y+15,x+23,y+15);
delay(ret);
line(x+23,y+15,x+23,y+11);
delay(ret);
/**/
}
//*******************************************************************
void peonn(void)
{
/*rellenar el peon de color negro*/
estilo=1;
setfillstyle(estilo,16);

bar(x+17,y+32,x+33,y+38);  /*base del peon*/
bar(x+22,y+25,x+28,y+38);  /*cuello del peon*/

setcolor(16);
/*cabeza del peon sup.*/
line(x+22,y+18,x+28,y+18);
line(x+21,y+19,x+29,y+19);
line(x+20,y+20,x+30,y+20);
line(x+19,y+21,x+31,y+21);
/*centro*/
line(x+18,y+22,x+32,y+22);
/*cabeza del peon inf.*/
line(x+19,y+23,x+31,y+23);
line(x+20,y+24,x+29,y+24);
line(x+21,y+25,x+28,y+25);
line(x+22,y+26,x+27,y+26);

/*lineas que delimitan al peon*/
setcolor(15);
line(x+22,y+18,x+28,y+18);
delay(ret);
line(x+28,y+18,x+32,y+22);
delay(ret);
line(x+32,y+22,x+28,y+26);
delay(ret);
line(x+28,y+26,x+28,y+32);
delay(ret);
line(x+28,y+32,x+33,y+32);
delay(ret);
line(x+33,y+32,x+33,y+38);
delay(ret);
line(x+33,y+38,x+17,y+38);
delay(ret);
line(x+17,y+38,x+17,y+32);
delay(ret);
line(x+17,y+32,x+22,y+32);
delay(ret);
line(x+22,y+32,x+22,y+26);
delay(ret);
line(x+22,y+26,x+18,y+22);
delay(ret);
line(x+18,y+22,x+22,y+18);
delay(ret);
}
//*******************************************************************
void peonb(void)
{
/*rellenar el peon de color blanco*/
estilo=1;
setfillstyle(estilo,15);

bar(x+17,y+32,x+33,y+38);  /*base del peon*/
bar(x+22,y+25,x+28,y+38);  /*cuello del peon*/

setcolor(15);
/*cabeza del peon sup.*/
line(x+22,y+18,x+28,y+18);
line(x+21,y+19,x+29,y+19);
line(x+20,y+20,x+30,y+20);
line(x+19,y+21,x+31,y+21);
/*centro*/
line(x+18,y+22,x+32,y+22);
/*cabeza del peon inf.*/
line(x+19,y+23,x+31,y+23);
line(x+20,y+24,x+29,y+24);
line(x+21,y+25,x+28,y+25);
line(x+22,y+26,x+27,y+26);

/*lineas que delimitan al peon*/
setcolor(16);
line(x+22,y+18,x+28,y+18);
delay(ret);
line(x+28,y+18,x+32,y+22);
delay(ret);
line(x+32,y+22,x+28,y+26);
delay(ret);
line(x+28,y+26,x+28,y+32);
delay(ret);
line(x+28,y+32,x+33,y+32);
delay(ret);
line(x+33,y+32,x+33,y+38);
delay(ret);
line(x+33,y+38,x+17,y+38);
delay(ret);
line(x+17,y+38,x+17,y+32);
delay(ret);
line(x+17,y+32,x+22,y+32);
delay(ret);
line(x+22,y+32,x+22,y+26);
delay(ret);
line(x+22,y+26,x+18,y+22);
delay(ret);
line(x+18,y+22,x+22,y+18);
delay(ret);
}

//*******************************************************************