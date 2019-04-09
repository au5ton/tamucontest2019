import primefac

[a,b]=map(int, input().split())

af=list(primefac.primefac(a))
bf=list(primefac.primefac(b))

d=set(af)&set(bf)

print(float(len(d)/(len(af)+len(bf)-len(d))))

