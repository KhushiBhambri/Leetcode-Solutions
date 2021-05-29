//720 Longest Word in Dictionary

// Given an array of strings words representing an English Dictionary, return the longest word in words 
// that can be built one character at a time by other words in words.

// If there is more than one possible answer, return the longest word with the smallest lexicographical order. 
// If there is no answer, return the empty string.

 

// Example 1:
// Input: words = ["w","wo","wor","worl","world"]
// Output: "world"
// Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

// Example 2:
// Input: words = ["a","banana","app","appl","ap","apply","apple"]
// Output: "apple"
// Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
 

// Constraints:
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 30
// words[i] consists of lowercase English letters.



class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        set<string> s;
        string res="";
        for(int i=0;i<words.size();i++){
          if(words[i].length()==1 || s.find(words[i].substr(0,words[i].length()-1))!=s.end())
               {
               s.insert(words[i]);
               if(res.length()<words[i].length()) res=words[i];
               }
        }   
               return res;
    }
};
