set title "Algorithm 3 - Size Vs. Execution Time"
set xlabel "log(Size of Array)"
set ylabel "log(Seconds)"
set logscale xy
set autoscale
set term png
set output "alg3plotlog.png"
plot "alg3.t" using 1:2 
