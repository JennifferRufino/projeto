#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <strings.h>
int  verificar_dia(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida);
int verificar_vaga(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int matriz[13][32]);
int checar_vagas(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int n);
int verificarDisponibilidade();
int verificarDisponibilidade1();
void deletar_vagas(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int n);
void apagar_vaga(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int matriz[13][32]);
void acrescentar_vaga(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int n);
void add_vagas(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int matriz[13][32]);
void reservar();
void menuQuartos();
void apagar(char cpf[12]);
void contrato();
void checkout();
char *nome(int op);
void restaurante();
void babysitter();
void alugarCarro();
void reservafeita();
void buscar();
void listar();
void cadastrar();
void salvar();
void cartaodecredito();
char *cartao(int bandeira);
int altaestacao();
float fechou();

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
}end;

struct ficha
{
    char nome[15];
    int id; 
    char numreserva;
    char cpf[12];
    struct endereco end;
    struct tipo_Data data;

    int babysitter;
    float babysitter_total;

    int carro;
    int carro_executivo;
    int carro_luxo;
    int tanque;
    int seguro;
    float carro_total;

    char tipoQuarto[30];
    float quarto_total;

    float restaurante;
    int restaurante_lanches;
    int restaurante_selfservice;
    int restaurante_buffet;
    int restaurante_drinks;

    char bandeiracartao[30];
    int numerocartao;
    int diavalidade;
    int mesvalidade;
    int anovalidade;
    int codseguranca;

    float total;

};

FILE *vagas;

struct quarto
{
    int p[13][32];
    int es[13][32];
    int ed[13][32];
    int et[13][32];
    int ls[13][32];
    int ld[13][32];
    int lt[13][32];
};
struct ficha cliente;
struct quarto quartos;
float altaesta = 0.25;
void acrescentar_vaga(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int n) {
     vagas=fopen("vagas.dat","rb+");
    
     int resposta;  
          
		while(fread(&quartos,sizeof(struct quarto),1,vagas)==1)

         switch(n)
           {
               case 1:
                  add_vagas(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.es);
                  break;

                case 2:
                  add_vagas(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ed);
                  break;

                case 3:
                  add_vagas(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.et);
                  break;

                case 4:
                   add_vagas(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ls);
                   break;

                case 5:
                  add_vagas(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ld);
                   break;

                case 6:
                   add_vagas(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.lt);
                   break;

                case 7:
                   add_vagas(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.p);
                   break; 
           }
		  	fseek(vagas,ftell(vagas)-sizeof(struct quarto),0);	
			fwrite(&quartos,sizeof(struct quarto),1,vagas);	
		
			fclose(vagas); 
}

void  add_vagas(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int matriz[13][32]) {
     int final_do_mes; 
    
     int i,j;
      
     int controle;
     
     int x; 

     x=(m_entrada == 12 && m_saida==1)?1:2;

      if( m_entrada == m_saida)
             final_do_mes=d_saida; 
  
        else
            final_do_mes=31; 

            
            switch(x)
               {

                   case 1: 

                   i=m_entrada;
                   j=d_entrada;
                   controle=13;

                        while( i <= controle )
                            {
                                while(j<=final_do_mes)
                                    {   
                                       

                                        matriz[i][j]++;
                                              
                                        j++;
                                    } 

                                j=1;
                                i=1;
                                final_do_mes=d_saida;
                                controle-=12;
                            } 
                      
                      break; 

                      case 2:
                          i=m_entrada;
                          j=d_entrada;
                          while( i <= m_entrada+1)
                            {
                                 while(j<=final_do_mes)
                                    {   
                                      
                                        
                                        matriz[i][j]++;
                                     j++;
                                    } 

            
                               j=1;
                               final_do_mes=d_saida;
                               ++i;
                            }  

                        break;
               }
} 

void  apagar_vaga(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int matriz[13][32])
{
     int final_do_mes; 
     
     int i,j;
      
     int controle;
     
     int x; 

     x=(m_entrada == 12 && m_saida==1)?1:2;

      if( m_entrada == m_saida)
             final_do_mes=d_saida; 
  
        else
            final_do_mes=31; 

            switch(x)
               {

                   case 1: 

                   i=m_entrada;
                   j=d_entrada;
                   controle=13;

                        while( i <= controle )
                            {
                                while(j<=final_do_mes)
                                    {   
                                        matriz[i][j]--;
                                              
                                        j++;
                                    } 

                                j=1;
                                i=1;
                                final_do_mes=d_saida;
                                controle-=12;
                            } 
                      
                      break; 

                      case 2:
                          i=m_entrada;
                          j=d_entrada;
                          while( i <= m_entrada+1)
                            {
                                 while(j<=final_do_mes)
                                    {   
                                        matriz[i][j]--;
                                        j++;
                                    } 
                               j=1;
                               final_do_mes=d_saida;
                               ++i;
                            }  

                        break;
               }
} 

