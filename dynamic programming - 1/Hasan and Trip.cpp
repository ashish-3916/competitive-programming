#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define elif else if
#define pb push_back
#define pf push_front
#define PI 3.1415926535897932384
#define MOD 1000000007
using namespace std;

string s;

double dp[3005];

struct city {
	double X, Y, F;
};

vector<city> cities(3005);
double distance ( city a  , city b )
{
	double ans = sqrt(pow (a.X - b.X, 2)  + pow(a.Y - b.Y, 2) ) ;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> cities[i].X >> cities[i].Y >> cities[i].F;
	}

	for (int i = 0; i < 3005; i++) {
		dp[i] = -1 * 1e9;
	}

	dp[1] = cities[1].F;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = max( dp[i], dp[j] + cities[i].F - distance(cities[i], cities[j]));
		}
	}

	cout << fixed << setprecision(6) << dp[n] << endl;
}
