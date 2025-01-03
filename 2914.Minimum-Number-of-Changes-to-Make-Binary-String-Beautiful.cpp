class Solution {
public:
    int minChanges(string s) {
        // Initialize with first character of string
        char ch = s[0];

        int count = 0;
        int changes = 0;

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // If current character matches the previous sequence
            if (s[i] == ch) {
                count++;
                continue;
            }

            // If we have even count of characters, start new sequence
            if (count % 2 == 0) {
                count = 1;
            }
            // If odd count, we need to change current character
            // to match previous sequence
            else {
                count = 0;
                changes++;
            }

            // Update current character for next iteration
            ch = s[i];
        }

        return changes;
    }
};