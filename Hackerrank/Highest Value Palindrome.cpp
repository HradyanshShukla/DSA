#include <bits/stdc++.h>
using namespace std;
string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int left = 0, right = n - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            if (k <= 0) return "-1";
            char max_char = max(s[left], s[right]);
            s[left] = s[right] = max_char;
            changed[left] = changed[right] = true;
            k--;
        }
        left++;
        right--;
    }    
    left = 0;
    right = n - 1;
    while (left <= right && k > 0) {
        if (left == right) {
            // Middle character in odd length palindrome
            if (s[left] != '9' && k > 0) {
                s[left] = '9';
                k--;
            }
        } else {
            if (s[left] != '9') {
                // If already changed in first pass, only one more change needed
                if (changed[left] || changed[right]) {
                    if (k >= 1) {
                        s[left] = s[right] = '9';
                        k--;
                    }
                } else {
                    // Need two changes to upgrade both sides
                    if (k >= 2) {
                        s[left] = s[right] = '9';
                        k -= 2;
                    }
                }
            }
        }
        left++;
        right--;
    }    
    return s;
}
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;   
    cout << highestValuePalindrome(s, n, k) << "\n";
    return 0;
}
