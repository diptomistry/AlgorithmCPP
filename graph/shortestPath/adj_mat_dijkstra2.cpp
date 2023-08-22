#include<bits/stdc++.h>
using namespace std;


void Dijkstra_using_adj_matrix(vector<vector<int>>& adj, int v){
    vector<int> dist(v,INT_MAX);
    vector<bool>vis(v,false);

    dist[0] = 0;
    set<pair<int,int>> pq;
    pq.insert({dist[0],0});

    while(pq.empty()==false){
        auto node = pq.begin();
        int vertex = (*node).second;
        int wt = (*node).first;
        pq.erase({wt,vertex});

        if(vis[vertex]==true) continue;

        vis[vertex] = true;

        for(int child=0; child<v; child++){

            if(adj[vertex][child]>0 and dist[vertex] + adj[vertex][child] < dist[child]){
                dist[child] = dist[vertex] + adj[vertex][child];
                pq.insert({dist[child], child});
            }
        }
    }


    for(int i=0; i<dist.size(); i++){
        cout<<dist[i]<<endl;
    }


}


int main(){

int v;

cin>>v;

vector<vector<int>> adj(v,vector<int>(v));

for(int i=0; i<v; i++){
    for(int j=0; j<v; j++){
        cin>>adj[i][j]; //directed graph
    }
}


Dijkstra_using_adj_matrix(adj,v);




return 0;
}