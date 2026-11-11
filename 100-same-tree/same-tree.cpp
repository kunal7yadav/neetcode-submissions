class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) return false;
        
        bool LSTans = isSameTree(p->left  , q->left);
        if(LSTans==false) return false ;
        
        bool RSTans = isSameTree(p->right , q->right);
        if(RSTans==false) return false;

        return true;
    }
};