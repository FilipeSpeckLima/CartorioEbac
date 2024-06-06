#include <stdio.h> //biblioteca de conunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() // funcao responsavel para cadatrar os usuarios no sistema
{
	// inicio da criacao de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criacao de variaveis/strings
	
	printf("digite o cpf a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
		
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 	
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf(" DIgite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digitar o CPF a ser deletado: ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema. \n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; // definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
			
		setlocale(LC_ALL, "portuguese"); // linguagem do texto, podendo colocar acentos
	
		printf("### Cart�rio da EBAC### \n\n"); // inicio do menu
		
		system("cls"); // reponsavel por limpar a tela
		
		printf("Escolha a op��o desejada do meno:\n\n");
		printf("\t1 - Registrar nomes\n"); // \t da o espa�o da esquerda para direita
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n");
		printf("Op��o:"); // fim do meni
	
		scanf("%d", &opcao); // inicio da selecao
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro(); //chmada de fun��o
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();		
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}
	
	
	}

}
