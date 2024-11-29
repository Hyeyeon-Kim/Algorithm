-- 코드를 입력하세요
# SELECT ANIMAL_ID, NAME, IF(SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%', 'O
# ', 'X')
# FROM ANIMAL_INS
# ORDER BY ANIMAL_ID

SELECT ANIMAL_ID, NAME, if (sex_upon_intake like '%Neutered%' or sex_upon_intake like '%Spayed%', "O", "X") from animal_ins
order by ANIMAL_ID

 