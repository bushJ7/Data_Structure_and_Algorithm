#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void reverse_linked(Node *&head,Node*&tail){
    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while(current!=nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void delete_by_value(Node *&head,Node *&tail,int target){
    if(head==nullptr){
        cout<<"the list is empty!"<<endl;
        return;
    }

    if (head->data == target){
        Node *temp = head;
        head=head->next;
        if(head==nullptr){
            tail = head;
        }
        delete temp;
        return;
    }

    Node *prev = head;
    Node *current = head->next;
    while(current!=nullptr){
        if(current->data == target){
            prev->next = current->next;
            if(current->next==nullptr){
                tail = prev;
            }
            delete current;
            return;
        }
        current=current->next;
        prev = prev->next;
    }
    cout<<"the value to delete is not found"<<endl;
}

void insert_front(Node *&head,Node *&tail,int amount){
    for(int i=0;i<amount;i++){
        Node *newNode = new Node;
        cout<<"enter the number : ";cin>>newNode->data;
        if(head==nullptr){
            tail = newNode;
        }
        newNode->next = head;
        head = newNode;
    }
}

void free_list(Node *head){
    while(head!=nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void insert_end(Node *&head,Node *&tail,int size){
    for(int i=0;i<size;i++){
    Node *newNode = new Node;
    cout<<"enther the data : ";cin>>newNode->data;
    newNode->next = nullptr;
    if(head==nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
}

void display(Node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
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
            case 3:{
                int target;
                cout<<"enter the target value to delete : ";cin>>target;
                delete_by_value(head,tail,target);
                break;
            }
            case 4:{
                int amount;
                cout<<"enter the amount to add : ";cin>>amount;
                insert_front(head,tail,amount);
                break;
            }
            case 5:{
                reverse_linked(head,tail);
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