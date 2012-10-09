set title "Algorithm 1 - Size Vs. Execution Time"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term postscript
set output "alg1.plot"
plot "alg1Timing" using 1:2 
