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
    int countNodes(TreeNode* root) {
        if(!root){return 0;}
        TreeNode* curr=root;
        int lr=0;
        while(curr){
            curr=curr->left;
            lr++;
        }
        int rg=0;
        curr=root;
        while(curr){
            curr=curr->right;
            rg++;
        }
        if(lr==rg){
            return pow(2,lr)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};