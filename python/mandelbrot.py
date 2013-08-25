#!/bin/python

import math, PIL.Image

w, h = 640, 640
x, y = -0.7, 0
zoom = 200
radius        = 2**3
maxIterations = 41

areal = [(a,(a - w/2.)/zoom + x) for a in range(w)]
bimag = [(b,(b - h/2.)/zoom + y) for b in range(h)]

image = PIL.Image.new('L',(w,h),0)
pixel = image.load()

for (a,real) in areal:
  for (b,imag) in bimag:
    v = cv = real + imag*1j
    i = 0
    while i<maxIterations and abs(v)<radius:
      v = v*v + cv
      i += 1
    if i<maxIterations:
      pixel[a,b] = 128+128*math.sin(i - math.log(abs(v),radius))

# image.show()
image.save("mandelbrot.png")