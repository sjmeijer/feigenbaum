feigenbaum
==========
----------

Arbitrary precision calculations of the Feigenbaum constant.

The code makes use of the GNU Multiple Precision Library (http://gmplib.org/). The code was written on Mac OSX 10.6.8 and hasn't been tested on other platforms. Principally, it should work on any Mac OSX operating system, and any Linux based operating system.


----------
----------
BASIC TECHNIQUES:

The essential technique maps the techniques of Briggs. 

A bifurcation point is estimated using the last found value of the feigenbaum constant, and a Newton method iterates until the value gets closer to the bifurcation point.

There are several arrays used here:

aa  (2-D)

b

bprime

delta (1-D)

The aa array consists of the successive newton estimations of the bifurcation point. The value of aa[i][0] is the a0, the initial estimation for the next step. The aa[i][M] is the best estimate of the value of the bifurcation point.

The delta array is a vector of the successive values of the feigenbaum constant, increased after each full iteration.


----------
----------
COMPILING:

The "make" or "make all" commands should compile everything. 




----------
----------
KNOWN ISSUES:

The code is highly recursive, and each iteration takes exponentially longer to complete than the previous. As a result, the stack fills up after about 17 iterations, corresponding to about 8 MB of stack memory. The b-prime function should be rewritten to reduce the level of recursion required.

In the long term, for any practical usage, a power series solution must be found.
