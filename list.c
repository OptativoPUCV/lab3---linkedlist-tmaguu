#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList()
{
    List * new = (List *)malloc(sizeof(List));
    assert(new != NULL);
    new->head = new->tail = new->current = NULL;
    return new;
}

void * firstList(List * list) 
{
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }
    list->current = list->head;
    return (void *)list->current->data;  
}

void * nextList(List * list) 
{
    if (list == NULL || list->head == NULL || list->current == NULL || list->current->next == NULL)
    {
        return NULL;
    }
    list->current = list->current->next;
    return (void *)list->current->data;
}

void * lastList(List * list) 
{
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }
    list->current = list->tail;
    return (void *)list->current->data;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) 
{
    if (list == NULL)
    {
        return;
    }
    Node * new = createNode(data);
    if (list->head == NULL)
    {
        list->head = list->tail = new;
      
    }
    else
    {
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    }
  
}

void pushBack(List * list, void * data) 
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
    if (list == NULL)
    {
        return;
    }
    Node * new = createNode(data);
    if (list->current == NULL)
    {
        list->head = list->tail = new;
    }
    else
    {
        new->next = list->current->next;
        new->prev = list->current;
        if (list->current->next == NULL)
        {
            list->tail = new;
        }
        else
        {
            list->current->next->prev = new;
        }
    }
    list->current->next = new;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}