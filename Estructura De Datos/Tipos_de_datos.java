/*
 * En este código veremos los tipos de datos y variables primitivas existentes en Java y a utilizarlas en código
 */

public class Tipos_de_datos {

    public static void main(String[] args) {

        //Variables para números enteros

        byte entero = 12;                 //byte es un tipo de variable que se utiliza para numeros enteros y utiliza 8 bytes y va del -128 a 127
        short entero1 = 12456;            //short es otro tipo de variable de número entero utiliza 16 bytes y abarca del -23,768 a 32,767
        int entero2 = 1245656;            //int es la variable mas utilziada para números enteros utiliza 32 bytes de memoria y abarca de -2,147,483,648 a 2,147,483,647
        long entero3 = 123456789;         //long utiliza 64 bytes de memoria y abarca de -9,223,372,036,854,775,808 a 9,223,372,854,775,807

        //variables para números decimales

        float decimal = 3.45f;            //Float se utiliza para almacenar números decimales en variables, debemos indicar a la computadora que es un decimal utilizando la letra f utiliza 32 bytes de memoria
        double decimal1 = 3.123456;       //Al utilizar el tipo de variable double no necesitamos especificar el decimal con la letra f utiliza 64 bytes de memoria

        //Datos de tipo caracter

        char caracter = 'a';              //Sirve para almacenar cualquier caracter en la variable

        //Variables de tipo Booleano

        boolean decision = true;          //Se utiliza para verdadero y falso



        System.out.println("Numero entero byte: "+entero);
        System.out.println("Número entero short: "+entero1);
        System.out.println("Número entero int: "+entero2);
        System.out.println("Número entero long: "+entero3);
        System.out.println("Número Decimal float: "+decimal);
        System.out.println("Número Decimal double: "+decimal1);
        System.out.println("Caracter: "+caracter);
        System.out.println("La decisión es: "+ decision);

    }
    
}

