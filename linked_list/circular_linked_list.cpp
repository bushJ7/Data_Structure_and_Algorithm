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
void insert_front(Node *tail,int size){
    for(int i=0;i<size;i++){
        Node *newNode = new Node;
        cout<<"enter the value  ";cin>>newNode->data;
        Node *temp = tail->next;
        tail->next = newNode;
        newNode->next = temp;
    }
}
void free_list(Node *&tail){
    if(tail==nullptr){
        cout<<"the list is empty! there is no node to be freed "<<endl;
        return;
    }
    Node *head = tail->next;
    tail->next = nullptr;
    while(head!=nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

bool delete_single_Node(Node *&tail){
    if(tail==nullptr){
        cout<<"the list is empty"<<endl;
        return true;
    }
    if (tail->next==tail){
        delete tail;
        tail = nullptr;
        return true;
    }
    return false;
}
void delete_end(Node *&tail){
    if(!delete_single_Node(tail)){
    Node *head = tail->next;
    Node *newLast = head;
    while(newLast->next != tail){
        newLast = newLast->next;
    }
    newLast->next = head;
    delete tail;
    tail = newLast;
    }
}
void delete_front(Node *&tail){
    if(!delete_single_Node(tail)){
    Node *newHead = tail->next->next;
    delete tail->next;
    tail->next = newHead;
    }
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
        cout<<"1.display_student\n2.insert end\n3.delete_end\n4.insert_front\n5.delete front\n6.exit the program\n";
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
            case 3:{
                delete_end(tail);
                break;
            }
            case 4:{
                
                break;
            }
            case 5:{
                delete_front(tail);
                break;
            }
            case 6:{
                free_list(tail);
                cout<<"exited!"<<endl;
                break;
            }
        }
    }while(options!=6);
    return 0;
}