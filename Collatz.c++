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

//global cache of collatz values (lazy cache)
int cache[1000000] = {};

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
        //check if value has already been computed
        if (cache[current] != 0 ) current_count = cache[current];
        //pass value to helper function to compute
        else current_count = compute_collatz(current);
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

/*
    compute_collatz
    helper function to compute the collatz value for an individual number
*/

int compute_collatz(int i) {
    int test = i;
    int current_count = 1;
    //while the i value isnt 1, collatz
    while (test > 1) {
        //i is even
        if (test % 2 == 0) {
            test /= 2;
            current_count++;
        }
        //i is odd
        else {
            test = 3 * test + 1;
            current_count++;
        }
    }
    cache[i] = current_count;
    return current_count;
}