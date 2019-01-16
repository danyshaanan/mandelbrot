# mandelbrot

Renderings of the Mandelbrot set in various languages

### [C++](cpp/)
Continuous, interactive.

Run in shell and use the `wasd` keys for movement, `rf` for zoom, `tg` for changing the number of iterations, and `o` to quit.
Result will output to `temp.bmp`.

![The Mandelbrot set in cpp](cpp/mandelbrot.png?raw=true)

![The Mandelbrot set in cpp](cpp/mandelbrot_detail.png?raw=true)


### NodeJS
[cli-mandelbrot](https://npmjs.org/package/cli-mandelbrot) is an NPM package ([Github](https://github.com/danyshaanan/cli-mandelbrot)) for viewing and moving in the Mandelbrot set in a terminal, in ascii.

![The Mandelbrot set in nodejs](other/cli-mandelbrot.png?raw=true)

### [Canvas](docs/canvas/) and [GLSL](docs/glsl/)
The Mandelbrot-Julia relation implemented in both Canvas and GLSL
(OpenGL Shading Language over WebGL).

GLSL is much much faster, as can be seen in the similar implementations:

* [GLSL](https://danyshaanan.github.io/mandelbrot/glsl)
* [Canvas](https://danyshaanan.github.io/mandelbrot/canvas)

![The Mandelbrot set in glsl](docs/glsl.png?raw=true)

### [Python](python/)
Continuous, Require PIL:

![The Mandelbrot set in Python](python/mandelbrot.png?raw=true)

### [Go](go/)
![The Mandelbrot set in go](go/mandelbrot.png?raw=true)

### [Scala](scala/)
![The Mandelbrot set in Scala](scala/mandelbrot.png?raw=true)

### [Haskell](haskell/)
![The Mandelbrot set in haskell](haskell/mandelbrot_ascii.png?raw=true)

### [Awk](awk/)
![The Mandelbrot set in awk](awk/mandelbrot_ascii.png?raw=true)

### [Ruby](ruby/)
![The Mandelbrot set in Ruby](ruby/mandelbrot_ascii.png?raw=true)

### [PHP](php/)

![The Mandelbrot set in php](php/mandelbrot_ascii.png?raw=true)

### Spreadsheet

[This Google spreadsheet](https://docs.google.com/spreadsheet/ccc?key=0AoH_g__QQs5ldHE1R0I0TmE3Zmw1c1hmczFlVWt5MWc)
generates the Mandelbrot set out of five formulae - two to define the real and imaginary values of the area,
two to define the real and imaginary parts of the iteration, and one to define the escaping condition.
Those formulae can be found in the five cells marked with borders. All other cells are stretched from them.

## Guest committers

### [PostScript](postscript/)
By [Leerons]

Will get your printer huffing and puffing

![The Mandelbrot set in postscript - minimal version](postscript/preview.minimal.png?raw=true)

![The Mandelbrot set in postscript](postscript/preview.detail.png?raw=true)

[Leerons]: https://github.com/leerons
