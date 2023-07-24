class Solution {
public:
    int minFlips(int a, int b, int c) {
        string sa=bitset<32>(a).to_string();
        string sb=bitset<32>(b).to_string();
        string sc=bitset<32>(c).to_string();
        int cnt=0;
        for(int i=0;i<sc.length();i++){
            if(sc[i]=='0'){
                if(sa[i]=='1'){cnt++;}
                if(sb[i]=='1'){cnt++;}
            }
            else{
                if(sa[i]=='0' && sb[i]=='0'){cnt++;}
            }
        }
        return cnt;
    }
};