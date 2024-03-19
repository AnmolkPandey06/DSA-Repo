void insertAtBottom(stack<int> &stack,int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }

    int store=stack.top();
    stack.pop();
    
    insertAtBottom(stack,num);

    stack.push(store);
    return;


}


void solve(stack<int> &stack){
    if(stack.empty()) return;

    //
    int store=stack.top();
    stack.pop();

    solve(stack);


     
    //inserting the element in last
    insertAtBottom(stack,store);

}  

void reverseStack(stack<int> &stack) {

    // Write your code here
    solve(stack);

}