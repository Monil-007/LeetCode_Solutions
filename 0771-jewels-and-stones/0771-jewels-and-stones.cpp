class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;
        for(auto i:jewels){
            mp[i]++;
        }
        int rs=0;
        for(auto i:stones){
            if(mp[i]){rs++;}
        }
        return rs;
    }
};