void deletar_vagas(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int n)
{
     vagas=fopen("vagas.dat","rb+");
    
     int resposta;
             
		while(fread(&quartos,sizeof(struct quarto),1,vagas)==1)

         switch(n)
           {
               case 1:
                  apagar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.es);
                  break;

                case 2:
                  apagar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ed);
                  break;

                case 3:
                  apagar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.et);
                  break;

                case 4:
                   apagar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ls);
                   break;

                case 5:
                  apagar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ld);
                   break;

                case 6:
                   apagar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.lt);
                   break;

                case 7:
                   apagar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.p);
                   break; 
           }
		  	fseek(vagas,ftell(vagas)-sizeof(struct quarto),0);	
			fwrite(&quartos,sizeof(struct quarto),1,vagas);	
		    fclose(vagas); 
}


int checar_vagas(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int n)
{
     vagas=fopen("vagas.dat","rb+");
    
     int resposta;
            
		while(fread(&quartos,sizeof(struct quarto),1,vagas)==1)

         switch(n)
           {
               case 1:
                  resposta=verificar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.es);
                  break;

                case 2:
                  resposta=verificar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ed);
                  break;

                case 3:
                  resposta=verificar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.et);
                  break;

                case 4:
                   resposta=verificar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ls);
                   break;

                case 5:
                   resposta=verificar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.ld);
                   break;

                case 6:
                   resposta=verificar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.lt);
                   break;

                case 7:
                   resposta=verificar_vaga(d_entrada,m_entrada,a_entrada,d_saida,m_saida,a_saida,quartos.p);
                   break;
           }
		
				fclose(vagas); 

                if(resposta==0) 
                   return 0;
                
                 else 
                 return 1; 

}

int  verificar_vaga(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida,int matriz[13][32]) {
     int final_do_mes; 
    
     int disponivel=1;
     
     int i,j;
      
     int controle;
     
     int x; 

     x=(m_entrada == 12 && m_saida==1)?1:2;


      if( m_entrada == m_saida)
             final_do_mes=d_saida; 
  
        else
            final_do_mes=31; 

            switch(x)
               {
                   case 1: 

                   i=m_entrada;
                   j=d_entrada;
                   controle=13;

                        while( i <= controle )
                            {
                                while(j<=final_do_mes)
                                    {   
                                        if(matriz[i][j] == 0) 
                                              disponivel--;
                                        j++;
                                    } 

                                j=1;
                                i=1;
                                final_do_mes=d_saida;
                                controle-=12;
                            } 
                      
                      break; 

                      case 2:
                          i=m_entrada;
                          j=d_entrada;
                          while( i <= m_entrada+1)
                            {
                                 while(j<=final_do_mes)
                                    {   
                                         if(matriz[i][j] == 0) 
                                              disponivel--;
                                     j++;
                                    } 
                               j=1;
                               final_do_mes=d_saida;
                               ++i;
                            }  

                        break; 
               }

    if(disponivel <= 0) 
          return 0;
    else 
          return 1;
} 
int op;
void menuQuartos() {
    printf("             ___________________________________________________ \n");
    printf("            |                    BEM VINDOS!                    |\n");
    printf("            |___________________________________________________|\n");
    printf("             ___________________________________________________ \n");
    printf("            |           HOTEL CAMPINA CONFORT PREMIUM           |\n");
    printf("            |___________________________________________________|\n");
    printf("             ___________________________________________________ \n");
    printf("            |       TIPOS DE QUARTO     VALOR DA DI%cRIA        |\n", 181);
	printf("            |                                                   |\n");
    printf("            |       1 - EXECUTIVO SIMPLES   R$ 360, 00          |\n");
    printf("            |       2 - EXECUTIVO DUPLO     R$ 385, 00          |\n");
	printf("            |       3 - EXECUTIVO TRIPLO    R$ 440, 00          |\n");
    printf("            |       4 - LUXO SIMPLES        R$ 520, 00          |\n");
	printf("            |       5 - LUXO DUPLO          R$ 570, 00          |\n");
	printf("            |       6 - LUXO TRIPLO         R$ 620, 00          |\n");
    printf("            |       7 - PRESIDENCIAL        R$ 1.200, 00        |\n");
    printf("            |___________________________________________________|\n");
	printf("            |                INFORME SUA OP%c%cO:               |\n", 128, 199);
	fflush(stdin);
    scanf("%d",&op);
}

char *nome(int op) {
    if(op == 1) {
        return "EXECUTIVO SIMPLES";
    }
    if(op == 2) {
        return "EXECUTIVO DUPLO";
    }
    if(op == 3) {
        return "EXECUTIVO TRIPLO";
    }
    if(op == 4) {
        return "LUXO SIMPLES";
    }
    if(op == 5) {
        return "LUXO DUPLO";
    }
    if(op == 6) {
        return "LUXO TRIPLO";
    }
    if(op == 7) {
        return "PRESIDENCIAL";
    }
}
int dias = 0;

int dia_entrada, mes_entrada,ano_entrada;
int dia_saida,mes_saida, ano_saida;

int tipodeQuarto;

