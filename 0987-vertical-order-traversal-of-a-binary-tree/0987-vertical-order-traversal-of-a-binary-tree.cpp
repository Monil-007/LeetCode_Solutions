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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){return ans;}
        queue<pair<int,TreeNode*>> q;
        
        map<int,vector<int>> mp;
        q.push({0,root});
        while(q.size()>0){
            int cnt=q.size();
            map<int,multiset<int>> srt;
            for(int i=0;i<cnt;i++){
                TreeNode* node=q.front().second;
                int currLevel=q.front().first;
                srt[currLevel].insert(node->val);
                q.pop();
                if(node->left){
                    q.push({currLevel-1,node->left});
                }
                if(node->right){
                    q.push({currLevel+1,node->right});
                }
            }
            for(auto it:srt){
                int l=it.first;
                for(auto i:it.second){
                    mp[l].push_back(i);
                }
            }
        }
        for(auto it:mp){
            vector<int> temp=it.second;
            //for(auto i:it.second){temp.push_back(i);}
            ans.push_back(temp);
        }
        return ans;
    }
};