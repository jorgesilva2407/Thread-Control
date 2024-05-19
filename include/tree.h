#ifndef TREE_H_
#define TREE_H_

/* Nó de uma árvore */
typedef struct Node {
    int val;             // Grupo real
    int hash;            // Grupo virtual
    struct Node* right;  // Nó da direita
    struct Node* left;   // Nó da esquerda
} Node;

/* Árvore que define renomeia os grupo de cada thread */
typedef struct {
    int counter;  // Contador de quantos elementos existem na árvore
    Node* root;   // Nó raiz da árvore
} Tree;

/* Atribui um grupo virtual a um grupo real */
Node* create_node(int val, int hash);
/* Libera a memória de um nó */
void free_node(Node* node);

/* Inicializa uma árvore */
void init_tree(Tree* tree);
/* Encontra o grupo virtual de um grupo real já inserido */
int find(Tree* tree, int val);
/* Insere um novo grupo real na árvore e retorna seu grupo virtual */
int insert(Tree* tree, int val);
/* Retorna o grupo virtual de um grupo real */
int get_hash(Tree* tree, int val);

#endif
