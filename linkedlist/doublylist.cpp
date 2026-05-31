#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};
class doublylist{
    Node*head;
    Node*tail;
    public:
    doublylist(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node*newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
    void push_back(int val){
        Node*newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    void pop_front(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        else{
            Node*temp=head->next;
            head->next=NULL;
            head->prev=NULL;
            delete head;
            head=temp;
            if(head!=NULL){
            head->prev=NULL;
            }
        }
    }
    void pop_back(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        else if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
            Node*temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            tail->prev=NULL;
            delete tail;
            tail=temp;
            temp->next=NULL;
        }
    }
    void printLL(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};
int main(){
    doublylist l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_back(3);
    l1.pop_front();
    l1.pop_back();
    l1.pop_back();
    l1.printLL();
}