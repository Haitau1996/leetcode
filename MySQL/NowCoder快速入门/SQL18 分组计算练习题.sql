SELECT gender, university,
        COUNT(*) AS user_num,
        AVG(active_days_within_30) AS avg_active_day,
        AVG(question_cnt) AS avg_question_cnt
FROM user_profile
GROUP BY gender, university;
