class Solution {
public:
    void inorderhelp(TreeNode* root, vector<int>& x){
        
        if(root == NULL){
            return;
        }
        inorderhelp(root->left, x);  //left subtree
        x.push_back(root->val);      //pushing value of root to ans
        inorderhelp(root->right, x); //right subtree
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> x;
        inorderhelp(root, x);
        return x;
    }
};