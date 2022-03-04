-- 1. Defina uma função que recebe o salário base de um funcionário
-- e resulta no salário líquido a receber, sabendo-se que o
-- funcionário tem gratificação de 10% sobre o salário base e paga
-- imposto de 7% sobre o salário base

liquidSalary salary = salary - taxes + bonus
    where
        taxes = salary * 0.07
        bonus = salary * 0.1

-- 2. Os lados de qualquer triângulo respeitam a seguinte restrição:
-- - A soma dos comprimentos de quaisquer dois lados de um triângulo é superior ao
-- comprimento do terceiro lado.
-- Escreva uma função que receba o comprimento de três segmentos de reta e resulte em um
-- valor lógico indicando se satisfazem esta restrição.

isTriangle a b c = 
    if c > a + b then "It's a triangle"
    else "It's not a triangle"

studentConcept n1 n2 n3 = concept((n1*2 + n2*3 + n3*5) / 10)
    where
        concept note = if note >= 8 && note <= 10 then "A" else concept' note
        concept' note = if note >= 7 && note < 8 then "B" else concept'' note
        concept'' note = if note >= 6 && note < 7 then "C" else concept''' note
        concept''' note = if note >= 5 && note < 6 then "D" else "E"

portraitPrice:: Integer -> [Char] -> Double
portraitPrice amountOfPeople dayWeek =
    let price = price' amountOfPeople in
        if isWeekend dayWeek
            then price + price * 0.2
        else
            price
        where
            isWeekend dayWeek = dayWeek == "sabado" || dayWeek == "domingo"
            price' amountOfPeople
                | amountOfPeople == 1 = 100
                | amountOfPeople == 2 = 130
                | amountOfPeople == 3 = 150
                | amountOfPeople == 4 = 165
                | amountOfPeople == 5 = 175
                | amountOfPeople == 6 = 180
                | amountOfPeople >= 7 = 185

-- 5. Escreva uma função que recebe três números em ponto flutuante,
-- calcula e exibe o produto dos números.
floatProduct:: Float -> Float -> Float -> Float
floatProduct a b c = a * b * c

idealWeight:: Float -> [Char] -> Float
idealWeight height gender
    | gender == "masculino" = 72.7 * height - 58
    | gender == "feminino" = 62.1 * height - 44.7

notesAverage:: Float -> Float -> Float -> ([Char], Float)
notesAverage a b c = isApproved ((a + b + c) / 3)
    where
        isApproved average 
            | average < 3 = ("Reprovado", average)
            | average >= 3 && average < 7 = ("Exame especial", average)
            | average >= 7 = ("Aprovado", average)

-- 8. Escreva uma função que recebe uma String e testa
-- se ela representa uma palíndromo, retornando um Bool.
isPalindrome:: [Char] -> (Bool, [Char])
isPalindrome word = let reversed = reverse word 
    in
        (word == reversed, reversed)

-- 9. A prefeitura de Chapecó abriu uma linha de crédito
-- para os funcionários estatutários. O valor máximo da
-- prestação não poderá ultrapassar 30% do salário bruto.
-- Fazer uma função que permita entrar com o salário bruto
-- e o valor da prestação, e que retorne um booleano indicando
-- se o funcionário pode ou não receber o empréstimo.
ableToGetLoan:: Double -> Double -> [Char]
ableToGetLoan salary installment =
    let salaryLimit = salary * 0.3
        in
    if installment > salaryLimit
        then "Nao podera fazer o imprestimo"
    else "Podera fazer o imprestimo"


electoralClass:: Integer -> [Char]
electoralClass age
    | age < 16 = "Nao eleitor"
    | age >= 18 && age < 65 = "Eleitor obrigatorio"
    | (age >= 16 && age < 18) || age >= 65 = "Eleitor facultativo"

-- 11. O fatorial duplo de um número natural n é o produto de todos
--  os números de 1 (ou 2) até n, contados de 2 em 2. Por exemplo,
-- o fatorial duplo de 8 é 8 × 6 × 4 × 2 = 384, e o fatorial duplo
-- de 7 é 7 × 5 × 3 × 1 = 105 . Defina uma função para calcular o
-- fatorial duplo usando recursividade.

doubleFat n
    | n == 1 = 1
    | n == 2 = 2
    | n == 3 = 3
    | n > 3 = n * doubleFat(n-2)

-- 12. Defina uma função recursiva para calcular a potência de um
-- número, considerando que o expoente é um número natural. Utilize
-- o método das multiplicações sucessivas:
power:: Integer -> Integer -> Integer
power b p = 
    if p == 0 then 1
    else b * power b (p-1)

