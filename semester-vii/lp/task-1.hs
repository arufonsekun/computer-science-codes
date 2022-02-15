isEmpty list = if null list then "A lista é vazia" else " A lista não é vazia"

factorial x = if x == 1 then 1 else x * factorial (x-1)

main = do
    putStrLn(isEmpty [])
    print(factorial 4)
