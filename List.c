
#include "List.h"

#define _ITEM_COUNT 5

int main(){
    srand(time(NULL));
    char *randomWords[] = {"Bananana ", "Humtalumpta ", "Discount ", "Sthing ", "Geography "};
    char *randomLowerWords[] = { "more info ", "someting ", "lower case ", "already fked up "};

    Item items[_ITEM_COUNT];
    for (int i = 0; i < _ITEM_COUNT; i++)
    {
        items[i].number = i;
        strcpy(items[i].info, randomWords[rand() % 5]);
        for (int j = 0; j < 5 + rand() % 5; j++)
        {
            strcat(items[i].info, randomLowerWords[rand() % 4]);
        }
        items[i].price = randomDoubleInRange(1, 1500);
        items[i].weight = randomDoubleInRange(0.1, 100);

    }
    

    node_t* head = create_node(items[0]);
    for (int i = 1; i < _ITEM_COUNT; i++)
    {
        push(&head ,items[i]);
    }
    print_listInfo(head);
    totalItemsWeight(head);
    printf("Min price is: %lf\n", minPriceItem(head)->data.price);

    return EXIT_SUCCESS;
}

void push(node_t** list, Item data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

node_t* create_node(Item data){
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_listInfo(node_t* list){
    node_t* current = list;
    while (current){
        printf("%s ", current->data.info);
        current = current->next;
        printf("\n");
    }
    printf("\n");
}



double totalItemsWeight(node_t* head){
    double weight = 0;
    node_t* current = head;
    if (NULL == head)
    {
        return -1;
    }
    
    while (current)
    {
        weight += current->data.weight;
        current = current->next;
    }
    
    printf("Combined weight is : %fkg\n", weight);
    return weight;
}
node_t *minPriceItem(node_t* head){
    if (NULL == head)
    {
        return NULL;
    }
    
    node_t* current = head;
    node_t* ptrToMin = NULL;
    double minPrice = __DBL_MAX__;
    while (current)
    {
        if (current->data.price < minPrice)
        {
            minPrice = current->data.price;
            ptrToMin = current;
        }
        
        current = current->next;
    }
    return ptrToMin;
}

void listFree(node_t** head){
    node_t *current = *head, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *head = NULL;
}

void insertNth(node_t** head, Item data, size_t n){
    node_t* node = create_node(data);
    if (n == 0 || *head == NULL){
        
        *head = node;
        return;
    }
    node_t* current = *head;
    node_t* prev = current;
    while (current != NULL && n--){
        prev = current;
        current = current->next;
    }
    prev->next = node;
    node->next = current;
}
