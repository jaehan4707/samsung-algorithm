#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int t, n;
vector<vector<int>> graph;
vector<vector<int>> visit;
vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
int max_core;
int answer;
int tt = 0;
void make_core(vector<pair<int,int>>&p,vector<pair<int, int>> &temp, int index, int depth);
void funct(vector<pair<int, int>> &temp, int count, int depth, int length);
vector<pair<int, int>> result[10001];
int main()
{
    cin >> t;
    for (int A = 0; A < t; A++)
    {
        cin >> n;
        graph.assign(n, vector<int>(n, 0));
        visit.assign(n, vector<int>(n, 0));
        vector<pair<int, int>> p;
        vector<pair<int, int>> test;
        vector<pair<int, int>> temp;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> graph[j][k];
                if (j == 0 || j == n - 1 || k == n - 1 || k == 0)
                {
                    continue;
                }
                if (graph[j][k] == 1)
                {
                    p.push_back(make_pair(j, k));
                }
            }
        }
        max_core = 0;
        max_core = p.size();
        answer = INT_MAX;
        for (int i = max_core; i > 0; i--) // 여기서 갯수를 정해줌. max_core는
        {
            // 경우의 수를 짜개줘야하는디..
            bool flag = true;
            tt = 0;
            visit.assign(n, vector<int>(n, 0)); //  방문초기화
            test.assign(i, make_pair(0, 0));    // test초기화
            temp.assign(i, make_pair(0, 0));
            make_core(p,test, 0, 0);
            for (int v = 0; v < tt; v++)
            {
                for (int b = 0; b < result[v].size(); b++)
                {
                    temp[b] = result[v][b];
                }
                funct(temp, i, 0, 0);
                if (answer != INT_MAX)
                {
                    cout << "#" << A + 1 << " " << answer << endl;
                    flag = false;
                    break;
                }
            }
            for (int i = 0; i < tt; i++)
            {
                result[i].clear();
            }
            if (flag == false)
            {
                break;
            }
        }
    }
}
void make_core(vector<pair<int,int>>&p,vector<pair<int, int>> &temp, int index, int depth)
{
    if (depth == temp.size())
    {
        for (int i = 0; i < temp.size(); i++)
        {
            result[tt].push_back(temp[i]);
        }
        tt++;
        return;
    }
    else
    {
        for (int i = index; i < p.size(); i++)
        {
            temp[depth] = p[i];
            make_core(p,temp, i + 1, depth + 1);
        }
    }
}
void funct(vector<pair<int, int>> &result, int count, int depth, int length)
{
    for (int i = 0; i < x.size(); i++)
    { // 방향 크기만큼 일단 돌려줍니다.
        int row = result[depth].first;
        int col = result[depth].second;
        int step = 0;
        while (1)
        {
            step++;
            row += x[i];
            col += y[i];
            if (graph[row][col] == 1 || visit[row][col] == -1)
            {
                break;
            }
            if (row == 0 || row == n - 1 || col == 0 || col == n - 1)
            { // 제대로 도착한경우
            
                length += step;
                if (depth == count - 1)
                {
                    answer = min(answer, length);
                    length -= step;
                    break;
                }
                int R = result[depth].first;
                int C = result[depth].second;
                for (int j = 0; j < step; j++)
                {
                    R += x[i];
                    C += y[i];
                    visit[R][C] = -1; // 선
                }
                funct(result, count, depth + 1, length); // 다음거 확인.
                R = result[depth].first;
                C = result[depth].second;
                for (int j = 0; j < step; j++)
                {

                    R += x[i];
                    C += y[i];
                    visit[R][C] = 0; // 선이 없는건 0
                }
                length -= step;
                break;
            }
        }
    }
}