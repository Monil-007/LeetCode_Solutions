class Solution {
public:
    string interpret(string command) {
        stack<char> stkk;
        string ans="";
        for(auto i:command){
            stkk.push(i);
        }
        stack<char> stk;
        while(stkk.size()){
            stk.push(stkk.top());
            stkk.pop();
        }
        while(stk.size()){
            char ch=stk.top();
            stk.pop();
            if(ch=='('){
                int cnt=0;
                while(stk.size() && stk.top()!=')'){
                    cnt++;
                    stk.pop();
                }
                if(stk.size()){stk.pop();}
                if(cnt){
                    ans+="al";
                }
                else{
                    ans+="o";
                }
            }
            else{
                ans+="G";
            }
        }
        return ans;
    }
};