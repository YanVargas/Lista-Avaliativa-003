#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define P 2 
#define MAX_FABRICANTE 5
//Area de STRUCT:

struct Fabrica{
  char marca[100];
  char site[40];
  char uf[5];
  char telefone[30];
};

struct Produto{
  char descricao[100];
  float peso;
  float compra;
  float venda;
  float lucro;
  float percentual;
  struct Fabrica fabricante;
  char descricaoProvisoria[100];
};

//Prototipaçao Funcoes :
int QuantidadeFabricante (int qnt); //quantidade de fabricas;
int QuantidadeProduto(int qnt);
//todos os menus/relatorio :
int MenuPrincipal(int *seletor, int qnt_produto, int qnt_fabricante, struct Fabrica fabrica[], struct Produto produto[]);
void ufs_escolhidas_pelo_fabricante(struct Fabrica *fabrica, int con);
//void ufs_disoniveis_para_pesquisa(struct Fabrica*fabrica); // deve ser colocado dentro do menu principal na opcao 3
void Opcao1(struct Fabrica* fabrica, int qnt_fabricante);
void Opcao2(struct Produto* fabrica, int qnt_produto);
void Opcao3(struct Fabrica* fabrica, struct Produto* produto, int qnt_fabrica,int qnt_produto);
void Opcao4(struct Produto* produto, int qnt_produto);
void Opcao5(struct Produto* produto, int qnt_produto);
void Opcao6(struct Produto* produto, int qnt_produto);
void Opcao7(struct Produto* produto, int qnt_produto);
void Opcao8(struct Produto* produto, int qnt_produto);
void Opcao9(struct Produto* produto, int qnt_produto);
//Bubble Sort
//void BubbleSort(int qntTotal , struct BubbleSort* bubble );

//fim da funcoa 

int main (void){//Inicio main
//Area de variaveis geras:
  int qnt_fabricante;
  int qnt_produto;
  int seletorUF;
  int seletorFabrica;
  int seletorRelatori;
  int ret;
  int retorno;
  
                     
  
  //cadastro fabricante :
          //quantidade de fabricantes:
          qnt_fabricante = QuantidadeFabricante (qnt_fabricante);
          qnt_produto = QuantidadeProduto (qnt_produto);

              //qnt_produto = P;
  
            //atribuição do tamanho do vetor
            struct Fabrica fabrica[qnt_fabricante];
            struct Produto produto[qnt_produto];  

         //cadastro dos fabricantes:
        
            for(int con=0; con < qnt_fabricante;con++){//inicio for
                printf("+---------------------------------------------------+\n");
                printf("Cadastro Fabricante (%d)\n\n", con+1);
                printf("Informe o nome do Fabricante: ");
                scanf(" %[^\n]s", &fabrica[con].marca);
                printf("\nInforme o site do Fabricante: ");
                scanf(" %[^\n]s", &fabrica[con].site);
                printf("\nInforme o telefone do Fabricante: ");
                scanf(" %[^\n]s", &fabrica[con].telefone);
                
                printf("\n");
                ufs_escolhidas_pelo_fabricante(fabrica, con);
                printf("\n\t>Fabricante UF (%d): %s\n",con+1, fabrica[con].uf);
                }//Fechamento do FOR   //fim do cadastro do fabricante ;

              
            //cadastro produto:
            for(int con=0; con < qnt_produto;con++){//incio for: 
                printf("+---------------------------------------------------+\n");
                printf("Cadastro Produto (%d)\n\n", con+1);
                printf("Informe o nome do produto: ");
                scanf(" %[^\n]s", &produto[con].descricao);
                printf("\nInforme o peso do produto: ");
                scanf(" %f", &produto[con].peso);
                printf("\nInforme o valor de compra do produto: ");
                scanf(" %f", &produto[con].compra);
                printf("\nInforme o valor de venda do produto: ");
                scanf(" %f", &produto[con].venda);
              //lucro & percentual :
                produto[con].lucro = produto[con].venda - produto[con].compra;
                produto[con].percentual = produto[con].lucro * 100 / produto[con].venda;
              
                printf("\nLucro: %.2f\nPercentual: %.2f%%\n", produto[con].lucro, produto[con].percentual);//Referencia provisória (TESTE)
                printf("\nEscolha entre as opcoes abaixo: \n");

                //FOR para imprimir as fabricas
                for(int i = 0 ; i < qnt_fabricante ; i++){
                  printf("\t[%i] %s\n",i+1,fabrica[i].marca);
                } 

                //DO WHILE para verificar
                do {
                    //Ta tendo erro com o CHAR, repetição infinita;
                  printf("\n Digite: ");
                  scanf("%d", &seletorFabrica);
                
                  if (seletorFabrica < 1 || seletorFabrica > qnt_fabricante) {
                    printf("\n\t!Opcao incorreta. Digite novamente!\n");
                  } 
                } while (seletorFabrica < 1 || seletorFabrica > qnt_fabricante);
                
                strcpy(produto[con].fabricante.marca, fabrica[seletorFabrica - 1].marca);
                strcpy(produto[con].fabricante.uf, fabrica[seletorFabrica - 1].uf);
                
                printf("\nMarca do produto (%s): %s\n", produto[con].descricao, produto[con].fabricante.marca);
                printf("\nUF do produto (%s): %s\n", produto[con].descricao, produto[con].fabricante.uf);
                } //Fechamento do FOR produto; //fim do cadastro do produto; 
  
                //Função para o relatório
                do{
                  retorno = MenuPrincipal(&seletorRelatori, qnt_produto, qnt_fabricante, fabrica, produto);
                   // printf("\nretorno = %d", retorno);
                }while(retorno != 0);
        
return 0;
}//Fim main;


