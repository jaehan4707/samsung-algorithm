#include <iostream>
#include <cmath>
using namespace std;


long long funct(long long n)
{    
    long long k = sqrt(2*n);
    if (k*(k+1) /2== n)
        return k;
    else
        return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    long long n;
    for (int i = 1; i <= t; i++)
    {    
        cin >> n;            
        cout<<"#"<<i<<" "<<funct(n)<<endl; //endl과 '\n'은 차이가 심하다.
    }
    return 0;
}
