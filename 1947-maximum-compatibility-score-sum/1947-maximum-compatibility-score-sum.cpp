class Solution {
public:
    int scr(vector<int> sans,vector<int> mans){
        int cr=0;
        for(int i=0;i<sans.size();i++){
            if(sans[i]==mans[i]){cr++;}
        }
        return cr;
    }
    int slv(int ind,vector<vector<int>> &students,vector<vector<int>> &mentors,vector<int> &vis){
        if(ind==students.size()){
            return 0;
        }
        int trl=0;
        for(int i=0;i<mentors.size();i++){
            if(!vis[i]){
                vis[i]=1;
                trl=max(trl,scr(students[ind],mentors[i])+slv(ind+1,students,mentors,vis));
                vis[i]=0;
            }
        }
        return trl;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> vis(mentors.size());
        return slv(0,students,mentors,vis);
    }
};