int verificarDisponibilidade() {
    int x;

    printf("INFORME A DATA DE ENTRADA\n");
    printf("\t DIA:");
    scanf("%d", &dia_entrada);
    printf("\t MES:");
    scanf("%d", &mes_entrada);
    printf("\t ANO:");
    scanf("%d", &ano_entrada);
    printf("\n");
    printf("INFORME A DATA DE SA%cDA\n", 214);
    printf("\t DIA:");
    scanf("%d", &dia_saida);
    printf("\t MES:");
    scanf("%d", &mes_saida);
    printf("\t ANO:");
    scanf("%d", &ano_saida);

    system("cls");

    menuQuartos(op);

    system("cls");
    x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,op);
    if(x == 1) {
        printf("SIM! H%c VAGAS!\n", 181);
    }
    else {
        printf("N%cO H%c VAGAS!", 199, 181);
    }  
    system("pause");
    system("cls");
    printf("TAMBEM DISPONIVEIS\n");
        for(int i = 1; i < 8; i++) {
            x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,op);
            if(x == 1) {
                printf("%s \n\t\n", nome(i));
            }
        }  
}

int verificarDisponibilidade1() {
    
    int x;

    printf("INFORME A DATA DE ENTRADA\n");
    printf("\t DIA:");
    scanf("%d", &dia_entrada);
    printf("\t MES:");
    scanf("%d", &mes_entrada);
    printf("\t ANO:");
    scanf("%d", &ano_entrada);
    printf("\n");
    printf("INFORME A DATA DE SA%cDA\n", 214);
    printf("\t DIA:");
    scanf("%d", &dia_saida);
    printf("\t MES:");
    scanf("%d", &mes_saida);
    printf("\t ANO:");
    scanf("%d", &ano_saida);

    system("cls");
    printf("             ___________________________________________________ \n");
    printf("            |                    BEM VINDOS!                    |\n");
    printf("            |___________________________________________________|\n");
    printf("             ___________________________________________________ \n");
    printf("            |           HOTEL CAMPINA CONFORT PREMIUM           |\n");
    printf("            |___________________________________________________|\n");
    printf("             ___________________________________________________ \n");
    printf("            |       TIPOS DE QUARTO VALOR DA DI%cRIA        |\n", 181);
	printf("            |                                                   |\n");
    printf("            |       1 - EXECUTIVO SIMPLES   R$ 360, 00          |\n");
    printf("            |       2 - EXECUTIVO DUPLO     R$ 385, 00          |\n");
	printf("            |       3 - EXECUTIVO TRIPLO    R$ 440, 00          |\n");
    printf("            |       4 - LUXO SIMPLES        R$ 520, 00          |\n");
	printf("            |       5 - LUXO DUPLO          R$ 570, 00          |\n");
	printf("            |       6 - LUXO TRIPLO         R$ 620, 00          |\n");
    printf("            |       7 - PRESIDENCIAL        R$ 1.200, 00        |\n");
    printf("            |___________________________________________________|\n");
	printf("            |                 INFORME SUA OP%c%cO:              |\n", 128, 199);

	fflush(stdin);
    scanf("%d",&tipodeQuarto);

    dias = verificar_dia(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida);
 
    cliente.quarto_total = 0.0;
    if(tipodeQuarto == 1) {
        x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,tipodeQuarto);
        cliente.quarto_total += (dias * 360.00);
        if(altaestacao() == 1) {
            cliente.quarto_total += cliente.quarto_total * altaesta;  
        } 
        strcpy(cliente.tipoQuarto, nome(tipodeQuarto)); 
    }

    if(tipodeQuarto == 2) {
        x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,tipodeQuarto);
        cliente.quarto_total += (dias * 385.00);
        if(altaestacao() == 1) {
            cliente.quarto_total += cliente.quarto_total * altaesta;
        }    
        strcpy(cliente.tipoQuarto, nome(tipodeQuarto));
    }

    if(tipodeQuarto == 3) {
        x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,tipodeQuarto);
        cliente.quarto_total += (dias * 440.00);
        if(altaestacao() == 1) {
            cliente.quarto_total += cliente.quarto_total * altaesta;
        }   
        strcpy(cliente.tipoQuarto, nome(tipodeQuarto));
    }

    if(tipodeQuarto == 4) {
        x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,tipodeQuarto);
        cliente.quarto_total += (dias * 520.00);
        if(altaestacao() == 1) {
            cliente.quarto_total += cliente.quarto_total * altaesta;
        }  
        strcpy(cliente.tipoQuarto, nome(tipodeQuarto));  
    }

    if(tipodeQuarto == 5 ) {
        x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,tipodeQuarto);
        cliente.quarto_total += (dias * 570.00);
        if(altaestacao() == 1) {
            cliente.quarto_total += cliente.quarto_total * altaesta;
        }  
        strcpy(cliente.tipoQuarto, nome(tipodeQuarto));  
    }

    if(tipodeQuarto == 6) {
        x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,tipodeQuarto);
        cliente.quarto_total += (dias * 620.00);
        if(altaestacao() == 1) {
            cliente.quarto_total += cliente.quarto_total * altaesta;
        }  
        strcpy(cliente.tipoQuarto, nome(tipodeQuarto));  
    }

    if(tipodeQuarto == 7) {
        x = checar_vagas(dia_entrada,mes_entrada,ano_entrada,dia_saida,mes_saida,ano_saida,tipodeQuarto);
        cliente.quarto_total += (dias * 1200.00);
        if(altaestacao() == 1) {
            cliente.quarto_total += cliente.quarto_total * altaesta;
        } 
        strcpy(cliente.tipoQuarto, nome(tipodeQuarto));   
    }

    system("cls");

    if(x == 1) {
        reservar();
        reservafeita();
        //deletar_vagas(dia_entrada,mes_entrada,ano_saida,dia_saida,mes_saida,ano_saida,op);
    }
    else {
        printf("N%cO H%c VAGAS!",198, 181);
    }     
}

