feigenbaum
==========

Arbitrary precision calculations of the Feigenbaum constant.

The code makes use of the GNU Multiple Precision Library (http://gmplib.org/). The code was written on Mac OSX 10.6.8 and hasn't been tested on other platforms. Principally, it should work on any Mac OSX operating system, and any Linux based operating system.



----------
BASIC TECHNIQUES:

Forthcoming...




----------
COMPILING:

The "make" or "make all" commands should compile everything. 




----------
KNOWN ISSUES:

The code is highly recursive, and each iteration takes exponentially longer to complete than the previous. As a result, the stack fills up after about 17 iterations, corresponding to about 8 MB of stack memory. The b-prime function should be rewritten to reduce the level of recursion required.

In the long term, a power series solution must be found.
