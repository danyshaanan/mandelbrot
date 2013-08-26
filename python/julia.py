#!/bin/python

import math, PIL.Image

w, h = 640, 640
x, y = 0, 0
zoom = 200
radius        = 2**3
maxIterations = 41

areal = [(a,(a - w/2.)/zoom + x) for a in range(w)]
bimag = [(b,(b - h/2.)/zoom + y) for b in range(h)]

image = PIL.Image.new('L',(w,h),0)
pixel = image.load()

for (a,real) in areal:
  for (b,imag) in bimag:
    z = real + imag*1j
    cz = (0.328 + 0.7j)#/2 + z/2 #uncomment for half julia half mandelbrot
    i = 0
    while i<maxIterations and abs(z)<radius:
      z = z*z + cz
      i += 1
    if i<maxIterations:
      pixel[a,b] = 128+128*math.sin(i - math.log(abs(z),radius))

# image.show()
image.save("julia.png")

