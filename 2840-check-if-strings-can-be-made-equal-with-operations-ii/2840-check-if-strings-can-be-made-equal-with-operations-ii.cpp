class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string ev1="",ev2="",od1="",od2="";
        for(int i=0;i<s1.size();i++){
            if(i%2==0){ev1+=s1[i];ev2+=s2[i];}
            else{od1+=s1[i];od2+=s2[i];}
        }
        sort(ev1.begin(),ev1.end());
        sort(ev2.begin(),ev2.end());
        sort(od1.begin(),od1.end());
        sort(od2.begin(),od2.end());
        if(ev1==ev2 && od1==od2){return true;}
        return false;
    }
};