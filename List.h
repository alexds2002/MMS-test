#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <inttypes.h>

typedef struct Item{
    int16_t number;
    char info[250];
    double price;
    double weight;
}Item;

typedef struct node {
    Item data;
    struct node* next;
} node_t;

double randomDoubleInRange(double min, double max){
    return (double)min + ((double)rand() / RAND_MAX) * (double)max;
}

node_t* create_node(Item);
void push(node_t**, Item);
void print_listInfo(node_t*);
double totalItemsWeight(node_t*);
node_t *minPriceItem(node_t*);
void listFree(node_t**);
void insertNth(node_t**, Item, size_t);
