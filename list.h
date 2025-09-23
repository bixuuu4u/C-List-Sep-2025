#if !defined(LIST_H)
#define LIST_H

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
    int size;
} List;

Node *create_node(int value);
void init_list(List *l);
void display(List *l);
void push_back(List *l, int value);
void push_front(List *l, int value);
void pop_front(List *l);
void pop_back(List *l);
void insert(List *l, int position, int value);
#endif // LIST_H
