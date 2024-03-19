#include <bits/stdc++.h> 
void insertinSortedWay(stack<int> &stack,int num){
    if(stack.empty() || stack.top()<num ){
		stack.push(num);
		return;
	}
     
	int store=stack.top();
	stack.pop();

	insertinSortedWay(stack,num);

	stack.push(store);

	return;

}




void solve(stack<int> &stack){
	if(stack.empty()){
		return;
	}

	// store here
	int store=stack.top();
	stack.pop();
     
	solve(stack);
	//Now insert in sorted way 
	insertinSortedWay(stack,store);

	
	return;
}



void sortStack(stack<int> &stack)
{
	// Write your code here

    solve(stack);



}