FILE *arq; 

void alugarCarro()
{  
    char busca[15];
    int achou=0;
    int op;
    int loc;
    char resposta;
    fflush(stdin);
    puts("DIGITE O CPF:");
    gets(busca);
    system("cls");
    fflush(stdin);
    arq=fopen("nomes.txt","rb+");
		while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
		{  
			if( strcmp(cliente.cpf,busca)==0 )
            { 
                    printf("LOCACAO DE CARRO POR QUANTOS DIAS:");
                    scanf("%d", &loc);
                    system("cls");
                    printf("1 - AUTOMOVEL LUXO - R$ 100,00\n");
                    printf("2 - AUTOMOVEL EXECUTIVO - R$ 60, 00\n");
                    printf("DIGITE 1 OU 2 PARA A ESCOLHA DO CARRO:");
                    scanf("%d", &op);
                 
                    switch(op) {
                        case 1: { 

                             if(altaestacao() == 1) {
                                cliente.carro_total += (100 * 1.25 * loc);
                            }
                            else
                            cliente.carro_total += 100 *loc;
                            cliente.carro_luxo+=1;
                            cliente.carro+=1;
                            system("cls");
                            printf("DESEJA O TANQUE CHEIO, s/n: ");
                            fflush(stdin);
                            scanf("%c", &resposta);
                            if(resposta ==  's' || resposta == 'S') {
                                
                                 if(altaestacao() == 1) {
                                cliente.carro_total += (150 * 1.25 *loc);
                            }
                            else 
                            cliente.carro_total+=150 *loc;
                                cliente.tanque+=1;
                            }
                            system("cls");
                            printf("CARRO ASSEGURADO - R$ 250, 00 | s/n: ");
                            fflush(stdin);
                            scanf("%c",&resposta);
                            if(resposta ==  's' || resposta == 'S') { 
                                 if(altaestacao() == 1) {
                                cliente.carro_total += (250 * 1.25 * loc);
                            } 
                            else
                                cliente.carro_total+=250.00 * loc;
                                cliente.seguro+=1;
                            }
                           
                            break;
                        }
                        case 2: 
                        { 

                             if(altaestacao() == 1) {
                                cliente.carro_total += (60 * 1.25 * loc);
                            }
                            else
                            cliente.carro_total += 60 *loc;
                            cliente.carro_luxo+=1;
                            cliente.carro+=1;
                            system("cls");
                            printf("DESEJA O TANQUE CHEIO, s/n: ");
                            fflush(stdin);
                            scanf("%c", &resposta);
                            if(resposta ==  's' || resposta == 'S') {
                                
                                 if(altaestacao() == 1) {
                                cliente.carro_total += (150 * 1.25 *loc);
                            }
                            else 
                            cliente.carro_total+=150 *loc;
                                cliente.tanque+=1;
                            }
                            system("cls");
                            printf("CARRO ASSEGURADO - R$ 250, 00 | s/n: ");
                            fflush(stdin);
                            scanf("%c",&resposta);
                            if(resposta ==  's' || resposta == 'S') { 
                                 if(altaestacao() == 1) {
                                cliente.carro_total += (250 * 1.25 * loc);
                            } 
                            else
                                cliente.carro_total+=250.00 * loc;
                                cliente.seguro+=1;
                            }
                           
                            break;
                        }

                    }
                
            fseek(arq,ftell(arq)-sizeof(struct ficha),0);  
			fwrite(&cliente,sizeof(struct ficha),1,arq);	 
			fclose(arq); 
            achou++;
            }
       } 
     if(achou==0) {
         system("cls"); 
         printf("VOC%c AINDA NAO EST%c CADASTRADO!", 210, 181); 
     }     
}


void babysitter() {  
    char cpf[12];
    int achou=0;
    puts("INFORME O CPF:");
    scanf("%s", &cpf);  
    fflush(stdin);
    arq=fopen("nomes.txt", "rb+");
		while(fread(&cliente, sizeof(struct ficha), 1, arq) == 1)
		{
			if( strcmp(cliente.cpf,cpf)==0)
            {
                system("cls");
                puts("INFORME A QUANTIDADE DE HORAS DO BABYSITTER:");
                scanf("%d",&cliente.babysitter);
                cliente.babysitter_total = 45 * cliente.babysitter;
                if(altaestacao() == 1) {
                    cliente.babysitter_total += cliente.babysitter_total * 0.25;
                }
                else {
                    cliente.babysitter_total = cliente.babysitter_total;
                }
                
                fseek(arq,ftell(arq)-sizeof(struct ficha),0); 
				fwrite(&cliente,sizeof(struct ficha),1,arq);
				fclose(arq); 

                achou++;
            }
        } 

       if(achou==0) {
           system("cls");
           printf("N%cO H%c CADASTROS COM ESSE CPF!", 198, 160); 
       } 
}

