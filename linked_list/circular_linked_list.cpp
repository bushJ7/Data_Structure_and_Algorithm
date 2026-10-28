#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
void insert_end(Node *&head,Node *&tail,int size){
    for(int i=0;i<size;i++){
        Node *newNode = new Node;
        cout<<"enter the value : ";cin>>newNode->data;
        newNode->next = head;
        if(head == nullptr){
            head = newNode;
            tail = newNode;

        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
}
void display(Node *head,Node *tail){
    do{
        cout<<head->data<<" ";
        head = head->next;
    }while(head->next!=tail->next);
}
int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    return 0;
}