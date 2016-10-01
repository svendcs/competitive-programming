def get_max(board, y, x):
    best = 0
    if y > 1 and x > 1 and board[y-1][x-1] == 'B' and board[y-2][x-2] == '#':
        board[y-1][x-1] = '#'
        best = max(best, 1+get_max(board, y-2, x-2))
        board[y-1][x-1] = 'B'
    if y < 8 and x < 8 and board[y+1][x+1] == 'B' and board[y+2][x+2] == '#':
        board[y+1][x+1] = '#'
        best = max(best, 1+get_max(board, y+2, x+2))
        board[y+1][x+1] = 'B'

    if y > 1 and x < 8 and board[y-1][x+1] == 'B' and board[y-2][x+2] == '#':
        board[y-1][x+1] = '#'
        best = max(best, 1+get_max(board, y-2, x+2))
        board[y-1][x+1] = 'B'
    if y < 8 and x > 1 and board[y+1][x-1] == 'B' and board[y+2][x-2] == '#':
        board[y+1][x-1] = '#'
        best = max(best, 1+get_max(board, y+2, x-2))
        board[y+1][x-1] = 'B'

    return best

for testcase in range(int(input())):
    input()
    board = [list(input()) for i in range(10)]
    
    best = 0
    for y in range(10):
        for x in range(10):
            if board[y][x] != 'W': continue
            board[y][x] = '#'
            best = max(best, get_max(board, y, x))
            board[y][x] = 'W'
    print(best)
