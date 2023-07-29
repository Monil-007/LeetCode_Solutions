class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            vector<int> v=image[i];
            int i1=0,j=v.size()-1;
            while(i1<=j){
                
                int t=v[i1];
                v[i1]=v[j];
                v[j]=t;
                if(i1==j){v[i1]=!v[i1];}
                else{
                  v[i1]=!v[i1];
                v[j]=!v[j];   
                }
                i1++;j--;
            }
            // reverse(v.begin(),v.end());
            // for(int j=0;j<v.size();j++){
            //     v[j]=!v[j];
            // }
            image[i]=v;
        }
        return image;
    }
};