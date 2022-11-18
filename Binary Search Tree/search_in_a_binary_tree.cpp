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
 // MY SOLUTION
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        while(temp!=NULL){
            if(temp->val==val){
                return temp;
            }

            if(val>temp->val){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }

        return NULL;
        
    }
};

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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if (root == NULL) {
            return NULL;
        }
        
        if (root->val == val) {
            return root;
        }
        else if(root->val < val) {
            if (root->right == NULL)
                return NULL;
            return searchBST(root->right, val);
        }
        else {
            if(root->left == NULL)
                return NULL;
            return searchBST(root->left, val);
        }
    }
};