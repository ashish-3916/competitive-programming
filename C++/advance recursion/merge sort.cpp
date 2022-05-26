

void merge(int arr[], int s  , int m, int e )
{
    int i =s ,j = m;
    int a[e-s+1];
    int index =0 ;
    
    while(i<m and j <=e)
    {
		if(arr[i] <=arr[j])
            a[index++]=arr[i++];
        else 
            a[index++]=arr[j++];
    }
    while(i<m)
         a[index++]=arr[i++];
    while(j<=e)
         a[index++]=arr[j++];
    
    index=0;
    for(int i =s  ;i <=e ; i++)
        arr[i]=a[index++];
        
}

void mergesort(int arr[], int s , int e)
{
    if(s>=e)
        return;
    
    int mid  = ( s + e)/2 ;
    
    mergesort(arr, s , mid );
    mergesort(arr, mid+1 , e);
    merge(arr, s, mid+1 , e);

}
void mergeSort(int input[], int size){
	// Write your code here
        
    mergesort(input, 0, size-1);
}
