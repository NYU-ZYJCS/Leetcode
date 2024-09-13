# Write your MySQL query statement below
select 
    a.score as score,
    (select count(distinct b.score) 
        from Scores as b
        where b.score >= a.score
    ) as `rank`
from Scores as a
order by score DESC