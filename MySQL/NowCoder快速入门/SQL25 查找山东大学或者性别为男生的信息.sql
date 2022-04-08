SELECT device_id, gender, age,gpa
FROM user_profile
WHERE university='山东大学'
UNION ALL
SELECT device_id, gender, age, gpa
FROM user_profile
WHERE gender='male';
