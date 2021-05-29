//problem : 692. Top K Frequent Words

// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.



class Solution {
public:
static bool cmp(pair<string,int>& a,pair<string, int>& b)
{   if(a.second==b.second) return a.first<b.first;
    return a.second > b.second;
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string ,int> m;
        vector<string> v;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }  
    vector<pair<string, int>> A;  
    for (auto& it : m) {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);
   for(int i=0;i<k;i++) {  
        v.push_back(A[i].first);
       }
        return v;
    }
};
