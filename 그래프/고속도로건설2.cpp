#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>
using namespace std;
vector<int> x;
vector<int> y;
vector<pair<int, int>> graph[50001];
vector<int> visit;
int t, e, v;
void mst();
int answer = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> v >> e;
        visit.assign(v + 1, 0);
        answer = 0;
        for (int j = 1; j <= v; j++)
        {
            graph[j].clear();
        }
        for (int k = 0; k < e; k++)
        {
            int s, f, w;
            cin >> s >> f >> w;
            graph[s].push_back(make_pair(f, w)); // s -> (f,w);
            graph[f].push_back(make_pair(s, w));
        }
        pq.push(make_pair(0, 1));
        mst();
        cout << "#" << i + 1 << " " << answer << endl;
    }
}
void mst()
{
    while (!pq.empty())
    {
        int start = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (visit[start] == 1)
        {
            continue;
        }
        answer += weight;
        if (visit[start] == 0)
        {
            visit[start] = 1;
            for (int i = 0; i < graph[start].size(); i++)
            {
                if (visit[graph[start][i].first] == 0)
                    pq.push(make_pair(graph[start][i].second, graph[start][i].first)); // 지점과 거리를 넣자.
            }
        }
    }
}