-- 코드를 작성해주세요
SELECT a.ID, (
    SELECT COUNT(*)
    FROM ECOLI_DATA b
    WHERE a.ID = b.PARENT_ID
) AS CHILD_COUNT
FROM ECOLI_DATA a
ORDER BY a.ID