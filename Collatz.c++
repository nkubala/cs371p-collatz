// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

#include "Collatz.h"

// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
    int i;
    r >> i;
    if (!r)
        return std::make_pair(0, 0);
    int j;
    r >> j;
    return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>



    //simplest possible solution to collatz problem
    int current = i;
    int test, current_count;
    int max = -1;
    //iterate through all values between i and j
    while (current <= j) {
        current_count = 0;
        test = current;
        // std::cout << "test is " << test << std::endl;

        //while the test value isnt 1, collatz
        while (test > 1) {
            //test is even
            if (test % 2 == 0) {
                test /= 2;
                current_count++;
            }
            //test is odd
            else {
                test = 3 * test + 1;
                current_count++;
            }
        }
        if (current_count > max)
            max = current_count;
        current++;
    }
    return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int i = p.first;
        const int j = p.second;
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
