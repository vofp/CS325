set autoscale
set term png
set nokey
set output "test.png"
plot  "test/example-input-3.txt" using 2:3,"output.txt" using 1:2 with l
