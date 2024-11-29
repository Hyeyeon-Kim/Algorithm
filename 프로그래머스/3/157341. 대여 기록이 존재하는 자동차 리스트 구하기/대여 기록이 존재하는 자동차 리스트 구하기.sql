-- 코드를 입력하세요
SELECT c.CAR_ID
FROM CAR_RENTAL_COMPANY_CAR c
INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY h
ON c.CAR_ID = h.CAR_ID
WHERE c.CAR_TYPE = '세단'
GROUP BY c.CAR_ID
HAVING MAX(MONTH(START_DATE) = 10)
ORDER BY c.CAR_ID DESC

# SELECT *
# FROM CAR_RENTAL_COMPANY_CAR c
# INNER JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY h
# ON c.CAR_ID = h.CAR_ID
# WHERE c.CAR_TYPE = '세단' AND MONTH(START_DATE) = 10
# ORDER BY START_DATE DESC