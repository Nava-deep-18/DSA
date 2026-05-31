#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    Node*head;
    Node*tail;
    public:
    List(){
       head=NULL;
       tail=NULL;
    }
    void push_front(int val){
        Node *newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            return;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    void push_back(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void pop_front(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        else{
            Node*temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        else{
            Node*temp=head;
            while(temp->next!=tail){
               temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next=NULL;
            // temp->next=NULL;
            // tail=temp;    // This causes memory leak and not recommonded
        }
    }   
    void insert(int val,int pos){
        Node*newnode=new Node(val);
        if(pos==0){
            push_front(val);
        }
        else if(pos<0){
            return;
        }
        else{
           Node *temp=head;
           for(int i=0;i<pos-1;i++){
               temp=temp->next;
               if(temp==NULL){
                 cout<<"invalid position"<<endl;
                 return;
               }
           }
           newnode->next=temp->next;
           temp->next=newnode;
        }
    } 
    void search(int val){
        Node*temp=head;
        int count=0;
        while(temp!=NULL){
            if(temp->data==val){
                cout<<count<<endl;
                return;
            }
            temp=temp->next;
            count++;
        }
        cout<<"element is not present in the list"<<endl;
        return;
    }
    void printLL(){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
List l1;
l1.push_front(1);
l1.push_front(2);
l1.push_front(3);
l1.push_back(0);
l1.push_back(5);
l1.pop_front();
l1.pop_back();
l1.insert(5,0);
l1.insert(6,4);
l1.printLL();
l1.search(2);
}