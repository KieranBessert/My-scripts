# Display the age of the oldest employee (as an int) in absolute years (assuming they are still working there)
select timestampdiff(year, birth_date, curdate()) as Age from employees order by birth_date limit 1;
