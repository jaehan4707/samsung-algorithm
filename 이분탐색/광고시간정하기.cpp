#include <iostream>
using namespace std;

int interval[100001];
int start[100000], finish[100000];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int l, n;
        cin >> l >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> start[j] >> finish[j];
            interval[j + 1] = interval[j] + (finish[j] - start[j]);
        }
        int s = 0, ans = 0;
        for (int k = 0; k< n; k++)
        {
            for (; s <= k && start[s] + l <= finish[k]; s++)
            {
                int len = start[s] + l - start[k];
                if (len > 0)
                    ans = max(ans, interval[k] - interval[s] + len);
                else
                    ans = max(ans, interval[k] - interval[s]);
            }
        }
        if (s < n)
            ans = max(ans, interval[n] - interval[s]);
        cout << '#' << i << ' ' << ans << '\n';
    }
    return 0;
}