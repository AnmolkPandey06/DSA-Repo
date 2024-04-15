//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
 
class node{
    public:
    int data;
    int i;
    int j;
    node(int data, int i,int j){
        this->data=data;
        this->i=i;
        this->j=j;
    }
}; 


class compare {
    public:
    bool operator ()(node *a, node * b){
        return a->data>b->data; 
    }
};


class Solution
{
    public:
    
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
         priority_queue <node *,vector<node*> ,compare>minheap;
         //step 1 inseert al elements of 1st array
         for(int i=0;i<k;i++){
             node * temp=new node(arr[i][0],i,0);
             minheap.push(temp);
         }
         
         vector <int> ans;
         //step 2
         while(minheap.size()>0){
             node * temp=minheap.top();
             ans.push_back(temp->data);
             minheap.pop();
             
             int i=temp->i;
             int j=temp->j;
             
             if(j+1<arr[i].size() ){
                 node * next=new node(arr[i][j+1],i,j+1);
                 minheap.push(next);
             }
         }
             
             
         return ans;
         
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends