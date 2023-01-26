#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
vector<int> x;
vector<int> y;
vector<int> visit;
int t, n;
double tax;
queue<pair<int, long long>> q;
void funct();
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        x.assign(n, 0);
        y.assign(n, 0);
        visit.assign(n, 0);
        tax = 0.0;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (j == 0)
                {
                    cin >> x[k];
                }
                else
                    cin >> y[k];
            }
        }
        cin >> tax;        
        q.push(make_pair(0, 0));
        funct();
    }
}
void funct()
{
    while (!q.empty())
    {
        int num = q.front().first;
        long long dis = q.front().second;
        if (visit[num] == 1)
        {
            q.pop();
            continue;
        }
        visit[num] = 1;
        q.pop();
        for (int i = 0; i < n; i++)
        {
            long long d = 0;
            if (i != num)
            {
                d = dis + sqrt(pow(x[num] - x[i], 2) + pow(y[num] - y[i], 2));
                cout << x[num] << " " << y[num] << " " << x[i] << " " << y[i] << " " << d << endl;
                q.push(make_pair(i, d));
            }
        }
    }
}