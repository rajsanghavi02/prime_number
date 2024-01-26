# Prime Number Program

## Problem Statement

Write a C program to find and print "good prime numbers" between 1 and 1000. Store these good prime numbers in a file named "gprime.txt". Additionally, print and store in another file, named "cgprime.txt," those good prime numbers that are also "circular primes."

## Definition

A good prime is a prime number whose square is greater than the product of any two primes at the same number of positions before and after it in the sequence of primes.

A good prime satisfies the inequality: \( p_0^2 > p_i \cdot p_{i+n} \) for all \( 0 \leq i \leq n-1 \), where \( p_i \) is the \( i \)th prime.

The first 20 Good Prime numbers are: 5, 11, 17, 29, 37, 41, 53, 59, 67, 71, 97, 101, 127, 149, 179, 191, 223, 227, 251, 257.

## Approach

1. **Generate Prime Numbers:** Use a function to generate prime numbers up to 1000.
2. **Identify Good Primes:** Check each prime number if it satisfies the condition of being a "good prime."
3. **Identify Circular Primes:** For each good prime, check if it is also a "circular prime."
4. **Print and Store:** Print the results to the console and store them in a file named "prime_results.txt."

## File Structure

- **prime_program.c:** Contains the complete program logic.
  - Prints results using `printf`.
  - Stores results in "prime_results.txt."

## Running the Program

1. Compile the program using a C compiler.
   ```bash
   gcc prime_program.c -o prime_program
