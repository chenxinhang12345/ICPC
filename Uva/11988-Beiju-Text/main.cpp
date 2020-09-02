#include<iostream>
#include <list>
#include <string>
using namespace std;
void solve(string in){
    // cout<<in<<"\n";
    list<char> l;
    list<char>::iterator it = l.end();
    for(int i = 0; i < in.length();i++){
        if(in[i]=='['){
            it = l.begin();
        }else if(in[i]==']'){
            it = l.end();
        }else{
            l.insert(it,in[i]);
        }
    }
    for(it = l.begin(); it != l.end();it++){
        cout<<*it;
    }
    cout<<"\n";
    
}
int main(int argc, char const *argv[])
{
    string in;
    while(getline(cin,in)){
        solve(in);
    }
    return 0;
}
