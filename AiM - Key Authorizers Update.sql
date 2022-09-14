# Find all Keys with John as Authorizer
SELECT * FROM ae_kac_key_authorizer
WHERE emp_id = 'W########';

# Insert Avinash as Authorizer on all Keys with John as Authorizer
INSERT INTO ae_kac_key_authorizer (multitenant_id, Key_id, Emp_id, Required_yn, Active_yn, Edit_date, Edit_clerk)
VALUES 
(1,'100K','W########','Y','Y',NOW(),'SQL_LOAD');

# Find all Keys with Avinash as Authorizer
SELECT * FROM ae_kac_key_authorizer
WHERE emp_id = 'W########';

# Delete all Keys with John as Authorizer
DELETE FROM ae_kac_key_authorizer
WHERE emp_id = 'W########';

# Show all Keys with John as Authorizer (expected 0)
SELECT * FROM ae_kac_key_authorizer
WHERE emp_id = 'W########';
