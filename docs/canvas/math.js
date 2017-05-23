'use strict'

const math = (_ => {
  const r2 = Math.pow(2, 6)
  const abs2 = (a, b) => a * a + b * b

  const getJulia = c => (z, max) => {
    let a = z[0]
    let b = z[1]
    let prevA, i = 0
    while (true) {
      if (++i > max) return Infinity
      if (abs2(a, b) > r2) return Math.max(0, i - Math.log(abs2(a, b)) / Math.log(r2))
      prevA = a
      a = a * a - b * b + c[0]
      b = 2 * prevA * b + c[1]
    }
  }

  return {
    sampleJulia: getJulia([-0.82, 0.2]),
    getJulia,
    mandelbrot: (z, max) => getJulia(z)(z, max)
  }
})()
