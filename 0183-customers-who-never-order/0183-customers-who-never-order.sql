# Write your MySQL query statement below
SELECT name AS Customers FROM Customers  
LEFT JOIN Orders AS b
ON Customers.id=b.customerId
WHERE b.id IS NULL;