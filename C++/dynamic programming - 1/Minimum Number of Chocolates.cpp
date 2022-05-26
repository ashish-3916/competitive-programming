#include<vector>
int getMin(int *arr, int n)
{
	vector<int> sum(n,1);
    
    for(int i=1; i< n ;i++)  // optimise via left
        if(arr[i]>arr[i-1])
            sum[i]= sum[i-1]+1;
    
    for(int i = n-2 ; i>=0 ; i--) // optimise via right
        if(arr[i]>arr[i+1])
            sum[i]= max(sum[i], sum[i+1]+1);
    
    int ans =0 ;
    for(int i = 0;i<n ;i++) // total
        ans+=sum[i];
    
    return ans;
}
