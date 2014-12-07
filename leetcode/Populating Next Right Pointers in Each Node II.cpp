/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        root->next = NULL;
        TreeLinkNode *cur = root;
        while(cur != NULL)
        {
            TreeLinkNode *nextFirst = NULL;
            TreeLinkNode *nextCur = NULL;
            while(cur != NULL)
            {
                if(nextFirst == NULL)
                    nextFirst = cur->left;
                if(nextFirst == NULL)
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
