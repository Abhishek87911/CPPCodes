//leetcode 2801
class Solution {
public:
    int mod=1e9+7;
    int dp[101][2][2][11];
    int fn(int i,int start,int tight,string &s,int prev)
    {
        if(i>=s.size()) return start==1;
        int upper = (tight?s[i]-'0':9);
        int ans=0;
        if(dp[i][start][tight][prev+1]!=-1) return dp[i][start][tight][prev+1];
        if(start==0){
            ans=fn(i+1,0,0,s,-1)%mod;
        }
        for(int d=0;d<=upper;d++)
        {
            if(d==0 and start==0) continue;
            if(prev!=-1 and abs(d-prev)!=1) continue;
            int new_tight = (tight?(d==upper):0);
            ans=(ans+fn(i+1,1,new_tight,s,d))%mod;
        }
        return dp[i][start][tight][prev+1]=ans;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        int  l =  fn(0,0,1,low,-1);
        memset(dp,-1,sizeof(dp));
        int  h =  fn(0,0,1,high,-1);
        int r=1;
        for(int i=1;i<low.size();i++){
            if(abs(low[i]-low[i-1])!=1) {
                r=0;
                break;
            }
        }
        
        return ((h-l+mod)+r)%mod;

    }
};