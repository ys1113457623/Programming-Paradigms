class Solution {
   public:
      int height(TreeNode* root,int &flag){
         if(root==NULL)
           return flag;
         int x=height(root->left,flag)+1;
         int y=height(root->right,flag)+1;
    
         if(abs(x-y) >1)
            flag=1;
         
         return max(x,y);
     }


    bool isBalanced(TreeNode* root) {
        if(root==NULL)
           return 1;
       
        int flag=0;
        int x=height(root->left,flag);
         
        if(flag)
          return 0;
    
        flag=0;
        int y=height(root->right,flag);
        
        if(flag)
          return 0;

        if(abs(x-y)>1)
           return 0;
        
       return 1;
    }
};