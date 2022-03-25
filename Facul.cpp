#include <iostream>
#include <locale.h>

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
	int codigo_cliente=0;
	char nome[30]="null";
	int ano_nascimento=0;
	float total_gastos=0;
};

struct cliente cliente[10];

int main (){
setlocale(LC_ALL,"portuguese");
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
		printf("3 - Zerar todos os pedidos\n");
		printf("4 - Listar melhor comprador\n");
		printf("5 - Exibir compras de um cliente\n");
		printf("Digite o número da opção desejada:");
		scanf("%d", &menu_principal);
		if (menu_principal>0&&menu_principal<6)
			resposta_valida=1;
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
			//remover_cliente();
			break;
		
		case 3:
			//zerar_todos_pedidos();
			break;
	
		case 4:
			//listar_melhor_comprador();
			break;
	
		case 5:
			//exibir_compras_cliente();
			break;			
	}
}
	
void incluir_cliente(){
static int x=0;
	printf("\n\nMENU INCLUIR CLIENTE:\n");
	printf("\nNome do Cliente:");
	scanf("%s",&cliente[x].nome);
	printf("Ano de Nascimento:");
	scanf("%d",&cliente[x].ano_nascimento);
	printf("\nCliente código %d cadastrado com sucesso!\n\n",x);
	x++;
	menu_principal();
}
	
	

