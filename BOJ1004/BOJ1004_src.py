# https://www.acmicpc.net/problem/1004

# 함수
def dist_pow(dx1, dy1, dx2, dy2):
    return pow(dx2 - dx1, 2) + pow(dy2 - dy1, 2)

def solve():
    count = 0
    for cx, cy, r in planets:
        is_count = False
        if dist_pow(x1, y1, cx, cy) <= pow(r, 2):
            is_count = not is_count
        if dist_pow(x2, y2, cx, cy) <= pow(r, 2):
            is_count = not is_count
        count += is_count

    return count

# 입력
t = int(input())
solved = ""

for i in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    planets = [list(map(int, input().split())) for _ in range(n)]
    solved += str(solve()) + "\n"

print(solved)