#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
vector<string> x;
vector<string> y;
int answ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m, answ = 0;
        cin >> n >> m;
        y.clear(), x.clear();
        for (int j = 0; j < n; j++)
        {
            string str;
            cin >> str;
            x.push_back(str);
        }
        for (int j = 0; j < m; j++)
        {
            string str;
            cin >> str;
            y.push_back(str);
        }
        sort(x.begin(), x.end()); // 알파벳 순서대로 정렬하기.
        sort(y.begin(), y.end());
        cout << "#" << i << " ";
        int x_idx = 0;
        int y_idx = 0;
        // 반복문을 돌려야합니다.
        while (1)
        { // 둘다 끝까지 탐색했을때 종료합니다.

            if (x_idx >= x.size() || y_idx >= y.size())
            {
                break;
            }
            if (x[x_idx] == y[y_idx])
            { // 만약 같다면.
                //cout << x[x_idx] << " " << y[y_idx] << endl;
                answ++;
                x_idx++;
                y_idx++;
            }
            else if (x[x_idx] > y[y_idx])
            { // 앞글자가 X가 더 크다면 X의 알파벳이라는 뜻이므로 y의 index를 증가시킴.
                y_idx++;
            }
            else if (x[x_idx] < y[y_idx])
            { // 앞글자가 Y가 더 크다면 Y의 알파벳이 뒤 알파벳이라는 뜻이므로 X의 index를 증가시킴.
                x_idx++;
            }
        }
        cout << answ << endl;
    }
}