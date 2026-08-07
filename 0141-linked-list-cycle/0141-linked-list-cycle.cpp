/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode *node=head;
        while(node)
        {   
            if(st.find(node)!= st.end())
            {
                return true;
            }
            else
                st.insert(node);
            node= node->next;
            
        }
        return false;
        
    }
};