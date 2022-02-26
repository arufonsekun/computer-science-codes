-- Pattern matching
data Cliente = OrgGovern String
             | Empresa String Integer String String
             | Individuo Pessoa Bool
             deriving Show

data Pessoa = Pessoa String String Genero
            deriving Show

data Genero = Masculino | Feminino | Outro
            deriving Show

nomeCliente :: Cliente -> [Char]
nomeCliente cliente = 
        case cliente of 
            OrgGovern nome -> nome
            Empresa nome _ _ _ -> nome
            Individuo (Pessoa nome s _) _ -> nome ++ " " ++ s

-- nomeCliente (OrgGovern "Google")
-- nomeCliente (Individuo (Pessoa "Junior" "Vitor" Masculino) False)

nomeEmpresa :: Cliente -> Maybe String
nomeEmpresa empresa =
    case empresa of
        Empresa nome _ _ _  -> nome