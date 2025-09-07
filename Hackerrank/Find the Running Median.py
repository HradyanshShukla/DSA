import heapq
def runningMedian(arr):
    min_heap = []
    max_heap = [] 
    medians = []

    for num in arr:
        # Add number to one of the heaps
        if not max_heap or num <= -max_heap[0]:
            heapq.heappush(max_heap, -num)
        else:
            heapq.heappush(min_heap, num)

        # Balance the heaps sizes
        if len(max_heap) > len(min_heap) + 1:
            moved = -heapq.heappop(max_heap)
            heapq.heappush(min_heap, moved)
        elif len(min_heap) > len(max_heap):
            moved = heapq.heappop(min_heap)
            heapq.heappush(max_heap, -moved)
        # Calculate median
        if len(max_heap) == len(min_heap):
            median = (-max_heap[0] + min_heap[0]) / 2
        else:
            median = float(-max_heap[0])

        medians.append(median)

    return medians

if __name__ == '__main__':
    n = int(input())
    arr = [int(input()) for _ in range(n)]
    medians = runningMedian(arr)
    for median in medians:
        # Print median with one decimal place (as per HackerRank requirement)
        print(f"{median:.1f}")
