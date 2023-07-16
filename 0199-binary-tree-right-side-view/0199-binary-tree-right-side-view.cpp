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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){return ans;}
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        //ans.push_back(root->val);
        while(q.size()){
            int cnt=q.size();
            for(int i=0;i<cnt;i++){
                TreeNode* node=q.front().second;
                int lvl=q.front().first;
                q.pop();
                if(i==cnt-1){
                    ans.push_back(node->val);
                }
                if(node->left){q.push({lvl-1,node->left});}
                if(node->right){q.push({lvl+1,node->right});}
            }
        }
        return ans;
    }
};