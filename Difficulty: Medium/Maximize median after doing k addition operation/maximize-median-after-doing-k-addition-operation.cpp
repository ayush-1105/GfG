class Solution {
  public:
    bool possible(vector<int>& arr, int mid, int pos, int k) {
        long long operations = 0;
        for (int i = pos; i < arr.size(); i++) {
            if (arr[i] < mid) 
                operations += (mid - arr[i]);
            if (operations > k) return false; // early stop
        }
        return true;
    }

    int maximizeMedian(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // median position (lower median if even size)
        int pos = (n & 1) ? n/2 : n/2 - 1;

        long long low = arr[pos];
        long long high = arr[pos] + k;
        long long ans = low;

        // binary search maximum possible median
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (possible(arr, mid, pos, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // if odd length, just return median
        if (n & 1) return ans;

        // if even, median is average of two middle values
        if (ans <= arr[pos + 1]) 
            return (ans + arr[pos + 1]) / 2;
        return ans;
    }
};