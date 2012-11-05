set xlabel "x"
set ylabel "y"
set autoscale
set term png
set key left top
f(x) = (12+8.8*x)/5.5 
set output "plot.png"
plot f(x),"points.dat" using 1:2 
