SELECT c.name, c.population, c.area
FROM World AS c
WHERE c.area >= 3000000
   OR c.population >= 25000000;
