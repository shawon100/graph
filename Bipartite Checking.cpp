#include <bits/stdc++.h>
using namespace std;
vector<int>edges[100];
queue<int>q;
vector<int>item;
int level[100],color[100],visited[100],tn;

int bipartite(int s)
{
    int j,k,fr;
    q.push(s);
    color[s]=1;
    memset(color,-1,sizeof color);
    for(j=0;j<tn;j++)
    {
        visited[j]=0;
    }
    while(!q.empty())
    {
        fr=q.front();
        for(k=0;k<edges[fr].size();k++)
        {
            if(visited[edges[fr][k]]==0 && color[edges[fr][k]]==-1)
            {
                 q.push(edges[fr][k]);
                 visited[edges[fr][k]]=1;
                 color[edges[fr][k]]=1-color[fr];

            }


        }
        for(k=0;k<edges[fr].size();k++)
        {
            if(color[edges[fr][k]]==color[fr])
            {
                return false;

            }

        }

        q.pop();
    }
    return true;
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
    }
    cout<<endl;
    if(bipartite(0))
    {
        cout<<"Input Graph Is Bipartite"<<endl;
    }
    else
    {
        cout<<"Input Graph Is Not Bipartite"<<endl;
    }

    return 0;
}
