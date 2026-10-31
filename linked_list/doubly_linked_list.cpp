#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};

bool initial_the_first_node(Node *&head,Node*&tail){
    if(head==nullptr){
        Node *newNode = new Node;
        cout<<"enter the value : ";cin>>newNode->data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return true;
    }
    return false;
}
void insert_front(Node *&head,Node *&tail,int size){
    if(initial_the_first_node(head,tail)){
        size--;
    }
    for(int i=0;i<size;i++){
        Node *newNode = new Node;
        cout<<"enter the value : ";cin>>newNode->data;
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
    }
}
void insert_end(Node *&head , Node *&tail,int size){
    if(initial_the_first_node(head,tail)){
        size--;
    }
    for(int i=0;i<size;i++){
        Node *newNode = new Node;
        cout<<"enter the value : ";cin>>newNode->data;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
        }
}



void display_list(Node *head,Node *tail){
    if(head==nullptr){
        cout<<"the list is empty!"<<endl;
        return ;
    }
    int options;
    cout<<"1.display forward"<<endl;
    cout<<"2.display backward"<<endl;
    cout<<"enter the option : ";cin>>options;
    if(options==1){
        cout<<"<- ";
        while(head!=nullptr){
        cout<<head->data<<" -> <- ";
        head = head->next;
        }
    }
    else{

        while(tail!=nullptr){
            cout<<"<- ";
            cout<<tail->data<<" -> <- ";
            tail = tail->prev;
        }
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
                display_list(head,tail);
                break;
            case 2:{
                int size;
                cout<<"enter the size to add : ";cin>>size;
                insert_end(head,tail,size);
                break;
            }
            case 6:{
                free_list(head,tail);
                cout<<"exited !"<<endl;
                break;
            }
        }
    }while(options!=6);
    return 0;
}