all:
	gcc -Wall -g3 main.c
	
.PHONY: plot
plot: insplot
	gnuplot -c q sort.dat
insplot:
	gnuplot -c ins inssort.dat
