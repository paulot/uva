while True:
    t = int(input())
    if t == 0:
        break

    dx, dy = map(int, input().split())

    for _ in range(0, t):
        cx, cy = map(int, input().split())
        if dx == cx or dy == cy: print('divisa')
        elif cx > dx and cy > dy: print('NE')
        elif cx > dx and cy < dy: print('SE')
        elif cx < dx and cy > dy: print('NO')
        elif cx < dx and cy < dy: print('SO')
