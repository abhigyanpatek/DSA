class Solution {
  public:
      int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
          int n = energy.size(), ans = 0;
          int totalEnergy = 0;
          int exp = initialExperience, beforeTrainingExp = initialExperience;
          for(int i = 0; i < n; i++){
              //sum of energy
              totalEnergy += energy[i]; 
              
              //to calculate minimum experience which is being updated in initialExperience
              if(exp <= experience[i]){
                  initialExperience += experience[i]-exp+1;
                  exp += experience[i]-exp+1;
              }
              exp += experience[i];
          }
          if(totalEnergy >= initialEnergy) ans += totalEnergy-initialEnergy+1;
          if(beforeTrainingExp < initialExperience) ans += initialExperience-beforeTrainingExp;
          return ans;
      }
  };