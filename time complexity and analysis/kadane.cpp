//negative included

int maxSubarraySum(int arr[], int n){
    int ans= arr[0];
    int curr = arr[0];
    for(int i=1 ; i< n ;i++)
    {
        if(arr[i] + curr > arr[i] )
            curr+=arr[i];
        else
            curr=arr[i];
            
        if(curr>ans) ans=curr;   
    }
    return ans;
 }

/// negative excluded

int maxSubarraySum(int arr[], int n)
{
  int ans =0 ;
  int best=0;
  
  for(int i=0;i<n;i++)
  {
    curr+=arr[i];
    if(curr>best)
    best=curr;
    
    if(curr<0)curr=0;
  }
  return best;
}
