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
void list_init(List *l);
void list_display(List *l);
void list_push_back(List *l, int value);
void list_push_front(List *l, int value);
void list_pop_front(List *l);
void list_pop_back(List *l);
void list_insert(List *l, int position, int value);
void list_erase(List *l, int position);
void list_clear(List *l);
int list_front(List *l);
int list_back(List *l);
int list_empty(List *l);
int list_size(List *l);
#endif // LIST_H
