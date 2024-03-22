#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	deque <int> mini;
	deque <int> maxi;
    long long int sum=0;
	for (int i=0;i<k;i++){
		while(!mini.empty() && nums[mini.back()]>nums[i]){
			mini.pop_back();
		} 
		while(!maxi.empty() && nums[maxi.back()]<nums[i]){
			maxi.pop_back();
		} 
		maxi.push_back(i);
		mini.push_back(i);
	}
	

	for (int i=k;i<n;i++){
		//taking sum
		sum=sum+nums[maxi.front()] + nums[mini.front()];
         
		 //removing the ones which are out of window
		while(!mini.empty() && i-mini.front()>=k){
			mini.pop_front();
		} 
        
		while(!maxi.empty() && i-maxi.front()>=k){
			maxi.pop_front();
		}
	   
	   // adding 
	    while(!mini.empty() && nums[mini.back()]>nums[i]){
			mini.pop_back();
		} 
		while(!maxi.empty() && nums[maxi.back()]<nums[i]){
			maxi.pop_back();
		} 
		maxi.push_back(i);
		mini.push_back(i);
	}
    
	//taking sum of last 
	sum=sum+nums[maxi.front()] + nums[mini.front()];
    
	return sum;
}
