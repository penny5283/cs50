SELECT AVG(rating) AS average_rating_o_all FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE movies.year = 2012;
