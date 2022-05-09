SELECT class
FROM courses
GROUP BY class
HAVING count(*)>=5;
# 题解中写的是 having count(distinct student)>=5，数据没问题是 count(*)>=5 好像也能 ac
