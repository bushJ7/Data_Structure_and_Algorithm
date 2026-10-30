#include <iostream>
using namespace std;

// this circular linked list will not use the tail pointer 
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

void free_list(Node *head){
    Node *current = head;
    do{
        Node *temp = current;
        current = current->next;
        delete temp;
    }while(current!=head);
}

void display(Node *head){
    if(head==nullptr){
        cout<<"the list is empty!"<<endl;
        return;
    }
    Node *current = head;
    do{
        cout<<current->data<<"->";
        current = current->next;
    }while(current!=head);
}
int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    int options;
    do{
        cout<<"===============student management menu dashboard==============="<<endl;
        cout<<"1.display_student\n2.insert end\n3.delete_student\n4.insert_front\n5.reverse the list\n6.exit the program\n";
        cout<<"enter the options : ";cin>>options;
        cout<<"==============================================================="<<endl;
        switch(options){
            case 1:{
                display(head);
                break;
            }
            case 2:{
                int size;
                cout<<"enter the amount of the student to add : ";cin>>size;
                insert_end(head,tail,size);
                break;
            }
            case 6:{
                free_list(head);
                cout<<"exited!"<<endl;
                break;
            }
        }
    }while(options!=6);
    return 0;
}