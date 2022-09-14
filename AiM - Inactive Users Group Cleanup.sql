DELETE FROM ae_group_members
WHERE ae_group_members.login IN (
SELECT user_id FROM (
    SELECT user_id
    FROM ae_h_emp_e
    WHERE active= 'n') x );
