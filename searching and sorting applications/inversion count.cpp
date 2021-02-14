long long merge(long long arr[], int s , int m, int e)
{
	int i = s, j = m;
	long long arr1[e - s + 1];
	int index = 0;
	long long inver = 0;
	while (i < m  and j < e + 1)
	{
		if (arr[i] <= arr[j])
		{
			arr1[index++] = arr[i++];
		}
		else
		{
			inver += m - i;
			arr1[index++] = arr[j++];

		}
	}

	while (j < e + 1)
		arr1[index++] = arr[j++];


	while (i < m )
		arr1[index++] = arr[i++];

	for (int i = 0; i < index; i++)
		arr[s++] = arr1[i];

	return inver;

}


long long countInversions(long long arr[], int s, int e)
{
	if (s >= e)
		return 0;

	int mid = (s + e) / 2;

	long long cnt1 = countInversions(arr, s, mid);
	long long cnt2 = countInversions(arr, mid + 1, e);

	long long cnt3 = merge(arr, s , mid + 1 , e);

	return cnt1 + cnt2 + cnt3;
}

long long getInversions(long long *arr, int n)
{
	//Write your code here

	long long ans = countInversions(arr, 0, n - 1);
	return ans;


}
