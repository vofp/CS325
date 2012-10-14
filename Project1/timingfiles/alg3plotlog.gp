set title "Algorithm 3 - Size Vs. Execution Time"
set xlabel "log(Size of Array)"
set ylabel "log(Seconds)"
set logscale xy
set autoscale
f(x)=10**(a*log(x)/log(10)+b)
fit f(x) "alg3.t" using 1:2 via a,b
set term png
set output "alg3plotlog.png"
plot f(x),"alg3.t" using 1:2 
