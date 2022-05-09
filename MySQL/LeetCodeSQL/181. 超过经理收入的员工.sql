# 在内连接中， 不一定要连接同一个列或者同名的列
# 这里就是 manageId 和 id 连接

SELECT e1.name AS Employee 
FROM Employee AS e1 JOIN Employee AS e2
    ON e1.managerId = e2.id 
WHERE e1.salary > e2.salary;
