# Write your MySQL query statement below
SELECT b.id
FROM Weather a JOIN Weather b 
ON datediff(b.recordDate ,a.recordDate)=1
WHERE b.temperature > a.temperature;