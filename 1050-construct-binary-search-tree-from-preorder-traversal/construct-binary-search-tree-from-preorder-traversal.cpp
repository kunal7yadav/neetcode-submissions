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
TreeNode* build(vector<int>&pre , int prelo , int prehi , vector<int>&in , int inlo , int inhi){
    if(prelo>prehi) return NULL;
    TreeNode* root = new TreeNode(pre[prelo]);
    if(prelo==prehi) return root;
    int i = inlo; 
    while(i<=inhi){
        if(in[i]==pre[prelo]) break;
        i++;
    }
    int leftCount = i - inlo;
    int rightCount = inhi - i ;
    root->left = build(pre , prelo+1 , prelo+leftCount , in , inlo , i-1);
    root->right = build(pre , prelo+leftCount+1 , prehi , in , i+1 , inhi);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int>inorder(n); 
        for(int i = 0 ; i<n ; i++ ){
            inorder[i] = preorder[i];
        }
        sort(inorder.begin() , inorder.end());
        return build(preorder , 0 , n-1 , inorder , 0 , n-1);
        
    }
};