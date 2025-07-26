// Approach - 1(brute force)
// T.C -> o(n^2)
// S.C -> o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]== target){
                    return {i,j};
                } 
            }
        }
        return {};  
    }
};

// Approach- 2(by using map)
// T.C -> o(n)
// S.C -> o(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int remain = target - nums[i];
            if(mp.find(remain)!=mp.end()){
                return {mp[remain],i}; // return map value(index) and current index
            }
            mp[nums[i]]=i; // key(number and value(index) pushing in map
        }
        return {}; // since the function return vector<int> so we have to return here something or might be an empty vector
    }
};
