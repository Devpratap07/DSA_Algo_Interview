// Approah -> 1

//1. Sort the array(because we want to return the element not the index).
//2. Fix one number nums[i] (loop over i), and then
//3. Use two pointers (l, r) to find pairs that sum to -nums[i].
//4. Skip duplicates for both the fixed element and the moving pointers to ensure uniqueness.

// T.C -> O(n^2)
// S.C -> O(1)

// The twosum function is not designed to return just one number or any single value — it is finding all pairs for a given target.
// If we return int or vector<int>, we could only return one pair at a time (or we'd need multiple calls), which is inefficient.
  
class Solution {
public:
   vector<vector<int>>  result;

   void twosum(vector<int> &nums , int target , int i , int j){
    while(i<j){
        if(nums[i] + nums[j] > target){
            j--;
        }
        else if(nums[i] + nums[j] < target){
            i++;
        }
        else{
          result.push_back({-target,nums[i],nums[j]});
            while(i<j && nums[i]==nums[i+1]){
                i++;
            }
            while(i<j && nums[j] ==nums[j-1]){
                j--;
            }
            i++;
            j--;
        }
    }
   }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3){ 
            return {};
        }
        result.clear();  
      // Make sure result is empty for this run.
      
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int n1=nums[i];
            int target=-n1;
            twosum(nums,target,i+1,n-1); 
// Since result is accessible directly inside twosum (as it's a member of the class), 
// there's no need for twosum to return anything. It simply modifies result in place.
        }
        return result;
    }
};
