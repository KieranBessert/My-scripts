# You will need two queries for this one. 
# It can be done in one but it will require too much copying.
# Using the previous query, create a view (this will help you from copy pasting it) and display the ratio of women to men for each department. 
# Display department and ratio rounded in 2 decimals points.
# For the view use: CREATE OR REPLACE VIEW
# Otherwise scripts will fail if a view exists
select t1.dept_name, round(t1.number_of_people / t2.number_of_people, 2) as "M/F Ratio"
from(SELECT dept_name, gender, count(emp_no) as "number_of_people"
FROM departments natural join dept_emp natural join employees
GROUP BY dept_name, gender) as t1, 
(SELECT dept_name, gender, count(emp_no) as "number_of_people"
FROM departments natural join dept_emp natural join employees
GROUP BY dept_name, gender) as t2
where (t1.dept_name = t2.dept_name) and (t1.gender = "F") and (t2.gender = "M");
