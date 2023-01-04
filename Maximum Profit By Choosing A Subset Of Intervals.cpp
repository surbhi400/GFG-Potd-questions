/* Given a list intervals of n intervals, the ith element [s, e, p] denotes the starting point s, ending point e, and the profit p earned by choosing the ith interval. Find the maximum profit one can achieve by choosing a subset of non-overlapping intervals.

Two intervals [s1, e1, p1] and [s2, e2, p2] are said to be non-overlapping if [e1 <= s2] and [s1 < s2].

Example 1:

Input:
n = 3
intervals = {
{1, 2, 4},
{1, 5, 7},
{2, 4, 4}
}
Output:
8
Explanation:
One can choose intervals [1, 2, 4] and [2, 4, 4] for a 
profit of 8. */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
          sort(intervals.begin(),intervals.end());

        vector<int>dp(n,0); 

        int maxi=0;

        for(int i=0;i<n;i++)

       {

           dp[i]=intervals[i][2];

           maxi=max(maxi,dp[i]);

       }

        for(int i=1;i<n;i++)

        {

            for(int j=0;j<i;j++)

            {

                if(intervals[i][0] >= intervals[j][1])

                {

                    if( dp[i] < dp[j]+intervals[i][2])

                    {

                        dp[i]=intervals[i][2]+dp[j];

                    }

                }

            }

            maxi=max(maxi,dp[i]);

}
      return maxi;

    
        
        
        
    }
};
