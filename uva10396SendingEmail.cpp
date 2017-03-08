#include <bits/stdc++.h>
using namespace std;
#define p pair<long long int,long long int>
vector < p >edges[50005];
priority_queue <p,vector <p>,greater<p> >q;
long long int sp[50005],visited[50005];
int pr[50005];

long long int dijkstra(long long int s, long long int d)
{
    pair <int,int >t;
    long long int n1,n2,w,j,k,l;
    for(l=0;l<50005;l++)
    {
        sp[l]=999999999;
    }
    sp[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        t=q.top();
        n1=t.second;
        q.pop();
        //cout<<"n1"<<n1<<endl;
        if(n1==d)
        {
            return sp[n1];
        }
        for(j=0;j<edges[n1].size();j++)
        {
            n2=edges[n1][j].first;
            w=edges[n1][j].second;

            if(sp[n1]+w<sp[n2])
            {
                sp[n2]=sp[n1]+w;
                pr[n2]=n1;

                q.push(make_pair(sp[n2],n2));
            }
        }



    }

   return -1;

}
int main()
{
    long long int v1,v2,v3,e,c,s,i,length,d,n,m,tc,x;
    //freopen("10986in.txt","r",stdin);
    //freopen("10986.txt","w",stdout);
    cin>>tc;
    for(x=1;x<=tc;x++)
    {

        cin>>n>>e>>s>>d;
        for(i=0;i<e;i++)
        {
            cin>>v1>>v2>>c;
            edges[v1].push_back(make_pair(v2,c));
            edges[v2].push_back(make_pair(v1,c));

        }
        length = dijkstra(s,d);
        if(e==0)
        {
            cout <<"Case #"<<x<<": "<<"unreachable"<<endl;
        }
        else if(length==-1)
        {
            cout <<"Case #"<<x<<": "<<"unreachable"<<endl;
        }
        else
        {
            cout <<"Case #"<<x<<": "<<length<<endl;
        }
        memset(edges,0,sizeof edges);
        while(!q.empty())
        {
           q.pop();
        }
    }


    return 0;
}

