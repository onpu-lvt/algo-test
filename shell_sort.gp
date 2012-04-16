set term png size 1280, 400
set output "shell_sort.png"
#set term dumb
plot 'shell_sort.dat' with lines, x*x/500, x*x/800, x*x/1000
