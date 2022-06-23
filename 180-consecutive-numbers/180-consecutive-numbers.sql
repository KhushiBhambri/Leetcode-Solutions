# Write your MySQL query statement below
select distinct(num) as ConsecutiveNums from logs

    where (Id+1,num) in (select * from logs)
    and (Id+2,num) in (select * from logs)
    
