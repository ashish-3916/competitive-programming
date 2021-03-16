#include<bits/stdc++.h>
using namespace std;
int main() {

	int sum , n ;
    cin>> sum>> n;
    
    assert( sum <= 9*n);
    
    string s(n,'0');
    
    s[0]='1';
    
    sum--;
    
   	for (int i = n - 1 ; i >= 0 ; i--)
	{
		int last ;
		if (sum >= 9)
			last = 9;
		else last = sum;

		sum -= last;

		s[i] = s[i] + last;
	}
    
    cout<< s << endl;  
}
