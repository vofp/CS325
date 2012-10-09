set title "Algorithm 1 - Size Vs. Execution Time"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term png
set output "alg1plot.png"
plot "alg1.t" using 1:2 