// funçoes :

int QuantidadeFabricante (int qnt){//inicio funçoes:
 //quantidade de fabricantes:
    printf("+---------------------------------------------------+\n");
    printf("Informe o numero de fabricantes a serem registrados \n");
    printf("Entre 2 a 5 fabricantes \n\n");
    do {
        while (1) {
          printf(" Digite: ");
          if (scanf("%d", &qnt) == 1) {//incio if
              break;
          } else {//fim if //inicio elese
              printf("\n\t!Digite um numero. Tente novamente!.\n\n");
              // Limpar o buffer de entrada para evitar repetições infinitas
              while (getchar() != '\n');
          }//fim else 
        }//Fechamento While
  
        if(qnt < 2 || qnt > 5){
               printf("\n\t!Numero invalido. Tente novamente!.\n\n");
        }
        else{}
    } while (qnt < 2 || qnt > 5);
    //fim do quantidade fabricante ;
return qnt;
}//fim funcoe

int QuantidadeProduto (int qnt){//inicio funçoes:
 //quantidade de fabricantes:
    printf("+---------------------------------------------------+\n");
    printf("Informe o numero de produto a serem registrados \n");   
    printf("Entre 5 a 50 fabricantes \n\n");
    do {
        while (1) {
          printf(" Digite: ");
          if (scanf("%d", &qnt) == 1) {//incio if
              break;
          } else {//fim if //inicio elese
              printf("\n\t!Digite um numero. Tente novamente!.\n\n");
              // Limpar o buffer de entrada para evitar repetições infinitas
              while (getchar() != '\n');
          }//fim else 
        }//Fechamento While
  
        if(qnt < 5 || qnt > 50){
               printf("\n\t!Numero invalido. Tente novamente!.\n\n");
        }
        else{}
    } while (qnt < 5 || qnt > 50);
    //fim do quantidade fabricante ;
return qnt;
}//Função Quantidade 

