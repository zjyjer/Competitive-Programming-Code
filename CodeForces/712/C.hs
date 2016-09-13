main :: IO()
main = do
  (x, y) <- getLine >>= return . (\[x,y] -> (x,y)) . map (read :: String -> Int) . words
  print $ solve (y, y, y, x)

solve :: (Int, Int, Int, Int) -> Int
solve (a, b, c, x)
  | a == x && b == x && c == x = 0
  | a > x || b > x || c > x = error "error!"
  | b + c - 1 > x = solve(b, c, x, x) + 1
  | otherwise = solve(b, c, b + c - 1, x) + 1