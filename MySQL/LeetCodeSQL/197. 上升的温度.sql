SELECT w2.id 
FROM Weather as w1 JOIN Weather as w2
ON w2.recordDate = date_add(w1.recordDate, interval 1 day)
WHERE w2.Temperature > w1.Temperature;
