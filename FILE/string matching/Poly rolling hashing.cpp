

/*
hash(s)=s[0]+s[1]⋅p+s[2]⋅p2+...+s[n−1]⋅pn−1 mod m = ∑i=0n−1 s[i]⋅pi  modm,
*/

#include<bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define mod 1000000007
using namespace std;

lli getHash(string key)
{
	lli value = 0;
	lli p = 31;
	lli p_power = 1;
	
	for(char ch : key)
	{
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}
	
	return value;
}

int main()
{
  
  string key;
  cin>> key;
	cout<<"Key : "<<key<<" Hash : "<<getHash(key)<<endl;	
}
