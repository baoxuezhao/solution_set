class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        root->next =  NULL;
        
        TreeLinkNode *nextFirst = NULL;
        TreeLinkNode *cur = root;
        
        while(cur)
        {
            TreeLinkNode *nextCur = NULL;
            nextFirst = NULL;
            while(cur)
            {
                if(!nextFirst)
                    nextFirst = cur->left;
                if(!nextFirst)
                    nextFirst = cur->right;
                    
                if(cur->left)
                {
                    if(nextCur) nextCur->next = cur->left;
                    nextCur = cur->left;
                }
                
                if(cur->right)
                {
                    if(nextCur) nextCur->next = cur->right;
                    nextCur = cur->right;   
                }
                cur = cur->next;
            }
            cur = nextFirst;
        }
    }
};
