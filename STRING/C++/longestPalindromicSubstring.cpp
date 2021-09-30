string longestPalindrome(string s) {

  // idea is pretty simple track for each and every index 

  int sz = s.length();
  if (sz <= 1)
    return s;

  string ans = "";

  for (int i = 0; i < sz; i++) {

    int left = i - 1;
    int right = i + 1;
    while (right < sz && s[right] == s[i])
      right++;

    while (left >= 0 && right < sz && s[right] == s[left]) {
      left--;
      right++;
    }

    if (right - left - 1 > ans.length())
      ans = s.substr(left + 1, right - left - 1);
  }
  return ans;
}
