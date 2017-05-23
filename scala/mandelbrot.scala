
import java.io.File
import javax.imageio.ImageIO
import java.awt.image.BufferedImage
import scala.annotation.tailrec

val size = 600

def grey(v: Int) = v << 16 | v << 8 | v
def color(i: Int) = grey(41 * i)
def map(v: Double) = 4 * (v / size - 0.5)

@tailrec
def mandelbrot(a0: Double, b0: Double, a: Double = 0, b: Double = 0, i: Int = 0): Int =
  if (a * a + b * b > 4) i
  else if (i >= 100) 0
  else mandelbrot(a0, b0, a * a - b * b + a0, 2 * a * b + b0, i + 1)

val image = new BufferedImage(size, size, BufferedImage.TYPE_INT_RGB)

for {
  x <- 0 until size
  y <- 0 until size
} image.setRGB(x, y, color(mandelbrot(map(x), map(y))))

ImageIO.write(image, "PNG", new File("mandelbrot.png"))
