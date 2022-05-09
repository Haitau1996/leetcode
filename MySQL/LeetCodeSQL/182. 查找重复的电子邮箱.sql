# Write your MySQL query statement below
SELECT DISTINCT a.Email 
FROM Person as a INNER JOIN Person as b
ON a.Email = b.Email and a.Id < b.Id;
