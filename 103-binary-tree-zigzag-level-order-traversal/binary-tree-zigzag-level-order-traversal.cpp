class Solution {
public:
int level(TreeNode*root){
    if(root==NULL) return 0 ;
    return 1+max(level(root->left) , level(root->right));
}
void leftprint(TreeNode*root , int curr , int level , vector<int>&ans){
    if(root==NULL) return ; 
    if(curr==level){
        ans.push_back(root->val);
        return;
    }
    leftprint(root->left ,  curr+1 ,level , ans);
    leftprint(root->right , curr+1 , level , ans);
}
void rightprint(TreeNode*root , int curr , int level , vector<int>&ans){
    if(root==NULL) return ; 
    if(curr==level){
        ans.push_back(root->val);
        return;
    }
    rightprint(root->right ,  curr+1 ,level , ans);
    rightprint(root->left , curr+1 , level , ans);
}
void levelOrder(TreeNode*root , vector<vector<int>>&finalans){
    int n = level(root);
    for(int i = 1 ; i<=n ; i++){
        if(i%2==0){
            vector<int>ans;
            rightprint(root , 1 , i , ans);
            finalans.push_back(ans);
        }
        else{
            vector<int>ans;
            leftprint(root , 1 , i , ans);
            finalans.push_back(ans);
        }
    }

}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>finalans;
        levelOrder(root , finalans);
        return finalans;
    }
};