int MenuPrincipal(int *seletor, int qnt_produto, int qnt_fabricante, struct Fabrica fabrica[], struct Produto produto[]) {//abertura Menu:
    do{
        printf("+---------------------------------------------------+\n");
        printf("Relatorio\n\n");
        printf("Escolha uma opcao:\n");
        printf("[1] Listar todas as marcas\n");//funcionando
        printf("[2] Listar todos os produtos\n");//funcionando
        printf("[3] Listar os produtos de um determinado estado\n");//Não está funcionando!!
        printf("[4] Listar os produtos de uma determinada marca\n");//funcionando
        printf("[5] Apresentar o(s) estado(s) onde esta resgistrado o produto mais caro\n");//funcionando
        printf("[6] Apresentar o(s) fabricante(s) onde esta resgitrado o produto mais barato\n");//funcionando
        printf("[7] Listar todos os produtos em ordem crescente de valor\n");//funcionando
        printf("[8] Listar todos os produtos em ordem crescente de maior valor de lucro\n");//funcionando
        printf("[9] Listar todos os produtos em ordem crescente de maior percentual de lucro\n");//funcionando
        printf("[0] Para sair\n");//funcionando
        printf("\nOpcao selecionada: ");
        scanf("%d",seletor);
      
        switch (*seletor) {
        case 1:
          Opcao1(fabrica ,qnt_fabricante);
          break;
        case 2:
          Opcao2(produto,qnt_produto);
          break;
        case 3:
          Opcao3(fabrica,produto,qnt_fabricante,qnt_produto);
          break;
        case 4:
          Opcao4(produto,qnt_produto);
          break;
        case 5:
          Opcao5(produto,qnt_produto);
          break;
        case 6:
          Opcao6(produto, qnt_produto);
          break;
        case 7:
          Opcao7(produto, qnt_produto);
          break;
        case 8:
          Opcao8(produto, qnt_produto);
          break;
        case 9:
            Opcao9(produto, qnt_produto);
          break;
        
         }//fim  SWITCH

    }while(*seletor>9||*seletor<0);
return *seletor;
}//fim menu 
//todos os relatorios;
void Opcao1(struct Fabrica* fabrica, int qnt_fabricante){
  printf("\n+---------------------------------------------------+\n");
  printf("Relatorio das marcas:\n");
  
  for(int i=0; i<qnt_fabricante;i++){
    printf("- %s\n", fabrica[i].marca);
    }
}//fim função

void Opcao2(struct Produto* produto, int qnt_produto){
  printf("\n+---------------------------------------------------+\n");
  printf("Relatorio dos produtos:\n");
  
  for(int i=0; i<qnt_produto;i++){
    printf("- %s\n", produto[i].descricao);
    }
}//fim função

void Opcao3(struct Fabrica* fabrica, struct Produto* produto, int qnt_fabrica, int qnt_produto) {
    printf("\n+---------------------------------------------------+\n");
    printf("Relatorio dos produtos de um determinado estado:\n");
    char validaUf[5];

    printf("Digite a UF desejada: ");
    scanf(" %[^\n]s", validaUf);

    printf("UF selecionada: %s\n", validaUf);

    int contador = 0; // Contador para armazenar a quantidade de produtos encontrados

    for (int i = 0; i < qnt_produto; i++) {
        if (strcmp(produto[i].fabricante.uf, validaUf) == 0) {
            contador++; // Incrementa o contador quando a UF é igual
            printf("- %s\n", produto[i].descricao);
        }
    }

    if (contador == 0) {
        printf("\nNenhum produto encontrado com a UF selecionada.\n");
    } else {
        printf("\nOBS: Não esta funcionando como deveria, tive um pouco de dificuldade!%d\n", contador);
    }
}//fim função


void Opcao4(struct Produto* produto, int qnt_produto){
  printf("\n+---------------------------------------------------+\n");  
  printf("Relatorio dos produtos de uma determinada marca:\n");
  char ValidaMarca[100];//Variavel pra validar a marca
  int ret;//variavel para reter o inteiro da função STRCMP
  int ValidaDowhile;

    do{ //For para verificar se o VALIDA é igual ao nome, se caso for igual ele vai PRINTAR 
      printf("Digite a marca desejada existente!: ");
      scanf(" %[^\n]s", ValidaMarca);
      getchar(); // Limpa o caractere de nova linha (\n) do buffer de entrada
      printf("\n");
      
      for(int i = 0; i<qnt_produto ;i++){
          ret = strcmp(produto[i].fabricante.marca, ValidaMarca);
            
            if(ret == 0){
              printf("- %s\n",produto[i].descricao);
            }
            else{
              ret=0; //else para reinicializar o ret e não conflitar no do while  
            }
        }//Fechamento FOR

   }while(ret != 0);//fechamento DO WHILE
}

