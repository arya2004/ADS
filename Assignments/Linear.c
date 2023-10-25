#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

void init(int* _table, int* _count, int _TS){
    for (int i = 0; i < _TS; i++)
    {
        _table[i] = -1;
    }
    *_count = 0;
    
}

int getHash(int _key, int TS)
{
    return _key % TS;
}

void insert(int* _table, int _key, int _TS, int* _count)
{
    int count = *_count;
    if(count == _TS){
        fprintf(stdout, "size full");
        exit(1);
    }
    int k =  getHash(_key, _TS);
    while (_table[k] != -1)
    {
       k = (k + 1) % _TS;
    }
    _table[k] = _key;
    *_count += 1;
  //  printf("\nsuc");
    
}

int get(int* _table, int _key, int _TS, int* _count)
{
    
    int k =  getHash(_key, _TS);
    int i = 0;
    while (_table[k] != -1 && i < _TS)
    {   
        if(_table[k] == _key){
           // printf("\nsuc");
            return k;
        }
       k = (k + 1) % _TS;
       i++;
    }
    printf("\nfail");
    return -1;

}
void delete(int* _table, int _key, int _TS, int* _count)
{
    int count = *_count;
    if(count == 0){
        fprintf(stdout, "size empty");
        exit(1);
    }
    int k =  getHash(_key, _TS);
    int i = 0;
    while (_table[k] != -1 || i < _TS)
    {   
        if(_table[k] == _key){
            break;
        }
       k = (k + 1) % _TS;
       i++;
    }
    if(i != _TS)
    {
        _table[k] = -1;
        *_count -= 1;
        printf("\nsuc");
    }else{
        printf("\nfel");
    }
    
}

void display(int* _table, int _TS){
    printf("\n");
    for (int i = 0; i < _TS; i++)
    {
        printf("\n%i ", _table[i]);
    }
      printf("\n");
    
}

void MEnu() {
    int choice =0;
    int TS = 10;
    int count = 0;
    
    printf("Enter Hash Table Size: ");
    scanf("%i", &TS);
    
    int* arr = (int*) malloc(sizeof(int) * TS);
    init(arr, &count, TS);

    int key, key1, key2; // Declare the variables here

        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Get\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
       

    while (choice != 5) {
         printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

       

        switch (choice) {
            case 1:
                printf("Enter key: ");
                fflush(stdin);
                scanf("%i", &key);
                fflush(stdin);
                insert(arr, key, TS, &count);
                break;
            case 2:
                printf("Enter key: ");
                fflush(stdin);
                scanf("%i", &key1);
                fflush(stdin);
                printf("%i\n",get(arr, key1, TS, &count));
                break;
            case 3:
                printf("Enter key: ");
                fflush(stdin);
                scanf("%i", &key2);
                fflush(stdin);
                delete(arr, key2, TS, &count);
                break;
            case 4:
                display(arr, TS);
                break;
            case 5:
             
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }
}


int main()
{
    // int TS = 10;
    // int* arr = (int*) malloc(sizeof(int) * TS);
    // int count = 0;
    // init(arr, &count, TS);
    // insert(arr, 43, TS, &count);
    // insert(arr,135, TS, &count);
    // insert(arr, 72, TS, &count);
    // insert(arr,23, TS, &count);
    // insert(arr, 99, TS, &count);
    // insert(arr, 19, TS, &count);
    // insert(arr, 82, TS, &count);
    
    // display(arr, TS);

        MEnu();


   
    return 0;
}
