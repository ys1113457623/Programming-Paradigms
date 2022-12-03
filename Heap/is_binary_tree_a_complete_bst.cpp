/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
*/

//My Solution

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
private:
    int countNode(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int ans = 1 + countNode(root->left) + countNode(root->right);

        return ans;
    }
    bool isCBT(TreeNode* root,int index,int cnt){
        if(root==NULL){
            return true;
        }
        if(index >= cnt){
            return false;
        }
        else{
            bool left = isCBT(root->left,2*index+1,cnt);
            bool right = isCBT(root->right,2*index+2,cnt);
            return (left&&right);
        }
    }    
public:
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int totalCount = countNode(root);
        return isCBT(root,index,totalCount);
    }
};


//Optimal solution

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
    bool isCompleteTree(TreeNode* root) {
        // vector<vector<int>> ans;
        if(!root)   return false;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* prev = root;

        while(!q.empty()){
            int levelSize = q.size();
            // vector<int> level(levelSize);
            bool flag = false;
            for(int i=0;i<levelSize;i++){
                TreeNode* curr = q.front(); q.pop();

                if(curr){
                    if(!prev)   return false;
                    
                    // no checking if null or not, directly add to queue
                    q.push(curr->left);
                    q.push(curr->right);
                }
                prev = curr;
            }
        }
        return true;
    }
};