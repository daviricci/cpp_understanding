SELECT
   CASE
      WHEN
         grade >= 8 
      THEN
         name 
      ELSE
         'NULL' 
   END
   AS name, grade, value 
FROM
   (
      SELECT
         * 
      FROM
         notes 
         INNER JOIN
            students 
            ON (students.value <= notes.max_values) 
            AND 
            (
               students.value >= notes.min_values 
            )
   )
   AS data 
ORDER BY
   grade DESC,
   name;