/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int mxheight(TreeNode *root)
    {
        if(root==nullptr)return 0;
        int l = mxheight(root->left);
        int r = mxheight(root->right);
        if(abs(l-r)>1)return -1;
        if(l==-1 || r==-1)return -1;
        return 1+max(l,r);
    }
    // int mnheight(TreeNode *root)
    // {
    //     if(root==nullptr)return 0;
    //     return 1+max(mnheight(root->left),mnheight(root->right));
    // }
    // bool dfs(TreeNode *root)
    // {
    //     if(root==nullptr)return true;
    //    int rmn = mnheight(root->right);
    //     int rmx = mxheight(root->right);
    //    int lmn = mnheight(root->left);
    //     int lmx = mxheight(root->left);
    //     if(abs(lmx-rmx)>1)return false;
    //    if(abs(lmn-rmx)>1)return false;
    //     return dfs(root->left) && dfs(root->right);
    // }
public:
    bool isBalanced(TreeNode* root) {
        int h = mxheight(root);
        return h==-1?false:true;
        // return dfs(root);
    }
};