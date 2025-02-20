class Solution {
  public:
      double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
          if(arr1.size() > arr2.size()){
              return findMedianSortedArrays(arr2, arr1);
          }
          int total = arr1.size()+arr2.size();
          int half = (total+1)/2, low = 0, high = arr1.size();
          while(low <= high) {
              int mid = (low+high)/2;
              int rem = half-mid;
              
              int L1 = mid == 0? INT_MIN : arr1[mid-1];
              int L2 = rem == 0? INT_MIN: arr2[rem-1];
              int R1 = mid == arr1.size()? INT_MAX: arr1[mid];
              int R2 = rem == arr2.size()? INT_MAX: arr2[rem];
              
              if(L1 <= R2 && L2 <= R1){
                  if(total&1) return max(L1,L2);
                  else return (max(L1, L2) + min(R1, R2))/2.0;
              }
              else if(L2 > R1) low = mid+1;
              else high = mid-1;
          }
          return 0.0;
      }
  };