def sumXor(n):
    if n == 0:
        return 1
    zero_bits = 0
    temp = n
    while temp > 0:
        if (temp & 1) == 0:
            zero_bits += 1
        temp >>= 1    
    return 2 ** zero_bits
if __name__ == '__main__':
    n = int(input().strip())
    print(sumXor(n))
