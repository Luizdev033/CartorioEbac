#include <stdio.h>    //Comunicação com o usuário
#include <stdlib.h>   //Alocação de espaço em memória
#include <locale.h>   //Alocação de texto por região
#include <string.h>   //Geranciador de string
  
  
  int registro()   //Função responsável por cadastrar os usuários no sistema
  {
  	
  	//Criação de variáveis
  	char arquivo[40];
  	char cpf[40];
  	char nome[40];
  	char sobrenome[40];
	char cargo[40];
	
	
	
	printf("Digite o CPF a ser cadastrado: ");   //Coletando informações do usuário
	scanf("%s", cpf);   //%s refere-se a string
	
	strcpy(arquivo, cpf);   //Copiar o valor da string
	
	
	FILE *file;   //Cria o arquivo
	
	file = fopen(arquivo, "w");   //Cria o arquivo, "w" = Write
	fprintf(file, cpf);   //Salva o valor da variável
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
  
  
  int consulta()   //Função responsável por consultar os usuários no sistema
  {
  	
  	setlocale(LC_ALL, "Portuguese");
  	
  	char cpf[40];
  	char conteudo[200];
  	
  	printf("Digite o CPF a ser consultado: ");
  	scanf("%s", cpf);
  	
  	
  	
  	FILE*file;
  	file = fopen(cpf, "r");    //Lê o arquivo
  	
  	if(file == NULL)
	  {
	  	
	  	printf("\nArquivo não localizado! Tente novamente!\n\n");
	  		  	
	  }
	  
  	while(fgets(conteudo, 200, file) != NULL)
	  {
	  	
	  	printf("\nEssas são as informações do usuário:\n\n\n");
	  	printf("%s", conteudo);
	  	printf("\n\n\n");
  	
	  }
	
	fclose(file);
	
	system("pause");
	
	
  }
  
  
  int deletar()   //Função responsável por deletar os usuários no sistema
  {
  	
  	setlocale(LC_ALL, "Portuguese");
  	
  	char cpf[40];
  	
  	printf("Digite o CPF a ser deletado: ");
  	scanf("%s", cpf);
  	
  	remove(cpf);
  	
  	FILE*file;
  	file = fopen(cpf, "r");    //Lê o arquivo
  	
  	if(file==NULL)
  	{
		
		printf("\nO usúario não se encontra no sistema!\n");
		
		system("pause");
		
	}	
	
	fclose(file);
	
	
  }
  
  
  int main()
  {
  	
  	int opcao=0;    //Definição de variável
  	int menu=1;
  	
  	for(menu=1;menu=1;)
  	{
  		
  		system("cls");   //Limpar a tela
  		
  		setlocale(LC_ALL, "Portuguese");           //Definição de linguagem
  	
  	
  		printf("____ Cartório EBAC ____\n\n");    //Inicio do menu
  	
 	 	printf("Escolha a opção no Menu\n\n");
  	
  		printf("\t1 - Registrar Usuário\n");
  	
  		printf("\t2 - Consultar Usuário\n");
  	
  		printf("\t3 - Deletar Usuário\n\n\n");
	
		printf(" Opção: ");    //Fim do menu
  	
  	
  	
  	
  		scanf("%d", &opcao);    //Armazenando dados do usuário
  	
  		system("cls");   //Limpar a tela
  		
  		
  		
  		
  		switch(opcao)    //Início da seleção
  		{
  			case 1:
  				
  				registro();    //Chamada de funções
  				break;
  			
  			case 2:
  				
  				consulta();	
				break;
				
			case 3:
				
				deletar();
				break;
				
			default:
				
				printf("Opção não disponivel!\n");
		  		system("pause");
  			
		}    //Fim da seleção
		
		
  	
  	}
  	
  	
  	
  	
  	//printf("Software de uso livre dos alunos");  //Créditos
  }
