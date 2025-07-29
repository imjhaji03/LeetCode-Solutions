# Write your MySQL query statement below
SELECT MAX(e1.Salary) AS SecondHighestSalary
FROM Employee e1 INNER JOIN Employee e2
ON e1.Salary < e2.Salary