#!/bin/python
import math, PIL.Image

w, h = 640, 640
x, y = -0.5, 0
zoom = 200
radius        = 2**3
maxIterations = 41
continuous    = True

image = PIL.Image.new('L',(w,h),0)

areal = [(a,(a - w/2.)/zoom + x) for a in range(w)]
bimag = [(b,(b - h/2.)/zoom + y) for b in range(h)]
pixel = image.load()

for (b,imag) in bimag:
  for (a,real) in areal:
    v = cv = real + imag*1j
    i = 0
    while i<maxIterations and abs(v)<radius:
      v = v*v + cv
      i += 1
    if i<maxIterations:
      pixel[a,b] = 127+127*math.sin(i - math.log(abs(v),radius)) if continuous else 6*i

image.show()
# image.save("mandelbrot.png")