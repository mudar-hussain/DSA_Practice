# Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

def max_subarray(arr, k):
    n = len(arr)
    max_ans = []
    mx_arr = []
    i = 0
    j = 0
    while j < n:
        mx_arr.append(arr[j])
        mx = max(mx_arr)
        if j-i+1 < k:
            j += 1
        elif j-i+1 == k:
            max_ans.append(mx)
            mx_arr.pop(0)
            i += 1
            j += 1

    return max_ans




if __name__ == "__main__":
    arr = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
    k = 4
    print(max_subarray(arr, k))