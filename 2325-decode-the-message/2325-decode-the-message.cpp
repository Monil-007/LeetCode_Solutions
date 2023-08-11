class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> hash(26);
        unordered_map<char,char> mp;
        int cnt=96;
        for(auto i:key){
            if(i==' '){continue;}
            if(hash[i-'a']){continue;}
            cnt++;
            hash[i-'a']=1;
           // int asc=i-'a';
            char td=cnt;
            mp[i]=td;
        }
        mp[' ']=' ';
        string res=""; 
        for(auto i:message){
            res+=mp[i];
        }
        return res;
    }
};