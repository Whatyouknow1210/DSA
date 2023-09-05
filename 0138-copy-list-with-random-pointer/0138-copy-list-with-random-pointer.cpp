/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /* Using HashMap */

        // Node *dummy = new Node(-1);
        // Node *ans = dummy;
        // Node* dummy_head = head;
        // unordered_map<Node*,Node*>mp;
        // mp[nullptr] = nullptr;
        // while(head)
        // {
        //     Node *curr = new Node(head->val);
        //     mp[head] = curr;
        //     head = head->next;
        // }
        // while(dummy_head)
        // {
        //     dummy->next = mp[dummy_head];
        //     dummy = mp[dummy_head];
        //     dummy->next = mp[dummy_head->next];
        //     dummy->random = mp[dummy_head->random];
        //     dummy_head = dummy_head->next;
        // }
        // return ans->next;
        if(!head)return head;
        /* Modified LL */
        Node *ind = head;
        while(ind)
        {
            Node *clone = new Node(ind->val);
            clone->next = ind->next;
            ind->next = clone;
            ind = clone->next; 
        }
        ind = head;
        while(ind)
        {
            ind->next->random = (ind->random)?ind->random->next:nullptr;
            ind = ind->next->next;
        }
        ind = head;
        ind = ind->next;
        Node* new_ind = ind;
        while(head)
        {
            head->next = ind->next;
            head = head->next;
            if(ind->next)
            ind->next = ind->next->next;
            ind = ind->next;
        }
        // while(new_ind)
        // {
        //     cout<<new_ind->val<<" ";
        //     new_ind = new_ind->next;
        // }
        return new_ind;
    }
};
// 7-->13-->11-->10-->1
// 7-->7-->13-->13-->11-->11-->10-->10-->1-->1