-- Keep a log of any SQL queries you execute as you solve the mystery.
-- first using schema
.schema
--what kind of description it provided
SELECT * FROM crime_scene_reports;
--it seems that description include the type of crime committed
--filter all the the theft happened on july 28,2021 and on that place
SELECT id, description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = 'Humphrey Street'
AND description LIKE 'Theft%';
--get the id->295
--
