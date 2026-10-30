#include <iostream>
using namespace std;

// this circular linked list will only use the tail pointer because it is the industry standard and improve the perfromance because the tail pointer already point to the head node
struct Node{
    int data;
    Node *next;
};
void insert_end(Node *&tail,int size){
     for(int i=0;i<size;i++){
        Node *newNode = new Node;
        cout<<"enter the number : ";cin>>newNode->data;
        if(tail==nullptr){
            tail = newNode;
            tail->next = newNode;
        }
        else{
            newNode->next = tail->next;
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

void display(Node *tail){
    if(tail==nullptr){
        cout<<"the list is empty!"<<endl;
        return;
    }
    Node *current = tail->next;
    do{
        cout<<current->data<<"->";
        current = current->next;
    }while(current!=tail->next);
}
int main(){
    Node *tail = nullptr;
    int options;
    do{
        cout<<"===============student management menu dashboard==============="<<endl;
        cout<<"1.display_student\n2.insert end\n3.delete_student\n4.insert_front\n5.reverse the list\n6.exit the program\n";
        cout<<"enter the options : ";cin>>options;
        cout<<"==============================================================="<<endl;
        switch(options){
            case 1:{
                display(tail);
                break;
            }
            case 2:{
                int size;
                cout<<"enter the amount of the student to add : ";cin>>size;
                insert_end(tail,size);
                break;
            }
            case 6:{
                free_list(tail->next);
                cout<<"exited!"<<endl;
                break;
            }
        }
    }while(options!=6);
    return 0;
}