#include <bits/stdc++.h>
using namespace std;
vector<long long int>edges[100];
vector<long long int>result;
long long int visited[1000],c=0;


long long int dfs(long long int s)
{
    long long int x,y,z;

        //cout<<s<<endl;


         if(visited[s]==0)
         {
            visited[s]=1;
            for(x=0;x<edges[s].size();x++)
            {
                  //cout<<edges[s].size()<<endl;
                  //cout<<edges[s][x]<<endl;

                    z=edges[s][x];
                    if(visited[z]==0)
                    {
                        result.push_back(z);
                        dfs(z);

                    }

                    //cout<<z<<endl;



            }
         }




}



int main()
{
    long long int i,j,k,l,u,v,n,e;
    cin>>n>>e;
    for(i=1;i<=e;i++)
    {
        cin>>u>>v;
        if(i==1)
        {
            l=u;
        }
        edges[u].push_back(v);
        edges[v].push_back(u);

    }
    memset(visited,0, sizeof visited);
    result.push_back(l);

    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
            c++;
        }
    }


    for(k=0;k<result.size();k++)
    {
        cout<<result[k]<<" ";
    }
    cout<<endl;
    cout<<"Connected Components="<<c<<endl;


    return 0;
}
