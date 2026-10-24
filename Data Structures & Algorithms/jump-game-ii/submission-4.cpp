class Solution {
public:
    int jump(vector<int>& nums) {
        priority_queue<int>pq;
        
        int i=0,ans=0;
         if(i>=nums.size()-1) return 0;
        pq.push(nums[0]);
        i++;
        while(true){
           
            int res=pq.top();
            cout<<res<<endl;
            pq.pop();
            ans++;
            int j=res;
           if(j>=nums.size()-1) return ans;
            while(i<=min((int)nums.size()-1,j)){
                if((i+nums[i])>=nums.size()-1) return ans+1;
                pq.push(nums[i]+i);
                i++;
            }
        }
        return 0;
    }
};
