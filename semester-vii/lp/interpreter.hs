data Exp = BTrue
         | BFalse
         | Num Int
         | Add Exp Exp
         | And Exp Exp
         | IF Exp Exp Exp
         deriving Show

step :: Exp -> Maybe Exp
step (Add (Num n1) (Num n2)) = Just (Num (n1 + n2))
step (Add (Num n1) e2) = case (step e2) of
                          Just e2' -> Just (Add (Num n1) e2')
                          Nothing -> Nothing
step (Add e1 e2) = case (step e1) of
                      Just e1' -> Just (Add e1' e2)
                      Nothing -> Nothing

step (And BTrue e2) = Just e2
step (And BFalse _) = Just BFalse
step (And _ BFalse) = Just BFalse
step (And e1 e2) = case (step e1) of
                      Just e1' -> Just (And e1' e2)
                      Nothing -> Nothing
step (IF BTrue e1 _) = Just e1
step (IF BFalse _ e2) = Just e2
step (IF e e1 e2) = case (step e) of
                        Just e' -> Just (IF e' e1 e2)
                        Nothing -> Nothing

step e = Just e
-- let a = Add (Num 1) (Num 2)
-- let b = Add (Num 1) (Add (Num 2) (Num 3))
-- let c = (IF BFalse (Num 1) (Num 2))
-- let d = (IF BTrue (Num 1) (Num 2))