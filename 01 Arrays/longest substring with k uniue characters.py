


def long_string(s, k):
    n = len(s)
    max_length = 0
    d = {}

    i = 0
    j = 0
    while j < n:
        if s[j] in d:
            d[s[j]] += 1
        else:
            d[s[j]] = 1
        if len(d) == k:
            max_length = max(max_length, j-i+1)
        elif len(d) > k:
            while len(d) > k and i < j:
                d[s[i]] -= 1
                i += 1
                if d[s[i]] == 0:
                    d.pop(s[i])

        j += 1

    return max_length



if __name__ == "__main__":
    s = [0, 0, 1, 1, 3, 3, 3]
    k = 1

    print(long_string(s, k))