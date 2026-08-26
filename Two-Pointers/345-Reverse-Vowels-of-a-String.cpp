/*
===========================================================
LeetCode 345 - Reverse Vowels of a String
Pattern: Two Pointers
Difficulty: Easy

-----------------------------------------------------------
PROBLEM:
Given a string, reverse only the vowels in the string.

Vowels:
a, e, i, o, u
A, E, I, O, U

Example:
Input:  "hello"
Output: "holle"

Input:  "leetcode"
Output: "leotcede"

-----------------------------------------------------------
KEY IDEA:
Use two pointers:

left  -> starts from the beginning
right -> starts from the end

1. If s[left] is NOT a vowel:
      move left forward.

2. Else if s[right] is NOT a vowel:
      move right backward.

3. If both are vowels:
      swap them.
      move both pointers.

-----------------------------------------------------------
DRY RUN:

s = "hello"

h e l l o
↑       ↑
L       R

h is not vowel
→ left++

  e l l o
  ↑     ↑
  L     R

e is vowel
o is vowel
→ swap

  o l l e
    ↑ ↑

Continue until left >= right.

Result = "holle"

-----------------------------------------------------------
WHY TWO POINTERS?
We only need to find vowels from both ends and swap them.
There is no need to create another string.

-----------------------------------------------------------
IMPORTANT C++:
tolower(c) -> converts uppercase character to lowercase
swap(a, b) -> swaps two values
s[left]     -> character at left pointer
s[right]    -> character at right pointer

-----------------------------------------------------------
TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(1)
(We modify the string in-place.)

-----------------------------------------------------------
COMMON MISTAKES:
1. Moving both pointers when only one side is not a vowel.
2. Forgetting to move pointers after swapping.
3. Checking only lowercase vowels.
4. Creating another string unnecessarily.
5. Forgetting that uppercase vowels are also vowels.

-----------------------------------------------------------
PATTERN TO REMEMBER:

Two Pointers + Condition

left →                         ← right

not vowel → left++
not vowel → right--
both vowels → swap + move both

===========================================================
*/

class Solution {

    // Helper function: checks whether a character is a vowel
    bool isVowel(char c) {
        c = tolower(c);

        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

public:
    string reverseVowels(string s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Left character is not a vowel
            if (!isVowel(s[left])) {
                left++;
            }

            // Right character is not a vowel
            else if (!isVowel(s[right])) {
                right--;
            }

            // Both are vowels
            else {
                swap(s[left], s[right]);

                left++;
                right--;
            }
        }

        return s;
    }
};
