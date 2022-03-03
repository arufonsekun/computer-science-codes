-- Uso do Where
areaTriangulo a b c = sqrt(s * (s - a) * (s - b) * (s - c))
    where 
        s = (a + b + c) / 2

-- Uso do let
areaTriangulo' a b c = let s = (a + b + c) / 2
    in
        sqrt(s * (s - a) * (s - b) * (s - c))

-- Funções temporárias definidas localmente
myFunc x = 3 + f x + f a + f b
    where
        f x = x + 7 * c
        a = 3 * c
        b = f 2
        c = 10 
