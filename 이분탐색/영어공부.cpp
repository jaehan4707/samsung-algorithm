#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int t,n,p,D,ans=0;
vector<int>visit;
int funct();
int main()
{

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> p;     
        visit.assign(10000001,0);   
        for (int j = 0; j < n; j++)
        {
            cin >> D;
            visit[D] = 1;
        }
        ans=p+1;
        cout << "#" << i << " " << funct() << endl;
    }
}
int funct()
{
    // 처음부터 검사해야지
    int finish = 1, start = 1, cnt = 0, rest = p;
    int big = D;

    while (finish < visit.size()) // 날짜의 최대값은 최대값 + n 이겟다. 그때까지 돌린다!
    {
        if (visit[finish])
        {
            finish++;
            cnt++;
            ans=max(ans,cnt);
        }
        else if (!visit[finish])
        {
            // 해킹수를 생각해줘야한다.
            {
                if (rest == 0) // 여기면 다시 시작점을 바꿔서 해야할거 같단 말이지.
                {              // 더이상 해킹할수 없다면...
                    ans = max(ans, cnt);
                    // 더 진행할수가 없다. 이러면 우쨰?
                    if (!visit[start])
                    { // 처음부터 검사해서 실제로 방문한날까지 해킹한거를 다시 초기화 시켜줌.
                        rest++;
                    }
                    start++;
                    cnt--;
                }
                else
                {
                    rest--;   // 해킹한 횟수를 줄여야합니다.!!!
                    cnt++;    // 공부한 날짜 체크
                    finish++; // 날자 이동
                }
            }
        }
    }
    return ans;
}