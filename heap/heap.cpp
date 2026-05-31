#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size=0;
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deletefromheap(){
        if(size==0){
            cout<<"nothing to delet"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<=size){
            int leftindex=2*i;
            int rightindex=2*i+1;
            int largest = i;
            if(leftindex <= size && arr[leftindex] > arr[largest]){
                largest = leftindex;
            }
            if(rightindex <= size && arr[rightindex] > arr[largest]){
                largest = rightindex;
            }
            if(largest != i){
               swap(arr[i], arr[largest]);
                i = largest;
            }
            else{
                return;
            }
        }
    }
};
void heapify(int arr[], int n, int i) {
    while (true) {
        int leftindex = 2 * i;
        int rightindex = 2 * i + 1;
        int largest = i;
        if (leftindex <= n && arr[leftindex] > arr[largest]) {
            largest = leftindex;
        }
        if (rightindex <= n && arr[rightindex] > arr[largest]) {
            largest = rightindex;
        }
        if (largest == i) {
            break; 
        }
        swap(arr[i], arr[largest]);
        i = largest;  
    }
}

void heapsort(int arr[], int n) {
    int size = n;
    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}
int main(){
    heap h;
    h.insert(54);
    h.insert(50);
    h.insert(59);
    h.insert(540);
    h.insert(89);
    h.deletefromheap();
    h.print();
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing the array"<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,n);
    cout<<"printing the sorted array"<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}