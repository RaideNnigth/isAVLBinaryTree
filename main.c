//arvore binaria de busca, objetivo:
//usuario vai inserindo elementos até que ele deseje parar
//depois verificar se é ou n uma arvore AVL(Balanceada)
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    struct cell* right;
    struct cell* left;
    struct cell* father;
    int data;
}cell, tree;

tree * insert(tree *head, int data);
void isAVL(tree *head);
int main(int argc, char const *argv[])
{
    tree *head = NULL;
    int opt = 0;
    do
    {
        printf("0-> Adicionar valor: \n");
        printf("1-> Parar: \n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            int valor = 0;
            printf("Digite um valor inteiro a ser adicionado na arvore: \n");
            scanf("%d", &valor);
            head = insert(head, valor);
            break;
        case 1:
            printf("Parando...\n");
            printf("Bye Bye...\n");
            break;
        default:
            printf("Valor errado digite novamente: \n");
            break;
        }
    } while (opt != 1);
    isAVL(head);
    return 0;
}
tree * insert (tree *head, int data) {
    if(head == NULL){
        head = malloc(sizeof(tree));
        head->data = data;
        return head;
    }
    if(head->data < data){
        if(head->right != NULL){
            insert(head->right, data);
        }else{
            cell* node = malloc(sizeof(tree));
            node->data = data;
            node->father = head;
            head->right = node;
        }
    }
    else{
        if(head->left != NULL){
            insert(head->left, data);
        }else{
            cell* node = malloc(sizeof(tree));
            node->data = data;
            node->father = head;
            head->left = node;
        }
    }
    return head;
}

void isAVL(tree *head){
    cell* right = head->right;
    int rH = 0;
    cell* left = head->left;
    int lH = 0;
    do
    {
        right = right->right;
        rH++;
    } while (right != NULL);
    do
    {
        left = left->left;
        lH++;
    } while (left != NULL);
    if((lH - rH) != 2 && (lH - rH) != -2){
        printf("Não é AVL");
    }else{
        printf(" é AVL");
    }
}
