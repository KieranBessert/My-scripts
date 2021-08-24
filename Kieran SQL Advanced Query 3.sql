#  Which employee got the largest salary increase since they started working in the company? 
# (display emp_no, salary increase in percentage rounded in 2 decimal places, e.g., 100%)
select emp_no, round((max(salary) -min(salary)) / min(salary)*100, 2) as "salary_increase"
from salaries
group by emp_no
order by (max(salary) / min(salary)) desc
LIMIT 1;
