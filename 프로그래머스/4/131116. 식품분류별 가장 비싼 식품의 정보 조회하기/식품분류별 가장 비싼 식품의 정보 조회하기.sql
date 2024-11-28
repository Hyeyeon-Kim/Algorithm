-- 코드를 입력하세요
SELECT CATEGORY, PRICE AS MAX_PRICE, PRODUCT_NAME
FROM FOOD_PRODUCT a
WHERE CATEGORY IN ('과자', '국', '김치', '식용유') AND 
a.PRODUCT_ID = (   
                SELECT PRODUCT_ID
                FROM FOOD_PRODUCT b
                WHERE a.CATEGORY = b.CATEGORY 
                ORDER BY PRICE DESC
                LIMIT 1)
ORDER BY MAX_PRICE DESC