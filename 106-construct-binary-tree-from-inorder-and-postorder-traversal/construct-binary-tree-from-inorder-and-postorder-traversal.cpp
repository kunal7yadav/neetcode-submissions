class Solution {
public:
TreeNode* build(vector<int>&in , int inlo , int inhi , vector<int>&pos , int poslo , int poshi){
    if(inlo>inhi) return NULL;
    TreeNode* root = new TreeNode(pos[poshi]);
    if(poslo==poshi) return root;
    int i = inlo ; 
    while(i<=inhi){
        if(in[i]==pos[poshi]) break;
        i++;
    }
    int leftCount = i - inlo ; 
    int rightCount = inhi - i ;
    root->left = build(in , inlo , i-1 , pos ,poslo, poslo+leftCount-1);
    root->right = build(in , i+1 , inhi , pos , poslo+leftCount , poshi-1);
    return root;
}
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        int n = pos.size();
        return build(in , 0 , n-1 , pos , 0 , n-1);
    }
};