-- 코드를 입력하세요
SELECT a.FOOD_TYPE, a.REST_ID, a.REST_NAME, a.FAVORITES	
FROM REST_INFO a
WHERE a.FAVORITES = (
                    SELECT MAX(b.FAVORITES)
                    FROM REST_INFO b
                    WHERE a.FOOD_TYPE = b.FOOD_TYPE
                )
ORDER BY FOOD_TYPE DESC