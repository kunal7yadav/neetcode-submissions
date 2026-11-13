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
int level(TreeNode*root){
    if(root==NULL) return 0 ;
    return 1 + max(level(root->left) , level(root->right));
}
void nthlevel(TreeNode*root , int curr , int level , vector<int>&ans){
    if(root==NULL) return ; 
    if(curr==level){
        ans.push_back(root->val);
        return;
    }
    nthlevel(root->left ,  curr+1 ,level , ans);
    nthlevel(root->right , curr+1 , level , ans);
}
void levelorder(TreeNode*root ,vector<vector<int>>&finalans){
    int n = level(root);
    for(int i = 1 ; i<=n ; i++){
        vector<int>ans;
        nthlevel(root , 1 , i , ans);
        finalans.push_back(ans);
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalans;
        levelorder(root ,finalans);
        return finalans; 
    }
};