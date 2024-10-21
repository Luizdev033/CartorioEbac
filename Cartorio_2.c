#include <stdio.h>    //Comunica��o com o usu�rio
#include <stdlib.h>   //Aloca��o de espa�o em mem�ria
#include <locale.h>   //Aloca��o de texto por regi�o
#include <string.h>   //Geranciador de string
  
  
  int registro()   //Fun��o respons�vel por cadastrar os usu�rios no sistema
  {
  	
  	//Cria��o de vari�veis
  	char arquivo[40];
  	char cpf[40];
  	char nome[40];
  	char sobrenome[40];
	char cargo[40];
	
	
	
	printf("Digite o CPF a ser cadastrado: ");   //Coletando informa��es do usu�rio
	scanf("%s", cpf);   //%s refere-se a string
	
	strcpy(arquivo, cpf);   //Copiar o valor da string
	
	
	FILE *file;   //Cria o arquivo
	
	file = fopen(arquivo, "w");   //Cria o arquivo, "w" = Write
	fprintf(file, cpf);   //Salva o valor da vari�vel
	fclose(file);   //Fecha o arquivo
	
	file = fopen(arquivo, "a");   //Atualiza o arquivo
	fprintf(file, ", ");
	fclose(file);
	
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");   //Atualiza o arquivo
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");   //Atualiza o arquivo
	fprintf(file, ", ");
	fclose(file);
	
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");   //Atualiza o arquivo
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");   //Atualiza o arquivo
	fprintf(file, ", ");
	fclose(file);
	
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");   //Atualiza o arquivo
	fprintf(file, cargo);
	fclose(file);
	
  }
  
  
  int consulta()   //Fun��o respons�vel por consultar os usu�rios no sistema
  {
  	
  	setlocale(LC_ALL, "Portuguese");
  	
  	char cpf[40];
  	char conteudo[200];
  	
  	printf("Digite o CPF a ser consultado: ");
  	scanf("%s", cpf);
  	
  	
  	
  	FILE*file;
  	file = fopen(cpf, "r");    //L� o arquivo
  	
  	if(file == NULL)
	  {
	  	
	  	printf("\nArquivo n�o localizado! Tente novamente!\n\n");
	  		  	
	  }
	  
  	while(fgets(conteudo, 200, file) != NULL)
	  {
	  	
	  	printf("\nEssas s�o as informa��es do usu�rio:\n\n\n");
	  	printf("%s", conteudo);
	  	printf("\n\n\n");
  	
	  }
	
	fclose(file);
	
	system("pause");
	
	
  }
  
  
  int deletar()   //Fun��o respons�vel por deletar os usu�rios no sistema
  {
  	
  	setlocale(LC_ALL, "Portuguese");
  	
  	char cpf[40];
  	
  	printf("Digite o CPF a ser deletado: ");
  	scanf("%s", cpf);
  	
  	remove(cpf);
  	
  	FILE*file;
  	file = fopen(cpf, "r");    //L� o arquivo
  	
  	if(file==NULL)
  	{
		
		printf("\nO us�ario n�o se encontra no sistema!\n");
		
		system("pause");
		
	}	
	
	fclose(file);
	
	
  }
  
  
  int main()
  {
  	
  	int opcao=0;    //Defini��o de vari�vel
  	int menu=1;
  	
  	for(menu=1;menu=1;)
  	{
  		
  		system("cls");   //Limpar a tela
  		
  		setlocale(LC_ALL, "Portuguese");           //Defini��o de linguagem
  	
  	
  		printf("____ Cart�rio EBAC ____\n\n");    //Inicio do menu
  	
 	 	printf("Escolha a op��o no Menu\n\n");
  	
  		printf("\t1 - Registrar Usu�rio\n");
  	
  		printf("\t2 - Consultar Usu�rio\n");
  	
  		printf("\t3 - Deletar Usu�rio\n\n\n");
	
		printf(" Op��o: ");    //Fim do menu
  	
  	
  	
  	
  		scanf("%d", &opcao);    //Armazenando dados do usu�rio
  	
  		system("cls");   //Limpar a tela
  		
  		
  		
  		
  		switch(opcao)    //In�cio da sele��o
  		{
  			case 1:
  				
  				registro();    //Chamada de fun��es
  				break;
  			
  			case 2:
  				
  				consulta();	
				break;
				
			case 3:
				
				deletar();
				break;
				
			default:
				
				printf("Op��o n�o disponivel!\n");
		  		system("pause");
  			
		}    //Fim da sele��o
		
		
  	
  	}
  	
  	
  	
  	
  	//printf("Software de uso livre dos alunos");  //Cr�ditos
  }
