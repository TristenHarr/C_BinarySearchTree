#include "lab13.h"

Employee* readRecord(FILE* fp){
    Employee* record = (Employee*)malloc(sizeof(Employee));
    fscanf(fp, "%d,%f,%d\n", &record->ID, &record->salary, &record->age); // scan file and get inputs
    return record;

}

Node* createNode(void *data){
    Node *mynode = malloc(sizeof(Node));
    if (mynode == NULL){
        printf("Allocation Failed");
        return NULL;
    }
    mynode->data = data;
    mynode->left = NULL;
    mynode->right = NULL;
    return mynode;
};

int comparison(void *a, void *b){
    float alpha = ((Employee *)a)->salary;
    float beta = ((Employee *)b)->salary;
    if (alpha > beta) {
        return 1;
    } else if (alpha == beta) {
        return 0;
    } else {
        return -1;
    }
};

Node* insertBST(Node *head, void *newdata){
    if (head == NULL){
        Node *node1 = createNode(newdata);
        return node1;
    } else {
    if (comparison(head->data, newdata) == 1){
        head->left = insertBST(head->left, newdata);
    } else {
        head->right = insertBST(head->right, newdata);
    }
    }
    return head;
};

void inOrderPrintAge(Node *root){
    if (root == NULL){
        return;
    }
    inOrderPrintAge(root->left);
    printf(" [%d]\n", ((Employee*)root->data)->age);
    inOrderPrintAge(root->right);
};

void deleteTree(Node *root){
    if (root->left == NULL && root->right == NULL){
        return free(root);
    }
    deleteTree(root->left);
    deleteTree(root->right);
};
