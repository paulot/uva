def nearest_points(cur_point, points, k):
    distance = lambda a: (a[0] - cur_point[0])**2 + (a[1] - cur_point[1])**2
    sort = sorted(points, key=distance)
    return sort[:k]

print nearest_points((0, 0), [(1, 0), (0, 1), (1, 1)], 2)