void Opcao5(struct Produto* produto, int qnt_produto){
  //qnt_produto pra avaliar a quantidade de vetores na condição
  //produto[i].venda pra printar o valor de venda
  printf("\n+---------------------------------------------------+\n");  
  printf("Relatorio do estado que possui o produto mais caro: \n");

        for(int j=0;j<qnt_produto;j++){
        strcpy(produto[j].descricaoProvisoria, produto[j].fabricante.uf);
        }


  for(int i=0;i<qnt_produto;i++){
    for(int j=0;j<(qnt_produto-1);j++){

        if(produto[j].venda > produto[j+1].venda){//Maior para crescente e Menor para descresente
          float temp = produto[j].venda;
          produto[j].venda = produto[j+1].venda;
          produto[j+1].venda = temp;

          char temp2[100];
          strcpy(temp2, produto[j].descricaoProvisoria);
          strcpy(produto[j].descricaoProvisoria, produto[j+1].descricaoProvisoria);
          strcpy(produto[j+1].descricaoProvisoria, temp2);
          
         
        }//Fevhamento IF

    }//Fechamento for J
  }//Fechamento for I

    printf("- Estado com o produto mais caro (R$%.2f): %s\n",produto[qnt_produto-1].venda, produto[qnt_produto-1].fabricante.uf);

}//fechamento função

void Opcao6(struct Produto* produto, int qnt_produto){
  //qnt_produto pra avaliar a quantidade de vetores na condição
  //produto[i].venda pra printar o valor de venda
  printf("\n+---------------------------------------------------+\n");  
  printf("Relatorio do fabricante que possui o produto mais barato: \n");

        for(int j=0;j<qnt_produto;j++){
        strcpy(produto[j].descricaoProvisoria, produto[j].fabricante.marca);
        }


  for(int i=0;i<qnt_produto;i++){
    for(int j=0;j<(qnt_produto-1);j++){

        if(produto[j].venda < produto[j+1].venda){//Maior para crescente e Menor para descresente
          float temp = produto[j].venda;
          produto[j].venda = produto[j+1].venda;
          produto[j+1].venda = temp;

          char temp2[100];
          strcpy(temp2, produto[j].descricaoProvisoria);
          strcpy(produto[j].descricaoProvisoria, produto[j+1].descricaoProvisoria);
          strcpy(produto[j+1].descricaoProvisoria, temp2);
          
         
        }//Fevhamento IF

    }//Fechamento for J
  }//Fechamento for I

    printf("- Fabricante com o produto mais barato (R$%.2f): %s\n",produto[qnt_produto-1].venda, produto[qnt_produto-1].fabricante.marca);

}//fechamento função

void Opcao7(struct Produto* produto, int qnt_produto){
  //qnt_produto pra avaliar a quantidade de vetores na condição
  //produto[i].venda pra printar o valor de venda
  printf("\n+---------------------------------------------------+\n");  
  printf("Relatorio em ordem cresente do valor de venda: \n");

        /*for(int j=0;j<qnt_produto;j++){
        strcpy(produto[j].descricaoProvisoria, produto[j].descricao);
        }*///Esse for ta servindo pra resolver um  problema que altera o valor do produto.descricao, pra evitar eu resolvi criar uma descricao feita pra ser alterada


  for(int i=0;i<qnt_produto;i++){
    for(int j=0;j<(qnt_produto-1);j++){

        if(produto[j].venda > produto[j+1].venda){//Maior para crescente e Menor para descresente
          float temp = produto[j].venda;
          produto[j].venda = produto[j+1].venda;
          produto[j+1].venda = temp;

          /*char temp2[100];
          strcpy(temp2, produto[j].descricaoProvisoria);
          strcpy(produto[j].descricaoProvisoria, produto[j+1].descricaoProvisoria);
          strcpy(produto[j+1].descricaoProvisoria, temp2);
          */
         
        }//Fevhamento IF

    }//Fechamento for J
  }//Fechamento for I

  for(int i=0;i<qnt_produto;i++){
    printf("%d- Valor do produto: R$%.2f\n", i+1,produto[i].venda);
  }//fechamento for que ta servindo pra printar

}//fechamento função

