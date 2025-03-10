-- 코드를 입력하세요
SELECT a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, SUM(s.SALES * b.PRICE) AS TOTAL_SALES
FROM BOOK b
INNER JOIN AUTHOR a ON b.AUTHOR_ID = a.AUTHOR_ID
INNER JOIN BOOK_SALES s ON b.BOOK_ID = s.BOOK_ID
WHERE s.SALES_DATE LIKE '2022-01%'
GROUP BY a.author_id, b.category
ORDER BY a.AUTHOR_ID, b.CATEGORY DESC