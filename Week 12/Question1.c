    #include <stdio.h>
    #include <string.h>
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    int longestCommonSubsequence(char *seq1, char *seq2, int len1, int len2)
    {
        int lcs[len1 + 1][len2 + 1];
        int i, j;
        for (i = 0; i <= len1; i++)
        {
            for (j = 0; j <= len2; j++)
            {
                if (i == 0 || j == 0)
                    lcs[i][j] = 0;
                else if (seq1[i - 1] == seq2[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        return lcs[len1][len2];
    }
    int main()
    {
        char seq1[] = "aggt";
        char seq2[] = "ggaaaggtha";
        int len1 = strlen(seq1);
        int len2 = strlen(seq2);
        int length = longestCommonSubsequence(seq1, seq2, len1, len2);
        printf("The length of the longest common subsequence is: %d\n", length);
        return 0;
    }