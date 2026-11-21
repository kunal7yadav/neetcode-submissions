class Solution {
public:
bool symmetric(TreeNode* p , TreeNode* q){
    if(p==NULL && q==NULL) return true;
    else if(p==NULL || q==NULL) return false;
    else if(p->val!=q->val) return false;
    bool lst = symmetric(p->left , q->right);
    if(lst==false) return false;
    bool rst = symmetric(p->right , q->left);
    if(rst==false) return false;
    return true;
}
    bool isSymmetric(TreeNode* root) {
        TreeNode*p = root->left;
        TreeNode*q = root->right;
        return symmetric(p , q);
        
    }
};