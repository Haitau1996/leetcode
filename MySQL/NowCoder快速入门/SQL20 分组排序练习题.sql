SELECT university, AVG(question_cnt) AS avg_question_cnt
FROM user_profile
GROUP BY university
ORDER BY AVG(question_cnt);
