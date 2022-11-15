/**
 * My Solution
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
private:
    void inorder(TreeNode* root,vector<int> &a){
        if(root==NULL){
            return;
        }
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    // vector<int> InorderTraversal(TreeNode* root){
    //     vector<int> ans;
    //     inorder(root,ans);

    //     return ans;
    // }
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int> ans;
        inorder(root,ans);

        for(int i=0;i<ans.size()-1;i++){
            // cout<<ans[i]<<" "<<ans[i+1]<<endl;
            if(ans[i]>=ans[i+1]){
                return false;
                break;
            }
        }

        return true;

    }
};

/*
    Optimal Solution
*/