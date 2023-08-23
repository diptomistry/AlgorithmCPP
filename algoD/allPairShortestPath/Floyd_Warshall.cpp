//G4G

#include<bits/stdc++.h>
using namespace std;

//#define infinity INT_MAX;

void PrintShortestPath(vector<vector<int>>& descendent, int src, int dest){

    if(descendent[src][dest]==-1){
        cout<<"no path exists"<<endl;
        return;
    }

    int i = src, j = dest;
    vector<int> path;

    path.push_back(i);

    while(i != j){
        i = descendent[i][j];
        path.push_back(i);
        
    }
    for(int a: path){
        cout<<a<<" ";
    }

    cout<<endl;
}


vector<vector<int>> Floyd_Warshall(vector<vector<pair<int,int>>>graph, int v){

    vector<vector<int>> dp(v, vector<int>(v));

    vector<vector<int>> descendent (v, vector<int>(v));

    

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i!=j){
                dp[i][j] = INT_MAX;
            }
            else {
                dp[i][j] = 0;
            }

            descendent[i][j] = -1;
        }
    }

    for(int i=0; i<graph.size(); i++){

        for(auto& a: graph[i]){
            int j = a.first;
            int w = a.second;

            //cout<<j<<endl;

            dp[i][j] = w;
            descendent[i][j] = j;

        }
    }


    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){

                if( (dp[i][k] != INT_MAX) and (dp[k][j] != INT_MAX)){

                    if(dp[i][j] >  dp[i][k] + dp[k][j]){
                        dp[i][j] = dp[i][k] + dp[k][j] ;
                        if(descendent[i][k]!=-1)descendent[i][j] = descendent[i][k];
                    }
                
                }

            }
        }
    }


    PrintShortestPath(descendent, 0 , 3);
    PrintShortestPath(descendent,0,2);


    return dp;
}

int main(){

int v, e;

cin>>v>>e;

vector<vector<pair<int,int>>> graph(v);

while(e--){
    int x,y,w;

    cin>>x>>y>>w;

    graph[x].push_back({y,w});
}

vector<vector<int>> ans = Floyd_Warshall(graph, v); //works for both directed and undirected graph

/*
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

*/
return 0;
}