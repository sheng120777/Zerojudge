#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inf 1e15
#define maxn 100005

vector<pair<int,int>>graph[maxn];
int dis[maxn];
bool visited[maxn]={false};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    while(cin>>n>>m){

        //init
        memset(dis,0x3f,sizeof(dis));
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            graph[i].clear();
        }
        dis[0]=0;

        //build graph
        for(int i=0;i<m;i++){
            int a,b,w;
            cin>>a>>b>>w;
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }

        //prim
        pq.push({0,0});
        while(!pq.empty()){
            auto now=pq.top();
            pq.pop();
            int v=now.second;
            if(visited[v]){
                continue;
            }
            visited[v]=true;
            for(auto next:graph[v]){
                int u=next.first;
                int k=next.second;
                if(visited[u]){
                    continue;
                }
                if(dis[u]>k){
                    dis[u]=k;
                    pq.push({dis[u],u});
                }
            }
        }
        int cnt=0;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(dis[i]>inf){
                flag=false;
            }
            else{
                cnt+=dis[i];
            }
        }
        if(flag){
            cout<<cnt<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
