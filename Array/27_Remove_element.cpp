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

        while(i>=0 && nums[i]==val) i--;
        return i+1;
    }
};