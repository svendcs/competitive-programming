import sys
positions = {(0,0): 'S'}

minX = 0
maxX = 0
minY = 0
maxY = 0

x = 0
y = 0

for move in sys.stdin:
    move = move.strip()

    if move == "down":
        y += 1
    if move == "up":
        y -= 1
    if move == "left":
        x -= 1
    if move == "right":
        x += 1

    if not (x,y) in positions:
        positions[(x,y)] = '*'
    minX = min(minX, x)
    maxX = max(maxX, x)
    minY = min(minY, y)
    maxY = max(maxY, y)

positions[(x,y)] = 'E'

print("#" * (maxX-minX+3))
for y in range(minY, maxY+1):
    row = "#"
    for x in range(minX, maxX+1):
        if (x,y) in positions:
            row += positions[(x,y)]
        else:
            row += ' '
    
    row += "#"
    print(row)
print("#" * (maxX-minX+3))
