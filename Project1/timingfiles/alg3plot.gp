set title "Algorithm 3 - Size Vs. Execution Time"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term png
set output "alg3plot.png"
plot "alg3.t" using 1:2 
