/*

similair to inversion count --- merge sort

 for each number on the stairs he will note down the sum of
 all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
*/

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

long long merge(vector< int >  &arr, int s , int m, int e)
{
	int i = s, j = m;
	long long arr1[e - s + 1];
	int index = 0;
	long long sum = 0;
	while (i < m  and j < e + 1)
	{
		if (arr[i] < arr[j])
		{
			sum += arr[i] * ( e - j + 1 );
			arr1[index++] = arr[i++];
		}
		else
		{ 
			arr1[index++] = arr[j++];

		}
	}

	while (j < e + 1)
		arr1[index++] = arr[j++];


	while (i < m )
		arr1[index++] = arr[i++];

	for (int i = 0; i < index; i++)
		arr[s++] = arr1[i];

	return sum;

}
ll count_minSums(vector<int > & stairs , int low , int high )
{
	if (low >= high)
		return 0;
	ll mid = (high + low) / 2;
	ll ans1 = count_minSums(stairs , low, mid );
	ll ans2 = count_minSums(stairs , mid + 1 , high);
	ll ans3 = merge( stairs  , low , mid + 1, high);

	return ans1 + ans2 + ans3;

}

void solve()
{
	int n;
	cin >> n;
	vector<int> stairs(n);
	for (int i = 0; i < n ; i++)
		cin >> stairs[i];

	ll ans = count_minSums(stairs , 0 , n - 1);
	for (int i : stairs)
		cout << i << " ";
	cout << endl;
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

