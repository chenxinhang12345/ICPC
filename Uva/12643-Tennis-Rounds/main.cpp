#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{

    int i,j,N;
    while(scanf("%d %d %d", &N,&i,&j)!=EOF){
    int counter = 0;
    while((i+1)/2 != (j+1)/2){
        i = (i+1)/2;
        j = (j+1)/2;
        counter++;
    }
    cout<<counter+1<<"\n";
    }
    return 0;
}
