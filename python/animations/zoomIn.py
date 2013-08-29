#!/bin/python

import math, PIL.Image

r = 1./2

w, h = int(1920*r), int(1080*r)
x, y = -1.1497082839086437, -0.3122206435405219
izoom = 400000000.0*r
radius        = 2**3
maxIterations = 500

frames = 100
framesmo = frames - 1

mul = izoom**(1./(frames-20))

rng = range(3) + range(frames/2, frames/2 + 3) + range(frames - 3,frames)
rng = range(frames - 3, frames)
rng = range(frames)
for f in rng:

  zoom = mul**(f)

  image = PIL.Image.new('L',(w,h),0)
  pixel = image.load()

  areal = [(a,(a - w/2.)/zoom + x) for a in range(w)]
  bimag = [(b,(b - h/2.)/zoom + y) for b in range(h)]


  for (a,real) in areal:
    for (b,imag) in bimag:
      z = real + imag*1j
      cz = z
      i = 0
      while i<maxIterations and abs(z)<radius:
        z = z*z + cz
        i += 1
      if i<maxIterations:
        v = i - math.log(abs(z),radius) - f/10.
        if v > -math.pi/2.:
          pixel[a,b] = 128+128*math.sin(v)

  # image.show()
  filename = "output/zoomIn_" + str(1000000 + f) + ".png"
  image.save(filename)
  print filename


