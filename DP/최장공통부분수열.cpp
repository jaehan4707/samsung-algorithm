#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
using namespace std;
int t;
string s1, s2;
vector<vector<int>> dp;
void funct();
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s1 >> s2;        
        dp.assign(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        funct();
        cout << "#"<<i+1<<" "<<dp[s1.size()][s2.size()]<<endl;               
        
    }
}
void funct()
{
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {            
            if (s1[i-1] == s2[j-1])
            {                                       
                dp[i][j] = dp[i - 1][j - 1] + 1;                
            }
            else
            {              
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}
