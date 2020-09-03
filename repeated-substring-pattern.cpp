class Solution {
public:
    
    bool check(string s, string t) {
        int k = s.length()/t.length();
        string temp = "";
        for(int i=0;i<k;i++) temp += t;
        return s==temp;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n==1) return false;
        unordered_set<char> mp;
        for(int i=0;i<n;i++) mp.insert(s[i]);
        if(mp.size()==1) return true;
        for (int i=1; i<=sqrt(n); i++) { 
            if (n%i == 0 && i!=1 && i!=n && n/i!=1 && n/i!=n) {
                if (check(s, s.substr(0, i)) || check(s, s.substr(0, n/i))) return true; 
            } 
        }
        return false;
    }
};
