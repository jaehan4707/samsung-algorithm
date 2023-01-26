#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n, num;
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        vector<string> origin;
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            origin.push_back(a);
        }
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            char o;
            int x, y;
            cin >> o;
            if (o == 'I')
            {
                // 앞에서 x의 위치에 s를 삽입
                cin >> x >> y;
                for (int j = 0; j < y; j++)
                {
                    string temp;
                    cin >> temp;
                    origin.insert(origin.begin() + x + j, temp);
                }
            }
            else if (o == 'A')
            {
                // 암호문의 맨 뒤에 y개의 숫자를 붙임.
                cin >> y;
                for (int j = 0; j < y; j++)
                {
                    string temp;
                    cin >> temp;
                    origin.push_back(temp);
                }
            }
            else if (o == 'D')
            {
                // 앞에서 x의 위치 바로 다음부터 y개의 숫자를 삭제함.
                cin >> x >> y;
                origin.erase(origin.begin() + x, origin.begin() + x + y);
            }
        }
        cout << "#" << i + 1 << " ";
        for (int i = 0; i < 10; i++)
        {
            cout << origin[i] << " ";
        }
        cout << endl;
    }
}