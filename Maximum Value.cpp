/* Given a binary tree, find the largest value in each level.


Example 1:

Input:
        1
       / \
      2   3 
Output:
1 3
Explanation:
At 0 level, values of nodes are {1}
                 Maximum value is 1
At 1 level, values of nodes are {2,3}
                Maximum value is 3 */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
class Solution {
  public:
    vector<int> maximumValue(Node* node) {
        //code here
        vector<int> ans;
        queue<Node*> q;
         if(node==NULL){// if node is empty then return empty vector.
      return ans;
  }
        q.push(node);
        while(!q.empty()){
            int count=q.size();
             vector<int> res;//make a new vector that will store the elements of same level in the queue.
             // traverse in the queue and push the elements in the res vector.
             for(int i=0; i<count; i++){
                 Node*temp=q.front();
                 res.push_back(temp->data);
               // make sure the pop the elements from the queue.
                 q.pop();
              
                 if(temp->left){
             q.push(temp->left);
           }
          if(temp->right){
               q.push(temp->right);
            }
             }
             // sort the vector res.
            sort(res.begin(),res.end());
            // push the last element of vector res into ans vector as it will be the largest element of that level.
            ans.push_back(res[res.size()-1]);
            
        }
        
     return ans;
     
        
    }
};
