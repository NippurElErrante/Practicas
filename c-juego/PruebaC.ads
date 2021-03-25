#include <curses.h>

int main() {
  initscr();  //activar el acceso a la pantalla
  clear(); //limpia la pantalla
  move(0,30); //mueve el cursos a la posición 0,30
  printw("Hola");
  refresh();  //mostrar en pantalla lo escrito por printw
  getch(); //espera la pulsación de una techa
  endwin();  //cerrar el acceso a la pantalla
  return 0;
}
