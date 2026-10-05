class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length()==0&&word2.length()==0)return 0;
        if(word1.length()==0&&word2.length()!=0)return word2.length();
        if(word1.length()!=0&&word2.length()==0)return word1.length();
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        dp[0][0]=word1[0]==word2[0]?0:1;
        for(int j=1;j<word2.length();j++){
            if(word1[0]==word2[j])  dp[0][j]=dp[0][j-1];
            else
            dp[0][j]=dp[0][j-1]+1;
        }
        for(int j=1;j<word1.length();j++){
            if(word1[j]==word2[0])  dp[j][0]=dp[j-1][0];
            else dp[j][0]=dp[j-1][0]+1;
        }
        for(int i=1;i<word1.length();i++){
            for(int j=1;j<word2.length();j++){
                if(word1[i]==word2[j]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min({dp[i][j-1]+1,dp[i-1][j-1]+1,dp[i-1][j]+1});
                }
            }
        }
        return dp[word1.length()-1][word2.length()-1];
    }
};
