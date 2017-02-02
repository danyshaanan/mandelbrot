-- Mandelbrot

insideSet' :: Int -> Double -> Double -> Double -> Double -> Bool
insideSet' i a b a0 b0 = checkComplete || not escaped && next
  where checkComplete = i == 0
        escaped = a^2 + b^2 > 4
        next = insideSet' (pred i) (a^2 - b^2 + a0) (2*a*b + b0) a0 b0

insideSet :: Double -> Double -> Bool
insideSet = insideSet' 41 0 0

dot :: Double -> Double -> String
dot n m = if insideSet n m then "00" else "--"
  where insideSet = insideSet' 41 0 0

main =
  let range = [n/16 | n <- [-20..20]] in
  let image = unlines [concat [dot (n - 0.8) m | n <- range] | m <- range] in
  putStrLn image
