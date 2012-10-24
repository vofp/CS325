set title "Algorithm 4 - Size Vs. Execution Time"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term png
set output "alg4plot.png"
plot "alg4.t" using 1:2 
