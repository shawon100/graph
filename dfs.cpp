#include <bits/stdc++.h>
using namespace std;
vector<int>edges[100];
stack<int>q;
vector<int>item;
int level[100],parent[100],visited[100],tn,v[100];

void dfs(int s)
{
    int j, k, fr;
    q.push(s);
    level[s] = 0;
    for (j = 1; j <= tn; j++)
    {
        visited[j] = 0;
    }
    for (j = 1; j <= tn; j++)
    {
        v[j] = 0;
    }
    v[s]=1;
    while (!q.empty())
    {
        fr = q.top();
        q.pop();
        if (0 == visited[fr])
        {
            visited[fr] = 1;
            item.push_back(fr);
            for (k = 0; k <edges[fr].size(); k++)
            {
                q.push(edges[fr][k]);

            }
        }
        for(k=0;k<edges[fr].size();k++)
        {
            if(v[edges[fr][k]]==0)
            {

                 level[edges[fr][k]]=level[fr]+1;
                 parent[edges[fr][k]]=fr;
                 v[edges[fr][k]]=1;
            }


        }
    }
}

int main()
{
    int i,e,p,n,u,v,f,m;
    cout<<"Enter Total Nodes And Edges="<<endl;
    cin>>tn>>e;
    for(i=1;i<=e;i++)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout<<"Enter 1st node"<<endl;
    cin>>f;
    dfs(f);
    cout<<"Sequence="<<endl;
    for(m=0;m<item.size();m++)
    {
        cout<<item[m]<<" ";
    }
    cout<<endl;
    cout<<"Enter Node to know shortest path"<<endl;
    cin>>n;
    cout<<"Shortest Path is="<<level[n]<<endl;
    cout<<"Enter Node To Know its Parent"<<endl;
    cin>>p;
    cout<<"Parent is="<<parent[p]<<endl;
    return 0;
}


