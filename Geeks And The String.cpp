/* Our geek loves to play with strings, Currently, he is trying to reduce the size of a string by recursively removing all the consecutive duplicate pairs. In other words, He can apply the below operations any number of times.

Remove all the consecutive duplicate pairs and concatenate the remaining string to replace the original string.
Your task is to find the string with minimum length after applying the above operations.

Note: If the string length become zero after applying operations, return "-1" as a string.


Example 1:

Input:
aaabbaaccd
Output: 
ad
Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
Example 2:

Input: 
aaaa
Output: 
Empty String
Explanation: 
Remove (aa)aa => aa
Again removing pair of duplicates then (aa) 
will be removed and we will get 'Empty String'.

Your Task:
This is a function problem. You only need to complete the function removePair() that takes a string as a parameter and returns the modified string. Return an empty string if the whole string is deleted.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
 */--------------------------------------------------------------------------------------------------------------------------------------------------------------------
   stack<char> st;
    string g="";
    int n=s.size();
    for(int i=n-1; i>=0; i--){
        if(st.size()==0){
            st.push(s[i]);
        }
        else{
            if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
        while(st.size()){
            char ch=st.top();
            st.pop();
            g.push_back(ch);
        }
        if(g.size()==0) return "-1";
        else{
            return g;
        }
    }
    
};
