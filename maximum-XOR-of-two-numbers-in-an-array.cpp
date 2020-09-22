class Solution {
public:
    // Classical trie problem
    // Not the prettiest solution, but who cares as long as it's AC :)
    struct Node {
        Node* child[2];
        
        Node() {
            child[0] = child[1] = NULL;
        }
    };
    
    Node* root = NULL;
    
    void insert(string b) {
        Node* crawl = root;
        for(int i=0;i<b.length();i++) {
            int index = b[i] - '0';
            if(!crawl->child[index])
                crawl->child[index] = new Node();
            crawl = crawl->child[index];
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        string ans = "";
        for(int num: nums) {
            string b = bitset<32> (num).to_string();
            // cout<<b<<'\t';
            insert(b);
            Node* crowl = root;
            string temp = "";
            for(int i=0; i<b.length();i++) {
                if(b[i] == '1') {
                    if(crowl->child[0]) {
                        temp += '1';
                        crowl = crowl->child[0];
                    }
                    else {
                        temp += '0';
                        crowl = crowl->child[1];
                    }
                } else {
                    if(crowl->child[1]) {
                        temp += '1';
                        crowl = crowl->child[1];
                    }
                    else {
                        temp += '0';
                        crowl = crowl->child[0];
                    }
                }
            }
            ans = max(ans, temp);
        }
        
        return stoull(ans, 0, 2);
    }
};
