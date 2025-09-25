#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/************************************************************
 *  C Doubly Linked List Implementation
 *  Author: Biswajeet Sahoo
 *  GitHub: https://github.com/bixuuu4u/C-LIST.git
 *  Description: STL-like list container implemented in C
 ************************************************************/

int list_empty(List *l)
{
    return l->size == 0;
}

int list_size(List *l)
{
    return l->size;
}

int list_front(List *l)
{
    if (l->head == NULL)
    {
        return -1;
    }
    return l->head->data;
}

int list_back(List *l)
{
    if (l->tail == NULL)
    {
        return -1;
    }
    return l->tail->data;
}

void list_clear(List *l)
{
    Node *curr = l->head;

    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    l->head = l->tail = NULL;
    l->size = 0;
}

void list_erase(List *l, int position)
{
    if (position < 0 || position >= l->size)
    {
        return;
    }

    if (position == 0)
    {
        list_pop_front(l);
        return;
    }
    if (position == l->size - 1)
    {
        list_pop_back(l);
        return;
    }
    Node *temp = l->head;
    for (int i = 0; i < position; i++)
    {
        if (temp == NULL)
        {
            return;
        }
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;

    free(temp);
    l->size--;
}

void list_insert(List *l, int position, int value)
{
    if (position < 0 || position > l->size)
    {
        return;
    }

    if (position == 0)
    {
        list_push_front(l, value);
        return;
    }

    if (position == l->size)
    {
        list_push_back(l, value);
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

void list_pop_front(List *l)
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

void list_pop_back(List *l)
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

void list_push_front(List *l, int value)
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

void list_push_back(List *l, int value)
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

void list_display(List *l)
{
    Node *temp = l->head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void list_init(List *l)
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