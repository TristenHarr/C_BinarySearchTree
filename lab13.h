#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ID;
    float salary;
    int age;
}Employee;

typedef struct node{
    void* data;
    struct node *left, *right;
}Node;

Employee* readRecord(FILE*);
Node* createNode(void*);
int comparison(void*,void*);
Node* insertBST(Node*, void*);
void inOrderPrintAge(Node*);
void deleteTree(Node*);