int altaestacao() {
    if((mes_entrada == 12) || (mes_entrada == 1) || (mes_entrada == 6)) {
        return 1;
    } 

    else {
        return 0;
    }
    
}
void restaurante () {
    int op;
    char cpf[12];
    int achou = 0;
    puts("INFORME O CPF:");
    scanf("%s", &cpf);
    fflush(stdin);
    arq=fopen("nomes.txt", "rb+");
    while(fread(&cliente, sizeof(struct ficha), 1, arq) == 1) {
        if(strcmp(cliente.cpf, cpf) == 0) {
            system("cls");
            printf("\t1 - LANCHES - R$ 20,00\n\n");
            printf("\t2 - SELF - SERVICE R$ 16, 90\n\n");
            printf("\t3 - BUFFET A LA CARTE R$ 55, 00\n\n");
            printf("\t4 - DRINKS R$ 25, 00\n\n");
            printf("\t\t\t\n INFORME SUA OPC%cO:", 198);
            scanf("%d", &op);
            cliente.restaurante = 0;
            switch(op) {
                case 1: {
                    cliente.restaurante = 20.00;
                    cliente.restaurante_lanches+=1;
                    if((mes_entrada == 12) || (mes_entrada == 1) || (mes_entrada == 6)) {
                        cliente.restaurante += (cliente.restaurante * 0.25);
                    }
                    else {
                        cliente.restaurante += 20.00;
                    }
                } 
                break;
                
                case 2: {
                    cliente.restaurante = 16.90;
                    cliente.restaurante_selfservice+=1;
                    if((mes_entrada == 12) || (mes_entrada == 1) || (mes_entrada == 6)) {
                        cliente.restaurante += (cliente.restaurante * 0.25);
                    }
                    else {
                        cliente.restaurante = cliente.restaurante;
                    }
                    break;
                    
                }
                case 3: {
                    cliente.restaurante = 55.00;
                    cliente.restaurante_buffet+=1;
                    if((mes_entrada == 12) || (mes_entrada == 1) || (mes_entrada == 6)) {
                        cliente.restaurante += (cliente.restaurante* 0.25);
                    }
                    else {
                        cliente.restaurante = cliente.restaurante;
                    }
                    break;
                    
                }
                case 4: {
                    cliente.restaurante = 25.00;
                    cliente.restaurante_drinks+=1;
                    if((mes_entrada == 12) || (mes_entrada == 1) || (mes_entrada == 6)) {
                        cliente.restaurante += (cliente.restaurante * 0.25);
                    }
                    else {
                        cliente.restaurante = cliente.restaurante;
                    }
                    break;
                }
            }
            fseek(arq,ftell(arq)-sizeof(struct ficha),0); 
			fwrite(&cliente,sizeof(struct ficha),1,arq);
			fclose(arq); 
        }
    }
}
void menuServicos() {
    int option;
                do {
                    printf("             ___________________________________________________ \n");
                    printf("            |                    BEM VINDOS!                    |\n");
                    printf("            |___________________________________________________|\n");
                    printf("             ___________________________________________________ \n");
                    printf("            |           HOTEL CAMPINA CONFORT PREMIUM           |\n");
                    printf("            |___________________________________________________|\n");
                    printf("             ___________________________________________________ \n");
                    printf("            |                   0 - CARRO                       |\n");
                    printf("            |                   1 - BABY-SITTER                 |\n");
                    printf("            |                   2 - RESTAURANTE                 |\n");
                    printf("            |___________________________________________________|\n");
                    printf("                         OPCAO ESCOLHIDA:");
                    scanf("%d", &option);
                    switch(option) {
                        case 0: {
                            system("cls");
                            alugarCarro();  
                            Sleep(10000);                        
                            break;
                        }
                        case 1: {
                            system("cls");
                            babysitter();
                            Sleep(10000);
                            break;
                        }
                        case 2: {
                            system("cls");
                            restaurante();
                            Sleep(10000);
                            break;
                        }
                        default: {
                            fprintf(stderr,"OPCAO INVALIDA!\n");
                            break;
                        }     
                    }
                }while(option > 3);
}
void cadastrar()
{   
    fflush(stdin);
    printf("NOME:");
    gets(cliente.nome);
    fflush(stdin);
    printf("\nCPF: ");
    fflush(stdin);
    gets(cliente.cpf);
    printf("\nRUA: ");
    fflush(stdin);
    gets(cliente.end.rua);
    printf("\nNUMERO DA CASA: ");
    fflush(stdin);
    scanf("%d",&cliente.end.numeroCasa);
    printf("\nBAIRRO:");
    fflush(stdin);
    gets(cliente.end.bairro);
    printf("\nCIDADE:");
    fflush(stdin);
    gets(cliente.end.cidade);
    printf("\nESTADO:");
    fflush(stdin);
    gets(cliente.end.estado);
    puts("\nDATA DE NASCIMENTO");
    fflush(stdin); 
    printf("DIA:");
    fflush(stdin);
    scanf("%d", &cliente.data.dia);
    printf("MES:");
    fflush(stdin);
    scanf("%d", &cliente.data.mes);
    printf("ANO:");
    fflush(stdin);
    scanf("%d", &cliente.data.ano);
    cliente.babysitter_total = 0;
    cliente.carro_total = 0;
    cliente.restaurante = 0;
    cliente.babysitter = 0;
    cliente.carro_executivo = 0;
    cliente.carro_luxo = 0;
    cliente.tanque = 0;
    cliente.seguro = 0;
}
char *cartao(int bandeira) {
    if(bandeira == 1) {
        return "MASTERCARD";
    }
    if(bandeira == 2) {
        return "VISA 16 DIGITOS";
    }
    if(bandeira == 3) {
        return "AMERICAN EXPRESS";
    }
    if(bandeira == 4) {
        return "DINERS CLUB";
    }
    if(bandeira == 5) {
        return "DISCOVER";
    }
    if(bandeira == 6) {
        return "enROUTE";
    }
    if(bandeira == 7) {
        return "JCB";
    }
    if(bandeira == 8) {
        return "VOYAGER";
    }
    if(bandeira == 9) {
        return "ELO";
    }

}

