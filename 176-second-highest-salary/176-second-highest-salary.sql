# Write your MySQL query statement below

With maxSal as 
(Select (salary) from employee where salary!= (Select max(salary) from employee))
Select max(salary) as SecondHighestSalary from maxSal