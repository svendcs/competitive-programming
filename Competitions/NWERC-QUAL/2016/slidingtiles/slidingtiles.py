alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

while True:
    n = int(input())
    if n == -1: break

    boardmap = {}
    board = {}
    for y in range(0,5):
        for x in range(0,5):
            letter = alphabet[y * 5 + x]
            boardmap[letter] = (x,y)
            board[(x,y)] = letter

    # for y in range(0, 5):
    #     row = ""
    #     for x in range(0, 5):
    #         row += (board[(x,y)] if (x,y) in board else " ")
    #     print(row)

    # print("-"*8)

    # print(board)
    for i in range(n):
        letter, move = input().split()

        if move == 'up':
            x, y = boardmap[letter]
            to_be_moved = []
            while True:
                if (x,y) in board:
                    to_be_moved.append(board[(x,y)])
                    y -= 1
                else:
                    break

            for c in reversed(to_be_moved):
                pos = boardmap[c]
                new_pos = (pos[0], pos[1] - 1)
                del board[pos]
                board[new_pos] = c
                boardmap[c] = new_pos

        if move == 'down':
            x, y = boardmap[letter]
            to_be_moved = []
            while True:
                if (x,y) in board:
                    to_be_moved.append(board[(x,y)])
                    y += 1
                else:
                    break

            for c in reversed(to_be_moved):
                pos = boardmap[c]
                new_pos = (pos[0], pos[1] + 1)
                del board[pos]
                board[new_pos] = c
                boardmap[c] = new_pos

        if move == 'right':
            x, y = boardmap[letter]
            to_be_moved = []
            while True:
                if (x,y) in board:
                    to_be_moved.append(board[(x,y)])
                    x += 1
                else:
                    break

            for c in reversed(to_be_moved):
                pos = boardmap[c]
                new_pos = (pos[0] + 1, pos[1])
                del board[pos]
                board[new_pos] = c
                boardmap[c] = new_pos

        if move == 'left':
            x, y = boardmap[letter]
            to_be_moved = []
            while True:
                if (x,y) in board:
                    to_be_moved.append(board[(x,y)])
                    x -= 1
                else:
                    break

            for c in reversed(to_be_moved):
                pos = boardmap[c]
                new_pos = (pos[0] - 1, pos[1])
                del board[pos]
                board[new_pos] = c
                boardmap[c] = new_pos

    # print 
    minX = min(map(lambda pos: pos[0], boardmap.values()))
    maxX = max(map(lambda pos: pos[0], boardmap.values()))
    minY = min(map(lambda pos: pos[1], boardmap.values()))
    maxY = max(map(lambda pos: pos[1], boardmap.values()))

    for y in range(minY, maxY+1):
        row = ""
        for x in range(minX, maxX + 1):
            row += (board[(x,y)] if (x,y) in board else " ")
        blah = ""
        i = len(row) - 1
        while i >= 0:
            if row[i] != " ":
                break
            i -= 1

        while i >= 0:
            blah += row[i]
            i -= 1

        res = ""
        for c in reversed(blah):
            res += c
        print(res)

    print()
