#!/usr/bin/env python3

target = 1000-1

def sum_divisible(n: int) -> int:
    """
    will calculate the sum of numbers that are multiple of n up to our target.

    :param n: Our multiple number
    :return: The sum of all numbers that are multiple of n up to our target
    """

    # Get our limit to be calculated.
    p = target // n

    # Calculate our number until this limit using the summation formula n(n+1)/2
    # We need to multiplity it to our n.
    return n * (p*(p+1) // 2)

if __name__ == '__main__':
    # Substract all the numbers that were divisible by 15, these numbers were calculated
    # twice by 3 and 5.
    print(sum_divisible(3) + sum_divisible(5) - sum_divisible(15))
