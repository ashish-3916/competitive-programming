/*

we  can always sort it if arr[i] is atmost 2 distance away from it sorted position

no to find minimum swaps used graph methhod

instead of converting sorted seq to required sequence , do opposite
*/

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

int minSwaps(int arr[], int n)
{
	// Create an array of
	// pairs where first
	// element is array element
	// and second element
	// is position of first element
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	// Sort the array by array
	// element values to
	// get right position of
	// every element as second
	// element of pair.
	sort(arrPos, arrPos + n);

	// To keep track of visited elements.
	// Initialize
	// all elements as not visited or false.
	vector<bool> vis(n, false);

	// Initialize result
	int ans = 0;

	// Traverse array elements
	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;

		// find out the number of  node in
		// this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;

			// move to next node
			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0)
		{
			ans += (cycle_size - 1);
		}
	}

	// Return result
	return ans;
}
void solve()
{
	unordered_map<int , int> m;
	int n ;
	cin >> n;
	int pos[n ];
	for (int i = 0 ; i < n ; i++)
	{
		cin >> pos[i];
		m[pos[i]] = i + 1;
	}
	for (int  i = 1 ; i <= n ; i++)
	{
		int p = m[i];
		if (abs( p - i) > 2)
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	cout << minSwaps(pos, n) << endl;

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

