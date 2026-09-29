class Solution {
public:
    bool isP(string s){
        string t=s;
        reverse(s.begin(),s.end());
        return s==t;
    }
    int ans=1;
    int l1=0,r1=0;
    string longestPalindrome(string s) {
    int n=s.size();
        for(int i=0;i<s.size();i++){
            int j=i;
            int l=j-1,r=j+1;
            int k=0;
            while(l>=0&&r<n&&s[l]==s[r]){k++;l--;r++;}
            l++;
            r--;
            if(ans<(2*k+1)){
                ans=2*k+1;
                l1=l;
                r1=r;
            }
        }
        for(int i=0;i<s.size()-1;i++){
            int l=i;
            int r=i+1;
            int k=0;
            while(l>=0&&r<n&&s[r]==s[l]){k++;l--;r++;}
            l++;
            r--;
             if(ans<(2*k)){
                ans=2*k;
                l1=l;
                r1=r;
            }
        }
        cout<<ans<<" "<<l1<<" "<<r1;
        string res="";
        for(int i=l1;i<=r1;i++)res+=s[i];
        return res;
    }
};
