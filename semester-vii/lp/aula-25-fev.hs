fatorial :: Integer -> Integer
fatorial n = if n == 0
        then 1
        else fatorial(n - 1) * n

-- Pattern matching
fatorial' :: Integer -> Integer
fatorial' 0 = 1
fatorial' 1 = 1
fatorial' 2 = 2
fatorial' n = fatorial'(n - 1) * n

-- Pattern matching
powerOfTwo :: Integer -> Integer
powerOfTwo 0 = 1
powerOfTwo n = 2 * powerOfTwo(n - 1)

powerOfTwo' :: Integer -> Integer
powerOfTwo' n
    | n == 0 = 1
    | n > 0 = 2 * powerOfTwo'(n - 1)

mul :: Int -> Int -> Int
mul m n
    | n == 0 = 0
    | n > 0  = m + mul m (n-1)

(++++) :: [Int] -> [Int] -> [Int]
[] ++++ lst2 = lst2
(h:t) ++++ lst2 = h : (t ++++ lst2)

merge :: [Int] -> [Int] -> [Int]
merge [] lst2 = lst2
merge (h:t) lst2 = h : (merge t lst2)

factInt:: Int -> Int -> Int
factInt m n = 
    if m == n then n
    else n * factInt m (n - 1)

fibo:: Int -> Int
fibo n
    | n == 0 = 0
    | n == 1 = 1
    | n == 2 = 1
    | n > 2  = fibo (n-2) + fibo (n-1)
    
soma:: Int -> Int -> Int
soma x y = x + y
let soma2 = soma 2 -- aplicação parcial da função
soma2 4
