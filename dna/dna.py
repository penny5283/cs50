import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        database = list(reader)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        sequence = file.read()


    # TODO: Find longest match of each STR in DNA sequence
    current_count = {}
    sequence_counts = {}
    for str in database[0].keys():
        if str != "name":
            current_count = {str: longest_match(sequence, str)}
            sequence_counts.update(current_count)

    # TODO: Check database for matching profiles
    # Loop through each person in the database
    for person in database:

        # Assume this person is a match until proven otherwise
        is_match = True

        # Check each STR count against the DNA sequence's counts
        for str in sequence_counts:
            # Convert the STR count from the database (which is a string) to an integer
            database_str_count = int(person[str])

            # Get the STR count from the DNA sequence
            sequence_str_count = sequence_counts[str]

            # If any STR count doesn't match, set is_match to False and break out of this inner loop
            if database_str_count != sequence_str_count:
                is_match = False
                break

        # If, after checking all STRs, is_match is still True, print the person's name
        if is_match:
            print(person['name'])
            # Exit the function after finding a match
            return

    # If the loop completes without finding a match, print "No match"
    print("No match")


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
