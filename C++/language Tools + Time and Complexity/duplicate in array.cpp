int findDuplicate(int *arr, int n)
{
    int x = n-2;

    int sum=(x*(x+1))/2;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
        sum2+=arr[i];
    }
    return (sum2-sum);
}
