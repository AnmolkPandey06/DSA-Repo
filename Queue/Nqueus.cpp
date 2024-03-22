#include <bits/stdc++.h> 
class NQueue{
public:
    
    int k;
    int size;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
    
    NQueue(int n, int s){
          int size=s;
          int k=n;
          arr=new int[size];
          front=new int [k];
          rear=new int [k];
          next=new int[size];
          freespot=0;

          for(int i=0; i<size-1; i++){
                next[i]=i+1;
          }
          next[size-1]=-1;

          for(int i=0; i<k; i++){
                rear[i]=-1;
                front[i]=-1;
          }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespot==-1) return false;
        
        int index=freespot;
        freespot=next[index];
        
        if(front[m-1]==-1)  front[m-1]=index;  //front ko index pe rakha jab new queue hai
        else next[rear[m-1]]=index;    //attached the last rear vale ko index se 
        
        rear[m-1]=index;   // rear ab vo index hai 
        next[index]=-1;   // us index ka next ko -1 pe point karao cause last hai
        arr[index]=x;    //value pushed

        return true;

    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1]==-1) return -1;
        int index=front[m-1];   // m q ka front liya
        int val=arr[index];  //val li
        front[m-1]=next[index];   // front ko agle me move karaya
        next[index]=freespot;  // next{index} jab khali hota hai to next freespot dikhata vahi lagaya
        freespot=index;        // freespot ye ho gya

        return val;

    }
};