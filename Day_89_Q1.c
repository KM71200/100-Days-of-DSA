def is_possible(arr, n, m, max_pages):
    students = 1
    current_pages = 0

    for i in range(n):
        if current_pages + arr[i] > max_pages:
            students += 1
            current_pages = arr[i]

            if students > m:
                return False
        else:
            current_pages += arr[i]

    return True


def allocate_books(arr, n, m):
    if m > n:
        return -1  # Not enough books

    low = max(arr)
    high = sum(arr)
    result = high

    while low <= high:
        mid = (low + high) // 2

        if is_possible(arr, n, m, mid):
            result = mid
            high = mid - 1
        else:
            low = mid + 1

    return result


# Input
n, m = map(int, input().split())
arr = list(map(int, input().split()))

# Output
print(allocate_books(arr, n, m))
