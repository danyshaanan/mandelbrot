#!/bin/python

import math, PIL.Image

w, h = 1920, 1080
zoom = 400
radius        = 2**3
maxIterations = 100

frames = 100
framesmo = frames - 1

for f in range(frames):

  image = PIL.Image.new('RGB',(w,h),(0,0,0))
  pixel = image.load()

  x = 0. * f/framesmo + -0.7*(1-1.0*f/framesmo)
  y = 0
  areal = [(a,(a - w/2.)/zoom + x) for a in range(w)]
  bimag = [(b,(b - h/2.)/zoom + y) for b in range(h)]


  for (a,real) in areal:
    for (b,imag) in bimag:
      z = real + imag*1j
      cz = (-0.8 + 0.14j)*f/framesmo + z*(1-1.0*f/framesmo)
      i = 0
      while i<maxIterations and abs(z)<radius:
        z = z*z + cz
        i += 1
      if i<maxIterations:
        contI = i - math.log(abs(z),radius)
        c1 = int(128+128*math.sin(contI+1))
        c2 = int(128+128*math.sin(contI+2))
        c3 = int(128+128*math.sin(contI+3))
        pixel[a,b] = (c1,c2,c3)

  # image.show()
  image.save("output/mandelbrot_to_julia_c_" + str(10000 + f) + ".png")

