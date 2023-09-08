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
    vector<int> preorderTraversal(TreeNode* root) {
//         //TreeNode* root;
//     stack<TreeNode*> stk;
//     stk.push(root);
//     vector<int> pre;
//     pre.push_back(root);
    
//     while(stk.size()){
//         while(root){
//             pre.push_back(root->val);
//             stk.push(root);
//             root=root->left;
//         }
//         TreeNode* t=stk.top();
//         stk.pop();
//         root=t->right;   
//     }
//     return pre;
//     }
    vector<int> pre;
    if(!root){return pre;}
    stack<TreeNode*> stk;
    
    bool fg=true;
    while(fg || root || stk.size()){
        fg=false;
        while(root){
            pre.push_back(root->val);
            stk.push(root);
            root=root->left;
        }
        TreeNode* t=stk.top();
        stk.pop();
        root=t->right;
        
    }
return pre;
}
};