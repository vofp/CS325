set autoscale
set term png
set key left top
set output "test.png"
plot "example-input-2.txt" using 2:3 with l
