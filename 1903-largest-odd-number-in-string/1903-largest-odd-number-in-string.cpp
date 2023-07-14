class Solution {
public:
    bool isOdd(char c){
        int x=c;
        return x%2!=0?true:false;
    }
    string largestOddNumber(string num) {
        int i=num.length(),n=i;
        i--;
        while(i>=0 && !isOdd(num[i])){
            i--;
        }
        if(i>=0){
            return num.substr(0,i+1);
        }
        return "";
    }
};