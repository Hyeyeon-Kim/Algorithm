-- 코드를 입력하세요
SELECT i.INGREDIENT_TYPE, SUM(f.TOTAL_ORDER) AS TOTAL_ORDER
FROM FIRST_HALF f
INNER JOIN 
ICECREAM_INFO i
ON f.FLAVOR = i.FLAVOR
GROUP BY INGREDIENT_TYPE
ORDER BY TOTAL_ORDER