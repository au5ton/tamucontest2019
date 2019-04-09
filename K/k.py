from math import sqrt
def dist(p1, p2):
    d = [abs(p2[0] - p1[0])**2, abs(p2[1] - p1[1])**2, abs(p2[2] - p1[2])**2]
    dist = sqrt(sum(d))
    return dist

if __name__ == "__main__":
    n, k = map(int, input().split())
    planets = []
    for _ in range(n):
        planets.append(list(map(int, input().split())))
    reached = [[0,0,0]]
    while True:
        n = 0
        for r in reached:
            for p in planets:
                if p not in reached and dist(r, p) <= k:
                    reached.append(p)
                    n += 1
        if n == 0:
            break
    print(len(reached) - 1)
