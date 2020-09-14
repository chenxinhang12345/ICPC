#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
void solve(int n, int m)
{
    int a,b;
    map< int, vector<int> > mem;
    for(int i = 0; i < n; i++){
        cin>>a;
        if (mem.find(a)==mem.end()){//no a exist
            vector<int> v;
            mem.insert(pair<int, vector<int> >(a,v));
        }
        mem[a].push_back(i);
    }
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        // cout<<a<<b<<"\n";
        if(mem.find(b)!=mem.end()){//if find
            vector<int> v  = mem[b];
            // cout<<"size"<<v.size()<<"\n";
            if(v.size()<a){//out of bound
                cout<<0<<"\n";
            }else{
                cout<<v[a-1]+1<<"\n";
            }
        }else{
            cout<<0<<"\n";
        }
    }
}
int main(int argc, char const *argv[])
{
    int m,n;
    while(scanf("%i %i\n", &n, &m)!=EOF){
        solve(n,m);
    }
    return 0;
}

