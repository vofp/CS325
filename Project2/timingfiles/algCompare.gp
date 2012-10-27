set title "Algorithm 3 and 4 Compare"
set xlabel "Size of Array"
set ylabel "Seconds"
set autoscale
set term png
set key left top
set output "algCompareplot.png"
plot "alg4.t" using 1:2, "alg3.t" using 1:2 
