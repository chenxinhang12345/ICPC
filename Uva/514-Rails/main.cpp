#include <iostream>
#include <stack>
using namespace std;
int n;
int a;
int arr[1005];
/**
 * push into stack 1,2,3,...,N
 * pop out a_N, a_(N-1),...,a_1
 **/
stack<int> s;
void solve(){
    stack<int> empty_stack;
    cin>>a;
    while(a){
        // cout<<a<<"\n";
        // cout<<"n:"<<n<<"\n";
        arr[1] = a;
        for(int i = 2; i<= n;i++){
            cin>>arr[i];
        }
        int i = 1;
        int j = 1;
        for(;i<=n;i++){
            s.push(i);
            while(!s.empty() && arr[j]==s.top()){
                j++;
                s.pop();
            }
        }
        
        if(j==n+1){
            cout<<"Yes\n";
        }else{ 
            // cout<<"s final top:"<<s.top()<<"\n";
            cout<<"No\n";
        }
       s.swap(empty_stack);
       cin>>a; 
    }
    cout<<'\n';
}
int main(int argc, char const *argv[])
{
    cin>>n;
    while(n){
        solve();
        cin>>n;
    }
    return 0;
}
