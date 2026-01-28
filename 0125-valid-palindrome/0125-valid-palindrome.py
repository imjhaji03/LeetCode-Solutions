class Solution:
    def isPalindrome(self, s: str) -> bool:
        st = ""

        for ch in s:
            if ch.isalnum():
                st += ch.lower()

        return True if st == st[::-1] else False        
        