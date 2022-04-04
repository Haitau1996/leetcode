SELECT university, AVG(question_cnt) AS avg_question_cnt, AVG(answer_cnt) AS avg_answer_cnt
FROM user_profile
GROUP BY university
HAVING AVG(question_cnt)<5 OR AVG(answer_cnt)<20;
