#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<char>> s;
vector<vector<char>> te;
int h, w, n, m,ans;
bool funct(int row, int col);
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ans=0;
        cin >> h >> w >> n >> m;
        s.assign(h, vector<char>(w, 0));
        te.assign(n, vector<char>(m, 0));
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < w; k++)
            {
                cin >> s[j][k];
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> te[j][k];
            }
        }
        for (int x = 0; x <= n-h; x++) //n은 3 h는 2
        {
            for (int y = 0; y <= m-w; y++) //m은 3 w는 2
            {
                if(funct(x, y)){                  
                    ans++;
                }
            }
        }
        cout<<"#"<<i<<" "<<ans<<endl;
    }
}
bool funct(int row, int col)
{

    for (int i = 0; i < h; i++) //이게 문제다. 이말이네.
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] != te[row + i][col + j])
            {
                return false;
            }
        }
    }
    return true;
}