void cartaodecredito() {
    int op;
    printf("\t\tQUAL E A BANDEIRA DE CARTAO DE CREDITO:");
    printf("\n\n");
    printf("\t\t1 - MASTERCARD\n");
    printf("\t\t2 - VISA 16 DIGITOS\n");
    printf("\t\t3 - AMERICAN EXPRESS\n");
    printf("\t\t4 - DINERS CLUB\n");
    printf("\t\t5 - DISCOVER\n");
    printf("\t\t6 - enROUTE\n");
    printf("\t\t7 - JCB\n");
    printf("\t\t8 - VOYAGER\n");
    printf("\t\t9 - ELO\n");
    printf("\n\t\t INFORME SUA OPCAO:");
    scanf("%d", &op);
    strcpy(cliente.bandeiracartao, cartao(op));

    system("cls");

    printf("NUMERO DO CARTAO:\n");
    scanf("%d", &cliente.numerocartao);
    printf("\n");
    printf("DATA DE VALIDADE\n");
    printf("DIA:\n");
    scanf("%d", &cliente.diavalidade);
    printf("MES:\n");
    scanf("%d", &cliente.mesvalidade);
    printf("ANO:\n");
    scanf("%d", &cliente.anovalidade);
    printf("\n");
    printf("CODIGO DE SEGURANCA:");
    scanf("%d", &cliente.codseguranca);
}
void editar()
{  
    char cpf[12];
    int achou=0;
    puts("INFORME O CPF:");
    scanf("%s", cpf);
    fflush(stdin);
    arq=fopen("nomes.txt","rb+");
		while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
		{
			if( strcmp(cliente.cpf,cpf)==0)
            {
                system("cls");
                fflush(stdin);
                puts("NOME:");
                gets(cliente.nome);
                fflush(stdin);
                puts("\nRUA:");
                fflush(stdin);
                gets(cliente.end.rua);
                puts("\nNUMERO DA CASA:");
                fflush(stdin);
                scanf("%d",&cliente.end.numeroCasa);
                puts("\nBAIRRO:");
                fflush(stdin);
                gets(cliente.end.bairro);
                puts("\nCIDADE:");
                fflush(stdin);
                gets(cliente.end.cidade);
                puts("\nESTADO:");
                fflush(stdin);
                gets(cliente.end.estado);
                puts("\nDATA DE NASCIMENTO");
                fflush(stdin); 
                puts("DIA:");
                fflush(stdin);
                scanf("%d", &cliente.data.dia);
                puts("MES:");
                fflush(stdin);
                scanf("%d", &cliente.data.mes);
                puts("ANO:");
                fflush(stdin);
                scanf("%d", &cliente.data.ano);
                fseek(arq,ftell(arq)-sizeof(struct ficha),0);  
				fwrite(&cliente,sizeof(struct ficha),1,arq);	 
				fclose(arq); 
                achou++;
            }
       } 

       if(achou==0) {
           system("cls");
           printf("N%cO H%c CADASTROS COM ESSE CPF!", 199, 181);
       }
}
void salvar()
{
    arq = fopen("nomes.txt","a");
    fwrite(&cliente,sizeof(struct ficha),1,arq);
    fclose(arq);
} 

void reservar() {
    cadastrar();
    system("cls");
    cartaodecredito();
    salvar();
    system("cls");
    printf("RESERVA REALIZADA COM SUCESSO!");
}
void apagar(char cpf[12])
{  
    int achou=0;
    arq=fopen("nomes.txt","rb+"); 
    rewind(arq);
    fflush(stdin); 
    while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
    {
        if(strcmp(cpf,cliente.cpf)==0)
        {
            FILE *auxiliar;
            auxiliar=fopen("temporario.txt","wb+");   
            rewind(arq);                
        
                 while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
                   {
                        if( strcmp(cliente.cpf,cpf) != 0)
                            {
                               fseek(auxiliar,0,SEEK_CUR);
                               fwrite(&cliente,sizeof(struct ficha),1,auxiliar);    
                             }                              
                    }
                     
                      fclose(auxiliar);
                      fclose(arq);
                      remove("nomes.txt"); 
                      rename("temporario.txt","nomes.txt");   
           achou++;
        }  
    } 

    if(achou==0) {
        system("cls");
        printf("N%cO H%c CADASTROS COM ESSE CPF!", 199, 181);
    }    
}

