# Write your MySQL query statement below
select em.unique_id , emp.name
from Employees as emp
left join EmployeeUNI as em
on emp.id = em.id;