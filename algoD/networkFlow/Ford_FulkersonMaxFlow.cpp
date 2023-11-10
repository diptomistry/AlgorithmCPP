#include<iostream>
#include<queue>
#define NODE 6
using namespace std;

typedef struct node {
   int val;
   int state; //status(to mark whether a node has been visited or not.)
   int pred; //to keep track of the predecessor or parent node 
}node;

int minimum(int a, int b) {
   return (a<b)?a:b;
}

int resGraph[NODE][NODE];

/* int graph[NODE][NODE] = {
   {0, 16, 13, 0, 0, 0},
   {0, 0, 10, 12, 0, 0},
   {0, 4, 0, 0, 14, 0},
   {0, 0, 9, 0, 0, 20},
   {0, 0, 0, 7, 0, 4},
   {0, 0, 0, 0, 0, 0}
}; */
//adjacency matrix
int graph[NODE][NODE] = {
   {0, 10, 0, 10, 0, 0},
   {0, 0, 4, 2, 8, 0},
   {0, 0, 0, 0, 0, 10},
   {0, 0, 0, 0, 9, 0},
   {0, 0, 6, 0, 0, 10},
   {0, 0, 0, 0, 0, 0}
};
                   
int bfs(node *vert, node start, node sink) {//to find if there's an augmented path between the source and sink
   node u;
   int i, j;
   queue<node> que;

   for(i = 0; i<NODE; i++) {
      vert[i].state = 0;    //not visited
   }

   vert[start.val].state = 1;   //visited
   vert[start.val].pred = -1;   //no parent node
   que.push(start);   //insert starting node

   while(!que.empty()) {
      //delete from queue and print
      u = que.front();
      que.pop();

      for(i = 0; i<NODE; i++) {
         if(resGraph[u.val][i] > 0 && vert[i].state == 0) {
            que.push(vert[i]);
            vert[i].pred = u.val;
            vert[i].state = 1;
         }
      }
   }
   return (vert[sink.val].state == 1);
}

int fordFulkerson(node *vert, node source, node sink) {
   int maxFlow = 0;
   int u, v;

   for(int i = 0; i<NODE; i++) {
      for(int j = 0; j<NODE; j++) {
         resGraph[i][j] = graph[i][j];    //initially residual graph is main graph
      }
   }

   while(bfs(vert, source, sink)) {    //find augmented path using bfs algorithm
      int pathFlow = 999;//as infinity
      for(v = sink.val; v != source.val; v=vert[v].pred) {
         u = vert[v].pred;
         pathFlow = minimum(pathFlow, resGraph[u][v]);
      }

      for(v = sink.val; v != source.val; v=vert[v].pred) {
         u = vert[v].pred;
         resGraph[u][v] -= pathFlow;   //update residual capacity of edges
         resGraph[v][u] += pathFlow;   //update residual capacity of reverse edges
      }

      maxFlow += pathFlow;
   }
   return maxFlow;    //the overall max flow
}

int main() {
   node vertices[NODE];
   node source, sink;

   for(int i = 0; i<NODE; i++) {
      vertices[i].val = i;
   }

   source.val = 0;
   sink.val = 5;
   int maxFlow = fordFulkerson(vertices, source, sink);
   cout << "Maximum flow is: " << maxFlow << endl;
}