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
 * MY SOLUTION
 */
class Solution {
private:
    void inorder(TreeNode* root,vector<int> &a){
        if(root==NULL){
            return;
        }

        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }    
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int mi = INT_MAX;
        for(int i=ans.size()-1;i>0;i--){
            mi = min(mi,ans[i]-ans[i-1]);
        }

        return mi;
    }
};


//OPTIMAL SOLUTION

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
    int res = INT_MAX, pre = -1;
    int minDiffInBST(TreeNode* root) {
        if (root->left != NULL) minDiffInBST(root->left);
        if (pre >= 0) res = min(res, root->val - pre);
        pre = root->val;
        if (root->right != NULL) minDiffInBST(root->right);
        return res;
    }
};