#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;



void solve()
{
	int n;
	cin >> n;
	vector<int> price(n);
	for (int i = 0; i < n; i++)
		cin >> price[i];

	for (int i = 1; i < n; i++)
		price[i] += price[i - 1];

	int q ;
	cin >> q;
	while (q--)
	{
		int save;
		cin >> save;

		int index = upper_bound(all(price), save) - price.begin();
		index--;
		//cout << index << " ";

		if (index == -1)
			cout << 0 << " " << save << endl;
		else
		{
			cout << index + 1 << " " << save - price[index] << endl;
		}
	}
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	solve();
	return 0;
}

