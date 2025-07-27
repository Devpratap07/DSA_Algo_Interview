// Approach -> 1
// T.C -> O(n^2)
// S.C -> O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closestSum=nums[0]+nums[1]+nums[2];
        sort(begin(nums),end(nums));
        for(int k=0;k<=n-3;k++){
            int i=k+1;
            int j=n-1;
            while(i<j){
                int sum=nums[k] +nums[i]+nums[j];
                if(abs(target-sum)<abs(target-closestSum)){
                    closestSum=sum;
                }
                if(sum<target){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return closestSum;
    }
};
