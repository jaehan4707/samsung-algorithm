/*
실버1 기타리스트
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int t, r, c;
vector<vector<char>> graph;
vector<int> visit;
vector<int> x = {-1, 1, 0, 0};
vector<int> y = {0, 0, -1, 1};
int answer;
void dfs(int row, int col, int result);
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        answer = 1;
        cin >> r >> c;
        graph.assign(r, vector<char>(c, 0));
        visit.assign(26, 0); // 알파벳. A~65
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cin >> graph[j][k];
            }
        }
        dfs(0, 0, answer);
        cout << "#" << i + 1 << " " << answer << "\n";
    }
}
void dfs(int row, int col, int result)
{
    visit[graph[row][col] - 65] = 1;
    answer = max(answer, result);
    for (int i = 0; i < 4; i++)
    {
        int mx = row + x[i];
        int my = col + y[i];
        if (mx < 0 || my < 0 || mx >= r || my >= c)
            continue;
        if (visit[graph[mx][my] - 65] == true)
            continue;
        dfs(mx, my, result + 1);
        visit[graph[mx][my] - 65] = false;
    }
}