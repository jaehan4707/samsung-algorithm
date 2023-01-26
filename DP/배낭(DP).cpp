#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
using namespace std;
int t, n, k;
vector<vector<int>>dp;
vector<int> V;
vector<int> C;
void funct(int b, int c);
void bag_sort();
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        V.assign(n + 1, 0);
        C.assign(n + 1, 0);        
        dp.assign(n+1,vector<int>(k+1,0));
        for (int j = 1; j <= n; j++)
        {
            int v, c;
            cin >> v >> c; // v가 부피 c가 가치
            V[j] = v;
            C[j] = c;
        }
        bag_sort(); //단위부피가 큰 순서대로 정렬햇다.
        //가방은 1번~n번까지 잇음. //1번을 담냐 안담냐.      
        for(int i=1; i<=n;i++){
            for(int j=1; j<=k; j++){
                if(j-V[i]>=0){ //담을수 있는 무게보다 가방의 무게보다 가볍다면
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-V[i]]+C[i]);
                }
            }
        }  
        cout<<"#"<<i+1<<" "<<dp[n][k]<<endl;
    }
}
void bag_sort()
{ // 무게당 부피가 큰 순서대로 정렬을 하고싶음.
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            
            double a= C[i]/V[i];
            double b= C[j]/V[j];                          
            if (a< b)
            {
                swap(C[i], C[j]);
                swap(V[i], V[j]);
            }
        }
    }
}