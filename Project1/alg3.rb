a = [31,-41,59,26,-53,58,97,-93,-23,84]
def greater(a,b)
	a > b ? a : b
end
def MaxSubarray(a)
	if a.size == 1 
		p a
		puts a[0]
		puts a[0]
		puts a[0]
		puts a[0]
		return a[0],a[0],a[0],a[0]
	end
	i = a.size/2
	p a[0...i]
	ls,ll,lr,lm = MaxSubarray(a[0...i])
	rs,rl,rr,rm = MaxSubarray(a[i..-1])
	
	sum = ls+rs
	l = ls+rl
	r = lr+rs
	mid = lr+rl

	l = greater(l,ll)
	r = greater(r,rr)
	#s = greater(l,r)
	m = greater(lm,rm)
	#m = greater(m,s)
	m = greater(m,mid)
	p a
	puts sum
	puts l
	puts r
	puts m
	return sum, l, r,m
end
s,l,r,m = MaxSubarray(a)
puts m
