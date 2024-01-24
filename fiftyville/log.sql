-- Keep a log of any SQL queries you execute as you solve the mystery.
-- first using schema
.schema
-- what kind of description it provided
SELECT * FROM crime_scene_reports;
-- it seems that description include the type of crime committed
-- filter all the the theft happened on july 28,2021 and on that place
SELECT id, description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = 'Humphrey Street'
AND description LIKE 'Theft%';
-- get the id->295
-- time->10:15am
-- place->Humphrey Street bakery
-- 3 witnesses mentioned the bakery
-- filter inerview of witnesses
SELECT id, name, transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%';
-- 161 Ruth security footage from bakery parking lot car left!
-- 162 Eugene saw thief at emma's bakery ATM on leggett Street withdraw
-- 163 Raymond heard earliest flight out of Fiftyville tomorrow

-- atm not finding enough clue
SELECT id, account_number, amount FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- security not enough clue
SELECT id, license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute > 15 AND minute < 25
AND activity = 'exit';
--combine security,people and phone call and account
SELECT people.id, people.name, people.passport_number FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN airports ON people.name = ai
WHERE phone_calls.year = 2021 AND month = 7 AND day = 28
AND duration <= 60 AND people.license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute > 15 AND minute < 25
AND activity = 'exit')
AND bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw');
--try flights
SELECT flights.id FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE year = 2021 AND month = 7 AND day = 29
AND airports.city = 'Fiftyville'
ORDER BY hour;
--earliest flight_id = 36
SELECT people.id, people.name, people.passport_number FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN airports ON people.name = ai
JOIN flights ON airports.id = flights.origin_airport_id
JOIN passengers ON flights.id = passengers.flight_id
WHERE phone_calls.year = 2021 AND month = 7 AND day = 28
AND duration <= 60 AND people.license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute > 15 AND minute < 25
AND activity = 'exit')
AND bank_accounts.account_number IN (SELECT account_number FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw')
AND ;
