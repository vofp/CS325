set title "Algorithm 3 - Size Vs. Execution Time"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term postscript
set output "alg3.plot"
plot "alg3Timing" using 1:2 
