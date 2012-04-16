set term png size 1280, 400
set output "quick_sort.png"
#set term dumb
plot 'quick_sort.dat' with lines, x*x/500, x*x/800, x*x/1000
