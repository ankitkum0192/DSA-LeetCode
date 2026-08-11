# Write your MySQL que
SELECT
    (SELECT distinct salary from employee order by salary desc
     limit 1 offset 1

    ) as secondhighestsalary;

