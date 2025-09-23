#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    List l;
    init_list(&l);

    push_back(&l, 10);
    push_back(&l, 11);
    push_back(&l, 12);

    push_front(&l, 13);
    push_front(&l, 14);

    insert(&l, 7, 99);

    // pop_back(&l);
    // pop_front(&l);

    display(&l);

    return 0;
}
void insert(List *l, int position, int value)
{
    if (position < 0 || position > l->size)
    {
        return;
    }

    if (position == 0)
    {
        push_front(l, value);
        return;
    }

    if (position == l->size)
    {
        push_back(l, value);
        return;
    }

    Node *new_node = create_node(value);
    Node *temp = l->head;

    for (int i = 0; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;

    l->size++;
}

void pop_front(List *l)
{
    if (l->head == NULL)
    {
        return;
    }
    Node *temp = l->head;

    if (l->head == l->tail)
    {
        l->head = l->tail = NULL;
    }
    else
    {
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    free(temp);
    l->size--;
}

void pop_back(List *l)
{
    if (l->head == NULL)
    {
        return;
    }
    Node *temp = l->tail;

    if (l->head == l->tail)
    {
        l->head = l->tail = NULL;
    }
    else
    {
        l->tail = l->tail->prev;
        l->tail->next = NULL;
    }
    free(temp);

    l->size--;
}

void push_front(List *l, int value)
{
    Node *new_node = create_node(value);
    if (l->head == NULL)
    {
        l->head = l->tail = new_node;
        l->size++;
        return;
    }

    new_node->next = l->head;
    l->head->prev = new_node;
    l->head = new_node;

    l->size++;
}

void push_back(List *l, int value)
{
    Node *new_node = create_node(value);
    if (l->head == NULL)
    {
        l->head = l->tail = new_node;
        l->size++;
        return;
    }

    l->tail->next = new_node;
    new_node->prev = l->tail;

    l->tail = new_node;

    l->size++;
}

void display(List *l)
{
    Node *temp = l->head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void init_list(List *l)
{
    l->head = l->tail = NULL;
    l->size = 0;
}

Node *create_node(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = node->prev = NULL;
    return node;
}