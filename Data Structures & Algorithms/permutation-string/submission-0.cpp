class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        int s1Count[26] = {0};
        int s2Count[26] = {0};

        // Count characters in s1 and initial window of s2
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Check the first window
        if (equal(s1Count, s1Count + 26, s2Count)) {
            return true;
        }

        // Sliding Window
        for (int right = s1.length(); right < s2.length(); right++) {

            // Add new character
            s2Count[s2[right] - 'a']++;

            // Remove character leaving the window
            s2Count[s2[right - s1.length()] - 'a']--;

            // Compare frequencies
            if (equal(s1Count, s1Count + 26, s2Count)) {
                return true;
            }
        }

        return false;
    }
};