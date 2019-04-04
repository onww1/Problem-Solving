T = int(input())
for tc in range(T):
	N = int(input())
	rs = cs = 10000
	rb = cb = -10000
	for _ in range(N):
		ri, ci = [float(a) for a in input().split()]
		if ri > rb:
			rb = ri
		if ri < rs:
			rs = ri
		if ci > cb:
			cb = ci
		if ci < cs:
			cs = ci

	area = (rb - rs) * (cb - cs)
	peri = (rb + cb - rs - cs) * 2

	print('Case ', (tc+1), ': Area ', area, ', Perimeter ', peri)
