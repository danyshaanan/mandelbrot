#!/bin/python

import math, PIL.Image

w, h = 640, 640
zoom = 200
radius        = 2**3
maxIterations = 41


frames = 100
framesmo = frames - 1

for f in range(frames):

  image = PIL.Image.new('L',(w,h),0)
  pixel = image.load()
  # x = 0. * f/framesmo + -0.7*(1-1.0*f/framesmo)
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
        pixel[a,b] = 128+128*math.sin(i - math.log(abs(z),radius))

  # image.show()
  image.save("output/mandelbrot_to_julia_bw_" + str(10000 + f) + ".png")

