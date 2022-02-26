dobro x = x + x

quadruplo y = dobro (dobro y)

areaTriangulo a b c = 
    let s = (a + b + c) / 2
        in sqrt((s * (s - a)) * (s - b) * (s - c))

firstOrEmpty :: [[Char]] -> [Char] -- func prototype
firstOrEmpty l = if not (null l) then head l else "Lista esta vazia"