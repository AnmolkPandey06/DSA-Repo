#include <bits/stdc++.h> 
class NStack
{
     int *arr;
     int *top;
     int *next;
    
     int n, s;
     
     int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
          n=N;
          s=S;
          top=new int[n];
          next=new int[s];
          arr=new int[s];

        
        //initialise top and next
         for(int i=0;i<n;i++){
              top[i]=-1;
              
         }
         ///initialise thr next
         for(int i=0;i<s;i++){
              next[i]=i+1;
              
         }
         
         next[s-1]=-1;

         //initialise spotlight
         freespot=0;
      
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // overload
        if(freespot==-1){
            return false;
        }

        //finding index
        int index=freespot;
        //updating spot
        freespot=next[index];
        //pushing the value
        arr[index]=x;
        //changing the next (top se pehle vali value)
        next[index]=top[m-1] ;

        //updating the top
        top[m-1]=index;

        return true;


        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {   

        if(top[m-1]==-1) return -1;
        ///finding the index
        int index=top[m-1];
        //changing the top
        top[m-1]=next[index];
        //now reinitialising the next
        next[index]=freespot;
        //reinitialising thr freeespot
        freespot=index;
        return arr[index];

    }
};