void solve (int arr[] , int i , int j)
{
  
	int low = i ;
    int high =j; 
    while(low <= high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high]= temp;
       
        low++; high--;
    }
}
void rotate(int *input, int d, int n)
{
    //Write your code ere
    if(d==0)return;
    
    int x  = d%n;
    
    solve(input , 0, x-1);
    solve(input , x , n-1);
    solve(input , 0 , n-1);
}
