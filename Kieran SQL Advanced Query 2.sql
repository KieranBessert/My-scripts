# Display the first name and last name as well as department name of all current department managers. SORT by department name, last name, first name
select first_name, last_name, dept_name from employees natural join dept_manager natural join departments where to_date = "9999-01-01" order by dept_name, last_name, first_name;
