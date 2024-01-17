import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database = sys.argv[1]
    str_patterns = []
    with open(database, mode = 'r') as d:
        database_r = csv.reader(d)
        for row in database_r:
            header = row
            break
        for i in header:
            if i != "name":
                str_patterns.append(i)
    # TODO: Read DNA sequence file into a variable
    sequence = sys.argv[2]
    with open(sequence, mode = 'r') as s:
        sequence_r = csv.reader(s)
        gene = next(sequence_r)
        gene_str = "".join(gene)
        print(gene_str)
    # TODO: Find longest match of each STR in DNA sequence
    d
    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
