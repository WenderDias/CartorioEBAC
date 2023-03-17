#include <stdio.h> //Biblioteca de comunicacao com o usuario
#include <stdlib.h> //Biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Define a Linguagem
	
	//Inicio da criacao das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das STRINGS
	
	FILE *file; //Cria um arquivo
	file = fopen(arquivo, "w"); //Abre o arquivo para editar
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo
	fprintf(file, ", ");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado: ");
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

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	//Inicio das variaveis/String
	char cpf[40];
	char conteudo[200];
	//Final das Variaveis
	
	printf("Digite o CPF a ser consultado: "); //Coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Consultar arquivo
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Não foi possível abrir o arquivo, não foi localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; //Consultar arquivos
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

int main()
{
	int opcao = 0; //Definindo Variaveis
	int repet = 1;
	
	for(repet = 1; repet = 1;){
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf("### Cartório Da EBAC ###\n\n"); //Inicio do Menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar  Nomes\n\n");
		printf("Opção: "); //Final do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuario
	
		system("cls");
	
		switch(opcao) //Inicio da Selecao
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
			
			default:
			printf("Essa opção não esta disponível!\n");
			system("pause");
			break;
		} //Final da Selecao
	}
}
