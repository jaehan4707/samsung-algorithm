#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// vector<int> result;
string result;
bool flag = false;
int check = 0;
string n;
int x, y, t;
void funct();
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> x >> y;
        if (x >= y || x < 0 || y > 9)
            continue;
        flag = false;
        cout << "#" << i + 1 << " ";
        // result.assign(0, 0);
        result = "";
        // n 입력받고.
        funct();
        if (result == "")
        {
            cout << -1;
        }
        else
            cout << result;
        cout << endl;
    }
}
void funct()
{
    // cout<<n.size()<<endl;
    for (int i = 0; i < n.size(); i++)
    {
        int num = n[i] - 48;
        // ut << num << endl;
        if (flag == true && i >= check)
        {
            result.push_back(y + 48);
        }
        else
        {
            if (num > y) // 숫자가 최대값보다 큰 경우 최대값을 넣어줌.
            {
                for (int i = result.size(); i < n.size(); i++)
                {
                    result.push_back(y + 48);
                }
                return;
            }
            else if (num == y)
            {
                result.push_back(y + 48);
            }
            else if (num > x) // 최대값보다 작고, 최소값보다 큰 경우  최소값 넣고 -> 뒤의 숫자 밀어주기.
            {
                if (x == 0 && result.size() == 0) // 근데 만약 그 최소값이 0이라면 숫자의 처음은 0이 올 수 없음. 그래서 실제 길이 -1만큼 최대값을 채워줌.
                {
                    for (int a = 0; a < n.size() - 1; a++)
                    {
                        result.push_back(y + 48);
                    }
                    return;
                }
                result.push_back(x + 48);                      // 만약 최소값이 0이거나 처음 들어가는 숫자가 아니라면 최소값을 넣어주고.
                for (int a = result.size(); a < n.size(); a++) // 뒤 부분은 최대값으로 밀어줌.
                {
                    result.push_back(y + 48);
                }
                return;
            }
            else if (num == x) // 최소값과 같은 경우는 실제 최소값이 0이고, 처음 들어간다는 경우는 배제함.
            {
                if (result.size() == 0 && x == 0)
                {
                    continue;
                }
                result.push_back(x + 48); // 0이 아니라면 그냥 넣어줌.
            }
            else if (num < x) // 작을 때 앞의 숫자를 깎아줘 야함.
            {
                if (i == 0 && n.size() == 1) // n이 한자린데 그 것마저 최소값보다 작다면 만들 수 없음.
                {
                    return;
                }
                if (i == 0) // n이 한자리 숫자가 아니라면. 뒤에 숫자를 다 최대값으로 밀어버림.
                {
                    // flag = true;
                    // check = i;
                    for (int m = 0; m < n.size() - 1; m++)
                    {
                        result.push_back(y + 48);
                    }
                    return;
                }
                else
                {
                    n[i - 1] = n[i - 1] - 1; // 한자리수 깎고,
                    // n[i] = y + 48; //그 다음 자리는 만들 수 있는 최대값으로 만듬.
                    result.pop_back(); // 다음에 깎은 수를 지워줌.
                    flag = true;       // 깎앗다는 표시를함.
                    check = i;         // i번쨰부터는 그냥 최대값으로 밀어도 된다는 뜻.
                    i -= 2;            // 깎은 숫자부터 검사 시작.
                }
            }
        }
    }
}