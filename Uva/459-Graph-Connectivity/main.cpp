#include <iostream>
#include <string>
#include <set>
using namespace std;
int fa[26];
int n;
int k;
set<int> component;
void init(){
    k = 0;
    component.clear();
    for(int i = 0; i < 26;i++){
        fa[i] = i;
    }
}
int find(int x){
    if(fa[x]!= x){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void union_sets( int x, int y){
    x = find(x);
    y = find(y);
    if(x == y){
        return;
    }else{
        fa[x] = y;
    }

}
void solve(){
    init();
    string s;
    while(s.empty()){
        getline(cin,s);
    }
    k = s[0]-65;
    while(!s.empty()){
        // cout<<s<<"\n";
        // cout<<(int)(s[0])-65<<(int)s[1]-65<<"\n";
        if(s.size()==2){
            // cout<<(int)(s[0])-65<<" "<<(int)s[1]-65<<"\n";
            union_sets((int)s[0]-65,(int)s[1]-65);
            // for(int i = 0; i<= k; i++){
            //     cout<<fa[i]<<" ";
            // }
            // cout<<"\n";
        }else{
            // letters.insert((int)s[0]-65);
        }
        if(!getline(cin, s))
            break;
    }
    // set<int>::iterator it;
    // for( it = letters.begin();it!= letters.end();it++){
    //     component.insert(find(*it));
    // }
    for(int i = 0; i<=k; i++){
        component.insert(find(fa[i]));
    }
    cout<<component.size()<<"\n";
}
int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i = 0; i< n; i++){
        // cout<<"n:"<<n<<"\n";
        solve();
        if(i<n-1){
            cout<<"\n";
        }
    }
    return 0;
}
