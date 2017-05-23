'use strict'

const color = (_ => {
  function hue2rgb(p, q, t) {
    t %= 6
    if (t < 1) return p + (q - p) * t
    if (t < 3) return q
    if (t < 4) return p + (q - p) * (4 - t)
    return p
  }

  return {
    hsvToRgb(h, s, v) {
      const i = Math.floor(h * 6)
      const f = h * 6 - i

      const p = v * (1 - s * (1    ))
      const q = v * (1 - s * (    f))
      const t = v * (1 - s * (1 - f))

      if (i === 0) return { r: v, g: t, b: p }
      if (i === 1) return { r: q, g: v, b: p }
      if (i === 2) return { r: p, g: v, b: t }
      if (i === 3) return { r: p, g: q, b: v }
      if (i === 4) return { r: t, g: p, b: v }
      if (i === 5) return { r: v, g: p, b: q }
    },
    hslToRgb(h, s, l) {
      if (s === 0) return { r: l, g: l, b: l }
      const q = l < 0.5 ? l * (1 + s) : l + s - l * s
      const p = 2 * l - q
      h *= 6
      return {
        r: hue2rgb(p, q, h + 2),
        g: hue2rgb(p, q, h    ),
        b: hue2rgb(p, q, h + 4)
      }
    }
  }
})()
