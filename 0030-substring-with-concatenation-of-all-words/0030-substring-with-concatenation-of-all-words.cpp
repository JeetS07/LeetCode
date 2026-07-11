class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty()) return ans;

        unordered_map<string, int> freq;
        for (string &w : words) freq[w]++;

        int wordSize = words[0].size();
        int totalWords = words.size();
        int windowSize = wordSize * totalWords;
        int n = s.size();

        if (windowSize > n) return ans;

        for (int offset = 0; offset < wordSize; offset++) {

            unordered_map<string, int> curr;
            int left = offset;
            int count = 0;

            for (int right = offset; right + wordSize <= n; right += wordSize) {

                string word = s.substr(right, wordSize);

                if (freq.count(word)) {

                    curr[word]++;
                    count++;

                    while (curr[word] > freq[word]) {
                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }

                    if (count == totalWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }

                } else {

                    curr.clear();
                    count = 0;
                    left = right + wordSize;
                }
            }
        }

        return ans;
    }
};