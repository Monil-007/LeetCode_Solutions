class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& a) 
    {
        int d,b;
        vector<int>c; 
        int n=a.size();
        for (int i=0;i<n-1;i++)
        {
            d=abs(a[i][0]-a[i+1][0]);
            b=abs(a[i][1]-a[i+1][1]);
            if (d>b)
            {
                c.push_back(d);
            }
            else
            {
                c.push_back(b);
            }
        } 
        int sui=0;
        for (int i=0;i<c.size();i++)
        {
            sui+=c[i];
        }
        return sui;
    }
};