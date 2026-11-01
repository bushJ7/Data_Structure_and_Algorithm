#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
};
void initialize_first_list(Node *&head,Node *&tail,int value){
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    tail = newNode;
    head = newNode;
}

void insert_end(Node *&head,Node *&tail,int size){
    for(int i=0;i<size;i++){
        int value;
        cout<<"enter the value: ";cin>>value;
        if(head==nullptr){
            initialize_first_list(head,tail,value);
        }
        else{
            Node *newNode = new Node;
            newNode->data = value;
            head->prev = newNode;
            newNode->prev = tail;
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
}
void insert_front(Node *&head,Node *&tail,int size){
    for(int i=0;i<size;i++){
        int value;
        cout<<"enter the value : ";cin>>value;
        if(head==nullptr){
            initialize_first_list(head,tail,value);
        }
        else{
            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
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
    else if(options==2){
        Node *current = tail;
        cout<<"Tail     NULL <-> ";
        do{
            cout<<"["<<current->data<<"] <-> ";
            current = current->prev;
        }while(current!=tail);
        cout<<"NULL     Head"<<endl;
    }
    else{
        cout<<"invalid input options!"<<endl;
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

void delete_by_value(Node *&head,Node*&tail,int target){
    if(head==nullptr){
        cout<<"the list is empty!"<<endl;
        return;
    }

    if(head->data== target){
        if(head->next==head){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else{
            Node *temp = head;
            head = head->next;
            delete temp;
            tail->next = head;
            head->prev = tail;
        }
        cout<<target<<" has been deleted"<<endl;
        return;
    }

    Node *current = head->next;
    do{
        if(current->data==target){
            if(current->next!=head){
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            else{
                tail = current->prev;
                head->prev = tail;
                tail->next = head;
                delete current;
            }
            cout<<target<<" has been deleted!"<<endl;
            return;
        }
        current = current->next;
    }while(current!=head);
    cout<<"the target "<<target<<" is not found"<<endl;
}
int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    int options;
    do{
        cout<<"===============student management menu dashboard==============="<<endl;
        cout<<"1.display_list\n2.insert end\n3.delete_value\n4.insert_front\n5.exit the program\n";
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
                free_list(head,tail);
                cout<<"exited!"<<endl;
                break;
            }
        }
    }while(options!=6);
    return 0;
}
    