#include<bits/stdc++.h>
using namespace std;

vector<int> dsuf;
//FIND root
int find(int v)
{
	if(dsuf[v]==-1)
		return v;
	return find(dsuf[v]);
}

void union_op(int fromP,int toP)
{
	fromP = find(fromP);
	toP = find(toP);
	dsuf[fromP] = toP;//fromp point to toP
}

bool isCyclic(vector<pair<int, int> >& edge_List)
{
    for (int i = 0; i < edge_List.size(); ++i)//edge_List=pair=(from,to)
    {
        int fromP = find(edge_List[i].first);//FIND absolute parent of subset
        int toP = find(edge_List[i].second);

        if (fromP == toP)//in the same set
            return true;
        
        union_op(fromP, toP);//UNION of 2 sets
    }
    return false;
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	dsuf.resize(V,-1);//parent	//Mark all vertices as separate subsets with only 1 element
	vector<pair<int,int> > edge_List;	//Adjacency list(x,y)=(from,to)
	for(int i=0;i<E;++i)
	{
		int from,to;
		cin>>from>>to;
		edge_List.push_back(make_pair(from,to));
	}

	if(isCyclic(edge_List))
		cout<<"TRUE\n";
	else
		cout<<"FALSE\n";
	
	return 0;
}

//TIME COMPLEXITY: O(E.V)