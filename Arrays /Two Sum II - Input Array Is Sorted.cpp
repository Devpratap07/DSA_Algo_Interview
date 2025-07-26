// Approach - 1(input already sorted)
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order.
// that's why we are returning {i+1 , j+1}
// T.C -> o(n)
// S.C -> o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            if(numbers[i]+numbers[j] == target){
                return {i+1,j+1};
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
        }
        return {}; // the function is return the vector<int> so, we have to return the something as vector at the end.
    }
};
