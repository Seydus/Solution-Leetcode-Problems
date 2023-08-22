bool isStrictlyPalindromic(int n)
{
    for(int i = 2; i <= n - 2; i++)
    {
        int num = n;
        char s[100];
        int len = 0;

        while(num > 0)
        {
            s[len++] = num % i + '0';
            num /= i;
        }

        int l = 0, r = len - 1;

        while(l < r)
        {
            if(s[l] != s[r]) return false;
            l++, r--;
        }
    }
    
    return true;
}
