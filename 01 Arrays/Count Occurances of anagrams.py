# Given a word and a text, return the count of the occurrences of anagrams of the word in the text(For eg: anagrams of word for are for, ofr, rof etc.))

def count_anagrams(s, ptr):
    k = len(ptr)
    n = len(s)
    d = {}
    for i in ptr:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1

    count = len(d)
    ans = 0
    i = 0
    j = 0

    while j < n:
        if s[j] in d:
            d[s[j]] -= 1
            if d[s[j]] == 0:
                count -= 1
        if j-i+1 < k:
            j += 1
        elif j-i+1 == k:
            if count == 0:
                ans += 1
            if s[i] in d:
                d[s[i]] += 1
                if d[s[i]] == 1:
                    count += 1

            i += 1
            j += 1

    return ans

if __name__ == "__main__":
    s = "aabaabaa"
    ptr = "aaba"

    print(count_anagrams(s, ptr))