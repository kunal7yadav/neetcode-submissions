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
int level(TreeNode* root){
    if(root==NULL) return 0 ;
    return 1 + max(level(root->left) , level(root->right));
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lst = level(root->left);
        int rst = level(root->right);
        if(abs(lst-rst)<=1){
           bool  l= isBalanced(root->left);
           bool r = isBalanced(root->right);
           if(!l || !r) return false;
        }
        else if(abs(lst - rst)>1) return false;
        return true;
        
    }
};