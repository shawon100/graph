#include <bits/stdc++.h>
using namespace std;

int main()
{

    int i,j,n,e,u,v,g[100][100];
    cin>>n>>e;
    for(i=1;i<=e;i++)
    {
        cin>>u>>v;
        g[u][v]=1;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

             cout<<g[i][j]<<" ";
        }

         cout<<endl;

    }
    return 0;
}

