#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int t, n, m, c1, c2;
int c[5000001];
int h;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m >> c1 >> c2;

        for (int j = 0; j < n; j++)
            cin >> c[j];
        sort(c, c + n);
        int Min = INT_MAX;
        int cnt = 0;
        int distance = 0;
        for (int k = 0; k < m; k++)
        {
            cin >> h;
            auto location = lower_bound(c, c + n - 1, h) - c;

            distance = abs(c[location] - h);
            if (distance < Min)
            {
                Min = distance;
                cnt = 1;
            }
            else if (distance == Min)
                cnt++;

            if (location > 0)
            {
                distance = abs(c[location - 1] - h);
                if (distance < Min)
                {
                    Min = distance;
                    cnt = 1;
                }
                else if (distance == Min)
                    cnt++;
            }
        }
        cout << "#" << i << " " << abs(c1 - c2) + Min << " " << cnt << '\n';
    }
    return 0;
}