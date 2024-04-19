#include <bits/stdc++.h>
void dfs(int i,  unordered_map<int,list<int>> &adj,unordered_map <int,bool> &visited, stack <int > &st){
    visited[i]=1;
    for(auto j:adj[i]){
          if(!visited[j]){
                dfs(j,adj,visited,st);
          }
    }
    st.push(i);
}


vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    unordered_map<int,list<int>> adj;
    for(int i=0; i<graph.size();i++){
      int u=graph[i][0];
      int v=graph[i][1];
      adj[u].push_back(v);
         
     }
     
     unordered_map <int,bool> visited;
     stack <int> st;

     for(int i=0; i<nodes;i++){
          if(!visited[i]){
                dfs(i,adj,visited,st);
                 
          }
     }

     vector <int > ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

    


}
    