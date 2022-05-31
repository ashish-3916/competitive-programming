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
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0 ; i < n ; i++) cin >> arr[i];
	sort(all(arr));

	for (int i = n -1 ; i >= 2 ; i--)
	{
		if (arr[i] < arr[i-1]+arr[i-2])
		{
			cout<< arr[i-2]<<" "<< arr[i-1]<<" "<< arr[i];
            return;
		}
	}
cout<<-1<< endl;

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

