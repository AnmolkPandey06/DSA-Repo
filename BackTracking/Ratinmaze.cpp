//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
      bool ifmovable(vector<vector<int>>m,vector <vector<int>> &visited,int sx,int sy,int n){
          if((sx>=0 && sx<n) && (sy>=0 && sy<n)  && visited[sx][sy]==0 && m[sx][sy]==1 ) return true;
          return false;
      }
      void solve(vector<vector<int>>m,vector <vector<int>> &visited,string op,vector <string> &ans,int sx,int sy,int n)
{          if(sx==n-1 && sy==n-1){
              ans.push_back(op);
              return;
          }
          //visited
          visited[sx][sy]=1;
          //checking if its movable;
          
          //down
          int x=sx+1,y=sy;
          if(ifmovable(m,visited,x,y,n)){
              op.push_back('D');
              solve(m,visited,op,ans,x,y,n);
              op.pop_back();
          }
          
          ///up
          
          x=sx-1,y=sy;
          if(ifmovable(m,visited,x,y,n)){
              op.push_back('U');
              solve(m,visited,op,ans,x,y,n);
              op.pop_back();
          }
          ///left
          
          x=sx,y=sy+1;
          if(ifmovable(m,visited,x,y,n)){
              op.push_back('R');
              solve(m,visited,op,ans,x,y,n);
              op.pop_back();
          }
          
          
          //right
           x=sx,y=sy-1;
          if(ifmovable(m,visited,x,y,n)){
              op.push_back('L');
              solve(m,visited,op,ans,x,y,n);
              op.pop_back();
          }
          
          
          
          
          
          
          
          
          
          //end
          visited[sx][sy]=0;
}
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector <string> ans;
        if(m[0][0]==0) return ans;
        string op="";
        int sx=0,sy=0;
        vector <vector<int>> visited=m;
        for(int i=0;i<visited.size();i++){
           for(int j=0;j<visited[i].size();j++){
               visited[i][j]=0;
           } 
        }
        
        solve(m,visited,op,ans,sx,sy,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends