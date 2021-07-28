  
/*
int arr[n];
int size=4*(n);
    int seg[size];
    buildTree(seg,arr,1,0,n-1);
    updateTree(seg,arr,1,0,n-1,idx, val)
    int ans=query(seg,1,0,n-1,l,r);
*/
void buildTree(int seg[], int arr[], int si, int ss, int se) //building minimum seg tree
{
    if (ss == se)
    {
        seg[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    buildTree(seg, arr, 2 * si, ss, mid);
    buildTree(seg, arr, 2 * si + 1, mid + 1, se);

    seg[si] = (seg[2 * si] + seg[2 * si + 1]);
}
void lazyProp(int seg[] , int lazy[], int si , int ss , int se , int qs , int qe , int val)
{
	if (lazy[si] != 0) // pending updates
	{
		seg[si] +=  lazy[si];

		if (ss != se)
		{
			lazy[2 * si] += lazy[si] ;
			lazy[2 * si + 1] += lazy [si];
		}
		lazy[si] = 0;
	}

	if (ss > qe || se < qs) // completely ouside
		return;

	if (ss >= qs && se <= qe) // qs ss se qe
	{
		seg[si] += val;
		if (ss != se)
		{
			lazy[2 * si] += val ;
			lazy[2 * si + 1] += val;
		}
		return ;
	}

	int mid = (ss + se) / 2;
	lazyProp(seg, lazy, 2 * si , ss , mid , qs , qe , val);
	lazyProp(seg, lazy, 2 * si + 1 , mid + 1 , se , qs , qe , val);

	seg[si] = min(seg[2 * si], seg[2 * si + 1]);

}
int query(int seg[], int lazy[], int si , int ss , int se , int qs , int qe) //note -> value stored by lazy node
{
	if (lazy[si] != 0) // check in lazy notebook
	{
		seg[si] += lazy[si];

		if (ss != se)// pass the note to children
		{	lazy[2 * si] += lazy[si] ;
			lazy[2 * si + 1] += lazy[si];
		} 

		lazy[si] = 0; // set current note to 0
	}

	// normal process
	if (ss > qe || se < qs) //completly outside
		return 0;

	if (ss >= qs && se <= qe) // overlapping
		return seg[si];

	int mid = (ss + se) / 2;
	int l = query(seg, lazy, 2 * si , ss , mid , qs , qe) ;
	int r = query(seg, lazy, 2 * si + 1 , mid + 1 , se , qs , qe);

	return min(l, r);
}
