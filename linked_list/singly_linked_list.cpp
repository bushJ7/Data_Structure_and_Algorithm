#include <iostream>
using namespace std;
void delete_by_value();
void insert_front();
void sort();
void update();
void display();
void free_list();
void search_by_id();
struct Student{
    int age;
    string name;
    double gpa;
};
struct Node{
    Student student;
    Node *next;
};
void free_list(Node *&head){
    while(head!=nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void insert_end(Node *&head,Node *&tail,int size){
    for(int i=0;i<size;i++){
        int age;
        string name;
        double gpa;
        cout<<"enter the age : ";cin>>age;
        cout<<"enter the name : ";cin>>name;
        cout<<"enter the gpa : " ;cin>>gpa;
        cout<<"===================="<<endl;
        Node *newNode = new Node;
        newNode->student.age = age;
        newNode->student.gpa = gpa;
        newNode->student.name = name;
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
void display_student(Node *head){
    while(head!=nullptr){
        cout<<"============================"<<endl;
        cout<<"name : "<<head->student.name<<endl;
        cout<<"age : "<<head->student.age<<endl;
        cout<<"gpa : "<<head->student.gpa<<endl;
        head = head->next;
    }
}
int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    int options;
    do{
        cout<<"===============student management menu dashboard==============="<<endl;
        cout<<"1.display_student\n2.add_student\n3.update_student\n4.sort_by_id\n5.search_by_id\n6.delete_student\n";
        cout<<"enter the options : ";cin>>options;
        cout<<"==============================================================="<<endl;
        switch(options){
            case 1:{
                display_student(head);
                break;
            }
            case 2:{
                int size;
                cout<<"enter the amount of the student to add : ";cin>>size;
                insert_end(head,tail,size);
                break;
            }
            case 3:{
                
            }
            case 7:{
                free_list(head);
                cout<<"exited!"<<endl;
                break;
            }
        }
    }while(options!=8);
    return 0;
}
