while True:
    n = int(input())
    if n == 0: break

    plaintext = input().upper().replace(' ', '')
    ciphertext = ['']*len(plaintext)
    l = len(plaintext)

    j = 0
    first = 1
    for i in range(l):
        if i != 0:
            j += n
            while j < l and ciphertext[j] != '': j += 1
            if j >= l:
                j = first
                while ciphertext[j] != '': j += 1
                first = j+1
        ciphertext[j] = plaintext[i]

    print("".join(ciphertext))


