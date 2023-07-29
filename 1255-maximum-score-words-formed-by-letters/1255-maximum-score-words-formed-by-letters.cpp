class Solution {
public:
    int chk(string s,unordered_map<char,int> &mp,vector<int> &score){
        int cnt=0;
        int sum=0;
        for(auto i:s){
            if(mp[i]){
                mp[i]--;
                cnt++;
                sum+=score[i-97];
            }
        }
        if(cnt==s.size()){return sum;}
        return -1;
    }
    int slv(int ind,unordered_map<char,int> &mp,vector<string> &words,vector<int> &score,int &res){
        if(ind>=words.size()){return 0;}
        //if(mdp[ind][sm]!=-1){return mdp[ind][sm];}
        int notTake=slv(ind+1,mp,words,score,res);
        int take=0;
        unordered_map<char,int> mp2=mp;
        int val=chk(words[ind],mp2,score);
        if(val!=-1){
            take=val+slv(ind+1,mp2,words,score,res);
        }
        //res=max(res,max(notTake,take));
        return max(notTake,take);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        int maxSum=0;
        unordered_map<char,int> freq;
        for(auto i:letters){
            freq[i]++;
            maxSum+=score[i-97];
        }
        vector<vector<int>> mdp(n,vector<int> (maxSum+1,-1));
        int res=0;
        return slv(0,freq,words,score,res);
        // for(int i=0;i<n;i++){
        //     cout<<mdp[i]<<" ";
        // }
        // cout<<endl;
        // cout<<t<<"-"<<res<<endl;
        // return res;
    }
};