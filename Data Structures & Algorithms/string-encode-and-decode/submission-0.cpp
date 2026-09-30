class Solution {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.length()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Extract the string
            string word = s.substr(j + 1, len);
            result.push_back(word);

            // Move to next encoded string
            i = j + 1 + len;
        }

        return result;
    }
};