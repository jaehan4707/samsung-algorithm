#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>
using namespace std;
vector<int> x;
vector<int> y;
vector<int> visit;
long long t, n;
double tax;
long double answer = 0;
priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;
void mst();
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
        answer = 0;
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
        pq.push(make_pair(0, 0));
        mst();
        cout << "#" << i + 1 << " " <<(long long)round(answer) << endl;
    }
}
void mst()
{
    while (!pq.empty())
    {
        long double cost = pq.top().first;
        long long start = pq.top().second;
        pq.pop();
        if (visit[start] == 1)
        {
            continue;
        }
        answer += pow(cost,2)*tax;

        if (visit[start] == 0)
        {
            visit[start] = 1;
            for (int i = 0; i < n; i++)
            {
                if (i != start && visit[i] == 0) // i는 현재좌표가 아니고. 그 i는 방문안해야함.
                {
                    long double d = 0;
                    d = sqrt(pow(x[start] - x[i], 2) + pow(y[start] - y[i], 2));                    
                    pq.push(make_pair(d, i));
   
                }
            }
        }
    }
}