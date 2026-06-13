/*
Approach - Maintian two pointers and do a swap if i encounters val otherwise move i++

In the end check if nums[i] is equal to val, if yes then return i else return i+1

i is index in code but represents size of the result list
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if (size==0) return 0;
        int i = 0, j = size-1;

        while(i<j){
            if (nums[i]==val){
                swap(nums[i], nums[j]);
                j--;
            }
            else{
                i++;
            }
        }

        return (nums[i]==val) ? i : i+1;
    }
};