
int longestBitonicSubarray(int *arr, int n) {

	int inc[n];
	int dec[n];

	inc[0] = 1;

	for (int i = 1 ; i < n; i++)
	{	int ans = 0 ;
		for (int  j = i - 1 ; j >= 0 ; j--)
		{
			if (arr[i] > arr[j])
				ans = max(ans , inc[j]);
		}
		inc[i] = ans + 1;
	}

	dec[n - 1] = 1;
    
	for (int i = n - 2 ; i >= 0; i--)
	{	int ans = 0 ;
		for (int  j = i + 1 ; j < n; j++)
		{
			if (arr[i] > arr[j])
				ans = max(ans , dec[j]);
		}
		dec[i] = ans + 1;
	}
    
	int res = 0;
	for (int  i = 0 ; i < n ; i++)
		res = max(res ,  inc[i] + dec[i] - 1);


	return res;
}
