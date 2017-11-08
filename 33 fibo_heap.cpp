#include <iostream>
using namespace std;
struct Node{
         Node *leftChild;
         Node *rightChild;
        int data;
    };
 bool insertHeap(Node **heap, int data, short index){
        Node *newNode, *temp, *parent;
        int tempData;
        short mask = 0x80;

    try{
        newNode = new Node;
    }
    catch (bad_alloc& e) {
        cerr << "Memory allocation error: " << e.what() << endl;
        return false;
    }

    while (!(index & mask)) index <<= 1;

    index <<= 1;
    parent = NULL;
    temp = *heap;

    while (temp){
        if (data > temp->data){
            tempData = temp->data;
            temp->data = data;
            data = tempData;
        }       
        parent = temp;

        if (!(index & mask)) temp = temp->leftChild; 
        else temp = temp->rightChild;

        if (temp) index <<= 1;
    }

    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->data = data;

    if(!parent){
        *heap = newNode;
        return true;
    }

    if (!(index & mask)) parent->leftChild = newNode;
    else parent->rightChild = newNode;

    return true;
}
int main (){
    Node *heap = NULL;
    int arr[13] = {3,6,8,1,5,9,4,2,0,7,11,14,13}; 

    for (int i=0; i<13; i++) insertHeap(&heap, arr[i], i+1);   
    return 0;
}


   
