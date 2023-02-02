#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
unordered_map<int, pair<int, int>> m;
int t, M, N;
void init();
void hire(int mID, int mTeam, int mScore);
void fire(int mID);
void updateTeam(int mTeam, int mChangeScore);
void updateSoldier(int mID, int mScore);
int bestSoldier(int mTeam);
vector<pair<int, int>> ary[6];
int main()
{
    cin >> t >> M;
    for (int i = 0; i < t; i++)
    {
        cin >> N;
        cout<<"#"<<i+1<<" "<<N<<endl;
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
    m.clear(); // map 초기화.
}

void hire(int mID, int mTeam, int mScore)
{
    m.insert(make_pair(mID, make_pair(mTeam, mScore))); //mID위치 바로 뒤의 넣을까

}

void fire(int mID)
{
    m.erase(mID);
}

void updateSoldier(int mID, int mScore)
{
    m[mID].second = mScore;
}

void updateTeam(int mTeam, int mChangeScore)
{
    for (auto iter = m.begin(); iter != m.end(); iter++) //시간을 여기서 줄여야하나.
    {
        if (iter->second.first == mTeam)
        {
            if (iter->second.second + mChangeScore > 5)
            {
                iter->second.second = 5;
            }
            else if (iter->second.second + mChangeScore < 1)
            { // 5보다 작을 경우
                iter->second.second = 1;
            }
            else
            {
                iter->second.second += mChangeScore;
            }
        }
    }
}

int bestSoldier(int mTeam)
{
    int id = 0, score = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second.first == mTeam)
        {
            if (score < iter->second.second) // 점수
            {
                score = iter->second.second;
                id = iter->first;
            }
            else if (score == iter->second.second)
            { // 점수가 같을 경우 그그그그ㅡ극 고유번호 큰거
                id = max(id,iter->first);
            }
        }
    }
    return id;
}
