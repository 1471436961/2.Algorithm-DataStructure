/*************************************************************************
	> File Name: 11.ac.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 25 Jul 2025 04:18:35 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define BASE 26

typedef struct Node {
    int flag;
    struct Node *next[BASE];
    struct Node *fail;
    const char *s;
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    p->fail = NULL;
    p->s = NULL;
    for (int i = 0; i < BASE; i++) p->next[i] = NULL;
    return p;
}

void insert(Node *root, const char *s) {
    Node *p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->s = strdup(s);
    p->flag = 1;
    return ;
}

void build_ac(Node *root) {
    queue<Node *> q;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        root->next[i]->fail = root;
        q.push(root->next[i]);
    }
    while (!q.empty()) {
        Node *cur = q.front(), *p;
        q.pop();
        for (int i = 0; i < BASE; i++) {
            if (cur->next[i] == NULL) continue;
            p = cur->fail;
            while (p && p->next[i] == NULL) p = p->fail; 
            // 假定根节点的失败指针为空
            if (p == NULL) p = root;
            else p = p->next[i];
            cur->next[i]->fail = p;
            q.push(cur->next[i]);
        }
    }
    return ;
}

void find_ac(Node *root, const char *s) {
    Node *p = root, *q;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        q = p;
        while (q) {
            if (q->flag) {
                int len = strlen(q->s);
                printf("find [%d, %d] = %s\n", i - len + 1, i, q->s);
            }
            q = q->fail;
        }
    }
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        clear(root->next[i]);
    }
    free(root);
    return ;
}

int main() {
    int n; 
    char s[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(root, s);
    }
    build_ac(root);
    scanf("%s", s);
    find_ac(root, s);
    clear(root);
    return 0;
}
