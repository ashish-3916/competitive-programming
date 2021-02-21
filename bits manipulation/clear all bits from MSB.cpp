/*
You are given two integers N and i. You need to clear all bits from ith to MSB bit (start i from right to left) and return the updated N.
*/

int clearAllBits(int n, int i){
 
    int x = 1<<i;
    int y = x-1 ;
    
    return n&y;
}

/*
     		      i
              |
 000000000001111010  =n  
 000000000000001111  =y=x-1
 000000000000010000  =x=1<<i

 000000000000000010  =n&y
    x&1 = x
    x&0 = 0

protection of bits means masking and AND is used for it
*/
