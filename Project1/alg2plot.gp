set title "Algorithm 2 - Size Vs. Execution Time"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term postscript
set output "alg2.plot"
plot "alg2Timing" using 1:2 
