#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_Data {
    int dia;
    int mes;
    int ano;
}data;

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
    char nome[15];
    int id; 
    char numreserva;
    char cpf[12];
    struct endereco end;
    struct tipo_Data data;
    int babysitter;
    int babysitter_total;
    int carro;
    int carro_executivo;
    int carro_luxo;
    int tanque;
    int seguro;
    int carro_total;
};

struct ficha cliente;


FILE *arq; 
void alugarCarro()
{  
    char busca[15];
    int achou=0;
    int op;
    char resposta;
    fflush(stdin);
    puts("Digite o nome:");
    gets(busca);
    fflush(stdin);
    arq=fopen("nomes.txt","rb+");
		while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
		{  
			if( strcmp(cliente.nome,busca)==0 )
            { 
            
                
                    printf("1 - AUTOMÓVEL LUXO - R$ 100,00\n");
                    printf("2 - AUTOMÓVEL EXECUTIVO - R$ 60, 00\n");
                    printf("DIGITE 1 OU 2 PARA A ESCOLHA DO CARRO:");
                    scanf("%d", &op);
                    switch(op) {
                        case 1: {
                            cliente.carro_total += 100;
                            cliente.carro_luxo+=1;
                            cliente.carro+=1;
                            printf("VOCÊ DESEJA O TANQUE CHEIO: s/n");
                            fflush(stdin);
                            scanf("%c", &resposta);
                            if(resposta ==  's' || resposta == 'S') {
                                cliente.carro_total+=150 ;//sugeri q opreco é 150
                                cliente.tanque+=1;
                            }
                            printf("VOCÊ QUER UM CARRO ASSEGURADO - R$ 250, 00: s/n");
                            fflush(stdin);
                            scanf("%c",&resposta);
                            if(resposta ==  's' || resposta == 'S') {
                                cliente.carro_total+=250;
                                cliente.seguro+=1;
                            }
                            break;
                        }
                        case 2: {
                            fflush(stdin);
                            cliente.carro_executivo +=1;
                            cliente.carro_total+=60;
                            cliente.carro+=1;

                            printf("VOCÊ DESEJA O TANQUE CHEIO - R$ 300, s/n:");
                            scanf("%c", &resposta);
                            if(resposta ==  's' || resposta == 'S') {
                                cliente.tanque+=1;
                                cliente.carro_total+=300;
                            }
                            printf("VOCÊ QUER UM CARRO ASSEGURADO - R$ 250, 00, s/n:"); 
                            fflush(stdin);
                            scanf("%c",&resposta);
                            if(resposta ==  's' || resposta == 'S') {
                                cliente.carro_total+=250;
                                cliente.seguro+=1;
                            }
                        } break;
                    }
                
             fseek(arq,ftell(arq)-sizeof(struct ficha),0);  
			fwrite(&cliente,sizeof(struct ficha),1,arq);	 
			fclose(arq); 
            achou++;
            }
       } 
     if(achou==0) printf("NÃO EXISTE ESSE ARQUIVO!"); 
}
void cadastrar()
{   
    fflush(stdin);
    puts("NOME:");
    gets(cliente.nome);
    puts("CPF: ");
    fflush(stdin);
    gets(cliente.cpf);
    puts("RUA:");
    fflush(stdin);
    gets(cliente.end.rua);
    puts("NUMERO DA CASA:");
    fflush(stdin);
    scanf("%d",&cliente.end.numeroCasa);
    puts("BAIRRO:");
    fflush(stdin);
    gets(cliente.end.bairro);
    puts("CIDADE:");
    fflush(stdin);
    gets(cliente.end.cidade);
    puts("ESTADO:");
    fflush(stdin);
    gets(cliente.end.estado);
    puts("DATA DE NASCIMENTO");
    fflush(stdin); 
    puts("DIA: \n");
    fflush(stdin);
    scanf("%d",cliente.data.dia);
    puts("MES: \n");
    fflush(stdin);
    scanf("%d", cliente.data.mes);
    puts("DIA: \n");
    fflush(stdin);
    scanf("%d", cliente.data.ano);
    cliente.carro=0;
    cliente.carro_total=0;
    cliente.carro_executivo=0;
    cliente.carro_luxo;
    cliente.tanque;
    cliente.seguro;
    
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

    puts("\nCPF \t NOME\t\t  DATA DE NASCIMENTO \t\t RUA\t NUMCASA\t  BAIRRO\t  CIDADE\t  ESTADO\t   CARRO\t  LUXO\t   EXECUTIVO\t  TANQUE\t  SEGURO\t  TOTAL\t");
     while(fread(&cliente,sizeof(struct ficha),1,arq))
        printf("%d\t%s\t%d/%d/%d\t%d\t%d\t%d\t%d\t%d\n",cliente.cpf, cliente.nome, cliente.data.dia, cliente.data.mes, cliente.data.ano, cliente.end.rua, cliente.end.numeroCasa, cliente.end.bairro,
        cliente.end.cidade, cliente.end.estado,
        cliente.carro,cliente.carro_luxo,cliente.carro_executivo,cliente.tanque,cliente.seguro,cliente.carro_total);
    fclose(arq);
} 

int main () {
    cadastrar();
    salvar();
    listar();
    alugarCarro();
    listar();
}