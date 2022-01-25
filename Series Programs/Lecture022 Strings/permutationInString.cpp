class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    vector<int> cur(26), goal(26);
        
        //we are storing the count of alphabers in the s1
        // this is the same method as the unordered_map but with using vector or array
	for(char c : s1) goal[c - 'a']++;
        
        //here we are storing the count of alphabers in s2
	for(int i = 0; i < s2.size(); i++) {
		cur[s2[i] - 'a']++;
//         if the window size is less than i matlab i aage nikal gaya toh
//         jis index ko chodhna h usko minus kardo
		if(i >= s1.size()) cur[s2[i - s1.size()] - 'a']--;
//         checking if the alphabets in window equals to the pattern
		if(goal == cur) return true;
	}
	return false;
    }
};