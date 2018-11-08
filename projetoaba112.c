#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct tipo_Data {
    int dia;
    int mes;
    int ano;
}Data;
struct endereco 
{
    char rua[15];
    char bairro[15];
    char cidade[15];
    char estado[15];
    int numeroCasa;
} end;

struct ficha
{
    char numreserva;
    char cpf[12];
    char nome[15];
    int id;
    struct endereco end;
    struct tipo_Data data;
};

struct ficha cliente;

void cadastrar()
{   
    fflush(stdin);
    puts("Nome:");
    gets(cliente.nome);
    puts("Id:");
    fflush(stdin);
    scanf("%d",&cliente.id);
    puts("Cpf: ");
    fflush(stdin);
    gets(cliente.cpf);
    puts("Rua:");
    fflush(stdin);
    gets(cliente.end.rua);
    puts("Numero da casa:");
    fflush(stdin);
    scanf("%d",&cliente.end.numeroCasa);
    puts("Bairro:");
    fflush(stdin);
    gets(cliente.end.bairro);
    puts("Cidade:");
    fflush(stdin);
    gets(cliente.end.cidade);
    puts("Estado:");
    fflush(stdin);
    gets(cliente.end.estado);
            printf("Digite a data de nascimento do cliente:");
        fflush(stdin);
        printf("\n      DIA : ");
        fflush(stdin);
        scanf("%d", cliente.data.dia);
        if (cliente.data.dia < 1 && cliente.data.dia > 31) {
            printf("Dia inválido... Por favor insira outro:");
            fflush(stdin);
            scanf("%d", cliente.data.dia);
        }
        printf("\n      MES : ");
        fflush(stdin);
        scanf("%d", cliente.data.mes);
        if (cliente.data.mes < 1 && cliente.data.mes < 12) {
            printf("Mes inválido... Por favor insira outro:");
            fflush(stdin);
            scanf("%d", cliente.data.mes);
        }
        printf("\n      ANO : ");
        fflush(stdin);
        scanf("%d", &cliente.data.ano);
        if(cliente.data.ano >= 1900 && cliente.data.ano <= 2100) {
            printf("Ano inválido... Por favor insira outro:");
            fflush(stdin);
            scanf("%d", cliente.data.ano);
        }


}

FILE *arq; 

void apagar()
{  
    char nome[15];
    int achou=0;
     printf("Digite o  nome: ");
    scanf("%s",nome);
    arq=fopen("nomes.txt","rb+"); 
    rewind(arq); //coloca o cursor no inicio
    while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
    {
        if(strcmp(nome,cliente.nome)==0)
        {
            FILE *auxiliar;
            auxiliar=fopen("temporario.txt","wb+");   
            rewind(arq); //volta pro inicio                  
        
                 while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
                   {
                        if( strcmp(cliente.nome,nome) != 0)
                            {
                               fseek(auxiliar,0,SEEK_CUR);
                               fwrite(&cliente,sizeof(struct ficha),1,auxiliar);    
                             }                              
                    }
                     
                      fclose(auxiliar);
                      fclose(arq);
                      remove("nomes.txt"); //apaga o original
                      rename("temporario.txt","nomes.txt"); //troca os nomes      
           achou++;
        }
    } 

    if(achou==0) puts("Não há cadastros com esse nome!");
}
void editar()
{  
    char cpf[12];
    int achou=0;
    puts("Digite o cpf:");
    scanf("%s", cpf);
    fflush(stdin);
    arq=fopen("nomes.txt","rb+");
		while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
		{
			if( strcmp(cliente.cpf,cpf)==0)
            {

                printf("Digite novo nome: ");
                scanf("%s",cliente.nome);
                puts("Digite a nova id: ");
                scanf("%d",&cliente.id); 
                puts("Digite a nova rua:");
                gets(cliente.end.rua);
                puts("Digite o novo umero da casa:");
                scanf("%d",&cliente.end.numeroCasa);
                puts("Digite o novo nome do bairro:");
                gets(cliente.end.bairro);
                puts("Digite o nome da nova cidade:");
                gets(cliente.end.cidade);
                puts("Digite o nome do novo estado:");
                gets(cliente.end.estado);

                fseek(arq,ftell(arq)-sizeof(struct ficha),0);  //retorna ao final menos a inicial pra calibrar
				fwrite(&cliente,sizeof(struct ficha),1,arq);	 //escreve a nova
				fclose(arq); 

                achou++;
            }
       } 

       if(achou==0) printf("Nâo existe esse cadastro!"); 


}
void buscar()
{   
    char cpf[12];
    int achou=0;
           
           puts("Digite o cpf: ");
           scanf("%s",cpf);
           fflush(stdin);
           arq = fopen("nomes.txt","rb+");


           while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
           {
               if( strcmp(cpf,cliente.cpf)==0)
               {
                   printf("\n %s\n %d",cliente.nome,cliente.id);
                   achou++;
               }
                 

           } 
           fclose(arq);
           
           if(achou == 0 ) puts("Nao ha cadastros com esse nome!");

}
void salvar()
{
    arq = fopen("nomes.txt","a");
    fwrite(&cliente,sizeof(struct ficha),1,arq);
    fclose(arq);

} 

void listar()
{   
    arq=fopen("nomes.txt","r");

     while(fread(&cliente,sizeof(struct ficha),1,arq));
        
        printf("NOME: %s\n", cliente.nome);
        printf("ID: %d\n", cliente.id);
        printf("RUA: %s\n", cliente.end.rua);
        printf("NUMERO DA CASA: %d\n", cliente.end.numeroCasa);
        printf("BAIRRO: %s\n",cliente.end.bairro);
        printf("CIDADE: %s\n",cliente.end.cidade );
        printf("ESTADO: %s\n", cliente.end.estado);
    fclose(arq);
} 


int main() {
   int op; 
   do {
        system("cls");
        system("color 3F");
        printf("             ___________________________________________________\n");
        printf("            |                    BEM VINDOS!!!!                 |\n");
        printf("            |___________________________________________________|\n");
        printf("             ___________________________________________________\n");
        printf("            |                                                   |\n");
        printf("            |___________________________________________________|\n");
        printf("             ___________________________________________________\n");
        printf("            |              1.CADASTRAR CLIENTE                  |\n");
        printf("            |              2.BUSCAR CADASTROS                   |\n");
        printf("            |              3.EDITAR CADASTRO                    |\n");
        printf("            |              4.LISTAR CADASTROS                   |\n");
        printf("            |              5.REMOVER                            |\n");
        printf("            |___________________________________________________|\n");
        printf("                         OPCAO ESCOLHIDA:");
        scanf("%d",&op);
        switch (op) {
            case 1: {
                system("cls");
                cadastrar();
                salvar();
                break;
            }
            case 2: {
                system("cls");
                buscar();
                break;
            }
            case 3: {
                system("cls");
                editar();
                Sleep(100000);
                break;
            }
            case 4: {
                system("cls");
                listar();
                getchar();
                Sleep(1000);
                break;
            }
            case 5: {
                system("cls");
                apagar();
                
                break;
            }
            case 6: {
                exit(1);
                break;
            }
            default: {
                fprintf(stderr,"Digite uma opcao valida!\\n");
                Sleep(1);
                break;
            }       
        }
   }while(op != 0);
}