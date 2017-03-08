#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int> >edges[1000];
priority_queue <pair<int,int>,vector <pair<int,int> >,greater<pair<int,int> > >q;
int pr[1000],sp[1000];

int dijkstra(int s, int d)
{
    pair <int,int >t;
    int n1,n2,w,j,k,l;
    memset(sp,10000,sizeof(sp));
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
    long long int v1,v2,v3,e,c,i,j,k,l,s,distance,d;
    cin>>s>>d;
    cin>>e;
    for(i=0;i<e;i++)
    {
        cin>>v1>>v2>>c;
        edges[v1].push_back(make_pair(v2,c));
        edges[v2].push_back(make_pair(v1,c));

    }
    distance = dijkstra(s,d);

    if(distance == -1)
        cout << "There is no link between source and destination\n\n";
    else
    {
        cout << "The distance is " << distance << endl;
    }


    return 0;
}
