/* N Students of different heights are attending an assembly. The heights of the students are represented by an array H[]. The problem is that if a student has less or equal height than the student standing in front of him, then he/she cannot see the assembly. Find the minimum number of students to be removed such that maximum possible number of students can see the assembly.
 

Example 1:

Input:
N = 6
H[] = {9, 1, 2, 3, 1, 5}
Output:
2
Explanation:
We can remove the students at 0 and 4th index.
which will leave the students with heights
1,2,3, and 5.


Expected Time Complexity: O(N logN)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105
1 ≤ H[i] ≤ 105
*/
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> ans;
       ans.push_back(H[0]);
       for(int i=1;i<N;i++)
       {
           if(H[i]>ans.back())
           ans.push_back(H[i]);
           else
           {
               int indx = lower_bound(ans.begin(),ans.end(),H[i]) - ans.begin();
               ans[indx] = H[i];
           }
       }
       return N - ans.size();  
        
    }
};
