
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
    print(type(reader))
    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    #sort the dataframe by
    sorted_reader = reader.sort_values(by=['state', 'date'], inplace = True)

    #group by state
    grouped = reader.groupby('state')

    new_cases = {}
    previous_cases = {}

    for index, row in reader.iterrows():
        state = row['state']
        cases_today = row['cases']



    return new_cases
# # TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    ...


main()
