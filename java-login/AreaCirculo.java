//Programa que calcula el area de un circulo
import java.util.Scanner; //para leer del teclado
public class AreaCirculo
{
    public static void main (String [] args)
    {
        //Crea un objeto para leer datos
        Scanner entrada = new Scanner(System.in);
        
        //declaracion de variables
        double radio;
        double area;
        
        //mensaje de usuario
        System.out.println("Calcula el area de un circulo");
        System.out.println("-----------------------------");
        
        // entrada
        System.out.print("Introduce el radio: ");
        radio = entrada.nextDouble();
        
        // asigna el valor al radio
        radio = 20;
        
        // asigna valor al area
        area = radio * radio * 3.14159;
        
        //imprimir el resultado
        System.out.println("El area es " + area);
        entrada.close();
    } // fin del metodo main
} //fin de la clase AreaCirculo
