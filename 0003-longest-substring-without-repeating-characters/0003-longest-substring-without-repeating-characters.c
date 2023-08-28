int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int charIndex[256]; 

    for (int i = 0; i < 256; i++) {
        charIndex[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (charIndex[s[i]] >= start) {
            start = charIndex[s[i]] + 1;
        }

        charIndex[s[i]] = i;

        maxLength = (i - start + 1 > maxLength) ? i - start + 1 : maxLength;
    }

    return maxLength;
}