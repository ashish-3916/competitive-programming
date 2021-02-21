int turnOffFirstSetBit(int n){
 
    return n ^ ( n&(-1*n) );
    
}


/*
   n=12
   
   n = 0001100
  -n = 1110011
       +     1
  -n = 1110100 
n&-n = 0000100   ( first set bit )

^  --> flips that bit
so n^(n&-n) = 0001000 answer
*/
