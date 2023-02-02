#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<int, pair<int, int>> m;
vector<pair<int, int>> p[6];
int t, M, N;
void init();
void hire(int mID, int mTeam, int mScore);
void fire(int mID);
void updateTeam(int mTeam, int mChangeScore);
void updateSoldier(int mID, int mScore);
int bestSoldier(int mTeam);
vector<pair<int, int>> ary[6];
vector<pair<int, int>> location[100001];
int main()
{
    cin >> t >> M;
    for (int i = 0; i < t; i++)
    {
        cin >> N;
        bool flag = true;
        for (int i = 0; i < N; i++)
        {
            int op, a, b, c;
            cin >> op;
            if (op == 1)
            {
                init();
            }
            if (op == 2)
            {
                cin >> a >> b >> c;
                hire(a, b, c);
            }
            if (op == 6)
            { // best
                cin >> a >> b;
                if (b != bestSoldier(a))
                {
                    flag = false;
                }
            }
            if (op == 3)
            { // fire
                cin >> a;
                fire(a);
            }
            if (op == 4)
            { // updateso
                cin >> a >> b;
                updateSoldier(a, b); // a인 병사를 b로 점수 바꾸기
            }
            if (op == 5)
            { // updateteam
                cin >> a >> b;
                updateTeam(a, b);
            }
        }
        if (flag == true)
        {
            cout << "#" << i + 1 << " 정답입니다" << endl;
        }
        else
        {
            cout << "#" << i + 1 << " 오답입니다" << endl;
        }
    }
}
void init()
{
    // m.clear(); // map 초기화.
    for (int i = 1; i <= 5; i++)
    {
        p[i].clear();
    }
    for (int i = 1; i <= 100001; i++)
    {
        location[i].clear();
    }
}

void hire(int mID, int mTeam, int mScore)
{
    // team정보를 가져온다?
    p[mTeam].push_back(make_pair(mID, mScore));
    location[mID].push_back(make_pair(mTeam, p[mTeam].size() - 1));
}

void fire(int mID)
{
    // m.erase(mID);
    int index = location[mID][0].second;    // 위치
    int team = location[mID][0].first;      // team
    p[team].erase(p[team].begin() + index); // 그 팀에 해당하는 위치를 지워본다.
    // index가 작은거는 안건드려도됨.
    for (int i = index; i < p[team].size(); i++)
    {
        // p[team][i].second -= 1;
        location[p[team][i].first][0].second -= 1;
    }
    // remove하면 다른애들도 한칸씩 땡겨줘야함.
    // p[team].erase(remove(p[team].begin(), p[team].end(),mID), p[team].end());
}

void updateSoldier(int mID, int mScore)
{
    int index = location[mID][0].second;
    int team = location[mID][0].first;
    p[team][index].second = mScore;
    // m[mID].second = mScore;
}

void updateTeam(int mTeam, int mChangeScore)
{
    for (int i = 0; i < p[mTeam].size(); i++)
    {
        if (p[mTeam][i].second + mChangeScore > 5)
        {
            p[mTeam][i].second = 5;
        }
        else if (p[mTeam][i].second + mChangeScore < 1)
        {
            p[mTeam][i].second = 1;
        }
        else
        {
            p[mTeam][i].second += mChangeScore;
        }
    }
}

int bestSoldier(int mTeam)
{
    int id = 0, score = 0;
    for (int i = 0; i < p[mTeam].size(); i++)
    {
        if (score < p[mTeam][i].second)
        {
            score = p[mTeam][i].second;
            id = p[mTeam][i].first;
        }
        else if (score == p[mTeam][i].second)
        {
            id = max(id, p[mTeam][i].first);
        }
    }
    return id;
}