/*
1.  Take two's complement of the given no as all bits are reverted
    except the first '1' from right to left (0100)
2.  Do a bit-wise & with original no, this will return no with the
    required one only (0100)
3.  Take the log2 of the no, you will get (position - 1) (2)
4.  Add 1 (3)
 
   20 -> 10100 
  -20 -> 01011   (2s complement
         +   1
      =  01100
    (10100)&(01100) = 100
    
    position = log2(100) + 1
*/
int returnFirstSetBit(int n){ 
   return n & (-1*n) ; 
}


int returnFirstSetBit(int n){
   for(int i=0 ;i<31 ;i++)
       if(n & 1<<i)
           return 1<<i;
}
