# Write your MySQL query statement below
SELECT unique_id, name
FROM EmployeeUNI a RIGHT JOIN Employees b
ON a.id=b.id