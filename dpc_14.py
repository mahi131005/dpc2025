def countSubstringsWithKDistinct(s: str, k: int) -> int:
    def atMostK(s, k):
        left = 0
        freq = {}
        count = 0
        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1
            
            # shrink if more than k distinct
            while len(freq) > k:
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    del freq[s[left]]
                left += 1
            
            # number of substrings ending at right
            count += (right - left + 1)
        return count
    
    if k == 0:
        return 0
    return atMostK(s, k) - atMostK(s, k - 1)

string = input("Enter String: ")
k = int(input("Enter k: "))
print(countSubstringsWithKDistinct(string,k))
