#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};

bool initial_the_first_node(Node *&head,Node*&tail,int value){
    if(head==nullptr){
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return true;
    }
    return false;
}
void insert_front(Node *&head,Node *&tail,int size){
    for(int i=0;i<size;i++){
        int value;
        cout<<"enter the value : ";cin>>value;
        if(!initial_the_first_node(head,tail,value)){
            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
    }
}
void insert_end(Node *&head , Node *&tail,int size){
    for(int i=0;i<size;i++){
        int value;
        cout<<"enter the value : ";cin>>value;
        if(!initial_the_first_node(head,tail,value)){
            Node *newNode = new Node;
            newNode->data = value;
            newNode->prev = tail;
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
    }
}
//this function assume that the user enter the valid position which is between 1 to n (1,n]
//which 1 is the position of the head and n is the position of the tail , n is inclusive , 1 is exclusive
//also assume that the list is >=2
void insert_at_position(Node *head,int pos){
    Node *newNode = new Node;
    cout<<"enter the value : ";cin>>newNode->data;
    for(int i=1;i<pos;i++){
        head  = head->next;
    }
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
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
        cout<<"Head     NULL <-> ";
        while(head!=nullptr){
        cout<<"["<<head->data<<"] <-> ";
        head = head->next;
        }
        cout<<"NULL     Tail"<<endl;
    }
    else{
        cout<<"Tail     NULL <-> ";
        while(tail!=nullptr){
            cout<<"["<<tail->data<<"] <-> ";
            tail = tail->prev;
        }
        cout<<"NULL     Head"<<endl;
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

bool delete_by_value(Node *&head,Node *&tail,int target){
    if(head==nullptr){
        cout<<"the list is empty!"<<endl;
        return false;
    }
    if(head->data==target){
        if(head->next==nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }
        else{
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return true;
        }
    }
    Node *current = head->next;
    while(current!=nullptr){
        if(current->data==target){
            if(current->next!=nullptr){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return true;
            }
            else if(current->next==nullptr){
                tail = tail->prev;
                tail->next = nullptr;
                delete current;
                return true;
            }
        }
        current = current->next;
    }
    return false;
}
int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    int options;
    do{
        cout<<"===============student management menu dashboard==============="<<endl;
        cout<<"1.display_value\n2.insert end\n3.insert_front\n4.insert_at_position\n5.delete by value\n6.exit the program\n";
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
            case 3:{
                int size;
                cout<<"enter the amount to add : ";cin>>size;
                insert_front(head,tail,size);
                break;
            }
            case 4:{
                int pos;
                cout<<"enter the position to insert (>=2) : ";cin>>pos;
                insert_at_position(head,pos);
                break;
            }
            case 5:{
                int target;
                cout<<"enter the target value to delete : ";cin>>target;
                if(!delete_by_value(head,tail,target)){
                    cout<<"the list is empty or the value is doesn't exist"<<endl;
                }
                else{
                    cout<<target<<" has been deleted!"<<endl;
                }
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