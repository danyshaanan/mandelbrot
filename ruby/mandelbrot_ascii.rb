#!/usr/bin/ruby

require 'Complex'

$ascii = '.`,;:clodxkO0KXNWM'
pixel_size = 20*2
uclid_size = 4.0
asft, bsft = -0.0,-0.6
u2p = uclid_size/pixel_size
yA = (0..pixel_size).collect { |y| (y-pixel_size/2)*u2p+asft }
xA = (0..pixel_size).collect { |x| (x-pixel_size/2)*u2p+bsft }

yA.each do |y|
  xA.each do |x|
    c = oc = Complex(x,y)
    n, mn = 0, 40
    while n<mn and c.abs2<2**2 do
      c = c**2 + oc
      n += 1
    end
    print (n<mn ? $ascii[$ascii.length * Math.sin(n-Math.log(c.abs))] : ' ')*2
  end
  puts
end  

