#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

//Constante pi
#define MPI 3.14159265358979323846

//Define el tamaño de la pila
#define STACK_SIZE 8

//Crea la pila, top es cuan llena está
double stack[STACK_SIZE];
int top = -1;

//Función push para agregar a la pila
void push(double value){
    if (top<STACK_SIZE - 1){
        top++;
        stack[top] = value;
    }
    else{
        printf("No se pueden agregar más elementos\n");
    }
}

//Función pop para sacar elementos de la pila
double pop(){
    if (top>=0){
        return stack[top--];
    }
    else{
        printf("No hay elementos");
    }
}

//Imprime la pila
void imprimirPila(){
    //Imprime mensaje si hay elementos en la pila
    if (top>=0){
        printf("\n\nPila:\n");
    }

    //Muestra advertencia si la pila está llena
    if (top==STACK_SIZE-1){
        printf("\n!! ADVERTENCIA !! Pila Llena: No se pueden agregar mas elementos !! ADVERTENCIA !!\n");
    }

    for(int i=0; i<=top; i++){
        printf("=>%.2f\n", stack[i]);
    }
    printf("\n");
}

int main() {
    printf("hola mundo\n\nIngresa un número para agregarlo a la pila\n");

    //Variables a operar
    double op1=0;
    double op2=0;

    while (true){
        imprimirPila();
        char e[5];
        printf("Operandos: +, -, *, /, r(aíz cuadrada), s(eno), c(oseno), t(angente), p(otencia)\nPara limpiar el último número ingresa Z\nIngresa un número u operando // Q para salir >");
        scanf("%s", e);

        // q - salir
        if (e[0]=='q'||e[0]=='Q'){
            break;
        }

        // Número
        else if(isdigit(e[0])||(e[0]=='-'&& isdigit(e[1]))){
            double valor = atof(e);
            push(valor);
        }

        // Suma
        else if(e[0]=='+'){
            op1=pop();
            op2=pop();
            push(op1+op2);
        }

        // Resta
        else if(e[0]=='-'){
            op1=pop();
            op2=pop();
            push(op2-op1);
        }

        // Multiplicación
        else if(e[0]=='*'){
            op1=pop();
            op2=pop();
            push(op1*op2);
        }

        // División
        else if(e[0]=='/'){
            op1=pop();
            op2=pop();

            //Revisa si el denominador es 0
            if (op1!=0){
                push(op2/op1);
            }
            else{
                printf("\nError matemático\n");
            }
        }

        // r - Raíz cuadrada
        else if(e[0]=='r'||e[0]=='R'){
            op1=pop();

            if (op1>=0){
                push(sqrt(op1));
            }
            else{
                printf("\nError matemático\n");
            }
        }

        // s - Seno
        else if(e[0]=='s'||e[0]=='S'){
            op1=pop();
            push(sin(op1*MPI/180));
        }

        // c - Coseno
        else if(e[0]=='c'||e[0]=='C'){
            op1=pop();
            push(cos(op1*MPI/180));
        }

        // t - Tangente
        else if(e[0]=='t'||e[0]=='T'){
            op1=pop();

            if (op1!=90 && op1!=180 && op1!=270){
                push(tan(op1*MPI/180));
            }
            else{
                printf("\nError matemático\n");
            }
        }

        // p - Potenciación
        else if(e[0]=='p'||e[0]=='P'){
            op1=pop();
            op2=pop();
            push(pow(op1,op2));
        }

        // z - Eliminar último elemento de la pila
        else if(e[0]=='z'||e[0]=='Z'){
            op1=pop();
        }

        //Entrada no válida
        else{
            printf("Entrada no válida");
        }
    }
    return 0;
}





