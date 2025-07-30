# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
Where salary not in (SELECt MAX(salary) FROM Employee);