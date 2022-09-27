#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//STRUCTS
struct Produto{
    int codigo;
    char descricao[50];
    float preco;
    int quantidadeVendida;
    float percentualLucro;
    float lucroObtido;
};


//FUNÇÕES GENERICAS
int buscaProduto(int tam,int cod,struct Produto * produto){
    int pos = -1;

    for (int i = 0; i < tam; ++i) {
        if(cod == produto[i].codigo){
            pos = i;
            break;
        }
    }
    return pos;
}

void receberDados(int pos,struct Produto *produto){
    printf("Digite o codigo:\n");
    scanf_s("%d",&produto[pos].codigo);
    fflush(stdin);
    printf("Digite uma descricao de ate 50 caracteres:\n");
    gets(produto[pos].descricao);
    printf("Digite o preco do produto:\n");
    scanf_s("%f",&produto[pos].preco);
    fflush(stdin);
    printf("Digite a quantidade vendida do produto:\n");
    scanf_s("%d",&produto[pos].quantidadeVendida);
    printf("Digite o percentual de lucro do produto: \n");
    scanf_s("%f",&produto[pos].percentualLucro);
    printf("Digite o lucro obtido:\n");
    scanf_s("%f",&produto[pos].lucroObtido);

    fflush(stdin);
};

void exibirDados(int pos,struct Produto * produto){
    printf("Codigo: %d\n",produto[pos].codigo);
    printf("Descricao: %s\n",produto[pos].descricao);
    printf("Preco: R$ %.2f\n",produto[pos].preco);
    printf("Quantidade: %d\n\n",produto[pos].quantidade);
}


//FUNÇÕES DO MENU

//OPÇÃO 1
int incluirProduto(int tam,struct Produto *produto){

    int pos;
    if (tam > 0){
        produto = (struct Produto*) realloc(produto,(tam+1)* sizeof(struct Produto));
    }
    tam ++;
    pos = tam-1;
    receberDados(pos,produto);
    return tam;
}

//OPÇÃO 2

void registrarVenda(int tam,struct Produto *produto){
    int cod;
    printf("Digite o codigo do produto que deseja registrar a venda:\n");
    int pos = buscaProduto(tam,cod,produto);

    if(pos < 0){
        printf("Nenhum produto com esse codigo foi encontrado!!\n");
    } else{
        printf("Digite a quantidade vendida do produto");
        int qnt;
        scanf_s("%d",qnt);
        produto[pos].quantidadeVendida += qnt;
    }
}

//OPÇÃO 3
void emitirLucratividade(){

}










int main() {
    int opcao = 0;
    struct Produto *produto;
    produto = (struct Produto*) malloc(sizeof(struct Produto));
    int tam = 0;
    int pos;
    printf("Bem vindo ao sitema!!!\n\n");
    while (opcao != 9){
        printf("Menu:\n\n");
        printf("1-Incluir Produto\n");
        printf("2-Registrar Venda\n");
        printf("3-Emitir Lucratividade\n");
        printf("9-Sair\n\n");
        printf("Escolha umas das opcoes acima:\n");
        scanf_s("%d",&opcao);

        switch (opcao) {
            case 9:
                printf("Finalizando o programa!");
                exit(2);
                break;
            case 1:
                tam = incluirProduto(tam,produto);
                break;
            case 2:

                break;
            case 3:

                break;
            default:
                printf("Digite uma opcao valida!!");
        }

    }

    return 0;
}

