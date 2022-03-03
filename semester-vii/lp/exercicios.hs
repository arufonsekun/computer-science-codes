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

