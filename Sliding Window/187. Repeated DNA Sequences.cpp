/**
 * @param {string} s
 * @return {string[]}
 */
 var findRepeatedDnaSequences = function(s) {
  let i = 0, j = 0, hash = new Map(), str = "";
  while(j < s.length){
      str += s[j];
      if(j-i+1 === 10){
          const st = str.slice(i);
          if(hash[st] !== undefined) hash[st]++;
          else hash[st] = 1;
          i++;
      }
      j++;
  }
  const ans = [];
  for(let key in hash){
      if(hash[key] > 1) ans.push(key);
  }
  return ans;
};