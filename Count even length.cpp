/*  Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits.
The anwer can be very large. So, you have to return answer modulo 109+7.

Example:

Input: n = 2
Output: 6
Explanation: There are 6 sequences of length 
2*n, the sequences are 0101, 0110, 1010, 1001, 
0000 and 1111.*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class solution{
    	
	public:
	int mod = 1000000007;
	long long inv(long long int r){
	    if(r==1) return 1;
	    return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
	}
	int compute_value(int n)
	{
	    // Code here
	    long long int ans = 1, ncr=1;
	    for(int i=1; i<=n; i++){
	        ncr=(((ncr*(n+1-i))%mod)*inv(i))%mod;
	        ans=(ans+(ncr*ncr)%mod)%mod;
	    }
	    return ans%mod;
	}
};
