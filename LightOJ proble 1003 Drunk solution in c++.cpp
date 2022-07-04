#include<bits/stdc++.h>
using namespace std;
map<string,vector<string>>graph;
map<string,int>visit;
bool drunk;
int dfs_cycle(string src)
{
    visit[src]=1;
    for(auto child:graph[src])
    {
        if(visit[child]==0)dfs_cycle(child);
        else if(visit[child]==1)//Cycle found
        {
            drunk=false;//drinking not possible
            return 0;
        }
    }
    visit[src]=2;//marking all source node for one dfs_cycle calling
}
int main()
{
    int t;cin>>t;
   for(int k=1;k<=t;k++)
   {
       int m,f=0;cin>>m;
       graph.clear();
       visit.clear();
       for(int i=1;i<=m;i++)
       {
           string a,b;cin>>a>>b;
           graph[a].push_back(b);
           visit[a]=0;
           visit[b]=0;
       }
       drunk=true;
       printf("Case %d: ",k);
       for(auto src:graph)
       {
           dfs_cycle(src.first);
           if(drunk==false){cout<<"No"<<endl;f=1;break;}
       }
       if(f==0)cout<<"Yes"<<endl;
   }
}
