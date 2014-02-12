There is an input data file, numbers.txt, in directory given_files.
Please note! Use standard library components whenever possible. Prefer standard algorithms to
hand-written loops, such asfor,while ordo (avoid completely, if possible). When required, define
components of your own, e.g. function objects.
If you need to define an operation to supply to, e.g., an algorithm, it shall be a function object t or
a lambda expression, not a normal function.
The program shall read input from the standard input stream, cin. When the program is run, cin is
to be redirected to read from a given input file, i.e. on the command line you shall write, e.g.:
a.out < given_files/numbers.txt
Output is to be written to the standard output stream, cout.
The program shall do the following, step by step.Note, in each step, no more, no less than what is
specified shall be done!
1) read all values from the input fil and store them in a, for the computations to be done, suitable
sequential standard container
2) print all values in the container onto cout, with one space after each value
3) sort the values in the container in ascending order (smallest first)
4) print all values in the container onto cout, with one space after each value
5) replace all odd values in the container with zero (0)
6) print all values in the container onto cout, with one space after each value
7) remove all elements in the container which are zero (0)
8) print all values in the container onto cout, with one space after each value
The output from the program shall be, including headings:
32 values read:
6 9 1 4 1 3 6 8 4 5 8 6 4 6 9 3 1 2 2 3 6 4 7 5 6 4 7 1 8 3 9 4
Values sorted:
1 1 1 1 2 2 3 3 3 3 4 4 4 4 4 4 5 5 6 6 6 6 6 6 7 7 8 8 8 9 9 9
Odd values replaced with zeroes:
0 0 0 0 2 2 0 0 0 0 4 4 4 4 4 4 0 0 6 6 6 6 6 6 0 0 8 8 8 0 0 0
Zeroes removed:
2 2 4 4 4 4 4 4 6 6 6 6 6 6 8 8 8
(It is possible to solve this using only standard library components… )