float fechou () {
    cliente.total = (cliente.quarto_total + cliente.carro_total + cliente.babysitter_total + cliente.restaurante);
    return cliente.total;
}

void contrato() {
   int achou = 0;
   char nomearquivo[30]; 
   char cpf[12];
   printf("INFORME O CPF:");
   scanf("%s", cpf);
   fflush(stdin);
   arq=fopen("nomes.txt","rb+"); 
   FILE *contrato;
   while(fread(&cliente, sizeof(struct ficha), 1, arq)==1) {
       if(strcmp(cpf, cliente.cpf)==0){
           strcpy(nomearquivo, cliente.nome);
           strcat(nomearquivo, ".txt");
           contrato = fopen(nomearquivo, "ab+");
           fprintf(contrato, "CONTRATO\t\r\n\r\n");
           fprintf(contrato, "NOME: %s", cliente.nome);
           fprintf(contrato, "\r\nCPF: %s", cliente.cpf);
           fprintf(contrato, "\r\nCARTAO DE CREDITO - BANDEIRA: %s, NUMERO DO CARTAO: %d, DATA DE VALIDADE: %d/%d/%d, CODIGO DE SEGURANCA: %d", cliente.bandeiracartao, cliente.numerocartao, cliente.diavalidade, cliente.mesvalidade, cliente.anovalidade, cliente.codseguranca);
           fprintf(contrato, "\r\nDATA: %d/%d/%d", cliente.data.dia, cliente.data.mes, cliente.data.ano);
           fprintf(contrato, "\r\nQUARTO: %s- PRECO: %.2f", cliente.tipoQuarto, cliente.quarto_total);
           fprintf(contrato, "\r\nCARRO LUXO: %d, CARRO EXECUTIVO: %d, TANQUE: %d, SEGURO: %d, TOTAL: R$ %.2f\n", cliente.carro_luxo, cliente.carro_executivo, cliente.tanque, cliente.seguro, cliente.carro_total);
           fprintf(contrato, "\r\nCUSTO TOTAL: %d / R$ %.2f\n",128, cliente.babysitter_total);
           fprintf(contrato, "\r\nRESTAURANTE - CUSTOS: R$ %.2f", cliente.restaurante);
           fprintf(contrato, "\r\n");
           fprintf(contrato, "TOTAL A PAGAR: R$ %.2f", fechou());
           fprintf(contrato, "\r\n");
           fprintf(contrato, "\r\n");
           fprintf(contrato, "*ATRASO NO PAGAMENTO ACARRETARÁ MULTAS!*");

           achou++;
       }
   }
    fclose(contrato);
    fclose(arq);
    apagar(cpf);
    acrescentar_vaga(dia_entrada, mes_entrada, ano_entrada, dia_saida, mes_saida, ano_saida, tipodeQuarto);
   
    
}    
void buscar()
{   
    char cpf[12];
    int achou=0;   
           puts("INFORME O CPF: ");
           scanf("%s", cpf);
           fflush(stdin);
           arq = fopen("nomes.txt","rb+");

           while(fread(&cliente,sizeof(struct ficha),1,arq)==1)
           {
               if( strcmp(cpf,cliente.cpf)==0)
               {
                   printf("VOC%c EST%c CADASTRADO!\n", 144, 181);
                   system("cls");
                   printf("\nNOME: %s \n", cliente.nome);
                   printf("\nCPF: %s \n", cliente.cpf);
                   printf("\nENDERECO: %s - %d, %s %s - %s \n", cliente.end.rua, cliente.end.numeroCasa, cliente.end.bairro, cliente.end.cidade, cliente.end.estado);
                   printf("\nDATA: %d/%d/%d \n", cliente.data.dia, cliente.data.mes, cliente.data.ano);
                   printf("\nCARTAO DE CREDITO - BANDEIRA: %s, NUMERO DO CARTAO: %d, DATA DE VALIDADE: %d/%d/%d, CODIGO DE SEGURANCA: %d", cliente.bandeiracartao, cliente.numerocartao, cliente.diavalidade, cliente.mesvalidade, cliente.anovalidade, cliente.codseguranca);
                   printf("\nQUARTO: %s - PRECO: R$ %.2f\n", cliente.tipoQuarto, cliente.quarto_total);
                   printf("\nCARRO LUXO: %d, CARRO EXECUTIVO: %d, TANQUE: %d, SEGURO: %d, TOTAL: R$ %.2f\n", cliente.carro_luxo, cliente.carro_executivo, cliente.tanque, cliente.seguro, cliente.carro_total);
                   printf("\nHORAS DE BABYSITTER : %d,  CUSTO TOTAL:R$ %.2f\n", cliente.babysitter, cliente.babysitter_total);
                   printf("\nRESTAURANTE - CUSTO: %.2f", cliente.restaurante);
                   achou++;
               }           
           } 
           fclose(arq);
           
           if(achou == 0 )  {
               system("cls");
               printf("N%cO H%c CADASTROS COM ESSE CPF!", 199, 181);
           }    
}

