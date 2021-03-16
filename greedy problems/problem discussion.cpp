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
	int n, k;
	cin >> n >> k;
	vector<int>arr(n);
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];

	sort(all(arr));

    int ans = arr[n-1]- arr[0]; // dont do anything 
    
	int mx  = arr[n - 1] - k;
	int mn = arr[0] + k;
	if (mn > mx)
		swap(mx, mn);
	for (int i = 1 ; i < n - 1 ; i++ )
	{
		if (mn > mx)
			swap(mx, mn);
		int c1 = arr[i] + k ;
		int c2 = arr[i] - k;

		if (c1 <=  mx  or c2 >= mn) // if any of c1 or c2 lie within mn....mx assign it c1/c2
			continue;

		// what should i take ?

		if ((c1 - mn) < (mx - c2) ) // check wjhich one yields smaller differ
			mx = c1;
		else
			mn = c2;

		assert(mx >= mn);

	}

	cout << min(ans,mx - mn) << endl;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

