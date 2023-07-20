class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> orig;
        int n=encoded.size();
        orig.push_back(first);
        int prev=0;
        for(int i=0;i<n;i++){
            orig.push_back(orig[prev]^encoded[i]);
            prev++;
        }
        return orig;
    }
};