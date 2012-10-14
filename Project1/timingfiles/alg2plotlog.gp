set title "Algorithm 2 - Size Vs. Execution Time"
set xlabel "log(Size of Array)"
set ylabel "log(Seconds)"
set logscale xy
f(x)=10**(a*log(x)/log(10)+b)
fit f(x) "alg2.t" using 1:2 via a,b
set term png
set output "alg2plotlog.png"
c=1
plot f(x),"alg2.t" using 1:2 
