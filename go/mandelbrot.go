package main
import ("fmt"; "strings"; "math/cmplx")

func iterations(z0 complex128, c int) int {
  z := z0
  for cmplx.Abs(z) < 2 && c > 0 {
	z = z * z + z0
	c--
  }
  return c
}

func main() {
  for b := -2.1; b < 2.1; b += 0.1 {
    for a := -2.1; a < 2.1; a += 0.1 {
	  fmt.Printf(strings.Repeat(string(" .,:cloO0X"[iterations(complex(a, b), 9)]), 2))
    }
    fmt.Println()
  }
}
