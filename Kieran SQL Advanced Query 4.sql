# How many women and how many men are working on each department. 
# Display three columns: dept name, gender and number of people working
SELECT dept_name, gender, count(emp_no) as "# of people"
FROM departments natural join dept_emp natural join employees
GROUP BY dept_name, gender;
