def get_mario_pos(tab, n, m):
    for i in range(n):
        if tab[i][0] == 'm':
            return (i, 0)


def get_princess_pos(tab, n, m):
    for i in range(n):
        if tab[i][-1] == 'p':
            return (i, m - 1)


def get_this_column_coins(i, j, up, tab):
    c_move = 0
    ans = 0
    while c_move <= up and tab[sx + c_move][sy] != '#':
        c_move += 1
        if tab[sx + c_move][sy] == 'c':
            ans += 1
    return ans


def get_count_of_coins(tab):
    ans = 0
    for row in tab:
        for el in row:
            ans += (el == 'c')

    return ans


def is_valid_coordinates(cx, cy, tab):
    return 0 <= cx < len(tab) and 0 <= cy < len(tab[0])


def is_valid_temp_position(cx, cy, tab):
    return is_valid_coordinates(cx, cy, tab) and tab[cx][cy] != '#'


def is_valid_final_position(cx, cy, tab):
    if not is_valid_temp_position(cx, cy, tab):
        return False

    return is_valid_coordinates(cx + 1, cy, tab) and tab[cx + 1][cy] == '#'


def relax_pos(din, i, j, a, b, tab, rc):

    tmp_coins = 0
    row_coins = 0
    for up in range(0, a + 1):
        if is_valid_temp_position(i - up, j, tab):
            tmp_coins += tab[i - up][j] == 'c'
            row_coins = 0
            for left in range(1, b + 1):
                if is_valid_temp_position(i - up, j + left, tab):
                    if left > 1:
                        tmp_coins += tab[i - up][j + left - 1] == 'c'
                        row_coins += tab[i - up][j + left - 1] == 'c'

                    cp = i - up
                    while cp < len(tab) and not is_valid_final_position(cp, j + left, tab):
                        cp += 1

                    if cp == len(tab):
                        continue

                    din[cp][j + left] = max(din[cp][j + left], din[i][j] + tmp_coins)
                    rc[cp][j + left] = True
                else:
                    break
            tmp_coins -= row_coins
        else:
            break


def main():
    n, m, a, b = map(int, input().split())

    tab = [list(input()) for _ in range(n)]
    din = [[0]*m for i in range(n)]
    reachable = [[False] * m for i in range(n)]

    sx, sy = get_mario_pos(tab, n, m)
    reachable[sx][sy] = True

    fx, fy = get_princess_pos(tab, n, m)

    count_of_coins = get_count_of_coins(tab)
    # init_start_pos(tab, sx, sy, a, b)

    for j in range(0, m):
        for i in range(n-1, -1, -1):
            if reachable[i][j]:
                relax_pos(din, i, j, a, b, tab, reachable)

    if din[fx][fy] == count_of_coins and reachable[fx][fy]:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()
