set title "Algorithm 3 and 4 Log Compare"
set xlabel "log(Size of Array)"
set ylabel "log(Seconds)"
set logscale xy
set autoscale
set term png
set key left top
set output "alglogcompare.png"
plot "alg4.t" using 1:2, "alg3.t" using 1:2
