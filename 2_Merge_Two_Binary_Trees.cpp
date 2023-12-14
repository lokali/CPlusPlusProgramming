/**
Input: 
    Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
         3
        / \
       4   5
      / \   \ 
     5   4   7

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2==NULL) return NULL;
        if(t1==NULL) return t2;
        if(t2==NULL) return t1;
        
        TreeNode* root = new TreeNode(0);
        TreeNode* left;
        TreeNode* right;
        
        root->val = t1->val + t2->val;
        left = mergeTrees(t1->left, t2->left);
        right = mergeTrees(t1->right, t2->right);
        
        root->left = left;
        root->right = right;
        return root;
    }
};