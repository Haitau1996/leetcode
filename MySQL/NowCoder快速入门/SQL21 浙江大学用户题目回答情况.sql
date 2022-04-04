SELECT device_id, question_id, result
FROM question_practice_detail
WHERE device_id in(SELECT user_profile.device_id 
                   FROM user_profile
                   WHERE user_profile.university='浙江大学');
