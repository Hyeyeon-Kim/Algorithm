-- 코드를 입력하세요
SELECT CONCAT('/home/grep/src/', BOARD_ID,'/',FILE_ID,FILE_NAME,FILE_EXT) AS FILE_PATH
FROM USED_GOODS_FILE f
WHERE f.BOARD_ID = (SELECT  BOARD_ID
                   FROM USED_GOODS_BOARD b
                   ORDER BY VIEWS DESC
                   LIMIT 1
                   )
ORDER BY FILE_PATH DESC

