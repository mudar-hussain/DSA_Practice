# Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

def neg_num(arr,k):
    neg_lst = []
    ans = []
    i = 0
    j = 0
    while j < len(arr):
        if arr[j] < 0:
            neg_lst.append(arr[j])
        if j-i+1 < k:
            j += 1

        elif j-i+1 == k:
            if len(neg_lst) == 0:
                ans.append(0)
            else:
                ans.append(neg_lst[0])
                if arr[i] == neg_lst[0]:
                    neg_lst.pop(0)
            i += 1
            j += 1

    return ans






if __name__ == "__main__":
    arr = [12,-1,-7,8,-15,30,16,28]
    k = 3
    print(neg_num(arr,k))