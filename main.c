//arvore binaria de busca, objetivo:
//usuario vai inserindo elementos até que ele deseje parar
//depois verificar se é ou n uma arvore AVL(Balanceada)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} node;

node* newNode(int item);
node * insert(node *root, int key);

int height(node* node);
int max(int a, int b);
int isBalanced( node* root);

int main()
{
    node *root = NULL;
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
            root = insert(root, valor);
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
    if (isBalanced(root) == 1)
        printf("Arvore AVL \n");
    else
        printf("Arvore nao AVL \n");
    return 0;
}
node* newNode(int item)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
node * insert(node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}
int height(node* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
int max(int a, int b)
{
    return (a >= b) ? a : b; 
}
int isBalanced(node* root)
{
    int lh;
    int rh;
    if (root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}