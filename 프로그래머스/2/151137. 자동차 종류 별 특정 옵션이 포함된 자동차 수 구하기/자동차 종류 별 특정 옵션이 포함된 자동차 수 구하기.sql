-- 코드를 입력하세요
SELECT CAR_TYPE, COUNT(CAR_TYPE) AS CARS
FROM CAR_RENTAL_COMPANY_CAR
WHERE OPTIONS LIKE '%열선%' OR OPTIONS LIKE '%가죽%' OR OPTIONS LIKE '%통풍%'
GROUP BY CAR_TYPE
ORDER BY CAR_TYPE