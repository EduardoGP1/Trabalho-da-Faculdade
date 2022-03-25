#include <iostream>
#include <locale.h>

int menu_principal();
void menu_compras_de_clientes();
void incluir_cliente();
void remover_cliente();
void zerar_todos_pedidos();
void listar_melhor_comprador();
void exibir_compras_cliente_por_codigo();
void exibir_compras_cliente_por_nome();
void exibir_compras_cliente_por_cpf();

int main (){
setlocale(LC_ALL,"portuguese");
menu_principal();
}
menu_principal(){
int menu_principal=0;
int resposta_valida=0;

	do{
		printf("1 - Incluir cliente\n");
		printf("2 - Remover cliente\n");
		printf("3 - Zerar todos os pedidos\n");
		printf("4 - Listar melhor comprador\n");
		printf("5 - Exibir compras de um cliente\n");
		printf("Digite o número da opção desejada:");
		scanf("%d", &menu_principal);
		printf("\n\no valor escolhido foi: %d\n", menu_principal);
		system("pause");
		system("cls");
	}
	while(resposta_valida==0);
	}

