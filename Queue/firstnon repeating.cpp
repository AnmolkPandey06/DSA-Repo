//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		   queue <char> q;
		   string ans;
		   unordered_map <char,int> count;
		   for(int i=0; i<A.length(); i++){
		      
		      char ch=A[i];
		      
		      // increase count
		      count[ch]++;
		      //push into queue
		      q.push(ch);
		      
		      
		      while(!q.empty()){
		          if(count[q.front()]>1){
		              //repeating character nhi chahiye
		              q.pop();
		          }
		          else {
		              //storing the ans
		              ans.push_back(q.front());
		              break;
		          }
		          
		      }
		      
		      if(q.empty()) ans.push_back('#');
		      
		      
		      
		   }
		   return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends