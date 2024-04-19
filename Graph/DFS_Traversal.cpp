#include <bits/stdc++.h>

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &ans){
     visited[node]=true;
     ans.push_back(node);
     for(auto i:adj[node]){
           if(!visited[i]){
                 dfs(i,visited,adj,ans);
           }
     }

    
     return;
}



vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{     
      unordered_map<int,bool> visited;
      unordered_map<int,list<int>> adj;
      for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
      }

       vector<vector<int>> ans;
       for(int i=0;i<V;i++){
            vector<int> component;
             if(!visited[i]){
                   dfs(i,visited,adj,component);
                   ans.push_back(component);
             }
             
       }
       return ans;
}