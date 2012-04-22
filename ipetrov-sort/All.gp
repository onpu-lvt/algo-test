set term png size 1280, 400
set output "All.png"
plot 'InsertionSort.dat' with lines, 'MergeSort.dat' with lines
