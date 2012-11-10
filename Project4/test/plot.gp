set autoscale
set term png
set key left top
set output "test.png"
plot "example-input-3.txt" using 2:3
