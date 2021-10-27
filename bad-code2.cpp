  	  // user-defined function to check prime number
  int checkPrimeNumber(int n)
      {
         		     bool flag = true;
        		    for(int j = 2; j <= n/2; ++j)
      {
  
            if (n%j == 0)
  {
  		flag = false;
         	     break;
     	                              }
    }
   	                 	          return flag;
  }
