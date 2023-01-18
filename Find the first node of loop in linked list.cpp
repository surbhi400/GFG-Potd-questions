/* Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop. If a loop is present return the node data of the first node of the loop else return -1.

Example 1:

Input:

Output: 3
Explanation:
We can see that there exists a loop 
in the given linked list and the first
node of the loop is 3.
 

Example 2:

Input:

Output: -1
Explanation: No loop exists in the above
linked list.So the output is -1. */
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        Node *slow=head,*fast=head;
        if(head==NULL or head->next==NULL or head->next->next==NULL)return -1;
        slow=slow->next;
        fast=fast->next->next;
        while(slow!=fast){
            if(fast->next==NULL or fast->next->next==NULL)return -1;
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow->data;
        
    }
};
