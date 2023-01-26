#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int t, n;
vector<vector<char>> graph;
vector<vector<int>> map;
queue<pair<int, int>> q;
vector<pair<int, int>> p;
vector<int> x = {1, 1, 1, -1, -1, -1, 0, 0};
vector<int> y = {1, 0, -1, 1, 0, -1, 1, -1};
int answer = 0;
void funct(int index);
bool detect_bomb(int row, int col);
int main()
{
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        graph.assign(n, vector<char>(n, 0));
        map.assign(n, vector<int>(n, 0));
        p.clear();
        answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == '.')
                {
                    p.push_back(make_pair(i, j));
                }
            }
        }
        for (int j = 0; j < p.size(); j++)
        {
            funct(j);
        }
        for (int j = 0; j < p.size(); j++)
        {
            if (map[p[j].first][p[j].second] == 0 && graph[p[j].first][p[j].second] == '.')
            {
                // 아직 방문안했고, 지뢰가 없는 구역이라면
                answer++;
            }
        }
        cout << "#" << k + 1 << " " << answer << endl;
    }
}
void funct(int index)
{    
    if (map[p[index].first][p[index].second] == 0 && detect_bomb(p[index].first, p[index].second)) 
    {   //만약 방문을 안했고,  주변에 폭탄이 없다면
        answer++; //클릭수 증가시켜줌
        q.push(p[index]); //큐에 그대로 넣고
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;            
            map[row][col] = 1;
            q.pop();            
            for (int i = 0; i < 8; i++) //8방향 탐색하기
            {
                int trow = row + x[i];
                int tcol = col + y[i];

                if (trow < 0 || trow >= n || tcol < 0 || tcol >= n)
                {
                    continue;
                }
                if (graph[trow][tcol] == '.' && map[trow][tcol] == 0) // 지뢰가 아닌 지역이고 아직 방문하지 않았다면.
                {
                    map[trow][tcol] = 1; // 방문처리를 해준다. 
                    if (detect_bomb(trow, tcol) == 1) //그 지역 8군대에서 만약 폭탄이 없다면 큐에 넣어준다.
                    {                        
                        q.push(make_pair(trow, tcol));
                    }
                }
            }
        }
    }
}
bool detect_bomb(int row, int col) //폭탄을 탐지하는 함수.
{

    for (int i = 0; i < 8; i++)
    {
        int R = row + x[i];
        int C = col + y[i];
        if (R < 0 || R >= n || C < 0 || C >= n)
        {
            continue;
        }
        if (graph[R][C] == '*')
        { // 지뢰라면
            return false;
        }
    }    
    return true;
}