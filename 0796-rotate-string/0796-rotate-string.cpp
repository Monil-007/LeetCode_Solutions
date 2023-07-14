class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=goal.size();
        if(s.size()!=n){return false;}
        int gInd;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(goal[i]==s[0]){v.push_back(i);}
        }
        int sInd=0,ind=0;
        int sz=v.size(),fg=00;
        while(ind<sz){
            gInd=v[ind];sInd=0;
            cout<<gInd<<" "<<v.size()<<endl;
            while(sInd<n){
                if(s[sInd]!=goal[gInd]){fg++;break;}
                sInd++;
                gInd=(gInd+1)%n;
            }
            ind++;
        }
        cout<<fg<<endl;
        return fg==sz?false:true;
    }
};