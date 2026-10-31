#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};

void insert_end(Node *&head , Node *&tail,int size){
    for(int i=0;i<size;i++){
        Node *newNode = new Node;
        cout<<"enter the value : ";cin>>newNode->data;
        newNode->next = nullptr;
        if(head==nullptr){
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
}
void display_list(Node *head){
    if(head==nullptr){
        cout<<"the list is empty!"<<endl;
        return ;
    }
    while(head!=nullptr){
        cout<<head->data<<" -> <- ";
        head = head->next;
    }
}

void free_list(Node *&head , Node *&tail){
    if(head==nullptr){
        return;
    }
    while(head!=nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    head = nullptr;
}
int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    int options;
    do{
        cout<<"===============student management menu dashboard==============="<<endl;
        cout<<"1.display_value\n2.insert end\n3.delete_student\n4.insert_front\n5.reverse the list\n6.exit the program\n";
        cout<<"enter the options : ";cin>>options;
        cout<<"==============================================================="<<endl;
        switch(options){
            case 1:
                display_list(head);
                break;
            case 2:{
                int size;
                cout<<"enter the size to add : ";cin>>size;
                break;
            }
        }
    }while(options!=6);
    return 0;
}