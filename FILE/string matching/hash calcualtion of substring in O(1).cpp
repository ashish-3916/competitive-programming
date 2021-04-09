/*
hash(s[i…j])* pi=  ∑k=ij s[k]*p^k  mod m = hash(s[0…j])−hash(s[0…i−1]) mod m
we must be able to divide hash(s[0…j]) − hash(s[0…i−1]) by p^i. Therefore we need to find the modular multiplicative inverse of p^i 
*/

lli dp[1000001];
lli inv[1000001];
 
lli power(lli a , lli n)
{
	lli result = 1;
 
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
 
		n >>= 1;
		a = (a * a) % mod;
	}
 
	return result;
}
 
 
void init(string input_string)
{
	lli p = 31;
	lli p_power = 1;
	inv[0] = 1;
	dp[0] = (input_string[0] - 'a' + 1);
 
 
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
 
		p_power = (p_power * p) % mod;
		inv[i] = power(p_power , mod - 2);
 
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}
 
lli substringHash(int L , int R) // indexes of the substring 
{
	int result = dp[R];
 
	if(L > 0) result -= dp[L-1];
 
	result = (result * inv[L]) % mod;
 
	return result;
}
