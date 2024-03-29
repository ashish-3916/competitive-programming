
/*-------------------------------------------------------------------------------*/

int N ; // N = n+1 , n -> the one given in input
//vector<int> arr(N); // input_array must be ONE BASED INDEXING
class fenwick
{
  int lsb(int i)
  {
    return i & -i;
  }
public:
  vector<int> bit;

  void build_tree (vector<int>& input_arr) // 1 based input_array , O(n)
  {
    int sz =  input_arr.size();
    input_arr[0] = 0;

    bit = input_arr;
    for (int i = 1 ; i < sz ; i++)
    {
      int parent = i + lsb(i);
      if (parent < sz )
        bit[parent] += bit[i];
    }
  }
  int query(int i) // [ 1 , i ] // 1 based  , O(logn)
  {
    int sum = 0 ;

    while (i != 0)
    {
      sum += bit[i];
      i &= ~lsb(i) ; //i -= lsb(i);
    }
    return sum;
  }
  int query_interval(int left , int right) // [left, right], O(logn)
  {
    if (left > right)
      return -1 ;
    return query(right) - query(left - 1);
  }
  int get_index(int i) // get_index value at index i
  {
    return query_interval(i, i);
  }
  void add_index(int i , int val) // add 'val' to index i  , O(logn)
  {
    while (i < N)
    {
      bit[i] += val;
      i += lsb(i);
    }
  }
  void set_index(int i , int val) // set index  i  to val , O(logn)
  {
    add_index( i , val - query_interval(i, i))  ;
  }


};


/*-----------------------------------------------------------------------------------------------------*/

