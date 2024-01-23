SELECT AVG(songs.energy) AS average_energy_Drake FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name = 'Drake';
