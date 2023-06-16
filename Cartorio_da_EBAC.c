#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos strings

//Novas fun��es para registro, consulta e deletar nomes do banco de dados. Isso foi feito para reduzir o peso de processamento do programa, deixando
//essas fun��es em espera, apenas para serem rodadas quando chamadas pelo programa.

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o Arquivo .txt (nesse caso)
	file = fopen(arquivo, "w"); //cria o arquivo, "w" de write
	fprintf(file, "CPF: ");
	fprintf(file, cpf); //salva o valor da vari�vel. fprintf igual utilizado no cmd, por�m ao inv�s de jogar para o usu�rio, o valor � "printado" no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo, "a" atualizar
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Aqui o comando printf conversa com o usu�rio
	scanf("%s", nome); //scanf vai possibilitar a entrada de texto pelo usu�rio
	
	file = fopen(arquivo, "a"); // N�o precisamos criar um arquivo novo, simplesmente atualizar o arquivo que criamos anterioremente com os novos dados inseridos pelo usu�rio
	fprintf(file, "Nome: ");
	fprintf(file,nome); //inclui o valor nome no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo, "a" atualizar
	fprintf(file, "\n"); // insere uma nova linha para espa�amento adequado
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
	setlocale(LC_ALL, "Portuguese"); //� preciso colocar o locale pois esta � uma nova fun��o, e como j� estamos com a library aberta, � f�cil
	
	char cpf[40]; //� preciso recriar a string cpf pois esta � uma nova fun��o
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	printf("\n\nEsses s�o os dados do usu�rio: \n\n");
	
	FILE *file;
	file = fopen(cpf, "r"); //leitura do arquivo cpf, "r" � read
	
	if(file == NULL) //Compara o file com vazio, ou seja, se o arquivo n�o existir, o printf abaixo � acionado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
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
	
	printf("Digite o usu�rio a se deletado: ");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra mais no sistema!\n\n");
		system("pause");
	}
}

//Fun��o principal do programa, ser� a primeira a ser carregada. Al�m disso, � a partir dela que o usu�rio ter� a op��o de 
//"chamar" as outras fun��es desejadas.

int main()
{
	int opcao=0;  // definindo as vari�veis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0 )
	{
		for(x=1; x=1;)
		{
	
			system("cls"); //limpar telas anteriores
		
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("Esse software foi criado por Rafael S Kr�ger\nAgradecimentos ao Professor Paulo da EBAC\n\n");
			printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n"); 
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema.\n\n"); // fecha a aplica��o
			printf("Op��o: ");//fim do menu
	
	
			scanf("%d", &opcao); //armazenando a escolha do usu�rio (vari�vel)
	
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
				printf("Essa op��o n�o est� dispon�vel\n\n");
				system("pause");
				break;
			}
		}
	}
	
	else 
		printf("Senha Incorreta");
}
