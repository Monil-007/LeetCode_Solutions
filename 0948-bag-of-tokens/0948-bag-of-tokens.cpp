class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        sort(tokens.begin(),tokens.end());
        int i=0,res=0,n=tokens.size(),j=n-1;
        while(j>=i){
            if(power>=tokens[i]){
                score++;
                res=max(res,score);
                power-=tokens[i++];
            }
            else{
                if(score<=0){break;}
                score--;
                power+=tokens[j--];
            }
        }
        return res;
    }
};