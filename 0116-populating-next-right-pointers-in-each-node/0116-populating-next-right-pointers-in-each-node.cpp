/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // BFS
        // Node *dummy = root;
        // queue<Node *>q;
        // if(root)
        // q.push(root);
        // Node *prev= nullptr;
        // while(!q.empty())
        // {
        //     int size = q.size();
        //     for(int i=0;i<size;++i)
        //     {
        //         Node *curr = q.front();
        //         q.pop();
        //         if(i)
        //         {
        //             prev->next = curr;
        //         }
        //         prev = curr;
        //         if(curr->left)
        //         {
        //             q.push(curr->left);
        //         }
        //         if(curr->right)
        //         {
        //             q.push(curr->right);
        //         }
        //     }
        //     prev->next = nullptr;
        // }
        // return dummy;

        // DFS 
        if(root==nullptr)return root;
        Node *leftmost = root;
        while(leftmost->left!=nullptr)
        {
            Node *head = leftmost;
            while(head!=nullptr)
            {
                head->left->next = head->right; // Simple Connection
                if(head->next)
                head->right->next = head->next->left; // Connection between diff parent nodes
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};