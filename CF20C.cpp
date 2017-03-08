#include <bits/stdc++.h>
using namespace std;
#define p pair<long long int,long long int>
vector < p >edges[100005];
priority_queue <p,vector <p>,greater<p> >q;
long long int sp[100005],visited[100005];
vector<long long int>vec;
int pr[100005];

long long int dijkstra(long long int s, long long int d)
{
    pair <long long int,long long int >t;
    long long int n1,n2,w,j,k,l;
    for(l=0;l<100005;l++)
    {
        sp[l]=99999999999;
    }
    pr[1]=-1;
    sp[s]=0;
    k=0;
    q.push(make_pair(0,s));
    //cout<<s<<" ";
    visited[1]=1;
    vec.push_back(1);
    while(!q.empty())
    {
        t=q.top();
        n1=t.second;
        q.pop();

        if(n1==d)
        {
            return sp[n1];
        }
        //cout<<"n1"<<n1<<endl
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
    long long int v1,v2,v3,e,c,i,s,length,d,n,vertex,x;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>v1>>v2>>c;
        edges[v1].push_back(make_pair(v2,c));
        edges[v2].push_back(make_pair(v1,c));

    }
    length= dijkstra(1,n);

    if(length==-1)
    {
        cout << "-1"<<endl;
    }
    else
    {
       vertex=n,x=1;
       while(vertex!=-1)
       {
           vec.push_back(vertex);
           //cout<<vertex<<endl;
           vertex=pr[vertex];
           x++;

       }
       for(i=vec.size()-1;i>0;i--)
       {
           cout<<vec[i]<<" ";
       }
       cout<<endl;
    }
    vec.clear();



    return 0;
}


