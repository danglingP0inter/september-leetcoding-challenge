class Solution {
public:
    vector<int> partitionLabels(string s) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        vector<int> ans;
        unordered_set<char> mp;
        for(auto c: s) freq[c - 'a']++;
        int cnt = 0;
        for(auto c: s) {
            cnt++;
            mp.insert(c);
            freq[c - 'a']--;
            if(freq[c - 'a'] == 0) {
                mp.erase(c);
                if(mp.empty()) {
                    ans.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        
        return ans;
    }
};
