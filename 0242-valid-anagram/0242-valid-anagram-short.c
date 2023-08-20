bool isAnagram(char * s, char * t){
    int ls = strlen(s), lt = strlen(t);
    if (ls != lt) return false;
    int letters[26] = {0};
    
    for (int i = 0; i < ls; i++) letters[s[i] - 'a'] += 1;
    for (int i = 0; i < lt; i++) letters[t[i] - 'a'] -= 1;
    for (int i = 0; i < 26; i++) {
        if (letters[i] != 0) return false;
    }
    return true;
}
