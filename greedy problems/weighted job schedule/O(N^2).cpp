/*
the idea is to calcluate for n-1 jobs , and fr 0th job check with job should be done next after completion of this 0th job

output arr constains the status to profit we can achieve if we started from this ith job amd yes i am considering this job ,
so which job should i start next which yeilds to max profit
so i check from all and take max among n-1 choices   .......( so in this way including excluding are managed)

NOTE: this is not same as  :  output[i] represints max profit till this job   , ouput[i] reprsents max profit if i includied / started with this job
so return the max profit 

cons:
 soln in O(N^2)  ,  exact jobs are difficult to retrieve (in case if asked )
 
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

class job
{
public:
	int start , finish , profit;
	job() {}
	job( int s , int f , int p)
	{
		start = s; finish = f; profit = p;
	}
};
bool myfunc(job j1 , job j2)
{
	return j1.finish < j2.finish;
}

vector<int> getans(vector<job> &arr, int i )
{
	int n = arr.size();
	if (n - 1 == i )
	{
		return {arr[i].profit};
	}

	vector<int > output = getans(arr, i + 1);
	int s = output.size();

	int ans = 0;
	for (int j = 0 ; j < s ; j++)
	{
		if (arr[j + i + 1].start >= arr[i].finish)
			ans = max(ans , output[j]);
	}
	//cout << ans << endl;
	ans += arr[i].profit;

	output.insert(output.begin(), ans);

	return output;
}
void solve()
{
	int n ;
	cin >> n ;

	vector<job> arr(n);
	for (int i = 0; i < n ; i++)
	{
		int x, y, z ;
		cin >> x >> y >> z;
		arr[i] = job(x, y, z);
	}

	sort(all (arr) , myfunc);
	/*for ( auto x : arr)
		cout << x.start << " " << x . finish << " " << x.profit << endl;*/
	vector<int> output =  getans(arr , 0);
	/*for (int x : output)
		cout << x << " ";*/
	int ans = -1 ;
	for (int i = 0 ; i < output.size() ; i++)
		ans = max(ans , output[i]);

	cout << ans << endl;

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}

