def is_vps(ps):
    list_ps = list(ps)
    count = 0

    for ind in range(len(list_ps)):
        if list_ps[ind] == '(':
            count += 1
        else:
            count -= 1

        if count < 0:
            return False

    return count == 0


count = input()
for i in range(int(count)):
    ps = input()
    if is_vps(ps):
        print("YES")
    else:
        print("NO")


