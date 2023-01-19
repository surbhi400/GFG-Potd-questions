/* Given an array of integers of size n and an integer k, find all the pairs in the array whose absolute difference is divisible by k.

Example 1:

Input:
n = 3
arr[] = {3, 7, 11}
k = 4
Output:
3
Explanation:  
(11-3) = 8 is divisible by 4
(11-7) = 4 is divisible by 4
(7-3) = 4 is divisible by 4

Example 2:

Input:
n = 4
arr[] = {1, 2, 3, 4}
k = 2
Output :
2
Explanation:
Valid pairs are (1,3), and (2,4).
Expected Time Complexity: O(n + k)
Expected Auxiliary Space: O(k)*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
         map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]%k]++;
        }
        long long res=0;
        for(auto x: mp)
        {
            res=res+(x.second*(x.second-1))/2;
        }
        return res;
    }
};
