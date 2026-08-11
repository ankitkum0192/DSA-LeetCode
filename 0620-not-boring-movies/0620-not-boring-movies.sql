# Write your MySQL query statement below
SELECT id,movie,description,rating
FROM cinema
where id%2=1 and description != 'boring'
ORDER by rating desc;
