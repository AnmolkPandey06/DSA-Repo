#include <bits/stdc++.h> 
class TwoStack {
    int *arr;
    int size;
    int top1;
    int top2;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        arr=new int[s];
        this->size=s;
        top1=-1;
        top2=s;

        // Write your code here.
    }

    // int isfull1(){
    //     if(top1==size1) return 1;
    //     else return 0;       
    // }
    
    // int isfull2(){
    //     if(top2==size2) return 1;
    //     else  return 0;       
    // }

    // int isempty1(){
    //    if(top1==-1) return 1;
    //    else return 0;
    // }
    // int isempty2(){
    //    if(top2==capacity/2) return 1;
    //    else return 0;
    // }
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top1+1!=top2){
           top1++; 
           arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2-1!=top1){
           top2--; 
           arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1<0){
           return -1;
        }
        else{
            
            int ret= arr[top1];
            top1--;
            return ret;

        }

    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2==size){
           return -1;
        }
        else{
            int ret=arr[top2];
            top2;
            return ret;
             
        }
    }
};