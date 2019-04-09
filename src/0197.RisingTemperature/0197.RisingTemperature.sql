# Write your MySQL query statement below
select Weather.id as 'Id' from Weather join Weather w on datediff(Weather.RecordDate,w.RecordDate) =1
and Weather.Temperature > w.Temperature