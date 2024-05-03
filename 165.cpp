class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, m = version1.length(), n = version2.length();

        while (i < m || j < n) {

            int v1 = 0;
            int v2 = 0;

            while (i < m && version1[i] != '.') v1 = v1 * 10 + (version1[i++] - '0');
            while (j < n && version2[j] != '.') v2 = v2 * 10 + (version2[j++] - '0');

            if (v2 < v1) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }

            i++;
            j++;
        }

        return 0;
    }
};