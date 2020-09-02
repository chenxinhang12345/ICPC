#include<iostream>
#include <vector>
using namespace std;
void solve(int n){
    int a,b,c;
    int max_iterate = 100;
    vector<int> states;
    vector<int> next;
    vector<vector<int>> students;
    int sleep_n = 0;
    for(int i = 0 ;i < n; i++){
        cin>>a>>b>>c;
        vector<int> abc;
        abc.push_back(a);
        abc.push_back(b);
        abc.push_back(c);
        students.push_back(abc);
        states.push_back(c);
        if (c > a){
            sleep_n++;
        }
    }
    int t = 1;
    bool sleep = sleep_n>n/2;
    if(sleep_n == 0){
        cout<<1;
        return;
    }
    while(t<max_iterate){
        sleep_n = 0;
        for(int i = 0; i < n;i++){
            a = students[i][0];
            b = students[i][1];
            int s = states[i];
            if (s == a){
                if (sleep){
                    s = a+1;
                }else{
                    s = 1;
                }
            }else if(s == a+b){
                s = 1;
            }else{
                s++;
            }
            states[i] = s;
            if (s>a){
                sleep_n++;
            }
            // cout<<s<<" ";
        }
        // cout<<sleep_n<<"sleep n\n";
        if(sleep_n == 0){//no one sleep
            cout<<++t;
            break;
        }
        sleep = sleep_n > n/2;
        t++;
    }
    if(t == max_iterate){
        cout<<-1;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int i = 1;
    while(n!=0){
        cout<<"Case "<<i<<": ";
        solve(n);
        cout<<"\n";
        cin>>n;
        i++;
    }
    return 0;
}
