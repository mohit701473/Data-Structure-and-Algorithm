https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        long p = 31;
        long pow = p;
        long mod = 1000000007;
        long pattHash = needle[0] - 'a' + 1;

        for (int i = 1; i < m; i++) {
            pattHash = (pattHash + (needle[i] - 'a' + 1) * pow) % mod;
            pow = (pow * p) % mod;
        }

        // Rabin Karp Rolling Hash
        long dp[n], powArray[n];
        dp[0] = haystack[0] - 'a' + 1;
        powArray[0] = 1;

        for (int i = 1; i < n; i++) {
            powArray[i] = (powArray[i - 1] * p) % mod;
            dp[i] = (dp[i - 1] + (haystack[i] - 'a' + 1) * powArray[i]) % mod;
        }

        long st = 0, end = m-1;
        while (end < n) {
            long hash = (st == 0 ) ? dp[end] : ((dp[end] - dp[st - 1] + mod) % mod);
            long tempPattHash = (pattHash * powArray[st]) % mod;
            if (hash == tempPattHash)
                return st;
            st++, end++;
        }

        return -1;
    }
};