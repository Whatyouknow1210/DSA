/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode *curr = nullptr;
        while(head)
        {
            ListNode *temp = head;
            temp = temp->next;
            head->next = curr;
            curr = head;
            head = temp;
        }
        return curr;
    }
};