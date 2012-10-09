set title "Algorithm 2 - Size Vs. Execution Time"
set xlabel "log(Size of Array)"
set ylabel "log(Seconds)"
set logscale xy
set autoscale
set term png
set output "alg2plotlog.png"
plot "alg2.t" using 1:2 
