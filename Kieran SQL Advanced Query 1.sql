# Display the first_name, last_name, latest salary of the 10 higher salaried employees still actively working in the company
select first_name, last_name, salary from employees natural join salaries where to_date = "9999-01-01" order by salary desc limit 10;
