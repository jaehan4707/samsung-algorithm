#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> A;
int x = 0, d = 1, n, k;
int funct();
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        A.assign(n + 1, 0);
        // 연산 횟수와 k를 저장함.
        for (int j = 1; j <= n; j++)
        {
            cin >> A[j];
        }
        cin >> k;
        int a = funct();
        cout << "#" << i << " " << a << endl;
    }
}
// 그럼 우리는 x=0 , D=1
int funct()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, k));
    int a = pq.top().second;
    while (pq.top().second!=0)
    {                               // 나머지가 1이 될때까지 돌림.
        int tempt = pq.top().first; // 연산횟수
        int left = pq.top().second; // 나머지 숫자.        
        pq.pop();
        // 여기서 더하고 빼기?
        pq.push(make_pair(tempt + left, 0));
        for (int i = 1; i <= n; i++)
        {           
            pq.push(make_pair(tempt + left % A[i], left / A[i]));
        }
    }
    return pq.top().first;
}