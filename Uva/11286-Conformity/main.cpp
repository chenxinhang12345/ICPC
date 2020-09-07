#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
void solve(int n){
    map<vector<int>,int> m;
    for(int i = 0; i < n; i++){
        vector<int> courses;
        for(int j = 0; j < 5; j ++){
            int a;
            cin>>a;
            courses.push_back(a);
        }
        sort(courses.begin(),courses.end());
        if(m.find(courses)!=m.end()){
            m[courses]+=1;
        }else{
            m.insert(pair<vector<int>,int>(courses,1));
        }
    }
    int max_c = 0;
    int ans = 0;
    map<vector<int>,int>::iterator it;
    for(it = m.begin();it!=m.end();it++){
        if (it->second >max_c){
            max_c = it->second;
        }
    }
    for(it = m.begin();it!=m.end();it++){
        if (it->second ==max_c){
            ans+=max_c;
        }
    }
    cout<<ans<<"\n";
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    // solve(n);
    // cin>>n;
    // solve(n);
    // cin>>n;
    // solve(n);
    while(n){
        solve(n);
        cin>>n;
    }
    return 0;
}

