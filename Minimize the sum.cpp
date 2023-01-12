/* You are given N elements, you can remove any two elements from the list, note their sum, and add the sum to the list. Repeat these steps while there is more than a 
single element in the list. The task is to minimize the sum of these chosen sums.

 

Example 1:

Input:
N = 4
arr[] = {1, 4, 7, 10}

Output:
39

Explanation:
Choose 1 and 4, Sum = 1 + 4 = 5.
arr[] = {5, 7, 10} 
Choose 5 and 7, Sum = 5 + (5 + 7) = 17.
arr[] = {12, 10} 
Choose 12 and 10, Sum = 17 + (12 + 10) = 39.
arr[] = {22}
 

Example 2:

Input:
N = 5
arr[] = {1, 3, 7, 5, 6}

Output:
48
 */-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int, vector<int>, greater<int>> pq;// minheap
        for (int i = 0; i < N ; ++i)
        {
            pq.push(arr[i]);
        }
        int sum = 0;
        int temp = 0;
        int temp2=0;
        while (pq.size() != 1) //Iterate in minheap and push the sum of top two elements in the heap again.
        {
            temp = pq.top();
            pq.pop();
            temp2 = pq.top();
            sum += temp+temp2;
            pq.pop();
            

            pq.push(temp+temp2);

        }
        return sum;
    }
};
