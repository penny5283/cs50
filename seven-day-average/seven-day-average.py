
import requests
import pandas as pd
from io import StringIO


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    str_data = StringIO(decoded_content)
    reader = pd.read_csv(str_data)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ").strip()
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    reader.sort_values(by=['state', 'date'], inplace=True)
    new_cases = {}
    previous_cases = {}

    for index, row in reader.iterrows():
                                                                                                                                                                                                                                                                                                                                        state = row['state']
        cases_today = row['cases']

        if state not in previous_cases:
            previous_cases[state] = cases_today
            new_cases[state] = []
            continue

        new_cases_today = cases_today - previous_cases[state]
        previous_cases[state] = cases_today

        if len(new_cases[state]) >= 14:
            new_cases[state].pop(0)
        new_cases[state].append(new_cases_today)

    return new_cases

# # TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        try:
            if state in new_cases and len(new_cases[state]) >=14:
                average_this_week = sum(new_cases[state][7::])/7
                average_last_week = sum(new_cases[state][:7])/7
                growth = (average_this_week - average_last_week)/average_last_week
                print(f"{state} had a 7-day average of {average_this_week:.2f} cases and increase of {growth:.2f}")
            else:
                print(f"Not enough data for {state}")
        except ZeroDivisionError:
            print(f"Data error for {state} - division by zero.")
main()
