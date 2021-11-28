# Given an array of integers, our goal is to find the length of the largest subarray having the sum of its elements = ‘k’

def long_subarray(arr, k):
    n = len(arr)
    sum = 0
    win_size = 0
    i = 0
    j = 0
    while j < n:
        sum = sum + arr[j]
        if sum == k:
            win_size = max(win_size, j-i+1)
        elif sum > k:
            while sum > k and i <= j:
                sum -= arr[i]
                i += 1
                if sum == k:
                    win_size = max(win_size, j-i+1)
        j += 1

    return win_size






if __name__ == "__main__":
    arr =[-5, 8, -14, 2, 4, 12]
    sum = -5
    print(long_subarray(arr, sum))