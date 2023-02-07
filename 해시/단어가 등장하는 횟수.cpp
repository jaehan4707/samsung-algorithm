#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int>ary;
void getPi(string p);
int kmp(string s, string p);
int main()
{	
	int t;
	cin>>t;	
	for (int i=1; i<=t; i++)
	{
		string x,y;
		cin>>x>>y;
		cout << "#" << i<< " " << kmp(x,y)<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
void getPi(string p) {
	
	int m = p.size();	
    ary.assign(m,0);
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = ary[j - 1];
		if (p[i] == p[j])
			ary[i] = ++j;
	}	
}
int kmp(string s, string p) {	
    getPi(p);
	int n = s.size(), m = p.size(), j = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = ary[j - 1];
		
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans++;
				j = ary[j];
			}
			else
				j++;
		}
	}
	return ans;
}