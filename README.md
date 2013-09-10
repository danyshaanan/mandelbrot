# mandelbrot

Renderings of the Mandelbrot set in various languages

#### cpp
Continuous, interactive.

Run in shell and use the `wasd` keys for movement, `rf` for zoom, `tg` for changing the number of iterations, and `o` to quit.
Result will output to `temp.bmp`.

![The Mandelbrot set in cpp](cpp/mandelbrot.png?raw=true)

![The Mandelbrot set in cpp](cpp/mandelbrot_detail.png?raw=true)

These two images were rendered at 1400x1400 and shrunk to 50% for smoothings.

#### nodejs
[cli-mandelbrot](https://npmjs.org/package/cli-mandelbrot),
which is in [another repo](https://github.com/danyshaanan/cli-mandelbrot)
is an npmjs package for viewing and moving in the Mandelbrot set in a terminal, in ascii.

![The Mandelbrot set in nodejs](other/cli-mandelbrot.png?raw=true)

#### javascript + canvas
Continuous, interactive, using HTML5's canvas object.
[&#91;live demo&#93;](http://leerons.github.io/mandelbrot.html)

![The Mandelbrot set in javascript + canvas](js-canvas/mandelbrot.png?raw=true)

![The Mandelbrot set in javascript + canvas](js-canvas/mandelbrot_detail.png?raw=true)

#### python
Continuous, Require PIL:

![The Mandelbrot set in Python](python/mandelbrot.png?raw=true)

#### ruby
![The Mandelbrot set in Ruby](ruby/mandelbrot_ascii.png?raw=true)

#### php
Simple ascii version:

![The Mandelbrot set in php](php/mandelbrot_ascii.png?raw=true)

#### postscript
Will get your printer huffing and puffing

![The Mandelbrot set in postscript - minimal version](postscript/preview.minimal.png?raw=true)

![The Mandelbrot set in postscript](postscript/preview.detail.png?raw=true)

#### Spreadsheet (or Excel)
Not a real language, but still noteworthy.

[This Google spreadsheet](https://docs.google.com/spreadsheet/ccc?key=0AoH_g__QQs5ldHE1R0I0TmE3Zmw1c1hmczFlVWt5MWc)
generates the Mandelbrot set out of five formulae - two to define the real and imaginary values of the area,
two to define the real and imaginary parts of the iteration, and one to define the escaping condition.
Those formulae can be found in the five cells marked with borders. All other cells are stretched from them.
