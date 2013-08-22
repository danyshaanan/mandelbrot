#!/bin/python
import math, PIL.Image

pixel_size = 320*2
uclid_size = 3.2
asft, bsft = -0.5,-0.0
radius     = 2**3
rounds     = 41
continuous = True

u2p = uclid_size/pixel_size
image = PIL.Image.new('L',(pixel_size,pixel_size),0)

bimag = [(b,(b-pixel_size/2)*u2p+bsft) for b in range(pixel_size)]
areal = [(a,(a-pixel_size/2)*u2p+asft) for a in range(pixel_size)]
pixel = image.load()

for (b,imag) in bimag:
  for (a,real) in areal:
    v = cv = real + imag*1j
    n = 0
    while n<rounds and abs(v)<radius:
      v = v*v + cv
      n += 1
    if n<rounds:
      pixel[a,b] = 127+127*math.sin(n - math.log(abs(v),radius)) if continuous else 6*n

image.show()
# image.save("mandelbrot.png")