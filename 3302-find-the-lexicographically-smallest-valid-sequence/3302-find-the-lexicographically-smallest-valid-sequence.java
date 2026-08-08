class Solution {
    public int[] validSequence(String word1, String word2) {

        int n = word1.length();
        int m = word2.length();

        int[] last = new int[m];

        // Initially no position found
        for (int i = 0; i < m; i++) {
            last[i] = -1;
        }

        // Find last possible positions from right
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            if (word1.charAt(i) == word2.charAt(j)) {
                last[j] = i;
                j--;
            }

            i--;
        }

        // Answer
        int[] ans = new int[m];

        i = 0;
        j = 0;

        // Mismatch is still available
        boolean canSkip = true;

        while (i < n && j < m) {

            // Exact match
            if (word1.charAt(i) == word2.charAt(j)) {

                ans[j] = i;
                j++;
            }

            // Use this index as the one mismatch
            else if (canSkip &&
                    (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;

                canSkip = false;
            }

            i++;
        }

        // Could not form complete sequence
        if (j < m) {
            return new int[0];
        }

        return ans;
    }
}