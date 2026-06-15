/*
Brute force approach - For every variation of subarray calculate them inimum element and calculate sum

we start the subarray from i and update mini for every next element and reset mini when we update i
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int size = arr.size();
        long long sum = 0;
        for (int i=0;i<size;i++){
            int mini = INT_MAX;
            for (int j=i;j<size;j++){
                mini = min(mini, arr[j]);
                sum+=mini;
            }
        }

        return sum%MOD;
    }
};

/*
Better Approach


*/