import re

energy=0
[n,k]=map(int, input().split())
s=input()
for x in range(0, k):
    [a,b]=input().split()
    b=int(b)
    #energy+=(len(re.findall(a, s))*b)
    for j in range(0, n-len(a)+1):
        if s[j:len(a)+j]==a:
            energy+=b

print(energy)
