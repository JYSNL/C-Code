class Solution {
public:

    int m,n;
    vector<vector<int>> dp;
    int state[4][2]={{-1,0},{1,0},{0,-1},{0,1}};   //иообвСср

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if(dp[i][j])
            return dp[i][j];
        dp[i][j]=1;
        for(auto s:state)
        {
            int y=i+s[0];
            int x=j+s[1];
            if(y>=0 && y<m && x>=0 &&  x<n && matrix[y][x]>matrix[i][j] )
                dp[i][j]=max(dp[i][j],dfs(matrix,y,x)+1);
        }
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        if(m==0)
            return 0;
        n=matrix[0].size();
        if(n==0)
            return 0;
        dp.resize(m,vector<int>(n,0));
        int longest=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=dfs(matrix,i,j);
                longest=max(longest,dp[i][j]);
            }
        }
        return longest;
    }
};

