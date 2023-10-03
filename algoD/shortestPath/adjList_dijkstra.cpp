//Luv - yt

#include<bits/stdc++.h>
using namespace std;

class heap_node{
public:
    int dist;
    int ind;

    heap_node(){
        dist = 0;
        ind = -1;
    }

    heap_node(int distance, int index){
        this->dist = distance;
        this->ind = index;
    }
};

class priority_queue_using_minheap{
    heap_node* a;
    int capacity;
    int size;


public:
    priority_queue_using_minheap(int capacity){
        this->capacity = capacity;
        a = new heap_node[capacity];
        this->size = 0;
    }

private:

    int left(int x){
        return (2*x + 1);
    }

    int right(int x){
        return (2*x + 2);
    }

    int parent(int x){
        return (x-1)/2;
    }

public:

    void minheapify(int ind){
        int l = left(ind);
        int r = right(ind);

        int lowest = ind;

        if(l<size and a[l].dist<a[lowest].dist){
            lowest = l;
        }
        
        if(r<size and a[r].dist<a[lowest].dist){
            lowest = r;
        }

        if(lowest == ind) return ;
        else {
            swap(a[lowest],a[ind]);
            minheapify(lowest);
        }
    }



    void enque(int dist, int ind){
        a[size] = heap_node(dist,ind);

        size++;

        for(int i=0; i<size; i++)
        minheapify(i);
    }

    heap_node extractMin(){

        if(size==0) return heap_node();

        heap_node temp = a[0];

        swap(a[0],a[size-1]);
        size--;

        minheapify(0);

        return temp;
    }

    bool empty(){
        if(size==0) return true;
        else return false;
    }



};


void dijkstra(vector<vector<pair<int,int> > > & graph, int v){

    vector<int> dist(v,INT_MAX);
    vector<bool> vis(v, false);
    priority_queue_using_minheap pq = priority_queue_using_minheap(v*v + v);

    pq.enque(0,0);
    dist[0] = 0;

    while(pq.empty()==false){
        auto node = pq.extractMin();
        int vertex = node.ind;

        if(vis[vertex]==true) continue;

        vis[vertex] = true;

        for(pair<int,int> edge: graph[vertex]){
            int child = edge.first;
            int wt = edge.second;

            if(dist[vertex] + wt < dist[child]){
                dist[child] = dist[vertex] + wt;
                pq.enque(dist[child], child);
            }

        }
    }


    ////need to check
    int shortest_path = INT_MAX;

    for(int i=0; i<dist.size(); i++){
        //if(dist[i]<shortest_path) shortest_path = dist[i];
        cout<<dist[i]<<endl;
    }

    //cout<<shortest_path<<endl;


//TC - O(V*V*logV) <- check later

}


int main(){

int v=2,e;
cin>>v>>e;

vector<vector<pair<int,int> > > graph(v);

while(e--){
    int x,y,w;

    cin>>x>>y>>w;

    graph[x].push_back({y,w});
    graph[y].push_back({x,w});
}

dijkstra(graph,v); //works for both directed and undirected graph
//does not work with negative weighted edges


return 0;
}