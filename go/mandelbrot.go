package main

import "fmt"
import "math/cmplx"

func main() {
  for b := -2.; b < 2.; b += 0.1 {
    for a := -2.; a < 2.; a += 0.1 {
      z0 := complex(a, b)
      z := z0
      c := 0
      for cmplx.Abs(z) < 2 && c < 10 {
        z = z * z + z0
        c++
      }
      if c < 10 {
        fmt.Printf("%d%d", c, c)
      } else {
        fmt.Printf("  ")
      }
    }
    fmt.Println("")
  }
}
