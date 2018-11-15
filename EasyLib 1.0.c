#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

typedef struct{
    char nome[20];
    int qnt;
}Relatorio;
typedef struct{
	int dia;
	int mes;
	int ano;
}Data;
typedef struct{
    char title [50];
    char autor[20];
    char genero[20];
    char num[5];
    int estoque;
    Relatorio relatorio[200];
} Livro;
typedef struct{
    char rua[40];
    char numero[5];
    char cep[10];
    char complemento[40];

} Endereco;
typedef struct{
  char num1[5];
  char num2[5];
  Data emp[2];
  Data ent[2];

}Emprestimo;
typedef struct{
    char nome[40];
    char cpf[15];
    Endereco end;
    Emprestimo emprest;
    float multa;
    Relatorio relatorio[100];
} Usuario;
typedef struct{
    Usuario u;
    Livro l;
    int estoque;
    char dataInicio[20];
    char dataEntrega[20];

} Reserva;
typedef struct{
    char login[20];
    char senha[10];
} Admin;
void Pesquisar(int i, Usuario* c){
    if(i == 1)
    {
        int j;
        char nome[20];
        printf("Digite o nome do cliente: ");
        gets(nome);
        strupr(nome);
        int k = 0;
        for(j = 0; j < 200; j++)
        {
            if(strcmp(c[j].nome, nome) == 0)
            {
                k++;
            }
        }
        int v = 1;
        system("cls");
        printf("Foram encontrados %d clientes com o nome digitado: \n", k);
        for(j = 0; j < 200; j++)
        {
            if(strcmp(c[j].nome, nome) == 0)
            {
                printf("%d:\nNome: %s\n",v,c[j].nome);
                printf("CPF: %s\n", c[j].cpf);
                printf("Rua: %s, Numero: %s, Complemento: %s\n", c[j].end.rua, c[j].end.numero,c[j].end.complemento);
                printf("CEP: %s\n",c[j].end.cep);
                printf("Multa:%.2f",c[j].multa);
                printf("\n1. %s Entrega: %d/%d/%d",c[j].emprest.num1,c[j].emprest.ent[0].dia,c[j].emprest.ent[0].mes,c[j].emprest.ent[0].ano);
                printf("\n2. %s Entrega: %d/%d/%d",c[j].emprest.num2,c[j].emprest.ent[1].dia,c[j].emprest.ent[1].mes,c[j].emprest.ent[1].ano);
                v++;
                printf("\n\n");
			}
        }
        system("pause");
        system("cls");
    }
    else if(i == 2)
    {
        char cpf[20];
        printf("Digite o CPF do cliente: ");
        gets(cpf);
        system("cls");
        int j, k = 0,i;
        for(j = 0; j < 200; j++)
        {
            if(strcmp(c[j].cpf, cpf) == 0)
            {
                printf("Nome: %s\n",c[j].nome);
                printf("CPF: %s\n", c[j].cpf);
                printf("Rua: %s, Numero: %s, Complemento: %s\n", c[j].end.rua, c[j].end.numero,c[j].end.complemento);
                printf("CEP: %s\n", c[j].end.cep);
                printf("Multa:%.2f",c[j].multa);
                printf("\n1. Codigo: %s\tEntrega: %d/%d/%d",c[j].emprest.num1,c[j].emprest.ent[0].dia,c[j].emprest.ent[0].mes,c[j].emprest.ent[0].ano);
                printf("\n2. Codigo: %s\tEntrega: %d/%d/%d",c[j].emprest.num2,c[j].emprest.ent[1].dia,c[j].emprest.ent[1].mes,c[j].emprest.ent[1].ano);
                printf("\n\n");
                k++;
                break;
            }
            
        }
        if(k==0)
        {
            printf("CPF não encontrado!!");
           	Sleep(2000);
		}
        system("pause");
        system("cls");
    }
    else if(i == 3)
    {
        char rua[20];
        printf("Digite a rua do cliente: ");
        gets(rua);
        strupr(rua);
        int j, k = 0;
        for(j = 0; j < 200; j++)
        {
            if(strcmp(c[j].end.rua, rua) == 0)
            {
                k++;
            }
        }
        int v = 1;
        system("cls");
        printf("\nForam encontrados %d pessoas morando nesse endereco: \n", k);
        for(j = 0; j < 200; j++)
        {
            if(strcmp(c[j].end.rua, rua) == 0)
            {
                printf("%d:\nNome: %s\n",v,c[j].nome);
                printf("CPF: %s\n", c[j].cpf);
                printf("Rua: %s, Numero: %s, Complemento: %s\n", c[j].end.rua, c[j].end.numero,c[j].end.complemento);
                printf("CEP: %s\n", c[j].end.cep);
                printf("Multa:%.2f",c[j].multa);
                printf("\n1. %s Entrega: %d/%d/%d",c[j].emprest.num1,c[j].emprest.ent[0].dia,c[j].emprest.ent[0].mes,c[j].emprest.ent[0].ano);
                printf("\n2. %s Entrega: %d/%d/%d",c[j].emprest.num2,c[j].emprest.ent[1].dia,c[j].emprest.ent[1].mes,c[j].emprest.ent[1].ano);
                v++;
                printf("\n\n");
            }
        }
        system("pause");
        system("cls");
    }
    else if(i==4)
    {

	}
    else
    {
        printf("Opção Inválida!");
        system("pause");
    }
    system("cls");
}
void add_cliente (int i, Usuario* u){
    
	int x;
    char cpf[12];
    Usuario aux;
    
    aux=u[150];

    fflush(stdin);
    printf("Digite o CPF do novo cliente: \n");
    gets(cpf);


    for (x=0;x<200;x++)
    {
        if ( strcmp(u[x].cpf,cpf) == 0 )
        {
            system("cls");
            printf("Cliente ja cadastrado.\nOperacao cancelada.\n");
            Sleep(2000);
            return;
        }
    }

    strcpy(aux.cpf,cpf);
    printf("Digite o nome do novo cliente: \n");
    gets(aux.nome);
    strupr(aux.nome);
    printf("Digite o endereco (Rua) do novo cliente: \n");
    gets(aux.end.rua);
    strupr(aux.end.rua);
    printf("Digite o numero da casa do novo cliente: \n");
    gets(aux.end.numero);
    printf("Digite o CEP do novo cliente: \n");
    gets(aux.end.cep);
    printf("Digite um complemento para o endereco do novo cliente: \n");
    gets(aux.end.complemento);
    strupr(aux.end.complemento);
    
    char esc;
    int k=0;
    do
    {
	
    printf("\n\nTem certeza que deseja adicionar o cliente? S ou N\n");
    esc = getchar();
    if(esc=='S'||esc=='s')
    {
    	 u[i]=aux;
    	 printf("\nUsuario cadastrado com sucesso!!!");
	     Sleep(2000);
	     k++;
	     system("cls");
	}
	else if(esc=='N'||esc=='n')
	{
		 printf("\nOperacão Cancelada");
	     Sleep(2000);
	     k++;
	     system("cls");
	}
    else
	{
	   	 printf("\nOpção Invalida");
	     Sleep(2000);
	     system("cls");	
	 }
  }while(k==0);
   
}
void Remover(Usuario* c){
    Usuario v;
    char cpf[11];
    int j;

    strcpy(v.cpf, "0");
    strcpy(v.nome, " ");
    strcpy(v.end.rua," ");
    for(j=0;j<100;j++)
    {
    	strcpy(v.relatorio[j].nome," ");
    	v.relatorio[j].qnt=0;
	}
    

    do
    {

        printf("Digite o cpf do cliente que deseja remover(Para voltar digite sair.): \n");
        scanf("%s",cpf);
        fflush(stdin);
        strupr(cpf);

        for(j = 0; j < 200; j++)
        {
            if(strcmp(cpf,c[j].cpf)==0 && c[j].multa==0)
            {
                char x;
                system("cls");
                printf("Nome: %s\n",c[j].nome);
                printf("CPF: %s\n", c[j].cpf);
                printf("Rua: %s, numero: %s, complemento: %s\n", c[j].end.rua, c[j].end.numero,c[j].end.complemento);
                printf("CEP: %s", c[j].end.cep);
                printf("\n\n");
                printf("Tem certeza que deseja remover:(S ou N) ");
                scanf("%c",&x);
                fflush(stdin);


                if(x=='S' || x=='s')
                {
                    c[j]=v;
                    printf("Cliente Removido.\n");
                    system("pause");
                    break;
                }
                else if(x=='N' || x=='n')
                {
                    printf("Operacao cancelada.\n");
                    system("pause");
                    system("cls");
                    break;
                }

            }
            else if(c[j].multa!=0)
            {
            	printf("Cliente possui pendências.");
            	system("pause");
            	break;
			}
            else if((strcmp(c[j].cpf, cpf)!=0) && (j==199) && strcmp("SAIR", cpf) != 0)
            {
                system("cls");
                printf("Cliente nao encontrado. Tente novamente...\n");
                system("pause");
            }
        }
        system("cls");
    }
    while(strcmp("SAIR", cpf) != 0);
}
void atualizar(Usuario* a){
    int escolha,k=0;
    Usuario aux;
    char esc;
    
    
    system("cls");
    printf("Nome: %s\nCPF: %s",(*a).nome,(*a).cpf);
    printf("\n\n1. Editar nome\n2. Editar CPF\n3. Endereco\n4. Voltar\n");
    scanf("%d",&escolha);
    system("cls");
    switch(escolha)
    {
    case 1:
    {
        getchar();
        printf("Digite o novo nome: ");
        gets(aux.nome);
        strupr(aux.nome);
        
            do
            {
			
		    printf("\n\nTem certeza que deseja editar o cliente? S ou N\n");
		    esc = getchar();
		    if(esc=='S'||esc=='s')
		    {
		    	 strcpy((*a).nome,aux.nome);
		    	 printf("\nCliente editado com sucesso!!!");
			     Sleep(2000);
			     k++;
			     system("cls");
			}
			else if(esc=='N'||esc=='n')
			{
				 printf("\nOperacão Cancelada");
			     Sleep(2000);
			     k++;
			     system("cls");
			}
		    else
			{
			   	 printf("\nOpção Invalida");
			     Sleep(2000);
			     system("cls");	
			 }
		  }while(k==0);
        
        break;
    }
    case 2:
    {
        getchar();
        printf("Digite o novo CPF: ");
        gets(aux.cpf);
        
        do
        {
            printf("\n\nTem certeza que deseja editar o cliente? S ou N\n");
		    esc = getchar();
		    if(esc=='S'||esc=='s')
		    {
		    	 strcpy((*a).cpf,aux.cpf);
		    	 printf("\nCliente editado com sucesso!!!");
			     Sleep(2000);
			     k++;
			     system("cls");
			}
			else if(esc=='N'||esc=='n')
			{
				 printf("\nOperacão Cancelada");
			     Sleep(2000);
			     k++;
			     system("cls");
			}
		    else
			{
			   	 printf("\nOpção Invalida");
			     Sleep(2000);
			     system("cls");	
			 }
		  }while(k==0);
        break;
    }
    case 3:
    {

        getchar();
        printf("Digite a rua: ");
        gets(aux.end.rua);
        strupr(aux.end.rua);
        printf("Digite o numero: ");
        gets(aux.end.numero);
        printf("Digite o CEP: ");
        gets(aux.end.cep);
        printf("Digite o complemento: ");
        gets(aux.end.complemento);
        strupr(aux.end.complemento);
        
         do
         {
		 
            printf("\n\nTem certeza que deseja editar o cliente? S ou N\n");
		    esc = getchar();
		    if(esc=='S'||esc=='s')
		    {
		    	 strcpy((*a).end.rua,aux.end.rua);
		    	 strcpy((*a).end.numero,aux.end.numero);
		    	 strcpy((*a).end.cep,aux.end.cep);
		    	 strcpy((*a).end.complemento,aux.end.complemento);
		    	 printf("\nCliente editado com sucesso!!!");
			     Sleep(2000);
			     k++;
			     system("cls");
			}
			else if(esc=='N'||esc=='n')
			{
				 printf("\nOperacão Cancelada");
			     Sleep(2000);
			     k++;
			     system("cls");
			}
		    else
			{
			   	 printf("\nOpção Invalida");
			     Sleep(2000);
			     system("cls");	
			 }
		  }while(k==0);
        
        break;
    }
    case 4:
    	{
    		break;
		}
    }
}
void pesquisarLivro(Livro* l, int i,Usuario c[]){
	if(i == 1){
		system("cls");
		char nome[50];
		int op;
		int f, k = 1,d,v=1;
		printf("Deseja pesquisar por:\n1.Titulo do livro completo\n2.Autor\n3.Genero\n4.Codigo\n5.Voltar\nOpcao: ");
		scanf("%d", &op);
		system("cls");
		if(op == 1)
		{
			printf("Digite o titulo: ");
			getchar();
			gets(nome);
			strupr(nome);
			for(f = 0; f < 100;f++){
				if(strcmp(l[f].title, nome) == 0)
				{
					printf("%d:\nTitulo: %s\n", k, l[f].title);
					printf("Autor: %s\n", l[f].autor);
					printf("Genero: %s\n", l[f].genero);
					printf("Codigo: %s\n",l[f].num);
					printf("Estoque: %d\n",l[f].estoque);
					k++;
					printf("\n");
					printf("Cliente(s) que possui(em) esse livro:\n");
					for(d=0;d<200;d++)
					{
					  if(strcmp(l[f].num, c[d].emprest.num1) == 0 || strcmp(l[f].num, c[d].emprest.num2)==0)
					  {
					  	printf("%d. %s\n",v,c[d].nome);
                        v++;
					  }	
					}
					
					system("pause");
					break;
				}
				else if(strcmp(l[f].title, nome) != 0 && f==99)
				{
					printf("Livro nao foi encontrado!!");
					Sleep(2000);
					break;
				}
			}
			system("cls");
		}
		else if(op == 2){
			printf("Digite o nome do autor: ");
			getchar();
			gets(nome);
			strupr(nome);
			for(f = 0; f < 100;f++)
			{
				if(strcmp(l[f].autor, nome) == 0)
				{
					printf("%d:\nTitulo: %s\n", k, l[f].title);
					printf("Autor: %s\n", l[f].autor);
					printf("Genero: %s\n", l[f].genero);
					printf("Codigo: %s\n",l[f].num);
					printf("Estoque: %d\n",l[f].estoque);
					k++;
					printf("\n\n");
				}

		 }
			printf("Fim da busca\n");
			system("pause");
			system("cls");
		}
		else if(op == 3)
		{
			printf("Digite o genero: ");
			getchar();
			gets(nome);
			strupr(nome);
			for(f = 0;f < 100;f++)
			{
				if(strcmp(l[f].genero, nome) == 0)
				{
					printf("%d:\nTitulo: %s\n", k, l[f].title);
					printf("Autor: %s\n", l[f].autor);
					printf("Genero: %s\n", l[f].genero);
					printf("Codigo: %s\n",l[f].num);
					printf("Estoque: %d\n",l[f].estoque);
					k++;

				}

			}
			printf("Fim da busca\n");
			system("pause");
			system("cls");
		}
		else if(op == 4)
		{
			printf("Digite o codigo: ");
			getchar();
			gets(nome);
			for(f = 0; f < 100;f++)
			{
				if(strcmp(l[f].num, nome) == 0)
				{
					printf("%d:\nTitulo: %s\n", k, l[f].title);
					printf("Autor: %s\n", l[f].autor);
					printf("Genero: %s\n", l[f].genero);
					printf("Codigo: %s\n",l[f].num);
					printf("Estoque: %d\n",l[f].estoque);
					k++;
					printf("\n");
					printf("Cliente(s) que possui(em) esse livro:\n");
					for(d=0;d<200;d++)
					{
					  if(strcmp(l[f].num, c[d].emprest.num1) == 0 || strcmp(l[f].num, c[d].emprest.num2)==0)
					  {
					  	printf("%d. %s\n",v,c[d].nome);
                        v++;
					  }	
					}
					system("pause");
					break;
				}
				else if(strcmp(l[f].num, nome) != 0 && f==99)
				{
					printf("Livro nao foi encontrado!!");
					Sleep(2000);
					break;
				}
			}
			system("cls");
		}

}
	else if(i == 2)
	{
		int f;
		int k = 1;
		system("cls");
		printf("Codigo | Titulo | Autor | Genero | Estoque\n");
		for(f = 0; f < 100;f++){
			if(strcmp(l[f].num,"0") != 0 )
			{
				printf("%d:\t%s | %s | %s | %s | %d\n", k,l[f].num, l[f].title, l[f].autor, l[f].genero,l[f].estoque);
				k++;
			}
		}
		system("pause");
		system("cls");
	}
}
void add_livro (Livro* u, int i){

    char aux[4];
    int vdd, j;
    Livro t;
    t=u[90];
    
    fflush(stdin);
    printf("Digite o titulo do novo livro: \n");
    gets(t.title);
    strupr(t.title);
    do {
	    vdd=0;	
	    printf("Digite o codigo do novo livro: \n");
	    gets(aux);
    
        for(j=0; j<100;j++)
		{

            if (strcmp(aux,u[j].num) == 0)
            {
                vdd = 1;
                printf("Código já existente no sistema.\n");
                Sleep(2000);
                system("cls");
            }
       	}
       	if (vdd == 0)
            {
                strcpy(t.num, aux);
                break;
            }
    }
    while(vdd==1);
	printf("Digite o nome do autor do novo livro: \n");
    gets(t.autor);
    strupr(t.autor);
    printf("Digite o genero(categoria) do novo livro: \n");
    gets(t.genero);
    strupr(t.genero);
    printf("Digite a quantidade desse livro contida no estoque: \n");
    scanf("%d",&t.estoque);
    fflush(stdin);
    
    char esc;
    int k=0;
    do
    {
	    printf("\n\nTem certeza que deseja adicionar o livro? S ou N\n");
	    esc = getchar();
	    if(esc=='S'||esc=='s')
	    {
	    	 u[i]=t;
	    	 printf("\nLivro adicionado com sucesso!!!");
		     Sleep(2000);
		     k++;
		     system("cls");
		}
		else if(esc=='N'||esc=='n')
		{
			 printf("\nOperacão Cancelada");
		     Sleep(2000);
		     k++;
		     system("cls");
		}
	    else
		{
		   	 printf("\nOpção Invalida");
		     Sleep(2000);
		     system("cls");	
		 }
	}while(k==0);
    
}
void editarlivro(Livro* a,int i){
    char escolha,esc;
    int j,l,vdd=0,k=0;
    Livro aux;
    system("cls");
    printf("%s\n%s",a[i].title,a[i].autor);
    printf("\n\nEditar livro escolhido? s/n\n");
    scanf("%c",&escolha);
    system("cls");

    if(escolha=='s' || escolha=='S')
    {
        fflush(stdin);
        printf("Editar:\n1. Nome\n2. Codigo\n3. Autor\n4. Genero\n5. Estoque\n");
        scanf("%d",&j);
        fflush(stdin);
        system("cls");
        if(j==1)
		{
		  	
        	do
        	{
        		vdd=0;
        		printf("Novo nome: ");
	        	gets(aux.title);
	        	strupr(aux.title);
	        	for(l=0;l<100;l++)
		    	{
		    		if(strcmp(aux.title,a[l].title)==0)
		    		{
		    			printf("\nLivro já existe.");
		    			Sleep(2000);
		    			vdd++;
		    			system("cls");
		    		  	break;
					}
				}
				
			}while(vdd==1);
        	do
			    {
				
				    printf("\n\nTem certeza que deseja editar o livro? S ou N\n");
				    esc = getchar();
				    if(esc=='S'||esc=='s')
				    {
				    	
				    	 strcpy(a[i].title,aux.title);
				    	 printf("Alteracao feita com sucesso...\n");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
					else if(esc=='N'||esc=='n')
					{
						 printf("\nOperacão Cancelada");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
				    else
					{
					   	 printf("\nOpção Invalida");
					     Sleep(2000);
					     system("cls");	
					 }
				}while(k==0);
        	
		}
		else if(j==2)
		{
				do
        	{
        		vdd=0;
        		printf("Novo codigo: ");
        		gets(aux.num);
	        	for(l=0;l<100;l++)
		    	{
		    		if(strcmp(aux.num,a[l].num)==0)
		    		{
		    			printf("\nCódigo já existe.");
		    			Sleep(2000);
		    			vdd++;
		    			system("cls");
		    		  	break;
					}
				}
				
			}while(vdd==1);
			do
			    {
				
				    printf("\n\nTem certeza que deseja editar o livro? S ou N\n");
				    esc = getchar();
				    if(esc=='S'||esc=='s')
				    {
				    	 strcpy(a[i].num,aux.num);
				    	 printf("Alteracao feita com sucesso...\n");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
					else if(esc=='N'||esc=='n')
					{
						 printf("\nOperacão Cancelada");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
				    else
					{
					   	 printf("\nOpção Invalida");
					     Sleep(2000);
					     system("cls");	
					 }
				}while(k==0);
		}
        else if(j==3)
        {
        	printf("Novo autor: ");
        	gets(aux.autor);
        	strupr(aux.autor);
            
            do
			    {
				
				    printf("\n\nTem certeza que deseja editar o livro? S ou N\n");
				    esc = getchar();
				    if(esc=='S'||esc=='s')
				    {
				    	 strcpy(a[i].autor,aux.autor);
				    	 printf("Alteracao feita com sucesso...\n");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
					else if(esc=='N'||esc=='n')
					{
						 printf("\nOperacão Cancelada");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
				    else
					{
					   	 printf("\nOpção Invalida");
					     Sleep(2000);
					     system("cls");	
					 }
				}while(k==0);
		}
		else if(j==4)
		{
		  	printf("Novo genero: ");
        	gets(aux.genero);
        	strupr(aux.genero);
        	do
			    {
				
				    printf("\n\nTem certeza que deseja editar o livro? S ou N\n");
				    esc = getchar();
				    if(esc=='S'||esc=='s')
				    {
				    	 strcpy(a[i].genero,aux.genero);
				    	 printf("Alteracao feita com sucesso...\n");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
					else if(esc=='N'||esc=='n')
					{
						 printf("\nOperacão Cancelada");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
				    else
					{
					   	 printf("\nOpção Invalida");
					     Sleep(2000);
					     system("cls");	
					 }
				}while(k==0);
        	
		}
		else if(j==5)
	    {
	    	printf("Digite a nova quantidade de livros no estoque: ");
	    	scanf("%d",&aux.estoque);
	    	do
			    {
				
				    printf("\n\nTem certeza que deseja editar o livro? S ou N\n");
				    esc = getchar();
				    if(esc=='S'||esc=='s')
				    {
				    	 a[i].estoque=aux.estoque;
				    	 printf("Alteracao feita com sucesso...\n");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
					else if(esc=='N'||esc=='n')
					{
						 printf("\nOperacão Cancelada");
					     Sleep(2000);
					     k++;
					     system("cls");
					}
				    else
					{
					   	 printf("\nOpção Invalida");
					     Sleep(2000);
					     system("cls");	
					 }
				}while(k==0);
		}
        else
        {
        	printf("Opcao Invalida");
        	Sleep(2000);
		}
    }
    else if(escolha=='n' || escolha=='N')
    {
    	printf("Operaçao Cancelada");
    	Sleep(2000);
	}
}
void Removerlivro(Livro* c){
    Livro v;
    char num1[5];
    int j;

    strcpy(v.num,"0");
    strcpy(v.title, " ");
    strcpy(v.genero," ");
    for(j=0;j<200;j++)
    {
    	strcpy(v.relatorio[j].nome," ");
    	v.relatorio[j].qnt=0;
	}

    do
    {

        printf("Digite o codigo do livro que deseja remover(Para voltar digite sair.): \n");
        scanf("%s",num1);
        strupr(num1);
        fflush(stdin);

        for(j = 0; j < 100; j++)
        {
            if(strcmp(num1,c[j].num)==0)
            {
                int n;
                char x;
                system("cls");
                printf("Codigo: %s\nNome: %s\n",c[j].num,c[j].title);
                printf("Autor: %s\n", c[j].autor);
                printf("Genero: %s\n",c[j].genero);
                printf("Estoque: %d", c[j].estoque);
                printf("\n\n");
                printf("A quantidade de livros que deseja remover: ");
                scanf("%d",&n);
                fflush(stdin);
                printf("\n\nTem certeza que deseja remover:(S ou N) ");
                scanf("%c",&x);
                fflush(stdin);


                if(x=='S' || x=='s')
                {
                    c[j].estoque-=n;
                    if(n>=c[j].estoque)
                    {
                       c[j]=v;
                       printf("Livro removido do acervo.\n");
                       Sleep(2000);
                       break;
                    }
                    else
                    {
                       printf("%d Livros foram removidos do estoque.\n",n);
                       system("pause");
                       break;
                    }
                }
                else if(x=='N' || x=='n')
                {
                    printf("Operacao cancelada.\n");
                    Sleep(2000);
                    system("cls");
                    break;
                }

            }
            else if((strcmp(c[j].num, num1)!=0) && (j==99) && strcmp("SAIR", num1) != 0)
            {
                system("cls");
                printf("Livro nao encontrado. Tente novamente...\n");
                Sleep(2000);
            }
        }
        system("cls");
    }
    while(strcmp("SAIR", num1) != 0);
}
void date_generator(Data* ent,Data atual){
    if (atual.mes == 02)
    {
        if((atual.ano - 2016)%4 == 0)
        {
            int aux = atual.dia+ 15;
            if(aux >29)
            {
                (*ent).dia = aux - 29;
                (*ent).mes = atual.mes+ 1;
                (*ent).ano = atual.ano;
            }
            else
            {
                (*ent).dia = aux;
                (*ent).mes = atual.mes;
                (*ent).ano = atual.ano;
            }

        }
    }
    if (atual.mes == 01 || atual.mes == 03 || atual.mes == 05 || atual.mes == 07 || atual.mes == 8 || atual.mes == 10)
    {
        int aux = atual.dia+ 15;
            if(aux >31)
            {
                (*ent).dia = aux - 31;
                (*ent).mes = atual.mes+ 1;
                (*ent).ano = atual.ano;
            }
            else
            {
                (*ent).dia = aux;
                (*ent).mes = atual.mes;
                (*ent).ano = atual.ano;
            }
    }

    if (atual.mes == 02 || atual.mes == 04 || atual.mes == 06 || atual.mes == 9 || atual.mes == 11)
    {
        int aux = atual.dia+ 15;
            if(aux >30)
            {
                (*ent).dia = aux - 30;
                (*ent).mes = atual.mes+ 1;
                (*ent).ano = atual.ano;
            }
            else
            {
                (*ent).dia = aux;
                (*ent).mes = atual.mes;
                (*ent).ano = atual.ano;
            }
    }

    if (atual.mes == 12)
    {

        int aux = atual.dia+ 15;
            if(aux >31)
            {
                (*ent).dia = aux - 31;
                (*ent).mes = atual.mes == 01;
                (*ent).ano = atual.ano+1;
            }
            else
            {
                (*ent).dia = aux;
                (*ent).mes = atual.mes;
                (*ent).ano = atual.ano;
            }

    }

}
int bissexto (int ano){
	return ((ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0)));
}
float multa (Usuario clientes[],Data atual,int j,int aux){
    int diasdmes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    float totaldias = 0; int i; int aux_bi;
    int aux_dias1 = clientes[j].emprest.emp[aux].dia;
    int aux_dias2 = atual.dia;

    while (clientes[j].emprest.emp[aux].ano < atual.ano)
    {

        totaldias = 365 + bissexto(clientes[j].emprest.emp[aux].ano++);
    }

    aux_bi = bissexto(clientes[j].emprest.emp[aux].ano);
    for(i= clientes[j].emprest.emp[aux].mes; i> 0; i--)
    {
        aux_dias1 += diasdmes[aux_bi][i];
    }

    aux_bi = bissexto(atual.ano);
    for(i=atual.mes; i> 0; i--)
    {
        aux_dias2 += diasdmes[aux_bi][i];
    }
    totaldias += (-aux_dias1+aux_dias2);
    if (totaldias > 15)
    {
    	totaldias-=15;
    	return (totaldias/2);
    }
    else
    {
    	return 0;
	}

}
void emprestimo (Usuario* cliente, Livro* livros,Data a){
        int i,j;
        char aux;
        char cpf[12],num1[5],num2[5];

        fflush(stdin);
        printf("Digite o cpf do cliente: \n");
        gets(cpf);

        for (j=0;j<200;j++)
        {
            if (strcmp(cpf,cliente[j].cpf) == 0)
            {
		            if (cliente[j].multa > 0)
                    {
                        printf("Cliente não pode pegar livros.\n Possui débito.\n");
                        printf("Operação cancelada.\n");
                        Sleep(2000);
                        system("cls");
                        break;

                    }
                    printf("Cliente %s, confirmado.\n",cliente[j].nome);
                    Sleep(2000);
                    system("cls");


                        if((strcmp(cliente[j].emprest.num1,"0") == 0 && strcmp(cliente[j].emprest.num2,"0")==0))
                        {
                            printf("Usuário poderá pegar 2 livros.\n");
                            Sleep(2000);
                            do
                            {
                                system("cls");
                                printf("Digite o código do livro:");
                                gets(num1);

                                for (i=0;i<100;i++)
                                {
                       	            if(strcmp(num1,livros[i].num) == 0)
                                    {
                                        if(livros[i].estoque > 0)
                                        {
                                            system("cls");
                                            printf("Livro disponivel!\n");
		   								    strcpy(cliente[j].emprest.num1,num1);
                                            cliente[j].emprest.emp[0]=a;
                                            date_generator(&cliente[j].emprest.ent[0],a);
                                            //Algoritmo de geração da data de entrega (data 2)
                                            printf("Emprestimo concluido\n");
                                            Sleep(2000);
                                            livros[i].estoque--;
                                            int k;
											for(k = 0; k < 100;k++){
											   if(strcmp(cliente[j].relatorio[k].nome,livros[i].num) == 0){
           									       cliente[j].relatorio[k].qnt++;
           										   break;
    										   }	
									        }
    									    for(k=0;k<200;k++){
            							        if(strcmp(livros[i].relatorio[k].nome,cliente[j].cpf) == 0){
            							            livros[i].relatorio[k].qnt++;
            									   	break;
               								    }
											}
                                            break;
                                        }
                                        else
                                        {
                                            printf("Livro indisponivel.\n");
                                            Sleep(2000);
                                            break;
                                            
                                        }
                                    }
                                }
                                if (i == 100)
                                {
                                    printf("Livro nao encontrado no acervo.\n");
                                    printf("Operação cancelada.\n");
                                    Sleep(2000);
                                }
                           }while(i==100);

                           printf("Deseja alugar outro livro(S ou N):");
                           scanf("%c",&aux);
                           fflush(stdin);
                           if(aux=='S' || aux=='s')
                           {
                               do
                               {
                               system("cls");
                               printf("Digite o código do livro:");
                               gets(num2);

                               for (i=0;i<100;i++)
                                {
                                    if(strcmp(num2,livros[i].num) == 0)
                                    {
                                        if(livros[i].estoque > 0)
                                        {
                                           printf("Livro disponivel!\n");
										   strcpy(cliente[j].emprest.num2,num2);
                                           cliente[j].emprest.emp[1]=a;
                                           date_generator(&cliente[j].emprest.ent[1],a);
                                           //Algoritmo de geração da data de entrega (data 2)
                                           printf("Emprestimo concluido");
                                           Sleep(2000);
                                           livros[i].estoque--;
                                           int k;
									       for(k = 0; k < 100;k++){
											   if(strcmp(cliente[j].relatorio[k].nome,livros[i].num) == 0){
           									       cliente[j].relatorio[k].qnt++;
           										   break;
    										   }	
									        }
    									    for(k=0;k<200;k++){
            							        if(strcmp(livros[i].relatorio[k].nome,cliente[j].cpf) == 0){
            							            livros[i].relatorio[k].qnt++;
            									   	break;
               								    }
											}
                                           return;
                                        }
                                        else
                                        {
                                            printf("Livro indisponível!!!\n");
                                            return;
                                            //Algoritmo reserva
                                        }

                                     }
                                 }
                                 if (i == 100)
                                    {
                                       printf("Livro nao encontrado no acervo.\n");
                                       printf("Operação cancelada.\n");
                                       Sleep(2000);
                                       return;
                                    }
                               }while(i==100);

                           }
                           else if(aux == 'N' || aux == 'n')
                           {
                               printf("Operação Concluída");
                               Sleep(2000);
                               return;
                           }

                        }
                        else if((strcmp(cliente[j].emprest.num1,"0") !=0 && strcmp(cliente[j].emprest.num2,"0")==0))
                        {
                            printf("Usuário poderá pegar 1 livro.\n");
                            Sleep(2000);

                            do
                            {
                                system("cls");
                               printf("Digite o código do livro:");
                               gets(num2);

                               for (i=0;i<100;i++)
                                {
                                    if(strcmp(num2,livros[i].num) == 0)
                                    {
                                        if(livros[i].estoque > 0)
                                        {
                                           printf("Livro disponivel!\n");
										   strcpy(cliente[j].emprest.num2,num2);
                                           cliente[j].emprest.emp[1]=a;
                                           date_generator(&cliente[j].emprest.ent[1],a);
                                           //Algoritmo de geração da data de entrega (data 2)
                                           printf("Emprestimo concluido");
                                           Sleep(2000);
                                           livros[i].estoque--;
                                           int k;
									       for(k = 0; k < 100;k++){
											   if(strcmp(cliente[j].relatorio[k].nome,livros[i].num) == 0){
           									       cliente[j].relatorio[k].qnt++;
           										   break;
    										   }	
									        }
    									    for(k=0;k<200;k++){
            							        if(strcmp(livros[i].relatorio[k].nome,cliente[j].cpf) == 0){
            							            livros[i].relatorio[k].qnt++;
            									   	break;
               								    }
											}
                                           return;
                                        }
                                        else
                                        {
                                            printf("Livro indisponivel, deseja fazer reserva?\n");
                                            return;
                                            //Algoritmo reserva
                                        }

                                     }
                                 }
                                 if (i == 100)
                                    {
                                       printf("Livro nao encontrado no acervo.\n");
                                       printf("Operação cancelada.\n");
                                       Sleep(2000);
                                       return;
                                    }
                            }while(i==100);

                        }
                        else if((strcmp(cliente[j].emprest.num1,"0") ==0 && strcmp(cliente[j].emprest.num2,"0")!=0))
                        {
                            printf("Usuário poderá pegar 1 livros.\n");
                            Sleep(2000);

                            do
                            {
                                system("cls");
                                printf("Digite o código do livro:");
                                gets(num1);

                                for (i=0;i<100;i++)
                                    {
                                        if(strcmp(num1,livros[i].num) == 0)
                                        {
                                            if(livros[i].estoque > 0)
                                            {
                                               system("cls");
                                               printf("Livro disponivel!\n");
											   strcpy(cliente[j].emprest.num1,num1);
                                               cliente[j].emprest.emp[0]=a;
                                               date_generator(&cliente[j].emprest.ent[0],a);
                                               //Algoritmo de geração da data de entrega (data 2)
                                               printf("Emprestimo concluido");
                                               Sleep(2000);
                                               livros[i].estoque--;
                                               int k;
											   for(k = 0; k < 100;k++){
											       if(strcmp(cliente[j].relatorio[k].nome,livros[i].num) == 0){
           									           cliente[j].relatorio[k].qnt++;
           										       break;
    										       }	
									           }
    									       for(k=0;k<200;k++){
            							           if(strcmp(livros[i].relatorio[k].nome,cliente[j].cpf) == 0){
            							               livros[i].relatorio[k].qnt++;
            									   	   break;
               								       }
											   }
                                               break;
                                               return;
                                            }
                                            else
                                            {
                                                printf("Livro indisponivel.\n");
                                                Sleep(2000);
                                                break;
                                            }
                                        }

                                    }
                                    if (i == 100)
                                        {
                                           printf("Livro nao encontrado no acervo.\n");
                                           printf("Operação cancelada.\n");
                                           Sleep(2000);
                                        }
                            }while(i==100);
                        }
                        else if((strcmp(cliente[j].emprest.num1,"0") != 0 && strcmp(cliente[j].emprest.num2,"0")!=0))
                        {
                           printf("Emprestimo negado. Cliente já possui dois livros pendentes.");
                           Sleep(2000);
                           return;
                        }
            }
        }
        if (j == 200)
        {
           printf("Usuario não cadastrado.\n");
           printf("Operação cancelada.\n");
           Sleep(2000);
           return;

        }
}
void devolucao(Usuario* a,Livro* livros){
	int i,j=1;
	int escolha,e1=0,e2=0;

	do
   {

       system("cls");

		if(strcmp((*a).emprest.num1,"0") == 0 && strcmp((*a).emprest.num2,"0")==0)
		{
			printf("Cliente não têm pendências\n");
			Sleep(2000);
			system("cls");
			return;
		}

	    else
	    {

	    	for(i=0;i<100;i++)
			{
				if(strcmp((*a).emprest.num1,"0")!=0 && strcmp((*a).emprest.num1,livros[i].num)==0)
				{
					printf("1. Titulo: %s  Autor:%s\n",livros[i].title,livros[i].autor);
					printf("Data Emprestimo: %d/%d/%d\t Data Entrega %d/%d/%d\t Multa:R$%.2f\n",(*a).emprest.emp[0].dia,(*a).emprest.emp[0].mes,(*a).emprest.emp[0].ano,(*a).emprest.ent[0].dia,(*a).emprest.ent[0].mes,(*a).emprest.ent[0].ano,(*a).multa);
					e1=1;
					break;
				}

			}
			for(i=0;i<100;i++)
			{
				if(strcmp((*a).emprest.num2,"0")!=0 && strcmp((*a).emprest.num2,livros[i].num)==0)
				{
					printf("2. Titulo: %s  Autor:%s\n",livros[i].title,livros[i].autor);
					printf("Data Emprestimo: %d/%d/%d\t Data Entrega %d/%d/%d\t Multa:R$%.2f\n",(*a).emprest.emp[1].dia,(*a).emprest.emp[1].mes,(*a).emprest.emp[1].ano,(*a).emprest.ent[1].dia,(*a).emprest.ent[1].mes,(*a).emprest.ent[1].ano,(*a).multa);
					e2=1;
					break;
				}

			}

		}

	printf("3. Voltar\nDigite a opção do livro que deseja retornar:");
	scanf("%d",&escolha);
	system("cls");
	fflush(stdin);

	if(escolha==1 && e1==1)
	{

		for(i=0;i<100;i++)
		{
			if(strcmp((*a).emprest.num1,livros[i].num)==0)
			{
				livros[i].estoque++;
				break;
			}
		}
		e1=0;
		(*a).emprest.emp[0].dia=0;
		(*a).emprest.emp[0].mes=0;
		(*a).emprest.emp[0].ano=0;
		(*a).emprest.ent[0].dia=0;
		(*a).emprest.ent[0].mes=0;
		(*a).emprest.ent[0].ano=0;
		strcpy((*a).emprest.num1,"0");
	    printf("Devolução efetuada com sucesso!\n");
		Sleep(2000);
	}




	else if(escolha==2 && e2==1)
	{
		for(i=0;i<100;i++)
		{
			if(strcmp((*a).emprest.num2,livros[i].num)==0)
			{
				livros[i].estoque++;
				break;
			}
		}
		e2=0;
		strcpy((*a).emprest.num2,"0");
		(*a).emprest.emp[1].dia=0;
		(*a).emprest.emp[1].mes=0;
		(*a).emprest.emp[1].ano=0;
		(*a).emprest.ent[1].dia=0;
		(*a).emprest.ent[1].mes=0;
		(*a).emprest.ent[1].ano=0;

	    printf("Devolução efetuada com sucesso!\n");
		Sleep(2000);
	}
	else if(escolha==1  && e1==0)
	{
		printf("Opção inválida");
		Sleep(2000);
	}
	else if(escolha==2  && e2==0)
	{
		printf("Opção inválida");
		Sleep(2000);
	}
  }while(escolha!=3);
}
void relatorioU(Usuario* u, Livro* l){
    int maior = 0;
    int maiorI = 0;
    int qnt = 0;
    int i, j,aux;
    
    //procurar usuario
    for(i = 0; i < 200;i++){
        for(j = 0;j < 100;j++){
            qnt += u[i].relatorio[j].qnt;
        }
        if(qnt > maior){
            maior = qnt;
            maiorI = i;
        }
        qnt = 0;
    }
    //apresentar usuario
    for(i = 0;i < 100;i++){
    	for(j=0;j<100;j++){
    		if(strcmp(l[i].num, u[maiorI].relatorio[j].nome)== 0 && u[maiorI].relatorio[j].qnt != 0){
    		system("cls");	
            printf("O Cliente mais presente é %s\nO seu livro mais locado foi: %s\n",u[maiorI].nome, l[i].title);
            aux=1;
            break;
      		}
		}
        if(aux==1)
        {
        	break;
		}
    }
    system("pause");
    system("cls");
}
void relatorioL(Usuario* u, Livro* l){
    int maior = 0;
    int maiorI = 0;
    int maiorJ = 0;
    int maiorQnt = 0;
    int qnt = 0;
    int i, j,aux;
    for(i = 0; i < 100;i++){
    	qnt = 0;
    	
        for(j = 0;j < 200;j++){
            qnt += l[i].relatorio[j].qnt;
        }
        if(qnt > maior){
            maior = qnt;
            maiorI = i;
            maiorQnt = qnt;
        }
    }
    for(i = 0; i < 100;i++){
    	for(j = 0;j < 200;j++){
	    	if(strcmp(u[i].cpf, l[maiorI].relatorio[j].nome)==0 && l[maiorI].relatorio[j].qnt!= 0){
	    		system("cls");
	        	printf("O livro mais locado é: %s\nAs vezes que esse livro foi locado é de: %d\nO cliente que mais pegou esse livro foi: %s\n", l[maiorI].title, maiorQnt, u[i].nome);
	        	aux=1;
				break;
	        }
		}
		if(aux==1)
		{
			break;
		}
	}
    system("pause");
    system("cls");
}
int login(){
    Admin a[10];
    char log[20], sen[10];
    int i;
    FILE* fusuarios;

    fusuarios = fopen("usuarios.bin", "rb");

    fread(&a, sizeof(Admin), 10, fusuarios);

	fclose(fusuarios);
	
	
    printf("Digite o login: ");
    scanf("%s",log);
    printf("Digite a senha: ");
    scanf("%s",sen);
    for(i=0; i<10; i++)
    {

        if ((strcmp(a[i].login, log) || strcmp(a[i].senha,sen)) == 0)
        {

            return 1;
        }

    }
    
    return 0;
}
void ParseData(char data[9], Data *a){
	// 0, 1 = mes
	// 2    = /
	// 3, 4 = dia
	// 5    = /
	// 6, 7 = ano
	// 8    = NULO
	char dia[3] = {data[3],	data[4],0};
	char mes[3] = {data[0],	data[1],0};
	char ano[3] = {data[6],	data[7],0};
	(*a).dia = atoi(dia);
	(*a).mes = atoi(mes);
	(*a).ano = atoi(ano);
	return;
}
main(){
    Usuario clientes[200]; Livro livros[100];
    int i,j;
    char dateStr[9];
    Data atual;
    setlocale(LC_ALL,"Portuguese");
    system("color 70");
    
    printf("\t\t\t ||||||EasyLib||||||\n\t\t\t\tv1.0\n\n\n\t\t\t      loading...\n\n\n\n\t\t\t  developed by  DLRS\n\n\n\n\n");
    Sleep(2000);
    system("cls");
    

    while(1)
    {
        if (login() == 1)
        {
            system("cls");
            printf("Login efetuado...");
            Sleep(2000);
            system("cls");
            int escolha,escolha2,escolha3;

            FILE* fclientes;
			FILE* flivros;

			fclientes = fopen("clientes1.txt", "r");
            fread(&clientes, sizeof(Usuario), 200, fclientes);
			fclose(fclientes);

			flivros = fopen("livros1.txt", "r");
            fread(&livros, sizeof(Livro), 100, flivros);
			fclose(flivros);
		

            do
            {

            	_strdate(dateStr);
            	ParseData(dateStr, &atual);

            	for(i=0;i<198;i++)
                {
                    int aux = 0; float a = 0,b = 0;
                    if(strcmp(clientes[i].cpf,"0") != 0)
                    {
                    	if(clientes[i].emprest.ent[aux].dia!= 0)
                    	{
                    		a = multa(clientes,atual,i,aux);
						}
                        aux++;
                        if(clientes[i].emprest.ent[aux].dia!= 0)
                        {
                        	b = multa(clientes,atual,i,aux);
						}
						clientes[i].multa = a+b;
                    }
                    aux = 0;
                }
                for(i=0;i<200;i++)
			    {
			        for(j=0;j<100;j++)
			        {
			            strcpy(clientes[i].relatorio[j].nome,livros[j].num);
			        }
			    }
			    for(i=0;i<100;i++)
			    {
			        for(j=0;j<200;j++)
			        {
			            strcpy(livros[i].relatorio[j].nome,clientes[j].cpf);
			        }
			    }
                
                
                

                printf("Menu principal\tData: %d/%d/%d\n\n1. Cliente\n2. Livro\n3. Emprestimo\n4. Redefinir tudo\n5. Sair\n",atual.dia,atual.mes,atual.ano);
                scanf("%d",&escolha);
                system("cls");

                if(escolha==1)
                {
                    do
                    {
                    printf("Cliente\n\n");
                    printf("1. Pesquisar\n2. Adicionar\n3. Editar\n4. Voltar\n");
                    scanf("%d",&escolha2);
                    system("cls");
                    switch(escolha2)
                    {
                    case 1:
                    {
                        int op;
                        do
                        {

						printf("Pesquisar por:\n1.Nome\n2.CPF\n3.Endereco\n4.Voltar\nOpcao: ");
                        scanf("%d", &op);
                        getchar();
                        system("cls");
                        Pesquisar(op, clientes);
                        }while(op!=4);
                        break;
                    }
                    case 2:
                    {
                        int y;
                             for(y=0; y<200; y++)
    						{
        						if(strcmp(clientes[y].cpf,"0") == 0)
        						{
        						     add_cliente(y,clientes);
        						     system("cls");
        							 break;
        						}

    						}

                            break;
                    }
                    case 3:
                    {
                        system("cls");
                        printf("1. Atualizar\n2. Remover\n");
                        scanf("%d",&escolha3);
                        if(escolha3==1)
                        {
                            system("cls");
                            char cpf[11];
                            escolha2=0;
                            int k=0;
                            do
                            {
                                int i;
                                printf("Atualizar\n\nCPF: ");
                                scanf("%s",&cpf);
                                for(i=0; i<200; i++)
                                {
                                    if(strcmp(clientes[i].cpf,cpf)==0)
                                    {
                                        atualizar(&clientes[i]);
                                        k++;
                                    }
                                }
                                if(k==0)
                                {
                                    printf("\nCPF nao encontrado!\n\n1. Tentar novamente\n2. Sair\n");
                                    scanf("%d",&escolha2);
                                }
                                else
                                {
                                    escolha2=2;
                                }
                                system("cls");

                            }
                            while(escolha2!=2);
                            break;
                            }
                            else if(escolha3==2)
                            {
                               system("cls");
                               Remover(clientes);
                               break;
                            }

                    }
                    case 4:
                    {
                        break;
                    }
                    }
                  }while(escolha2!=4);
                }
                else if(escolha==2)
                {
                	do
                	{

                    printf("Livro\n\n");
                    printf("1. Pesquisar\n2. Adicionar\n3. Editar\n4. Voltar\n");
                    scanf("%d",&escolha2);
                    system("cls");
                    switch(escolha2)
                    {
                    case 1:
                    {
                       	int op;
                    	do{
                    		system("cls");
                    		printf("Deseja:\n1.Pesquisar\n2.Listar\n3.Voltar\n");
                    		scanf("%d", &op);
                    		pesquisarLivro(livros, op,clientes);
						}while(op != 3);
						system("cls");
                        break;
                    }
                    case 2:
                    {
                    	for(i=0; i<100; i++)
					    {
					        if(strcmp(livros[i].num,"0") == 0)
					        {
					                add_livro(livros,i);
					                system("cls");
					                for(j=0;j<200;j++)
							        {
							            strcpy(livros[i].relatorio[j].nome,clientes[j].cpf);
							        }
					                break;
					        }

					    }
					    
                        break;
                    }
                    case 3:
                    {
                        printf("Editar\n\n1. Remover\n2. Alterar\n3. Voltar\n");
                        scanf("%d",&escolha3);
                        system("cls");
                        if(escolha3==1)
                        {
                              Removerlivro(livros);
                        }
                        else if(escolha3==2)
                        {
                            char codigolivro[5];
                            escolha3=0;
                            int k=0;
                            do
                            {
                                fflush(stdin);
                                printf("Editar\n\nCodigo do livro: ");
                                gets(codigolivro);
                                system("cls");
                                for(i=0; i<100; i++)
                                {
                                    if(strcmp(livros[i].num,codigolivro)==0)
                                    {
                                        editarlivro(livros,i);
                                        k++;
                                    }
                                }
                                if(k==0)
                                {
                                    printf("\nLivro nao encontrado!\n\n1. Tentar novamente\n2. Sair\n");
                                    scanf("%d",&escolha2);
                                }
                                else
                                {
                                    escolha3=2;
                                }
                                system("cls");

                            }while(escolha3=!2);


                        }
                        else if(escolha3==3)
                        {
                            system("cls");
                            break;
                        }
                    }
                    case 4:
                    {
                        break;
                    }
                    }
                }while(escolha2!=4);
        }
                else if(escolha==3)
                {
                	do
                	{
                	system("cls");
                    printf("Emprestimo\n\n1. Relatorio\n2. Locacao\n3. Devolucao\n4. Voltar\n");
                    scanf("%d",&escolha2);
                    system("cls");
                    switch(escolha2)
                    {
                    case 1:
                    {
                    	int op;
                    	printf("Relatorio de:\n1.Livro\n2.Usuario\nOpção: ");
                    	scanf("%d", &op);
                    	if(op == 1){
                    		relatorioL(clientes, livros);
						}else if(op == 2){
							relatorioU(clientes, livros);
						}
                        break;
                    }
                    case 2:
                    {
		                emprestimo(clientes,livros,atual);
		                system("cls");
		                break;
                    }
                    case 3:
                    {
                    	fflush(stdin);
                    	char cpf[15];
						int i=0, k=0;
						printf("CPF do cliente: ");
						gets(cpf);
						system("cls");
						for(i=0;i<200;i++)
						{
						    if(strcmp(cpf,clientes[i].cpf)==0)
						    {
						        devolucao(&clientes[i],livros);
						        k++;
							}
						}
						if(k==0)
						{
							printf("CPF não encontrado!");
							Sleep(2000);
						}
                        break;
                    }
                    case 4:
                    {
                        break;
                    }
                    }
                  }while(escolha2!=4);
                }
                else if(escolha==4)
            {
            	if(login()==1)
            	{
            		char esc; int k=0;
            		do
            		{

					printf("Tem certeza que deseja redefinir tudo(S ou N)?");
            		scanf("%c",&esc);
            		fflush(stdin);

            		if(esc=='S'||esc=='s')
            		{
            		   for(i=0;i<100;i++)
					    {
					        strcpy(livros[i].title," ");
					        strcpy(livros[i].autor," ");
					        strcpy(livros[i].genero," ");
					        strcpy(livros[i].num,"0");
					        livros[i].estoque=0;
					    }
					    for(i=0;i<200;i++)
					    {
					        strcpy(clientes[i].nome," ");
					        strcpy(clientes[i].cpf,"0");
					        strcpy(clientes[i].end.cep,"0");
					        strcpy(clientes[i].end.complemento," ");
					        strcpy(clientes[i].end.numero,"0");
					        strcpy(clientes[i].end.rua," ");
					        strcpy(clientes[i].emprest.num1,"0");
					        strcpy(clientes[i].emprest.num2,"0");
					        clientes[i].emprest.emp[0].dia=0;
							clientes[i].emprest.emp[0].mes=0;
							clientes[i].emprest.emp[0].ano=0;
							clientes[i].emprest.ent[0].dia=0;
							clientes[i].emprest.ent[0].mes=0;
							clientes[i].emprest.ent[0].ano=0;
							clientes[i].emprest.emp[1].dia=0;
							clientes[i].emprest.emp[1].mes=0;
							clientes[i].emprest.emp[1].ano=0;
							clientes[i].emprest.ent[1].dia=0;
							clientes[i].emprest.ent[1].mes=0;
							clientes[i].emprest.ent[1].ano=0;
					        clientes[i].multa=0;

					    }
					    for(i=0;i<200;i++)
					    {
					        for(j=0;j<100;j++)
					        {
					            strcpy(clientes[i].relatorio[j].nome,livros[j].num);
					            clientes[i].relatorio[j].qnt=0;
					        }
					    }
					    for(i=0;i<100;i++)
					    {
					        for(j=0;j<200;j++)
					        {
					            strcpy(livros[i].relatorio[j].nome,clientes[j].cpf);
					            livros[i].relatorio[j].qnt=0;
					        }
					    }
					        system("cls");
					        printf("Redefinindo...");
					        Sleep(2000);
					        system("cls");
					        printf("Operação Realizada com Sucesso");
					        Sleep(2000);
					        system("cls");
					        k++;
					}
					else if(esc=='N'||esc=='n')
					{
						system("cls");
						printf("Operação Cancelada");
						k++;
						Sleep(2000);
						system("cls");
					}
					else
					{
						printf("Escolha inválida");
						system("pause");
						system("cls");
					}

            		}while(k==0);
          }
				else
				{
					printf("Informações Inválidas");
				}
		}

                    fclientes = fopen("clientes1.txt", "w");

                    fwrite(&clientes, sizeof(Usuario), 200, fclientes);
                    fclose(fclientes);


                    flivros = fopen("livros1.txt", "w");
                    fwrite(&livros, sizeof(Livro), 100, flivros);
                    fclose(flivros);



            }while(escolha!=5);




        }
        else
        {
            system("cls");
            printf("Login ou senha errados\n");
            Sleep(2000);
            system("cls");
        }
    }
}
