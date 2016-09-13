main :: IO()
main = do
  str <- getLine
  print $ solve str

solve :: String -> Int
solve str
  | even $ length str = walk str
  | otherwise = -1

walk :: String -> Int
walk str = ((abs x) + (abs y)) `div` 2
  where (x, y) = route str (0, 0)

route :: String -> (Int, Int) -> (Int, Int)
route [] (x1, y1) = (x1, y1)
route (x:xs) (x1, y1)
         | x == 'L' = route xs (x1 - 1, y1)
         | x == 'R' = route xs (x1 + 1, y1)
         | x == 'U' = route xs (x1, y1 + 1)
         | x == 'D' = route xs (x1, y1 - 1)