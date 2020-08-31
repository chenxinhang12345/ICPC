#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<int> vi;
void p(vi a){
    for(int i = 0; i < a.size();i++){
        if(i < a.size()-1)
            cout<<a[i]<<" ";
        else{
            cout<<a[i];
        }
    }
}
void solve(){
    vi a,b,c;
    vi as,bs,cs;
    int n,m,k;
    int temp;
    cin>>n;
    for(int i = 0; i < n;i++){
        cin>>temp;
        // cout<<temp<<"\n";
        a.push_back(temp);
    }
    cin>>m;
    for(int i = 0; i < m;i++){
        cin>>temp;
        // cout<<temp<<"\n";
        b.push_back(temp);
    }
    cin>>k;
    for(int i = 0; i < k;i++){
        cin>>temp;
        // cout<<temp<<"\n";
        c.push_back(temp);
    }
    int ac = 0;
    int bc = 0;
    int cc = 0;
    for(int i = 0; i < n; i++){
        if (find(b.begin(),b.end(),a[i])==b.end()&&find(c.begin(),c.end(),a[i])==c.end()&&find(as.begin(),as.end(),a[i])==as.end()){
            ac+=1;
            as.push_back(a[i]);
        }
    }
    for(int i = 0; i < m; i++){
        if (find(a.begin(),a.end(),b[i])==a.end()&&find(c.begin(),c.end(),b[i])==c.end()&&find(bs.begin(),bs.end(),b[i])==bs.end()){
            bc+=1;
            bs.push_back(b[i]);
        }
    }
    for(int i = 0; i < k; i++){
        if (find(a.begin(),a.end(),c[i])==a.end()&&find(b.begin(),b.end(),c[i])==b.end()&&find(cs.begin(),cs.end(),c[i])==cs.end()){
            cc+=1;
            cs.push_back(c[i]);
        }
    }
    int max_p = max(ac,max(bc,cc));
    n = ac;
    m = bc;
    k = cc;
    
    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());
    sort(cs.begin(),cs.end());
    if(max_p == ac && max_p != bc && max_p != cc){
        cout<<1<<" ";
        cout<<n<<" ";
        p(as);
    }else if (max_p == bc && max_p != ac && max_p != cc){
             cout<<2<<" ";
        cout<<m<<" ";
        p(bs);
    }else if(max_p == cc && max_p != bc && max_p != ac){
             cout<<3<<" ";
        cout<<k<<" ";
        p(cs);
    }else if(max_p == ac && max_p == bc && max_p == cc){
        string space = " ";
        if (ac == 0){
            space = "";
        }
        cout<<1<<" ";
        cout<<n<<space;
        p(as);
        cout<<"\n";
        cout<<2<<" ";
        cout<<m<<space;
        p(bs);
        cout<<"\n";
         cout<<3<<" ";
        cout<<k<<space;
        p(cs);
        
    }else if(max_p == ac && max_p == bc){
        cout<<1<<" ";
        cout<<n<<" ";
        p(as);
        cout<<"\n";
        cout<<2<<" ";
        cout<<m<<" ";
        p(bs);
    }else if(max_p == ac && max_p == cc){
        cout<<1<<" ";
        cout<<n<<" ";
        p(as);
        cout<<"\n";
         cout<<3<<" ";
        cout<<k<<" ";
        p(cs);
        
    }else{
        cout<<2<<" ";
        cout<<m<<" ";
        p(bs);
        cout<<"\n";
         cout<<3<<" ";
        cout<<k<<" ";
       p(cs);
    }
    

}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cout<<"Case #"<<i<<":\n";
        solve();
        cout<<"\n";
    }
    return 0;
}
