#include <iostream>
#include <bits/stdc++.h>
#define ll long long // delete if it causes problem
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
	vector<int>arr(n);
	for (int & i : arr)
		cin >> i;

	for (int i = 0 ; i < n ; i++)
	{
		arr[i] = ceil((arr[i] - i) / (n * 1.0) );
	}
	int ans = min_element(all(arr)) - arr.begin() + 1;
	cout << ans << endl;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

