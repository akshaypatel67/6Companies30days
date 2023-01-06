class Solution {
public:
    long long merge(vector<int>& arr, long long l, long long r, long long mid, int& diff) {
        long long count = 0;
        long long n = mid-l+1, m = r-mid;
        long long arr1[n];
        long long arr2[m];
        
        for(long long i=0;i<n;i++) arr1[i]=arr[l+i];
        for(long long i=0;i<m;i++) arr2[i]=arr[mid+1+i];

        int ind = 0;
        for(int i=0; i<n; i++) {
            while(ind < m && arr1[i] > arr2[ind] + diff) ind++;
            count += m - ind;
        }
        
        int i=0, j=0, k=l;
        while(i<n && j<m) {
            if(arr1[i]<=arr2[j]) {
                arr[k] = arr1[i];
                i++;
            } else if(arr1[i]>arr2[j]) {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }
        while(i<n) {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        while(j<m) {
            arr[k] = arr2[j];
            j++;
            k++;
        }

        return count;
    }

    long long mergeSort(vector<int>& arr, long long l, long long r, int& diff) {
        long long ans = 0;
        if(l<r) {
            long long mid = l+(r-l)/2;
            ans += mergeSort(arr, l, mid, diff);
            ans += mergeSort(arr, mid+1, r, diff);
            ans += merge(arr, l, r, mid, diff);
        }
        return ans;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> numsdiff(nums1.size());

        for(int i=0; i<nums1.size(); i++) numsdiff[i] = nums1[i] - nums2[i];

        return mergeSort(numsdiff, 0, nums1.size()-1, diff);
    }
};