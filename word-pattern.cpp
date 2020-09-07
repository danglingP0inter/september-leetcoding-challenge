class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        string buf;                 
        stringstream ss(str);    
        
        vector<string> words;
        while (ss >> buf) words.push_back(buf);
        if(pattern.length() != words.size() || (!pattern.length() && !str.length())) return false;
        
        for(int i=0; i<pattern.length(); i++) {
            if(mp1.find(pattern[i]) != mp1.end() && mp1[pattern[i]] != words[i])
                return false;
            else if(mp2.find(words[i]) != mp2.end() && mp2[words[i]] != pattern[i])
                return false;
            else {
                mp1[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            }
        }
        
        return true;
    }
};
