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
	int arr[n];
	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];
	sort(arr, arr + n , greater<int >());


	ll distance = 0 ;
	for (int i = 0 ; i < n ; i++)
	{
		distance +=  pow(2, i ) * arr[i];
	}
	cout << distance << endl;

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