void Opcao8(struct Produto* produto, int qnt_produto){
  //qnt_produto pra avaliar a quantidade de vetores na condição
  //produto[i].lucro pra printar o valor de lucro
  printf("\n+---------------------------------------------------+\n");  
  printf("Relatorio em ordem cresente do valor de lucro: \n");

  for(int i=0;i<qnt_produto;i++){
    for(int j=0;j<(qnt_produto-1);j++){

        if(produto[j].lucro > produto[j+1].lucro){//Maior para crescente e Menor para descresente
          float temp = produto[j].lucro;
          produto[j].lucro = produto[j+1].lucro;
          produto[j+1].lucro = temp;
        }//Fevhamento IF

    }//Fechamento for J
}//Fechamento for I

  for(int i=0;i<qnt_produto;i++){
    printf("%d- lucro do produto: R$%.2f\n", i+1,produto[i].lucro);
  }//fechamento for que ta servindo pra printar

}//fechamento função

void Opcao9(struct Produto* produto, int qnt_produto){
  //qnt_produto pra avaliar a quantidade de vetores na condição
  //produto[i].percentual pra printar o percentual
  printf("\n+---------------------------------------------------+\n");  
  printf("Relatorio em ordem cresente do percentual de lucro: \n");

        for(int j=0;j<qnt_produto;j++){
        strcpy(produto[j].descricaoProvisoria, produto[j].descricao);
        }//Esse for ta servindo pra resolver um  problema que altera o valor do produto.descricao, pra evitar eu resolvi criar uma descricao feita pra ser alterada

  for(int i=0;i<qnt_produto;i++){
    for(int j=0;j<(qnt_produto-1);j++){

        if(produto[j].percentual > produto[j+1].percentual){//Maior para crescente e Menor para descresente

          float temp = produto[j].percentual;
          produto[j].percentual = produto[j+1].percentual;
          produto[j+1].percentual = temp;
        }//Fevhamento IF

    }//Fechamento for J
}//Fechamento for I

  for(int i=0;i<qnt_produto;i++){
    printf("%d- Percentual de lucro do produto: %.2f%%\n", i+1,produto[i].percentual);
  }//fechamento for que ta servindo pra printar

}


void ufs_escolhidas_pelo_fabricante(struct Fabrica *fabrica, int con){

    char ufs[27 /*nm_ufs*/][50] =
        {" AC", " AL", " AP", " AM", " BA",
         " CE", " DF", " ES", " GO", "MA",
         "MT", "MS", "MG", "PA", "PB",
         "PR", "PE", "PI", "RJ", "RN",
         "RS", "RO", "RR", "SC", "SP",
         "SE", "TO"};
    int op = 0;
    int count = 0;

    // imprimindo as ufs em formato de tabela
    for (int i = 0; i < 6 /*nm_linhas*/; i++)
    {
        for (int j = 0; j < 5 /*nm_colunas*/; j++)
        {
            if (count < 10 /*num_ufs*/)
            {
                printf("[%d]%-9s", count + 1, ufs[count]);
            }
            else if (count > 9 && count < 27)
            {
                printf("[%d]%-8s", count + 1, ufs[count]); // para um melhor alinhamento
            }
            count++;
        }
        printf("\n");
    }

    // recebe os nomes das ufs escolhidas pela marca/fabricante
    for (int i = 0; i < 1; i++)
    { // laço de validacao do intervalo
        printf("\nSelecione uma UF valida para o fabricante: ");
        scanf("%d", &op);
        if (op > 0 && op < 28)
        {
            strcpy(fabrica[con].uf, ufs[op - 1]);
        }
        else
        {
            printf("!Opcao invalida. Tente novamente!\n");
            i--;
        }
    }
}

void ufs_disoniveis_para_pesquisa(struct Fabrica*fabrica, int qnt_fabric){
  int retorno;
  
  for(int i=0;i<MAX_FABRICANTE;i++){

    retorno = strcmp(fabrica[i].uf, fabrica[i+1].uf);//raciocinio imcompleto, nao repete as UFS caso tenha mais de uma igual
    if(retorno!=0){
      printf("[%d]%-5s\t",i+1, fabrica[i].uf);
    }
  }
  printf("\n");

  
}