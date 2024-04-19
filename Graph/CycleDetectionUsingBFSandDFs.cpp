#include <bits/stdc++.h>
bool cyclebfs(int i,unordered_map<int,list<int>> &adj,unordered_map<int,bool>&visited){
    unordered_map<int,int>parent;
    queue <int> q;
    parent[i]=-1;
    visited[i]=1;
    q.push(i);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto padosi:adj[front]){
            if(visited[padosi]&& (padosi!=parent[front])){
                return true;
            }
            if(!visited[padosi]){
                q.push(padosi);
                visited[padosi]=1;
                parent[padosi]=front;
            }
        }
    }
    return false;
}

bool dfscycle( int i,unordered_map<int,list<int>> &adj,unordered_map<int,bool>&visited,int parent){
     visited[i]=true;
     for(auto j:adj[i]){
       if(!visited[j]){
             bool ans=dfscycle(j,adj,visited,i);
             if (ans) return true;
       }
       else if(j!=parent){
           return true;
       }
       
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //getting adjacency matrix
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;
    // for(int i=0; i<n;i++){
    //     if(!visited[i]){
    //         bool ans=cyclebfs(i,adj,visited);
    //         if(ans) return "Yes";
    //     }
    // }

    for(int i=0; i<n;i++){
        if(!visited[i]){

            bool ans= dfscycle(i,adj,visited,-1);
            if(ans) return "Yes";
        }
    }


    return "No";

}
