class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        int n=firstList.size();
        int m = secondList.size();
        if( n==0 || m==0 )
        {
            return ans;
        }
        int i=0 , j=0;
        while( true )
        {
            vector<int>v;
            if( i==n || j==m )
            {
                return ans;
            }
            if( firstList[i][1]<secondList[j][0] )
            {
                i++;
            }
            else if( firstList[i][0]>secondList[j][1] )
            {
                j++;
            }
            else
            {
                v.push_back( max( firstList[i][0] , secondList[j][0] ) );
                v.push_back( min( firstList[i][1] , secondList[j][1] ) );
                if( firstList[i][1]>secondList[j][1] )
                {
                    j++;
                }
                else
                {
                    i++;
                }
                ans.push_back( v );
                v.clear();
            }
        }
        return ans;
    }
};