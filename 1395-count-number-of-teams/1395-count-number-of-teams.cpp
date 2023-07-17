class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;
        for(int j=0;j<n;j++){
            int leftSmall=0,leftLarge=0,rightSmall=0,rightLarge=0;
            for(int i=0;i<j;i++){
                if(rating[j]<rating[i]){leftLarge++;}
                if(rating[j]>rating[i]){leftSmall++;}
            }
            for(int i=j+1;i<n;i++){
                if(rating[j]<rating[i]){rightLarge++;}
                if(rating[j]>rating[i]){rightSmall++;}
            }
            ans+=leftSmall*rightLarge+rightSmall*leftLarge;
        }
        return ans;
    }
};