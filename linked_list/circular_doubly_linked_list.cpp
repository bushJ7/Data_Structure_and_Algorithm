#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
};

void insert_end(Node *&head,Node *&tail,int size){
    for(int i=0;i<size;i++){
        Node *newNode = new Node;
        cout<<"enter the value : ";cin>>newNode->data;
        if(head==nullptr){
            head = newNode;
            tail = newNode;
            head->next = newNode;
            head->prev = newNode;
        }
        else{
            head->prev = newNode;
            newNode->prev = tail;
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
}
void display(Node *head,Node *tail){
    if(head==nullptr){
        cout<<"the list is empty!"<<endl;
        return ;
    }
    int options;
    cout<<"1.display forward"<<endl;
    cout<<"2.display backward"<<endl;
    cout<<"enter the option : ";cin>>options;
    if(options==1){
        cout<<"Head     Tail <-> ";
        Node *current = head;
        do{
            cout<<"["<<current->data<<"] <-> ";
            current = current->next;
        }while(current!=head);
        cout<<"Head     Tail"<<endl;
    }
    else{
        Node *current = tail;
        cout<<"Tail     NULL <-> ";
        do{
            cout<<"["<<current->data<<"] <-> ";
            current = current->prev;
        }while(current!=tail);
        cout<<"NULL     Head"<<endl;
    }
}
void free_list(Node *&head,Node *&tail){
    if(head==nullptr){
        return;
    }
    tail->next = nullptr;
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
        cout<<"1.display_student\n2.insert end\n3.delete_student\n4.insert_front\n5.reverse the list\n6.exit the program\n";
        cout<<"enter the options : ";cin>>options;
        cout<<"==============================================================="<<endl;
        switch(options){
            case 1:{
                display(head,tail);
                break;
            }
            case 2:{
                int size;
                cout<<"enter the amount of the student to add : ";cin>>size;
                insert_end(head,tail,size);
                break;
            }
            // case 3:{
            //     int target;
            //     cout<<"enter the target value to delete : ";cin>>target;
            //     delete_by_value(head,tail,target);
            //     break;
            // }
            // case 4:{
            //     int amount;
            //     cout<<"enter the amount to add : ";cin>>amount;
            //     insert_front(head,tail,amount);
            //     break;
            // }
            // case 5:{
            //     reverse_linked(head,tail);
            //     break;
            // }
            case 6:{
                free_list(head,tail);
                cout<<"exited!"<<endl;
                break;
            }
        }
    }while(options!=6);
    return 0;
}
    