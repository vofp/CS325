a = ARGV[0].to_f 
b = ARGV[1].to_f
c = ARGV[2].to_f

p = [[1,3],[2,5],[3,7],[5,11],[7,14],[8,15],[11,19]]
for i in 0..6
	print i,": ",a*p[i][0] + b*p[i][1] - c, "\n"
end
