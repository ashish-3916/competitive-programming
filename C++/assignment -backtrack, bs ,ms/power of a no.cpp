#include<iostream>
using namespace std;
int power(int x,int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
int main() {
	// Write your code here
	int x,n;
    cin>>x>>n;
    
    cout<< power(x,n)<< endl;
}


    
    
