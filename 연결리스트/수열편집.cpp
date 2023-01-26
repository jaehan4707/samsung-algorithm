#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int t, n, m, l;
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> l;
        vector<int> number;
        char o;
        int x, y;
        number.assign(n, 0);
        for (int j = 0; j < n; j++)
        {
            cin >> number[j];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> o;
            x=0,y=0;            
            if (o == 'I')
            {
                cin >> x >> y;
                number.insert(number.begin() + x, y);
            }
            else if (o == 'D')
            {
                cin >> x;
                if (x < number.size())
                    number.erase(number.begin() + x);
                else
                {
                    cout << -1 << endl;
                    break;                    
                }
            }
            else if (o == 'C')
            {
                cin >> x >> y;
                if(x<number.size())
                    number[x] = y;
                else{
                    cout << -1 << endl;
                    break;
                }
            }
        }
        if(l<number.size())
            cout << "#" << i + 1 << " " << number[l] << endl;
        else
            cout<<"#"<< i+1<<" "<<-1<<endl;
    }
}