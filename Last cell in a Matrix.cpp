/* Given a binary matrix of dimensions  with R rows and C columns. Start from cell(0, 0), moving in the right direction. Perform the following operations: 

If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction clockwise. ie - up, right, down, or left directions change to right, 
down, left, and up respectively.
Find the index of the cell where you will be forced to exit the matrix while performing the given traversal. 

Example 1:

Input:
matrix[][] = {{0,1},
              {1,0}}
R=2
C=2

Output: (1,1) 
Example 2:

Input: 
matrix[][] = {{0, 1, 1, 1, 0},
                   {1, 0, 1, 0, 1},
              {1, 1, 1, 0, 0}}
R=3
C=5

Output: (2,0)
Explanation: We will leave the grid after visiting the index (2,0).
*/------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        int i=0,j=0;
        int n=R;
        int m=C;
        bool move_right=true;
        bool move_left=false;
        bool move_up=false;
        bool move_down=false;
        while(i>=0 && i<n && j>=0 &&j<m){
            if(matrix[i][j]==0){
                if(move_right){
                    j++;
                }
                else if(move_down){
                    i++;
                }
                else if(move_up){
                    i--;
                }
                else{
                    j--;
                }
            }
            else{
                matrix[i][j]=0;
                if(move_up){
                    move_right=true;
                    move_up=false;
                }
                else if(move_right){
                    move_right=false;
                    move_down=true;
                }
                else if(move_down){
                    move_left=true;
                    move_down=false;
                }
                else{
                    move_left=false;
                    move_up=true;
                }
            }
        }
        if(move_up) return {i+1,j};
        else if(move_down) return {i-1,j};
        else if(move_right) return {i,j-1};
        else{
            return {i,j+1};
        }
        
    }
};
