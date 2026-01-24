-- Write your PostgreSQL query statement below

select e.Name as employee
from Employee as e
inner join Employee m
on e.ManagerID = m.ID
where e.salary > m.Salary