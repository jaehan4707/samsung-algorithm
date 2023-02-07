#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int t, n;
vector<string> ary;
bool comp(string a, string b);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        ary.resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> ary[j];
            // 문자열 길이순으로. 길이가 같다면 사전순
        }
        sort(ary.begin(), ary.end(), comp);
        ary.erase(unique(ary.begin(), ary.end()), ary.end());
        cout << "#" << i << endl;
        for (auto a : ary)
        {
            cout << a << '\n';
        }
    }
}
bool comp(string a, string b)
{ // true면 바꾸고, false 면 안바꿈.
    if (a.length() > b.length())
        return false;
    else if (a.length() == b.length())
        return a < b;
    else if (a.length() < b.length())
        return true;
}