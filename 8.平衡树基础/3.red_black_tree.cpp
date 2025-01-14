/*************************************************************************
	> File Name: 3.red_black_tree.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 11 Jan 2024 08:55:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED    0
#define BLACK  1
#define DBLACK 2
#define NIL (&__NIL)
#define K(n) (n->key)
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define C(n) (n->color)

typedef struct Node {
    int key, color; // 0 : red, 1 : black, 2 : double black
    struct Node *lchild, *rchild;
} Node;

Node __NIL;

__attribute__((constructor))
void init_NIL() {
    NIL->key = -1;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

bool has_red_node(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *left_rorate(Node *root) {
    Node *new_root = root->rchild;
    root->rchild = new_root->lchild;
    new_root->lchild = root;
    return new_root;
}

Node *right_rorate(Node *root) {
    Node *new_root = root->lchild;
    root->lchild = new_root->rchild;
    new_root->rchild = root;
    return new_root;
}

Node *insert_maintain(Node *root) {
    int flag = 0;
    if (C(L(root)) == RED && has_red_node(L(root))) flag = 1;
    if (C(R(root)) == RED && has_red_node(R(root))) flag = 2;
    if (flag == 0) return root;
    if (C(L(root)) == RED && C(R(root)) == RED) goto red_up_maintain;
    if (flag == 1) {
        if (C(R(L(root))) == RED) {
            L(root) = left_rorate(L(root));
        }
        root = right_rorate(root);
    } else {
        if (C(L(R(root))) == RED) {
            R(root) = right_rorate(R(root));
        }
        root = left_rorate(root);
    }
red_up_maintain:
    C(root) = RED;
    C(L(root)) = C(R(root)) = BLACK; // 红色上浮
    return root;
} // 将root结点当成祖父结点

Node *__insert(Node *root, int key){
    if (root == NIL) return getNewNode(key);
    if (key == root->key) return root;
    if (key < root->key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
} // 保证根结点必黑

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (C(L(root)) != DBLACK && C(R(root)) != DBLACK) return root;
    // brother : red
    if (has_red_node(root)) {
        C(root) = RED;
        if (C(L(root)) == RED) {
            root = right_rorate(root);
            R(root) = erase_maintain(R(root));
        } else {
            root = left_rorate(root);
            L(root) = erase_maintain(L(root));
        }
        C(root) = BLACK;
        return root;
    } // 情况4
    // brother : black
    if ((C(L(root)) == DBLACK && !has_red_node(R(root))) 
        || (C(R(root)) == DBLACK && !has_red_node(L(root)))) {
        C(root) += 1;
        C(R(root)) -= 1;
        C(L(root)) -= 1;
        return root;
    } // 情况1
    if (C(R(root)) == DBLACK) {
        C(R(root)) = BLACK;
        if (C(L(L(root))) != RED) {
            L(root) = left_rorate(L(root));
        } // 情况3
        // 情况2
        C(L(root)) = C(root);
        root = right_rorate(root);
    } else {
        C(L(root)) = BLACK;
        if (C(R(R(root))) != RED) {
            R(root) = right_rorate(R(root));
        } // 情况3
        // 情况2
        C(R(root)) = C(root);
        root = left_rorate(root);
    }
    C(L(root)) = C(R(root)) = BLACK;
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (key < root->key) {
        L(root) =  __erase(root->lchild, key);
    } else if (key > root->key) {
        R(root) = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color; //同时兼容三种度为0或1的情况
            free(root);
            return temp;
        } 
        Node *temp = predecessor(root);
        K(root) = K(temp);
        L(root) = __erase(L(root), K(temp));
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    C(root) = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d| %2d; %2d, %2d)\n",
        C(root), K(root),
        K(L(root)), K(R(root))
    );
    output(L(root));
    output(R(root));
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 10
    Node *root = NIL;
    for (int i = 0; i < MAX_N; i++) {
        int x = rand() % 100;
        printf("insert %d to red black tree : \n", x);
        root = insert(root, x);
        output(root);
    }
    int x;
    while (~scanf("%d", &x)) {
        printf("\nerase %d from red black tree\n", x);
        root = erase(root, x);
        output(root);
    }
    clear(root);
    return 0;
}
