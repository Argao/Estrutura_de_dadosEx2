#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//STRUCTS
struct Produto{
    int codigo;
    char descricao[50];
    float preco;
    int quantidade;
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
    printf("Digite a quantidade do produto:\n");
    scanf_s("%d",&produto[pos].quantidade);
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
void alterarProduto(int tam,struct Produto *produto){
    int cod;
    printf("Digite o codigo do produto que voce deseja alterar:\n");
    scanf_s("%d",&cod);
    int pos = buscaProduto(tam,cod,produto);

    if(pos < 0){
        printf("Nenhum produto com esse codigo foi encontrado!!\n");
    } else{
        printf("Produto encontrado:\n");
        exibirDados(pos,produto);
        printf("Qual dado deseja alterar?\nDigite:\n");
        printf("1 Para alterar o codigo\n");
        printf("2 Para alterar a descrição\n");
        printf("3 Para alterar o preco\n");
        printf("4 Para alterar a quantidade\n");
        int opcao;
        scanf_s("%d",&opcao);
        switch (opcao) {

            case 1:
                printf("Digite o novo codigo:");
                scanf_s("%d",&produto[pos].codigo);
                break;
            case 2:
                printf("Digite a nova descricao:");
                scanf_s("%s",&produto[pos].descricao);
                break;
            case 3:
                printf("Digite o novo preco:");
                scanf_s("%f",&produto[pos].preco);
                break;
            case 4:
                printf("Digite a nova quantidade:");
                scanf_s("%d",&produto[pos].quantidade);
                break;

            default:
                printf("Digite uma opcao valida!\n");
        }
    }
}

//OPÇÃO 3
void excluirProduto(int tam,struct Produto *produto){
    int cod;

    printf("Digite o codigo do produto que voce deseja excluir:\n");
    scanf_s("%d",&cod);
    int pos = buscaProduto(tam,cod,produto);

    if(pos < 0){
        printf("Nenhum produto com esse codigo foi encontrado!!\n");
    } else{
        printf("Produto encontrado:\n");
        exibirDados(pos,produto);
        printf("Deseja mesmo excluir esse produto?\nDigite 1 para sim ou 2 para nao:\n");
        int confirm;
        scanf_s("%d",&confirm);
        if (confirm ==1){
            produto[pos].quantidade = 0;
            printf("Produto excluido com sucesso!\n");
        } else {
            printf("Exclusao cancelada!\n");
        }
    }
}
//OPÇÃO 4
void consultarProduto(int tam,struct Produto *produto){
    int cod;

    printf("Digite o codigo do produto que voce deseja consultar:\n");
    scanf_s("%d",&cod);
    int pos = buscaProduto(tam,cod,produto);

    if(pos < 0){
        printf("Nenhum produto com esse codigo foi encontrado!!\n");
    } else{
        printf("Produto encontrado:\n");
        exibirDados(pos,produto);
    }

}
//OPÇÃO 5
void listarProdutos(int tam,struct Produto *produto){
    printf("Lista de produtos cadastrados:\n");
    for (int i = 0; i < tam; ++i) {
        printf("Produto %d:\n",i);
        exibirDados(i,produto);
    }

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
        printf("1-Incluir\n");
        printf("2-Alterar\n");
        printf("3-Excluir\n");
        printf("4-Consultar\n");
        printf("5-Listar\n");
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
                alterarProduto(tam,produto);
                break;
            case 3:
                excluirProduto(tam,produto);
                break;
            case 4:
                consultarProduto(tam,produto);
                break;
            case 5:
                listarProdutos(tam,produto);
                break;
            default:
                printf("Digite uma opcao valida!!");
        }

    }

    return 0;
}

