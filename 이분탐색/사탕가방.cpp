#include <iostream>

using namespace std;

int main()
{
    long long t, n, m, ans, Max = 0;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        cin >> n >> m;
        long long candy[n];
        ans = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> candy[j];
            // 사탕
            Max = max(Max, candy[j]); // Max에는 사탕의 최대값이 들어감.
        }        
        long long  low = 1;
        long long high = Max;        
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            long long sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum = sum + (candy[k] / mid);
            }            
            if (sum >= m) //사탕의 개수가 실제로 담아야 하는 사탕의 수보다 크다면 
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        cout << "#" << i << " " << high << '\n';
    }
}