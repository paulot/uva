Compiling:

    make

Usage:

    ./blob <input file>

Cleaning:

    make clean

Algorithm description:

    Find the first '1' in the input while reading the input in and perform flood fill from that point.

Assumptions:
    
   "Cell reads" marks the number of reads of any value from the input after reading the file. 
   There is only one blob in the input file.
   The input file does not contain more than 10 values per line and not more than 10 lines.
   The input file is not malformed.

Ammount of time spent:

    Solving task: 2 hrs
    Preparing packet (Makefile, Readme, etc): 1 hr

Known deficiencies/Possible improvements:

    C-style iterative code: Currently the solution does not make use of classes or templating, this
                            was done on purpose as this code is unlikely to be used for anything other
                            than validating coding ability.
    Use of global variables: The solution leverages global variables both for the input data and the
                             data returned to the user. Again, this could be fixed with a class, however
                             having a class to only solve one very specific task seems like an overkill,
                             especially for a program that will not be integrated into any other system.
