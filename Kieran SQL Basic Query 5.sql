# Display the first name, last name and rounded years worked of all employees sorted in a desceding order based on the rounded years
select first_name, last_name, timestampdiff(year, hire_date, curdate()) as "years_worked" from employees order by timestampdiff(year, hire_date, curdate()) desc;
