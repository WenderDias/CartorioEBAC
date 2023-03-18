#include <stdio.h> 	// Biblioteca responsavel pela comunicacao com o usuario
#include <stdlib.h> // Biblioteca responsavel pela alocacao de espaco em memoria
#include <locale.h> // Biblioteca responsavel pelas alocacoes de texto por regioes
#include <string.h> // Biblioteca responsavel por cuidar das strings

//Inicio da funcao de Cadastro, responsavel por cadastrar os usuarios no sistema
int registro()
{
	//Define a Linguagem
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio da criacao das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das variaveis
	
	printf("Digite o CPF a ser cadastrado: ");	//Coletando informacao do usuario
	scanf("%s", cpf);							//%s refere-se a string
	
	//Responsavel por copiar os valores das STRINGS
	strcpy(arquivo, cpf);
	
	FILE *file;					//Cria um arquivo
	file = fopen(arquivo, "w");	//Abre o arquivo para editar
	fprintf(file, cpf);			//Salva o valor da variavel
	fclose(file);				//Fecha o arquivo
	
	file = fopen(arquivo, "a");	//Atualiza o arquivo
	fprintf(file, ", ");
	fclose(file);				//Fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado: ");	//Mensagem que vai aparecer para o usuario
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}
//Final da funcao de Cadastro

//Inicio da funcao de Consulta, responsavel a consultar os dados dos usuarios cadastrados
int consulta()
{
	//Definindo Linguagem
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio das variaveis/String
	char cpf[40];
	char conteudo[200];
	//Final das Variaveis
	
	printf("Digite o CPF a ser consultado: ");	//Coletando informacao do usuario
	scanf("%s", cpf);							//%s refere-se a string
	
	FILE *file;	//Consultar o arquivo
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Não foi possível abrir o arquivo, não foi localizado!.\n");	//Mensagem que vai aparecer para o usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system("pause");
}
//Final da funcao de Consultar

//Inicio da funcao de Deletar, responsavel por deletar os usuarios do sistema
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	//Consultar arquivos
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file != NULL){
		printf("O usuario nao se encontra no sistema!.\n");
		system("pause");
	}
	
	else{
		printf("Usuario deletado com sucesso!.\n");
		system("pause");
	}
}
//Final da funcao de Deletar

//Inicio da funcao do MENU, responsavel por categorizar as opcoes de cadastro, consulta e deletar
int main()
{
	//Definindo Variaveis
	int opcao = 0;
	int repet = 1;
	
	for(repet = 1; repet = 1;){
		
		system("cls");
		
		//Definindo Linguagem
		setlocale(LC_ALL, "Portuguese");
	
		//Inicio do Menu
		printf("### Cartório Da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar  Nomes\n\n");
		printf("\t4 - Sair Do Sistema\n\n");
		printf("Opção: ");
		//Final do Menu
	
		//Armazenando a escolha do usuario
		scanf("%d", &opcao);
	
		system("cls");
	
		//Inicio da Selecao
		switch(opcao)
		{
			case 1:
			registro();
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não esta disponível!\n");
			system("pause");
			break;
		}
		//Final da Selecao
	}
}
//Final do CODIGO
