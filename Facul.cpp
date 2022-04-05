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

struct cliente{
	unsigned short int codigo_cliente=0;
	char nome[30]="\0";
	short int ano_nascimento=0; 
	float montante=0; 
} cliente[10];
static unsigned short int numero_de_clientes=0; //numero do cliente=codigo do cliente
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
		if (menu_principal>0&&menu_principal<7){
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
			zerar_todos_pedidos();
			break;
	
		case 5:
			listar_melhor_comprador();
			break;
	
		case 6:
			exibir_compras_cliente();
			break;			
	}
}
	
	
void incluir_cliente(){
int limite_de_memoria=2;
int add_espaco=0;
	if (numero_de_clientes>limite_de_memoria){
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
	cliente[numero_de_clientes].codigo_cliente=numero_de_clientes;
	printf("Cadastro cliente código %d",cliente[numero_de_clientes].codigo_cliente);
	printf("\nNome do Cliente:");
	scanf("%s",&cliente[numero_de_clientes].nome);
	printf("Ano de Nascimento:");
	scanf("%d",&cliente[numero_de_clientes].ano_nascimento);
	printf("\nCliente código %d cadastrado com sucesso!\n\n",numero_de_clientes);
	numero_de_clientes++;
	menu_principal();
}


void remover_cliente(){
short int limpa_dados=-1;
short int x=0,y=0,z=0;
short int num_cliente=-1;
	printf("\nImprimindo lista de cadastrados:\n");
	for (x=0;x<numero_de_clientes;x++){
		printf("\nCódigo_____:%d\n",cliente[x].codigo_cliente);
		printf("Nome_______:%s\n",cliente[x].nome);
		printf("Nascimento_:%d\n",cliente[x].ano_nascimento);
		printf("Montante___:%0.2fR$\n\n",cliente[x].montante);
	}
	printf("Digite o código do cliente para excluí-lo \n(para cancelar a exclusão digite um código numérico inexistente):");
	scanf("%d",&limpa_dados);
	num_cliente=numero_de_clientes;
	num_cliente--;
	if (limpa_dados==num_cliente){
		printf("\nIniciando limpeza de dados...\n");
		cliente[limpa_dados].codigo_cliente=0;
		cliente[limpa_dados].nome[0]='\0';
		cliente[limpa_dados].ano_nascimento=0;
		cliente[limpa_dados].montante=0;
		numero_de_clientes--;
		printf("limpeza da dados concluida com sucesso!\n");
	}
	else if (limpa_dados<num_cliente&&limpa_dados>=0){
		printf("\nIniciando limpeza de dados...");
		for (x=limpa_dados;x<numero_de_clientes;x++){
			y=x;
			y++;
			for (z=0;z<=30;z++){
			cliente[x].nome[z]=cliente[y].nome[z];
			}
			cliente[x].ano_nascimento=cliente[y].ano_nascimento;
			cliente[x].montante=cliente[y].montante;
		}
		numero_de_clientes--;
		printf("limpeza da dados concluida com sucesso!\n");
	}
	else{
		printf("Código inexistente\n\n");
		menu_principal();
	}
	printf("\nNova lista atualizada:\n");
	for (x=0;x<numero_de_clientes;x++){
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
	for (x=0;x<numero_de_clientes;x++){
		printf("\nCódigo_____:%d\n",cliente[x].codigo_cliente);
		printf("Nome_______:%s\n",cliente[x].nome);
		printf("Nascimento_:%d\n",cliente[x].ano_nascimento);
		printf("Montante___:%0.2fR$\n\n",cliente[x].montante);
	}
	printf("Digite o código do cliente:");
	scanf("%d",&cod_cliente);
	if (cod_cliente<0||cod_cliente>numero_de_clientes||numero_de_clientes==0){
		printf("código não existente\n\n");
		menu_principal();
	}
	printf("Digite o valor da compra(separando centavos com vírgula):R$");
	scanf("%f",&compra);
	cliente[cod_cliente].montante=cliente[cod_cliente].montante+compra;
	printf("compra adicionada no montante com sucesso!\n\n");
	menu_principal();
}

	
void zerar_todos_pedidos(){
int confirma=0,x;
	printf("\n1 - Confirmar\n2 - Cancelar\nZerar todos os pedidos?");
	scanf("%d",&confirma);
	if (confirma==1){
		for (x=0;x<numero_de_clientes;x++){
			cliente[x].montante=0;
		}
		printf("Montantes dos clientes foram zerados\n\n!");
		menu_principal();
	}
	else if (confirma==2){
		printf("Zerar os pedidos cancelado!\n\n");
		menu_principal();
	}
	else{
		printf("Resposta inválida!\n\n");
		menu_principal();
	}
}


void listar_melhor_comprador(){
unsigned short int cliente1=0,cliente2,lista[numero_de_clientes],clientex=0,x;
	if (numero_de_clientes==0){
		printf("\nNão possui clientes!\n\n");
		menu_principal();
	}
	else if (numero_de_clientes==1){
		printf("\nCódigo_____:%d\n",cliente[0].codigo_cliente);
		printf("Nome_______:%s\n",cliente[0].nome);
		printf("Nascimento_:%d\n",cliente[0].ano_nascimento);
		printf("Montante___:%0.2fR$\n\n",cliente[0].montante);
		menu_principal();
	}
	else if (numero_de_clientes>1){
		cliente2=1;
		for (cliente1=0;cliente2<numero_de_clientes;cliente1++){
			if (cliente[cliente1].montante>cliente[cliente2].montante){
				lista[0]='\0';
				clientex=0;
				lista[clientex]=cliente1;
				clientex=1;
			}
			else if (cliente[cliente1].montante<cliente[cliente2].montante){
				lista[0]='\0';
				clientex=0;
				lista[clientex]=cliente2;
				clientex=1;
			}
			else if (cliente[cliente1].montante==cliente[cliente2].montante){
				if (cliente1==0){
					lista[clientex]=cliente1;
					clientex++;
				}
				if (lista[clientex-1]!=cliente1){
					lista[clientex]=cliente1;
					clientex++;
				}
				lista[clientex]=cliente2;
				clientex++;
			}
			cliente2++;
		}
		
		for(x=0;x<clientex;x++){
		printf("%d\n",lista[x]);
		}
		printf("\n");
		menu_principal();
	}
	else{
		printf("o programa está com algum problema, contate o desenvolvedor");
	}
}


void exibir_compras_cliente(){
int codigo;
	printf("\nDigite o código do cliente a exibir montante:");
	scanf("%d",&codigo);
	if (codigo<0||codigo>=numero_de_clientes){
		printf("Lamento, esse código não existe\n\n");
		menu_principal();
	}
	printf("\nO montante de compras do cliente %s é %0.2fR$\n\n",cliente[codigo].nome,cliente[codigo].montante);
	menu_principal();
}
