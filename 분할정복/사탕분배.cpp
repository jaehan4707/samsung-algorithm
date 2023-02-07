#include <iostream>
using namespace std;

unsigned long long funct(unsigned long long n, unsigned long long sum);
unsigned long long answ(unsigned long long a, unsigned long long b, unsigned long long k);
int main()
{
    int t;
    unsigned long long a, b, k;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> k;        
        cout << "#" << i + 1 << ' ' << answ(a, b, k) << "\n";
    }
    return 0;
}
unsigned long long funct(unsigned long long n, unsigned long long sum)
{
    if (n == 0) //k가 0이라면 원래 갯수를 그대로 반환해줘야함.
    {
        return 1;
    }
    unsigned long long result = funct(n / 2, sum);
    // result = result % sum;
    result = (result * result) % sum;
    if (n & 1)
    {
        result = (result * 2) % sum;
    }
    return result;
}
unsigned long long answ(unsigned long long a, unsigned long long b, unsigned long long k)
{
    unsigned long long sum = a + b;
    unsigned long long result = (funct(k, sum) * a) % sum;
    return min(result, sum - result);
}