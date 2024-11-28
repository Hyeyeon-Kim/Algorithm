-- 코드를 작성해주세요

SELECT e.EMP_NO, EMP_NAME, CASE
                            WHEN AVG(g.SCORE) >= 96 THEN 'S'
                            WHEN AVG(g.SCORE) >= 90 THEN 'A'
                            WHEN AVG(g.SCORE) >= 80 THEN 'B'
                            ELSE 'C'
                            END AS GRADE,
                            CASE
                            WHEN AVG(g.SCORE) >= 96 THEN 0.2 * e.SAL
                            WHEN AVG(g.SCORE) >= 90 THEN 0.15 * e.SAL
                            WHEN AVG(g.SCORE) >= 80 THEN 0.1 * e.SAL
                            ELSE 0
                            END AS BONUS
FROM HR_EMPLOYEES e
INNER JOIN HR_GRADE g ON g.EMP_NO = e.EMP_NO
GROUP BY e.EMP_NO
ORDER BY e.EMP_NO