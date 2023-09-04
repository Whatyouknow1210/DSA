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
        // No.of nodes <=1e4 
        // Brute Force
        if(head==NULL)return false;
        int temp = 10001;
        while(temp--)
        {
            if(head->next==NULL)return false;
            head = head->next;
        }
        return true;

        /*
            TWO POINTERS
            ListNode* slow =head;
            ListNode* fast =head;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast)return true;
            }
            return false;
        */
    }
};