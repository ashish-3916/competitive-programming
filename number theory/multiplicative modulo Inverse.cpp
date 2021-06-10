/*
multiplicative modulo inverse
    (a*b)mod m =1 ;
    find b ?   a,b,m are integer

    b exists if a and b are coprime;
                a*x + b*y = gcd
    final eq =  a*b + m*Q = gcd(a,m) // Extended Euclid  with b and Q as soln of eq
*/

vector<int>ExtendedEuclid(int a , int b)
{
    if (b == 0)
        return {a , 1 , 0};

    vector<int> small = ExtendedEuclid(b, a % b);

    return {small[0]  , small[2] , small[1] - (a / b) *small[2]}; // gcd , x1 , y1
}
int MMInverse(int n , int m)
{   
    if(__gcd(n,m)!=1) // not coprime ,,, if m is prime , use fermat little thrm
        return -1;
    vector<int> res = ExtendedEuclid(n , m);
    return (res[1] + m ) % m; // in case res1 is neg
}
