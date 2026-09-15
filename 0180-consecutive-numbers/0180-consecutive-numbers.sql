# Write your MySQL query statement below
SELECT DISTINCT num AS ConsecutiveNums
FROM logs
WHERE
(
    (id+1,num) IN (SELECT * FROM Logs)
    AND
    (id+2,num) IN (SELECT * FROM Logs)
)