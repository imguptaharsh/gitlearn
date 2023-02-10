#include<iostream>
#include<vector>
using namespace std;
class disjointset
{
public:
    vector<int> parent, Rank;

    void disjoint(int n)
    {
        parent.resize(n + 1);
        Rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find_ur_parent(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = find_ur_parent(parent[n]);
    }
    void union_by_Rank(int u, int v)
    {
        int ulti_pnt_of_v = parent[v];
        int ulti_pnt_of_u = parent[u];
        if (Rank[ulti_pnt_of_u] > Rank[ulti_pnt_of_v])
        {
            parent[ulti_pnt_of_v] = ulti_pnt_of_u;
        }
        else if (Rank[ulti_pnt_of_u] < Rank[ulti_pnt_of_v])
        {
            parent[ulti_pnt_of_u] = ulti_pnt_of_v;
        }
        else
        {
            parent[ulti_pnt_of_v] = ulti_pnt_of_u;
            Rank[ulti_pnt_of_u]++;
        }
    }
};
int spanningTree(int V, vector<pair<int,pair<int,int>>>edges)
    {
     sort(edges.begin(),edges.end());
     disjointset ds;
     ds.disjoint(V);
     int mst=0;
         for(auto it:edges){
             int u=it.second.first;
             int v=it.second.second;
             int wt=it.first;
             if(ds.find_ur_parent(u)!=ds.find_ur_parent(v)){
                 ds.union_by_Rank(u,v);
                 mst+=wt;
             }
         }
     return mst;
    }
int main(){
    int V,E;
    cout<<"Number of nodes : ";
    cin>>V;
    cout<<"Number of edges : ";
    cin>>E;
    vector<pair<int,pair<int,int>>>edge;
    cout<<"Enter the edges";
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({w,{u,v}});
    }
    int mst=spanningTree(V,edge);
    cout<<"the sum of weights of the edges of the Minimum Spanning Tree : "<<mst<<endl;
    return 0;
}
