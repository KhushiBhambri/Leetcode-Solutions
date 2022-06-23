CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare m Int;
set m = n-1;
  RETURN (
      
      # Write your MySQL query statement below.
      select distinct(salary) from employee order by salary desc  LIMIT 1 OFFSET m
  );
END