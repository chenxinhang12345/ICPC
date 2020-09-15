#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int highest_ppa;
int G[501][501];
int n;
bool visited[501];
set<int> component;
void dfs(int u){
    for(int i = 1; i<= n; i++ ){
        
        if(G[u][i] == highest_ppa && !visited[i]){
            visited[i] = true;
            visited[u] = true;
            component.insert(u);
            component.insert(i);
            dfs(i);
            
        }
    }
}
void init_G(){
    for(int i = 0; i < 501; i++){
        for(int j = 0; j < 501; j++){
            G[i][j] = -2147483648;
        }
    }
}
void init_visited(){
    memset(visited, false ,sizeof(visited));
}
void solve(int m){
    int u,v,w;
    highest_ppa = -2147483648;
    int ans = 0;
    init_visited();
    init_G();
    component.clear();
    for(int i = 0; i< m; i++){
        cin>>u>>v>>w;
        if(w > G[u][v]){
        G[u][v] = w;
        G[v][u] = w;
        }
        highest_ppa = max(highest_ppa,w);
    }
    // cout<<"max ppa: "<<highest_ppa<<"\n";
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
        dfs(i);
        ans = max(ans, (int)component.size());
        component.clear();
        }
    }
    cout<<ans<<"\n";

}
int main(int argc, char const *argv[])
{
    int m;
    cin>>n>>m;
    while(m != 0 || n != 0){
        solve(m);
        cin>>n>>m;
    }
    return 0;
}
