/*
Approach - Maintain elements in a stack and remove less or equal elements as we move
then we update max element as top() if non-empty stack or as -1 if empty stack
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;

        int len = nums2.size()-1;
        for (int i=len;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if (st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        for (int &x: nums1) x = mpp[x];
        return nums1;
    }
};