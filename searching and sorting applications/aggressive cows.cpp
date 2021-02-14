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


bool solve2(vector<int> &arr , int n , int d, int c)
{
	int cnt = 1;
	int prev = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] - arr[prev] >= d)
		{
			cnt++;
			prev = i;
		}

	}
	if (cnt < c)
		return false;
	return true;

}

void solve()
{
	int n, c;
	cin >> n >> c;
	vector<int> arr(n);
	for (int &i : arr)
		cin >> i;
	sort(all(arr));

	int low = 0;
	int high = arr[n - 1] - arr[0];
	int ans = -1;

	while (low <= high)
	{
		int mid = (high + low) / 2;

		bool check = solve2(arr, n, mid, c);

		if (check)
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}

	}

	cout << ans << endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{solve();}
	return 0;
}

