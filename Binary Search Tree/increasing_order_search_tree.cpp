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

    TreeNode* increasingOrder(TreeNode* root,vector<int> &a){
        inorder(root,a);
        TreeNode* firstNode = new TreeNode(a[0]);
        TreeNode* temp = firstNode;
        cout<<firstNode->val;
        for(int i=1;i<a.size();i++){
            TreeNode* currNode = new TreeNode(a[i]);
            // cout<<currNode->val<<endl;
            temp->left = NULL;
            temp->right = currNode;
            temp = currNode;
        }

        return firstNode;
    }    

public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        // inorder(root,ans);
        return increasingOrder(root,ans);
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
        TreeNode*head=new TreeNode();
        TreeNode*it=head;
        void inorder(TreeNode*root){
                if(root==NULL)return;
                inorder(root->left);
                it->right=new TreeNode(root->val);
                it=it->right;
                inorder(root->right);
        }
    TreeNode* increasingBST(TreeNode* root) {
     inorder(root);
            return head->right;
            
    }
};