void listar()
{   system("cls");
    int achou = 0;
    arq=fopen("nomes.txt","r");
     while(fread(&cliente,sizeof(struct ficha),1,arq)) {
        printf("CPF: %s\n\n", cliente.cpf);
        fflush(stdin);
        printf("NOME: %s\n\n", cliente.nome);
        fflush(stdin);
        printf("DATA DE NASCIMENTO : %d/%d/%d\n\n", cliente.data.dia, cliente.data.mes, cliente.data.ano);
        fflush(stdin);
        printf("ENDERECO: %s- %d, %s,  %s - %s\n\n", cliente.end.rua, cliente.end.numeroCasa, cliente.end.bairro, cliente.end.cidade, cliente.end.estado);
        fflush(stdin);
        printf("CARTAO DE CREDITO - BANDEIRA: %s, NUMERO DO CARTAO: %d, DATA DE VALIDADE: %d/%d/%d, CODIGO DE SEGURANCA: %d\n\n", cliente.bandeiracartao, cliente.numerocartao, cliente.diavalidade, cliente.mesvalidade, cliente.anovalidade, cliente.codseguranca);
        printf("QUARTO: %s - PRECO: R$ %.2f\n\n", cliente.tipoQuarto, cliente.quarto_total);
        fflush(stdin);
        printf("CARRO LUXO: %d, CARRO EXECUTIVO: %d, TANQUE: %d, SEGURO: %d, TOTAL: R$ %.2f\n\n", cliente.carro_luxo, cliente.carro_executivo, cliente.tanque, cliente.seguro, cliente.carro_total);
        fflush(stdin);
        printf("HORAS DE BABYSITTER: %dhrs, TOTAL: R$ %.2f\n\n", cliente.babysitter, cliente.babysitter_total);
        printf("RESTAURANTE - CUSTO: R$ %.2f\n\n", cliente.restaurante);
        printf("\n");
        achou++;
    } 
    fclose(arq);

    if(achou == 0) printf("N%cO H%c CADASTROS!", 199, 181);
} 
void reservafeita() {
    printf("RESERVA EFETUADA COM SUCESSO!");
}

int main () {

    int op;
    do {
        system("cls");
        printf("             ___________________________________________________ \n");
        printf("            |                    BEM VINDOS!                    |\n");
        printf("            |___________________________________________________|\n");
        printf("             ___________________________________________________ \n");
        printf("            |           HOTEL CAMPINA CONFORT PREMIUM           |\n");
        printf("            |___________________________________________________|\n");
        printf("             ___________________________________________________ \n");
        printf("            |              1.CHECK-IN                           |\n");
        printf("            |              2.VER DISPONIBILIDADE                |\n");
        printf("            |              3.EDITAR DADOS                       |\n");
        printf("            |              4.LISTAR HOSPEDES                    |\n");
        printf("            |              5.BUSCAR HOSPEDE                     |\n");
        printf("            |              6.ADICIONAR SERVICOS                 |\n");
        printf("            |              7.CHECK-OUT                          |\n");
        printf("            |              8.SAIR DO PROGRAMA                   |\n");
        printf("            |___________________________________________________|\n");
        printf("                         OPCAO ESCOLHIDA:");
        scanf("%d", &op);
        switch(op) {
            case 1: {
                system("cls");
                verificarDisponibilidade1();
                system("cls");
                printf("RESERVA EFETUADA COM SUCESSO!");
                Sleep(2000);
                break;
            }
            case 2: {
                system("cls");
                verificarDisponibilidade();
                Sleep(1000);
                break;
            }
            case 3: {
                system("cls");
                editar();
                Sleep(5000);
            }
            case 4: {
                system("cls");
                listar();
                Sleep(10000);
                break;
            }
            case 5: {
                system("cls");
                buscar();
                Sleep(10000);
                break;
            }
            case 6: {
                system("cls");
                menuServicos();
                break;
            }
            case 7: {
                system("cls");
                contrato();
                system("pause");
                break;
            }
            case 8: {
                system("cls");
                exit(1);
                break;
            }
            default: {
                printf("OPCAO INVALIDA!\n");
                break;
            }     
        }
    }while (op != 0);
}
int  verificar_dia(int d_entrada,int m_entrada,int a_entrada,int d_saida,int m_saida,int a_saida) {
     int final_do_mes; 
    
     int cont=0;
     
     int i,j;
      
     int controle;
     
     int x; 

     x=(m_entrada == 12 && m_saida==1)?1:2;


      if( m_entrada == m_saida)
             final_do_mes=d_saida; 
  
        else
            final_do_mes=31; 

            switch(x)
               {
                   case 1: 

                   i=m_entrada;
                   j=d_entrada;
                   controle=13;

                        while( i <= controle )
                            {
                                while(j<=final_do_mes)
                                    {   
                                       
                                         cont++;
                                        j++;
                                    }

                                j=1;
                                i=1;
                                final_do_mes=d_saida;
                                controle-=12;
                            } 
                      
                      break; 

                      case 2:
                          i=m_entrada;
                          j=d_entrada;
                          while( i <= m_entrada)
                            {
                                 while(j<=final_do_mes)
                                    {   
                                         
                                    cont++;
                                     j++;
                                    } 
                               j=1;
                               final_do_mes=d_saida;
                               ++i;
                            }  

                        break; 
               }

    
          return cont -1 ;
} 