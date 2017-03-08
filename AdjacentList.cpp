#include <bits/stdc++.h>
using namespace std;
vector<int>edges[1000];
vector<int>cost[1000];
vector<int>outdegree;
vector<int>indegree[100];
vector<int>indeg;
int main()
{
    int i,j,n,e,u,v,k,c,l,m;
    cin>>n>>e;
    for(i=1;i<=e;i++)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        indegree[v].push_back(u);                           //1st u index then vector index ex: edges[1][0]=2, edges[1][1]=4
        cost[u].push_back(1);

    }
    cout<<endl;
    cout<<"Outdegree"<<endl;
    cout<<"......................................."<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<i<<"==>>";
         for(j=0;j<edges[i].size();j++)
         {
             cout<<edges[i][j]<<" ";
         }
         cout<<endl;
         outdegree.push_back(edges[i].size());

    }
    cout<<endl;
    cout<<"Indegree"<<endl;
    cout<<"......................................."<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<i<<"==>>";
         for(j=0;j<indegree[i].size();j++)
         {
             cout<<indegree[i][j]<<" ";
         }
         cout<<endl;
         indeg.push_back(indegree[i].size());

    }
    cout<<endl;
    cout<<"Count Of Outdegree Or Total Adjacent Nodes"<<endl;
    cout<<"......................................."<<endl;
    for(k=0;k<outdegree.size();k++)
    {
        cout<<"Outdegree Of "<<k+1<<"="<<outdegree[k]<<endl;
    }
    cout<<endl;
    cout<<"Count Of Indegree"<<endl;
    cout<<"......................................."<<endl;
    for(k=0;k<indeg.size();k++)
    {
        cout<<"indegree Of "<<k+1<<"="<<indeg[k]<<endl;
    }

    return 0;
}
