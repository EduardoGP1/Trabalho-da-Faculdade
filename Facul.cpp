#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int menu_principal();
void selecao(int);
void incluir_cliente();
void remover_cliente();
void adicionar_compras();
void zerar_todos_pedidos();
void listar_melhor_comprador();
void exibir_compras_cliente();
void exibir_compras_cliente_por_codigo();
void exibir_compras_cliente_por_nome();
void exibir_compras_cliente_por_cpf();

struct cliente{
	unsigned short int codigo_cliente=0;
	char nome[30]="NULL";
	short int ano_nascimento=0; 
	float montante=0; 
} cliente[10];
static unsigned short int numero_do_cliente=0; //numero do cliente=codigo do cliente
struct cliente *ponteiro = (struct cliente *)malloc(10*sizeof(struct cliente));


int main (){	
setlocale(LC_ALL,"portuguese");
menu_principal();
system("pause");
system("cls");
return 0;	
}


menu_principal(){
int menu_principal=0, resposta_valida=0;


	do{
		printf("MENU PRINCIPAL:\n");
		printf("1 - Incluir cliente\n");
		printf("2 - Remover cliente\n");
		printf("3 - Adicionar compras de um cliente\n");
		printf("4 - Zerar todos os pedidos\n");
		printf("5 - Listar melhor comprador\n");
		printf("6 - Exibir montante de compras de um cliente\n");
		printf("Digite o número da opção desejada:");
		scanf("%d", &menu_principal);
		if (menu_principal>0&&menu_principal<6){
			resposta_valida=1;
			}
		else{
			printf("\nResposta não válida!\n\n");
		}
	}
	while(resposta_valida==0);
	selecao(menu_principal);
}


void selecao(int menu_principal){

	switch(menu_principal) {
		case 1:
			incluir_cliente();
			break;
		
		case 2:
			remover_cliente();
			break;
		
		case 3:
			adicionar_compras();
			break;
		
		case 4:
			//zerar_todos_pedidos();
			break;
	
		case 5:
			//listar_melhor_comprador();
			break;
	
		case 6:
			//exibir_compras_cliente();
			break;			
	}
}
	
	
void incluir_cliente(){
int limite_de_memoria=1;
int add_espaco=0;
	if (numero_do_cliente>limite_de_memoria){
		printf("\nLista de clientes cheia! \nDeseja habilitar mais 10 espaços de memória?\n1 - Sim.\n2 - Não.\nDigite o número de sua resposta:");
		scanf("%d",&add_espaco);
		if (add_espaco==1){
			limite_de_memoria=limite_de_memoria+1;
    		struct cliente *ponteiro = (struct cliente *) realloc(ponteiro,10*sizeof(struct cliente));
			printf("\nFoi adicionado mais 10 espaços de memória com sucesso!\nJá pode adicionar mais clientes.");
		}
		else if (add_espaco==2){
			printf("\nEspaços de memória continuam cheios. \nRetornando ao Menu Principal...\n\n");
			menu_principal();
		}
		else{
			printf("\nDesculpe, sua resposta não foi válida!");
			incluir_cliente();
		}
	}
	printf("\n\nMENU INCLUIR CLIENTE:\n");
	cliente[numero_do_cliente].codigo_cliente=numero_do_cliente;
	printf("Cadastro cliente código %d",cliente[numero_do_cliente].codigo_cliente);
	printf("\nNome do Cliente:");
	scanf("%s",&cliente[numero_do_cliente].nome);
	printf("Ano de Nascimento:");
	scanf("%d",&cliente[numero_do_cliente].ano_nascimento);
	numero_do_cliente++;
	printf("\nCliente código %d cadastrado com sucesso!\n\n",cliente[numero_do_cliente].codigo_cliente);
	menu_principal();
}


void remover_cliente(){
short int limpa_dados=-1;
short int x=0,y=0,z=0;
short int num_cliente=-1;
	printf("\nImprimindo lista de cadastrados:\n");
	for (x=0;x<numero_do_cliente;x++){
		printf("\nCódigo_____:%d\n",cliente[x].codigo_cliente);
		printf("Nome_______:%s\n",cliente[x].nome);
		printf("Nascimento_:%d\n",cliente[x].ano_nascimento);
		printf("Montante___:%0.2fR$\n\n",cliente[x].montante);
	}
	printf("Digite o código do cliente para excluí-lo \n(para cancelar a exclusão digite um código numérico inexistente):");
	scanf("%d",&limpa_dados);
	num_cliente=numero_do_cliente;
	num_cliente--;
	if (limpa_dados==num_cliente){
		printf("\nIniciando limpeza de dados...");
		cliente[limpa_dados].codigo_cliente=0;
		cliente[limpa_dados].nome[0]='\0';
		cliente[limpa_dados].ano_nascimento=0;
		cliente[limpa_dados].montante=0;
		numero_do_cliente --;
		printf("limpeza da dados concluida com sucesso!\n");
	}
	else if (limpa_dados<num_cliente&&limpa_dados>=0){
		printf("\nIniciando limpeza de dados...");
		for (x=limpa_dados;x<numero_do_cliente;x++){
			y=x;
			y++;
			for (z=0;z<=30;z++){
			cliente[x].nome[z]=cliente[y].nome[z];
			}
			cliente[x].ano_nascimento=cliente[y].ano_nascimento;
			cliente[x].montante=cliente[y].montante;
		}
		numero_do_cliente--;
		printf("limpeza da dados concluida com sucesso!\n");
	}
	else{
		menu_principal();
	}
	printf("\nNova lista atualizada:\n");
	for (x=0;x<numero_do_cliente;x++){
		printf("\nCódigo_____:%d\n",cliente[x].codigo_cliente);
		printf("Nome_______:%s\n",cliente[x].nome);
		printf("Nascimento_:%d\n",cliente[x].ano_nascimento);
		printf("Montante___:%0.2fR$\n\n",cliente[x].montante);
	}
	menu_principal();
}


void adicionar_compras(){
unsigned short int cod_cliente,x;
float compra=0; 
		printf("\nImprimindo lista de cadastrados:\n");
	for (x=0;x<numero_do_cliente;x++){
		printf("\nCódigo_____:%d\n",cliente[x].codigo_cliente);
		printf("Nome_______:%s\n",cliente[x].nome);
		printf("Nascimento_:%d\n",cliente[x].ano_nascimento);
		printf("Montante___:%0.2fR$\n\n",cliente[x].montante);
	}
	printf("Digite o código do cliente:");
	scanf("%d",&cod_cliente);
	if (cod_cliente<0||cod_cliente>numero_do_cliente||numero_do_cliente==0){
		printf("código não existente\n\n");
		menu_principal();
	}
	printf("Digite o valor da compra(separando centavos com vírgula):");
	scanf("%f",&compra);
	cliente[cod_cliente].montante=cliente[cod_cliente].montante+compra;
	printf("compra adicionada no montante com sucesso!");
	menu_principal();
}
	

