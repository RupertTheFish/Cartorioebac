#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos strings

//Novas funções para registro, consulta e deletar nomes do banco de dados. Isso foi feito para reduzir o peso de processamento do programa, deixando
//essas funções em espera, apenas para serem rodadas quando chamadas pelo programa.

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o Arquivo .txt (nesse caso)
	file = fopen(arquivo, "w"); //cria o arquivo, "w" de write
	fprintf(file, "CPF: ");
	fprintf(file, cpf); //salva o valor da variável. fprintf igual utilizado no cmd, porém ao invés de jogar para o usuário, o valor é "printado" no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo, "a" atualizar
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Aqui o comando printf conversa com o usuário
	scanf("%s", nome); //scanf vai possibilitar a entrada de texto pelo usuário
	
	file = fopen(arquivo, "a"); // Não precisamos criar um arquivo novo, simplesmente atualizar o arquivo que criamos anterioremente com os novos dados inseridos pelo usuário
	fprintf(file, "Nome: ");
	fprintf(file,nome); //inclui o valor nome no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo, "a" atualizar
	fprintf(file, "\n"); // insere uma nova linha para espaçamento adequado
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //Novamente, atualiza-se o arquivo com os novos dados
	fprintf(file, "Sobrenome: ");
	fprintf(file,sobrenome); //Salva o novo valor sobrenome
	fclose(file);	//Fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo, "a" atualizar
 	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //é preciso colocar o locale pois esta é uma nova função, e como já estamos com a library aberta, é fácil
	
	char cpf[40]; //é preciso recriar a string cpf pois esta é uma nova função
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	printf("\n\nEsses são os dados do usuário: \n\n");
	
	FILE *file;
	file = fopen(cpf, "r"); //leitura do arquivo cpf, "r" é read
	
	if(file == NULL) //Compara o file com vazio, ou seja, se o arquivo não existir, o printf abaixo é acionado
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		
	}
	
	printf("\n\n");
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o usuário a se deletado: ");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra mais no sistema!\n\n");
		system("pause");
	}
}

//Função principal do programa, será a primeira a ser carregada. Além disso, é a partir dela que o usuário terá a opção de 
//"chamar" as outras funções desejadas.

int main()
{
	int opcao=0;  // definindo as variáveis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0 )
	{
		for(x=1; x=1;)
		{
	
			system("cls"); //limpar telas anteriores
		
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("Esse software foi criado por Rafael S Krüger\nAgradecimentos ao Professor Paulo da EBAC\n\n");
			printf("### Cartório da EBAC ###\n\n"); //início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n"); 
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema.\n\n"); // fecha a aplicação
			printf("Opção: ");//fim do menu
	
	
			scanf("%d", &opcao); //armazenando a escolha do usuário (variável)
	
			system("cls");
		
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
				printf("Obrigado por utilizar o sistema!\n");	
				return 0;
				break;
			
				default: 
				printf("Essa opção não está disponível\n\n");
				system("pause");
				break;
			}
		}
	}
	
	else 
		printf("Senha Incorreta");
}
