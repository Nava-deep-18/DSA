#include <iostream>
#include <vector>
using namespace std;
class CircularQueue{
    int currsize,cap;
    int *arr;
    int f,r;
    public:
        CircularQueue(int size){
           cap=size;
           arr=new int(cap);
           currsize=0;
           f=0;
           r=-1;
        }
        void push(int data){
            if(currsize==cap){
               cout<<"circular queue is full"<<endl;
               return ;
            }
            r=(r+1)%cap;
            arr[r]=data;
            currsize++;
        }
        void pop(){
            if(currsize==0){
                cout<<"circular queue is empty"<<endl;
                return;
            }
            f=(f+1)%cap;
            currsize--;
        }
        int front(){
            if(currsize==0){
                return -1;
            }
            return arr[f];
        }
        bool empty(){
            return currsize==0;
        }
};
int main(){
    CircularQueue cq(3);
    cq.push(0);
    cq.push(1);
    cq.push(2);
    cq.pop();
    cq.push(4);
    while(!cq.empty()){
        cout<<cq.front();
        cq.pop();
    }
}