-- 13. Um funcionário de uma empresa recebe aumento salarial anualmente.
-- O primeiro aumento é de 1,5% sobre seu salário inicial. Os aumentos
-- subsequentes sempre correspondem ao dobro do percentual de aumento do
-- ano anterior. Faça uma função onde é informado o salário inicial do
-- funcionário, o ano de contratação e o ano atual, e calcula e exibe o
-- seu salário atual.
-- currentSalary:: Double -> Integer -> Integer -> Fraction
currentSalary initSal yearHired currentYear = 
        initSal + initSal * salaryIncrease
    where
        yearsWorking = currentYear - yearHired
        increasePercentage = 2 ** yearsWorking
        salaryIncrease = 1.5 * increasePercentage / 100

-- 14. Defina uma função chamada ultimo que seleciona o último elemento de
-- uma lista não vazia, usando as funções do prelúdio.
ultimo list = last list

-- Verificar tamanho usando pattern matching
-- O pattern (x:xs) pega o head e o tail da lista.
tamanho' :: [Int] -> Int
tamanho' [] = 0
tamanho' (x:xs) = 1 + tamanho' xs

-- 15. Defina uma função chamada primeiros que seleciona
-- todos os elementos de uma lista não vazia, exceto o último,
-- usando as funções do prelúdio.
primeiros:: [Int] -> [Int]
primeiros list =
    if length list == 1 then []
    else head list : primeiros(tail list)

-- 16. Faça uma função que receba uma lista de elementos e
-- retorne a soma de todos eles.
soma:: [Int] -> Int
soma list =
    if null list then 0
    else head list + soma(tail list)

-- 17. Faça uma função que receba duas listas e retorne
-- outra lista produto destas duas listas, ou seja, cada
-- posição das listas de entrada devem ser multiplicadas
-- e armazenadas na mesma posição na lista de saída.
produto:: [Int] -> [Int] -> [Int]
produto l1 l2 =
    if null l1 && null l2 then []
    else head l1 * head l2 : produto (tail l1) (tail l2)

-- 18. Defina um novo tipo de dado chamado Produto, que permita
-- armazenar informações sobre:
--     a. Produto perecível: código, descrição, ano de validade
--         e se é comestível ou não.
--     b. Produto não perecível: código, descrição, fabricante,
--         ano de fabricação.
-- Faça testes com este novo tipo de dado.
data Produto = Code String
    | Description String
    | PerishableInfo Int Bool
    | NotPerishableInfo String Int
    deriving Show

getProdInfo:: Produto -> String
getProdInfo produto =
    case produto of
        Code cod -> cod
        Description d -> d
        PerishableInfo _ isEatable -> if isEatable then "Eh comestivel" else "Nao eh comestivel"
        NotPerishableInfo manufacturer _ -> "Feito por " ++ manufacturer

-- 19. Defina um novo tipo de dado para armazenar a forma de comercialização de um produto,
-- com duas opções:
-- a. Unidade
-- b. Peso

data SaleUnit = Unidade | Peso
    deriving Show

data Produto' = Code' String
    | Description' String
    | PerishableInfo' String Bool SaleUnit
    | NotPerishableInfo' String String SaleUnit
    deriving Show

getProdInfo':: Produto' -> String
getProdInfo' produto =
    case produto of
        Code' cod -> cod
        Description' d -> d
        PerishableInfo' _ isEatable unit -> if isEatable then "Eh comestivel" else "Nao eh comestivel"
        NotPerishableInfo' manufacturer manufacturingDate unit -> "Feito por " ++ manufacturer ++ " no dia " ++ manufacturingDate
-- getProdInfo' (NotPerishableInfo' "Santa Terezinha" "12/02/2022")

-- 20. Faça uma função que receba um produto e o ano atual e verifique se
-- ele ainda está válido para uso, retornando um valor booleano. Considere
-- que produtos não perecíveis sempre estão válidos.

isValid:: Produto -> Int -> Bool
isValid produto currentYear =
    case produto of
        Code c -> False
        Description d -> False
        PerishableInfo validityDate _ -> 
            if validityDate < currentYear then False
            else True
        NotPerishableInfo _ _-> True

-- 21. Escreva as funções and e or usando casamento de padrões.
and' :: Bool -> Bool -> Bool
and' True True = True
and' _ _ = False

or' :: Bool -> Bool -> Bool
or' False False = False
or' _ _ = True

-- 22. Usando casamento de padrão, defina uma função que, dada uma
-- lista de números, retorna: 
--     a. a soma dos dois primeiros elementos, se a lista tiver
--          pelo menos dois elementos;
--     b. a cabeça da lista, se ela contiver apenas um elemento;
--     c. zero, caso contrário.


-- 23. Utilize uma função de alta ordem para realizar a contagem
-- de elementos de uma lista.
conta list =
    if null list then 0
    else 1 + conta(tail list)

tamanho conta list = conta list
-- tamanho conta [2,1,5,1]

-- 24. Utilize uma função de alta ordem para realizar a filtragem
-- de uma lista de tuplas que contém o nome e o telefone de determinadas pessoas.

getContacts:: (String, String) -> Bool
getContacts contact = head (fst contact) == 'J'
-- filter getContacts [("Junior", "8823-5891"), ("Pai", "8837-8954"), ("mae", "8816-0155")]