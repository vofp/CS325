set title "Algorithm 2 - Size Vs. Execution Time"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term png
set output "alg2plot.png"
plot "alg2.t" using 1:2 
