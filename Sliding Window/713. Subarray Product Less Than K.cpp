/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
 var numSubarrayProductLessThanK = function(nums, k) {
  if(k <= 1) return 0;
  let prod = 1, ans = 0;
  for(let start = 0, end = 0; end < nums.length; end++){
      prod *= nums[end];
      
      while(prod >= k){
          prod /= nums[start++];
      }
      ans += end-start+1;
  }
  return ans;
};