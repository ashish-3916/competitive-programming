
#include<bits/stdc++.h>
using namespace std;
int minAbsoluteDiff(int arr[], int n) {
  
    sort(arr, arr+n);
    int ans = INT_MAX;
    for(int i=0 ; i< n-1 ; i++)
    {
        ans = min ( abs (arr[i] - arr[i+1 ] ) , ans );
    }
    return ans ;

}
