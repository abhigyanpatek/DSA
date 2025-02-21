class Solution {
  public:
      int maxArea(vector<int>& height) {
          int left = 0, right = height.size()-1, area = 0;
          while(left < right){
              int h1 = height[left];
              int h2 = height[right];
              area = max(area, (right-left)*min(h1, h2));
              if(h1 < h2){
                  left++;
              }else{
                  right--;
              }
          }
          return area;
      }
  };