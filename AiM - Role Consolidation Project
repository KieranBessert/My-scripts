# Count roles present in specific group
# Assists in determinig what roles most people are in
SELECT role_id, COUNT(role_id) '# of users'
FROM ae_authz_principal role
JOIN ae_group_members grp ON (role.login = grp.login)
WHERE group_tranx_num = 1026
GROUP BY role_id;

# See all Privileges inside a list of roles
SELECT * FROM ae_authz_privilege
WHERE role_id IN ('FM USER','IQ-001','SP-007','TM-006','U-002','WESTERN USER','wk-005');

# Count all Privileges inside a list of roles
SELECT privilege_id , COUNT(privilege_id) '# of privilege' 
FROM ae_authz_privilege
WHERE role_id IN ('FM USER','IQ-001','SP-007','TM-006','U-002','WESTERN USER','wk-005')
GROUP BY privilege_id;

# Check specific privileges inside specific roles
SELECT * FROM ae_authz_privilege
WHERE role_id = 'tradesperson'
AND privilege_id like 'craft%';

