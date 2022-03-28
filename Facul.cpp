#include <iostream>
#include <locale.h>
#include <stdlib.h>

int menu_principal();
void menu_compras_de_clientes();
void selecao(int);
void incluir_cliente();
void remover_cliente();
void zerar_todos_pedidos();
void listar_melhor_comprador();
void exibir_compras_cliente();
void exibir_compras_cliente_por_codigo();
void exibir_compras_cliente_por_nome();
void exibir_compras_cliente_por_cpf();

struct cliente{
	short int codigo_cliente=0;
	char nome[30]="NULL";
	short int ano_nascimento=0; 
	float montante=0; 
} cliente[10];

struct cliente *x= (struct cliente *)malloc(10*sizeof(struct cliente));

int main (){
	
setlocale(LC_ALL,"portuguese");
printf("%d",sizeof(struct cliente));

menu_principal();

system("pause");
system("cls");	
}

menu_principal(){
int menu_principal=0;
int resposta_valida=0;

	do{
		printf("MENU PRINCIPAL:\n");
		printf("1 - Incluir cliente\n");
		printf("2 - Remover cliente\n");
		printf("3 - Adicionar compras de um cliente");
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
			//adicionar_compras();
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
static int numero_do_cliente=0; //numero do cliente=codigo do cliente
int limite_de_memoria=1;
int add_espaco=0;
	if (numero_do_cliente>limite_de_memoria){
		printf("\nLista de clientes cheia! \nDeseja habilitar mais 10 espaços de memória?\n1 - Sim.\n2 - Não.\nDigite o número de sua resposta:");
		scanf("%d",&add_espaco);
		if (add_espaco==1){
			limite_de_memoria=limite_de_memoria+1;
			struct cliente *x= (struct cliente *)malloc((limite_de_memoria+1)*sizeof(struct cliente));
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
	printf("\nNome do Cliente:");
	scanf("%s",&cliente[numero_do_cliente].nome);
	printf("Ano de Nascimento:");
	scanf("%d",&cliente[numero_do_cliente].ano_nascimento);
	printf("\nCliente código %d cadastrado com sucesso!\n\n",numero_do_cliente);
	numero_do_cliente++;
	menu_principal();
}

void remover_cliente(){
	printf("nada ainda");
}
	
	

