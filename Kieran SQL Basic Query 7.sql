# Display two columns: sex, and sex counts. For all employees that work in the company.
select gender as "sex", count(gender) as sex_count from employees group by gender;
