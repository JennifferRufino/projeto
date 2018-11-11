#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct vagas {
	int preco;
    char x[2];
    int total;
};

struct vagas quarto;



int main()
{  
    int op;
    int preco;
    int alta_estacao;

     puts("1- PRESIDENCIAL ");
     puts("2- LUXO SIMPLES");
     puts("3-LUXO DUPLO");
     puts("4-LUXO TRIPLO");
     puts("5-EXECUTIVO SIMPLES");
     puts("6-EXECUTIVO DUPLO");
     puts("5-EXECUTIVO TRIPLO");
     scanf("%d",&op);

     switch(op)
     {
        case 1:
        strcpy(quarto.x,"p");
        quarto.total+=1200;
        break; 

        case 2:
        strcpy(quarto.x,"ls");
        quarto.total+=520;
        break; 

        case 3:
        strcpy(quarto.x,"ld");
        quarto.total+=570;
        break; 

        case 4:
        strcpy(quarto.x,"lt");
        quarto.total+=620;
        break; 

        case 5:
        strcpy(quarto.x,"es");
        quarto.total+=360;
        break; 

        case 6:
        strcpy(quarto.x,"ed");
        quarto.total+=385;
        break; 

        case 7:
        strcpy(quarto.x,"et");
        quarto.total+=440;
        break; 
          
     } 

      if(alta_estacao==1) quarto.total= (quarto.total*1.1); //fiz a suposicao a aumenta 10%


}