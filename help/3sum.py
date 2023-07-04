l = [-1,0,1,2,-1,-4]
n = len(l)
l.sort()
ans = []
for i in range(n):
    if i > 0 and l[i] == l[i-1]:
        continue
    j = i+1
    k = n-1
    while j < k:
        sum = l[i] + l[j] + l[k]
        if sum < 0:
            j += 1
        elif sum > 0:
            k -= 1
        else:
            temp = [l[i], l[j], l[k]]
            ans.append(temp)
            j += 1
            k -= 1
            while j < n and l[j] == l[j-1]:
                j += 1
            while j < k and l[k] == l[k+1]:
                k -= 1
print(ans)