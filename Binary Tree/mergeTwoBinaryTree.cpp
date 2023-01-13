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

 //MY SOLUTION

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;

        TreeNode* final = new TreeNode(root1->val+root2->val);
        final->left = mergeTrees(root1->left,root2->left);
        final->right = mergeTrees(root1->right,root2->right);

        return final;
    }
};


//OPTIMIZED SOLUTION
