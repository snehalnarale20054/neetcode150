class Solution {
public:
    string minWindow(string s, string t) {

        if (t.length() > s.length()) {
            return "";
        }

        int freq[128] = {0};

        for (char ch : t) {
            freq[ch]++;
        }

        int left = 0;
        int start = 0;
        int minLength = INT_MAX;
        int required = t.length();

        for (int right = 0; right < s.length(); right++) {

            char ch = s[right];

            if (freq[ch] > 0) {
                required--;
            }

            freq[ch]--;

            while (required == 0) {

                int windowLength = right - left + 1;

                if (windowLength < minLength) {
                    minLength = windowLength;
                    start = left;
                }

                char leftChar = s[left];

                freq[leftChar]++;

                if (freq[leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};
