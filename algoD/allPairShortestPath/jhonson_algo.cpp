#include<bits/stdc++.h>
using namespace std;

bool negCycleExists = false;

map<pair<int,int>,int> getEdges(vector<vector<pair<int,int> > >& graph, int v){

    map<pair<int,int>,int> edges;

    for(int i=0; i<v; i++){

        for(auto a: graph[i]){
            int j = a.first;
            int w = a.second;

            edges[make_pair(i,j)] = w;
        }
    }

    return edges;
}

vector<int> bellman_ford(map<pair<int,int>,int>& edges,int v){

    vector<int> h(v+1,INT_MAX);

    h[v] = 0; //declaring v as the source

    int n = v ;//check

    while(n--){

        for(auto &e : edges){
            int a = e.first.first;
            int b = e.first.second;
            int w = e.second;

            if(h[a]!=INT_MAX and h[a] + w < h[b]){
                h[b] = h[a] + w;
            }
        }
    }


    //checking neg cycle
    for(auto &e : edges){
            int a = e.first.first;
            int b = e.first.second;
            int w = e.second;

            if(h[a]!=INT_MAX and h[a] + w < h[b]){
                
                negCycleExists = true;
                return h;
            }
    }


    return h;

}



vector<int> dijkstra(vector<vector<pair<int,int> > >& graph, int v, int source){
    vector<int> dist(v,INT_MAX);
    vector<bool> vis(v, false);

    set<pair<int,int> >pq;

    dist[source] = 0;
    pq.insert(make_pair(dist[source], source));

    while(pq.empty()==false){

        auto node = pq.begin();
        int vertex = (*node).second;
        pq.erase(node);

        if(vis[vertex]==true) continue;

        vis[vertex] = true;

        for(auto& child_node: graph[vertex]){
            int child = child_node.first;
            int weight = child_node.second;

            if(dist[vertex] + weight < dist[child]){
                dist[child] = dist[vertex] + weight;
                pq.insert(make_pair(dist[child], child));
            }
        }
    }

    return dist;
}


vector<vector<int> > jhonsons_algo(vector<vector<pair<int,int> > >& graph,
            map<pair<int,int>,int>& edges, int v){

    for(int j=0;j<v; j++){
        edges[make_pair(v,j)] = 0; //v is the new vertex
    }

    vector<int> h = bellman_ford(edges,v);

    if(negCycleExists == true){
        cout<<"neg cycle exists.....so no jhonsons algo"<<endl;
        return vector<vector<int> >();
    }


    for(int i=0; i<v; i++){

        for(auto &a: graph[i]){
            int j = a.first;
            int& w = a.second; //check
            w = w + h[i] - h[j];
            //a.second = w;
        }
    }

    vector<vector<int> > ans(v, vector<int>());

    for(int source = 0; source<v; source++ ){
        ans[source] = dijkstra(graph,v,source);
    }


return ans;

}



int main(){
int v,e;

cin>>v>>e;

vector<vector<pair<int,int> > > graph(v+1);

for(int i=0; i<e; i++){
    int x,y,w;
    cin>>x>>y>>w;

    graph[x].push_back(make_pair(y,w));
}

map<pair<int,int>,int> edges = getEdges(graph,v);

vector<vector<int> >ans ;

ans = jhonsons_algo(graph,edges,v);


for(int i=0; i<ans.size()-1; i++){

    for(int j=0; j<ans[i].size()-1; j++){

        if(ans[i][j]!=INT_MAX)cout<<ans[i][j]<<"   ";
        else cout<<"INF ";

    }

    cout<<endl;
}


return 0;
}