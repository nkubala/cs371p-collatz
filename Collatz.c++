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

    //check preconditions
    assert(i > 0);
    assert(i < 1000000);
    assert(j > 0);
    assert(j < 1000000);

    //simplest possible solution to collatz problem
    int low, high;
    if (i < j) {
        low = i;
        high = j;
    }
    else {
        low = j;
        high = i;
    }
    int current = low;
    int current_count;
    int max = -1;

    //iterate through all values between i and j
    while (current <= high) {

        //pass value to helper function to compute
        current_count = compute_collatz(current);
        if (current_count > max)
            max = current_count;
        current++;
    }

    assert(max > 0);
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


int compute_collatz(int i) {
    int current_count = 1;
    //while the i value isnt 1, collatz
    while (i > 1) {
        //i is even
        if (i % 2 == 0) {
            i /= 2;
            //make sure we didn't overflow
            // assert(i > 0);
            current_count++;
        }
        //i is odd
        else {
            i = 3 * i + 1;
            //make sure we didn't overflow
            // assert(i > 0);
            current_count++;
        }
    }
    return current_count;
}