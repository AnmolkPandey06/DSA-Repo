#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size();i++){
      int u=edges[i][0];
      int v=edges[i][1];
      adj[u].push_back(v);
         
     }
      //finding indegress
     vector<int>indegree(v);
     for(int i=0;i<v;i++){
         indegree[i]=0;
     }
     for(auto i: adj){
          for(auto j:i.second){
              indegree[j]++;
          }
     }
     
     //puttting 0 indegree in q
     queue <int> q;

     for(int i=0;i<v;i++){
         if(indegree[i]==0){
             q.push(i);
         }
     }

     //do bfs now
     vector<int> ans;
     while(!q.empty()){
          int front=q.front();
          q.pop();
          ans.push_back(front);
          for(auto j:adj[front]){
              indegree[j]--;
              if(indegree[j]==0){
                 q.push(j); 
              }
          }
     }

    return ans;
    
}