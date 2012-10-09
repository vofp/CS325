set title "Algorithm 1 - Size Vs. Execution Time"
set xlabel "log(Size of Array)"
set ylabel "log(Seconds)"
set logscale xy
set autoscale
set term png
set output "alg1plotlog.png"
plot "alg1Timing" using 1:2 
