SELECT max(salary) as SecondHighestSalary 
FROM Employee as e1
WHERE e1.salary < (SELECT max(salary) FROM Employee);
