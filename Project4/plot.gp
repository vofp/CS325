set autoscale
set term png
set nokey
set output "test.png"
plot  "test/example-input-2.txt" using 2:3,"outputPlot.txt" using 1:2 with l
