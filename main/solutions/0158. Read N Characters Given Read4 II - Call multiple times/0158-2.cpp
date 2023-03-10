/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char* buf, int n) {
    int i = 0;  // buf's index

    // Put remaining chars in buf4 to buf
    while (i4 < n4 && i < n)
      buf[i++] = buf4[i4++];

    // While not reaching the tail (< 4 chars)
    while (i + 4 < n) {
      const int k = read4(buf + i);  // Directly write to buf
      if (k == 0)                    // Reach the EOF
        return i;
      i += k;
    }

    // Reach the tail
    while (i < n) {
      if (i4 == n4) {      // All characters in buf4 are consumed
        i4 = 0;            // Reset buf4's index
        n4 = read4(buf4);  // Read 4 (or less) chars from file to buf4
        if (n4 == 0)       // Reach the EOF
          return i;
      }
      buf[i++] = buf4[i4++];
    }

    return i;
  }

 private:
  char* buf4 = new char[4];
  int i4 = 0;  // buf4's index
  int n4 = 0;  // buf4's size
};
