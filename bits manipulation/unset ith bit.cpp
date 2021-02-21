int turnOffIthBit(int n, int i){
    
    if(n&(1<<i)) // if bit is set
    {
    	return (n^(1<<i)); // flip that bit    
    }
    return n ;  // else return same
}
  
