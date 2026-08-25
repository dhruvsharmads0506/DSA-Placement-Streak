/*
==================================================
LeetCode 125 - Valid Palindrome
Pattern: Two Pointers
Difficulty: Easy

Problem:
Given a string, check whether it is a palindrome after:
1. Converting uppercase letters to lowercase
2. Ignoring non-alphanumeric characters

Example:
"A man, a plan, a canal: Panama" -> true

--------------------------------------------------
KEY IDEA:
Use two pointers:
    left  -> beginning of string
    right -> end of string

1. If left character is not alphanumeric, skip it.
2. If right character is not alphanumeric, skip it.
3. Compare both characters after converting to lowercase.
4. If different -> return false.
5. If same -> move both pointers.

--------------------------------------------------
WHY TWO POINTERS?
We need to compare characters from both ends.
There is no need to create another string.

--------------------------------------------------
ALGORITHM:
left = 0
right = s.length() - 1

while left < right:
    if s[left] is not alphanumeric:
        left++
    else if s[right] is not alphanumeric:
        right--
    else:
        compare lowercase(left) and lowercase(right)
        if different:
            return false
        left++
        right--

return true

--------------------------------------------------
TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(1)

--------------------------------------------------
IMPORTANT C++ FUNCTIONS:
isalnum(c) -> checks letter or digit
tolower(c) -> converts character to lowercase

--------------------------------------------------
COMMON MISTAKES:
1. Using islower() instead of tolower()
2. Forgetting to move left and right
3. Comparing spaces/special characters
4. Putting left++ / right-- after return false
5. Creating another string unnecessarily

--------------------------------------------------
PATTERN TO REMEMBER:
Two Pointers + String Filtering

When you see:
- compare from both ends
- reverse-like checking
- palindrome
- sorted array pair problems

Think: TWO POINTERS
==================================================
*/

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }

                right--;
                left++;
            }
        }

        return true;
    }
};
