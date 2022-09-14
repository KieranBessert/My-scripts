SELECT role_id, COUNT(role_id) '# of users'
FROM ae_authz_principal role
JOIN ae_group_members grp ON (role.login = grp.login)
WHERE group_tranx_num = 1026
GROUP BY role_id;
