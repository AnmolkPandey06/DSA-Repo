#include <bits/stdc++.h>
bool dfscycle(int i,unordered_map<int,list<int>>&adj,unordered_map<int,bool> &visitedroots, unordered_map<int,bool> &visitedcalls){
    visitedroots[i]=1;
    for(auto neigh:adj[i]){
        if(!visitedroots[neigh]){
              visitedcalls[neigh]=1;
              bool ans=dfscycle(neigh,adj,visitedroots,visitedcalls);
              if(ans) return 1;
              visitedcalls[neigh]=0;
        }
        else if (visitedcalls[neigh] &&visitedroots[neigh] ){
              return 1;
        }
    }

    return 0;

}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
  for(int i=0; i<edges.size();i++){
      int u=edges[i].first;
      int v=edges[i].second;
      adj[u].push_back(v);
         
  }
  
 //to put the calls details
  unordered_map <int,bool> visitedroots;
  unordered_map <int,bool> visitedcalls;
  for(int i=0;i<n;i++){
    if(!visitedroots[i]){
         visitedcalls[i]=1;
         bool ans=dfscycle(i,adj,visitedroots,visitedcalls);
         visitedcalls[i]=0;  
         if(ans) return 1;
    }
  }
  return 0;




}