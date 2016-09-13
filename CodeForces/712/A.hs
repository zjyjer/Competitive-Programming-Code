import Data.List

main :: IO()
main = do
  n <- readLn :: IO Int
  arrays <- getLine
  putStrLn $ intercalate " " $ map show $ reverse . solve . reverse $ map read $ words arrays

solve ::[Int]->[Int]
solve a = zipWith (+) (0 : a) a
