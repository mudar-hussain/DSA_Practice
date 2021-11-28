# Python program to find the maximum for each and every contiguous subarray of size k

def max_sum(arr, k):
    n = len(arr)
    sum = 0
    max_sum = 0
    i = 0
    j = 0
    while j < n:
        sum = sum + arr[j]
        if j-i+1 < k:
            j += 1
        elif j-i+1 == k:
            max_sum = max(max_sum, sum)
            sum = sum - arr[i]
            i += 1
            j += 1

    return  max_sum


if __name__ == "__main__":
    arr = [1, 2, 3, 1, 4, 5, 2, 3, 6]
    k = 3
    print(max_sum(arr,k))



