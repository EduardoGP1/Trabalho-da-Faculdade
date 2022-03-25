#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct carro

{
int num=0;
char marca[50]="NULL";
char modelo[50]="NULL";
int ano=0;
char placa[50]="NULL";
}car;

int main(void)
{
setlocale(LC_ALL,"portuguese");
struct carro car[9];
int numcar=0;
int menu1=0;
int menu2=0;
int ano=0;
int z=0;
char modelopesq[50]="NULL";

do
{
printf("\n OPÇÕES:");
printf("\n 1. Lista");
printf("\n 2. Cadastrar");
printf("\n 3. Pesquisar");
printf("\n 4. Sair");
printf("\n \n Digite o Número da Opção Desejada: ");
scanf("%d",&menu1);

switch(menu1)
{
case 1:
printf("\nLista de Carros:\n");
if (numcar == 0)
{
printf("\nNenhum Veículo Cadastrado\n");
}
for(int x=0; x<numcar; x++)
{
printf("\n %d° Carro", x+1);
printf("\n Marca__: %s",car[x].marca);
printf("\n Modelo_: %s",car[x].modelo);
printf("\n Ano____: %d",car[x].ano);
printf("\n Placa__: %s\n\n",car[x].placa);
}

break;

case 2:
if (numcar<=9)
{
car[numcar].num=numcar;
printf("\n Digite a marca do veículo:");
scanf("%s",&car[numcar].marca);
printf("\n Digite o modelo do veículo:");
scanf("%s",&car[numcar].modelo);
printf("\n Digite o ano do veículo:");
scanf("%d",&car[numcar].ano);
printf("\n Digite a placa do veículo:");
scanf("%s",&car[numcar].placa);
numcar=numcar+1;
}

else
{
printf("\n Limite de cadastro é 10!\n");
}

break;

case 3:
do
{
printf("\n Pesquisar por:");
printf("\n 1. Ano");
printf("\n 2. Ano Mínimo");
printf("\n 3. Modelo");
printf("\n 4. Voltar");
printf("\n \n Digite o Número da Opção Desejada: ");
scanf("%d",&menu2);

switch(menu2)
{
case 1:
printf("\n Insira o Ano:");
scanf("%d",&ano);

for (int x=0; x<numcar; x++)
{
if (car[x].ano == ano)
{
printf("\n %d° Carro", x+1);
printf("\n Marca__: %s",car[x].marca);
printf("\n Modelo_: %s",car[x].modelo);
printf("\n Ano____: %d",car[x].ano);
printf("\n Placa__: %s\n\n",car[x].placa);
z++;
}
}

if (z==0)
{
printf("\n NÃO FOI ENCONTRADO VEÍCULOS DO ANO %d \n",ano);
}

else
{
z=0;
}

break;

case 2:
printf("\n Insira o Ano Mínimo:");
scanf("%d",&ano);

for (int x=0; x<numcar; x++)
{
if (car[x].ano >= ano)
{
printf("\n %d° Carro", x+1);
printf("\n Marca__: %s",car[x].marca);
printf("\n Modelo_: %s",car[x].modelo);
printf("\n Ano____: %d",car[x].ano);
printf("\n Placa__: %s\n\n",car[x].placa);
z++;
}
}

if (z==0)
{
printf("\n NÃO FOI ENCONTRADO VEÍCULOS ACIMA DE %d \n\n",ano);
}

else
{
z=0;
}

break;

case 3:
printf("\n Insira o Modelo:");
scanf("%s",&modelopesq);

for (int x=0; x<numcar; x++)
{
if (strcasecmp(car[x].modelo,modelopesq) == 0)
{
printf("\n %d° Carro", x+1);
printf("\n Marca__: %s",car[x].marca);
printf("\n Modelo_: %s",car[x].modelo);
printf("\n Ano____: %d",car[x].ano);
printf("\n Placa__: %s\n\n",car[x].placa);
z++;
}
}

if (z==0)
{
printf("\n NÃO FOI ENCONTRADO O MODELO %s \n\n",modelopesq);

}

else
{
z=0;
}

break;

case 4:

break;

default:
printf("\n OPÇÃO NÃO EXISTE!\n");

}
}
while (menu2!=4);
break;

case 4:
printf("\nPROGRAMA ENCERRADO!\n");

break;

default:
printf("\n OPÇÃO NÃO EXISTE!\n");

break;
}
}
while (menu1!=4);

return 0;

}
