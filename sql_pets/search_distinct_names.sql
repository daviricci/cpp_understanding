SELECT DISTINCT
   name 
FROM
   (
      SELECT
         name 
      FROM
         cats 
      UNION ALL
      SELECT
         name 
      FROM
         dogs
   )
   data;