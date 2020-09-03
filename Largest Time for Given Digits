class Solution {
public:
    string largestTimeFromDigits(vector<int>& a) {
        sort(a.begin(), a.end());
        
        char c[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string ans;
        string s;
        
        for(auto i: a) s += c[i];
        if(s>"2359") return "";
        
        do {
            int hr = stoi(s.substr(0,2));
            int mins = stoi(s.substr(2,4));
            if(hr<24&& mins<=59) 
                ans = s.substr(0,2)+":"+s.substr(2,4);
        }while(next_permutation(s.begin(),s.end()) && s<="2359");
        return ans;
    }
};
