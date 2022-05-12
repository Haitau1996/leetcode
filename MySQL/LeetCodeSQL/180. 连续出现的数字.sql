SELECT DISTINCT l1.Num AS ConsecutiveNums
FROM (Logs as l1 INNER JOIN Logs AS l2 ON
    l1.id+1 = l2.id) INNER JOIN Logs AS l3 ON
        l1.id+2 = l3.id
WHERE l1.Num = l2.Num AND l1.Num = l3.Num;
