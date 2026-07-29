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
public:
    bool issameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) return p == q;
        
        if(p->val != q->val)return 0;

        bool lefttree = issameTree(p->left , q->left);
        bool righttree = issameTree(p->right , q->right);

        return (lefttree && righttree);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(root == NULL) return 0; 
       bool ans = false;
        
        if(root->val == subRoot->val){
         ans = issameTree(root , subRoot);
        }
        if(ans == true) return ans;
        
        bool left = isSubtree( root->left, subRoot);
        bool right = isSubtree( root->right, subRoot);

        return left || right;
    }
};