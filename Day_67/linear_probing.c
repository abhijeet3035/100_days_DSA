// Day 67: Linear Probing (Open Addressing)
#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];
int flag[SIZE]; // 0=empty, 1=occupied

void init() { for (int i = 0; i < SIZE; i++) flag[i] = 0; }

int hashFunc(int key) { return key % SIZE; }

void insert(int key) {
    int idx = hashFunc(key);
    int i = 0;
    while (flag[(idx + i) % SIZE] == 1 && i < SIZE) i++;
    if (i == SIZE) { printf("Hash table full!\n"); return; }
    int pos = (idx + i) % SIZE;
    hashTable[pos] = key;
    flag[pos] = 1;
    printf("Inserted %d at index %d\n", key, pos);
}

int search(int key) {
    int idx = hashFunc(key);
    int i = 0;
    while (flag[(idx + i) % SIZE] && i < SIZE) {
        if (hashTable[(idx + i) % SIZE] == key) return (idx + i) % SIZE;
        i++;
    }
    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        if (flag[i]) printf("[%d]: %d\n", i, hashTable[i]);
        else printf("[%d]: --\n", i);
}

int main() {
    init();
    insert(10); insert(20); insert(15); insert(25); insert(30);
    display();
    int idx = search(25);
    printf("Search 25: %s\n", idx != -1 ? "Found" : "Not Found");
    return 0;
}
