# Write your MySQL query statement below
SELECT unique_id, name
FROM EmployeeUNI AS a RIGHT JOIN Employees AS b
ON a.id=b.id