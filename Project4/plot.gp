set autoscale
set term png
set key left top
set output "test.png"
plot  "test/example-input-2.txt" using 2:3,"output.txt" using 1:2 with l
