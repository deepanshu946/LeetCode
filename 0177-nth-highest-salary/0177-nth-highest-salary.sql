CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT

BEGIN

    DECLARE off INT;

    SET off = N - 1;

    RETURN (

        SELECT DISTINCT salary

        FROM Employee

        ORDER BY salary DESC

        LIMIT off, 1

    );

END