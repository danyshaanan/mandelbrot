package main

import ("os"; "image"; "image/color"; "image/png"; "math/cmplx"; "math")

func iterations(z0 complex128, max float64) float64 {
	z := z0
	i := 0.0
	for cmplx.Abs(z) < 2 && i < max {
		z = z * z + z0
		i += 1
	}
	return i / max
}

func pixelToPoint(n int, size int) float64 {
	return float64(n) / float64(size) * 4 - 2
}

func main() {
	size := 600
	img := image.NewGray16(image.Rectangle{image.Point{0, 0}, image.Point{size, size}})

	for x := 0; x < size; x++ {
		for y := 0; y < size; y++ {
			z0 := complex(pixelToPoint(x, size), pixelToPoint(y, size))
			col := color.Gray16{uint16(iterations(z0, 20) * math.Pow(2, 16))}
			img.Set(x, y, col)
		}
	}

	f, _ := os.Create("mandelbrot.png")
	png.Encode(f, img)

}