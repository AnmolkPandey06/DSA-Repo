#include <bits/stdc++.h>
using namespace std;
template <typename T> //har data typoe pe chalne ke liye


class graph{
    public:
    unordered_map <T,list<T>>adj;
    void  addEdge(T u,T v, bool direction){
        //create an edge with u and v
        //direction=1, directed graph, direction=0 undirected graph
        adj[u].push_back(v);
        if(direction==false){
            adj[v].push_back(u);//undirected graph
        }
         
    }

    void printAd(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};


int main(){

    int n;
    cout<<"Enter no. of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter no. of edges"<<endl;
    cin>>m;
     
    graph <int> gp; 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        //creating an undirected graph
        gp.addEdge(u,v,0);

    }

    gp.printAd();
    return 0;

    


 

}