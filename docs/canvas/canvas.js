'use strict'

function Canvas(id, generator, def) {
  const getColor = i => isFinite(i) ? color.hsvToRgb((i/240)%1, 1, 1) : {}
  const pixelLocation = (x, y) => [x * def.zoom + def.a, y * def.zoom + def.b]
  const zoomAround = (zoom, mouseEvent) => {
    def.a += mouseEvent.offsetX * def.zoom
    def.b += mouseEvent.offsetY * def.zoom
    def.zoom *= zoom
    def.a -= mouseEvent.offsetX * def.zoom
    def.b -= mouseEvent.offsetY * def.zoom
  }
  const getDiff = (e1, e2) => {
    const [x, y] = [e1.offsetX - e2.offsetX, e1.offsetY - e2.offsetY]
    return { x, y, r: Math.hypot(x, y) }
  }

  const canvas = document.getElementById(id)
  const ctx = canvas.getContext('2d')
  const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height)

  const draw = _ => {
    for (let y = 0; y < canvas.height; ++y) {
      for (let x = 0; x < canvas.width; ++x) {
        set(x, y, getColor(generator(pixelLocation(x, y), def.i)))
      }
    }
    ctx.putImageData(imageData, 0, 0)
  }

  const set = (x, y, c) => {
    const index = (canvas.width * y + x) << 2
    imageData.data[index+0] = 255 * c.r
    imageData.data[index+1] = 255 * c.g
    imageData.data[index+2] = 255 * c.b
    imageData.data[index+3] = 255
  }

  let onClick, downE, downTime
  canvas.oncontextmenu = e => false
  canvas.onmousedown = e => {
    downE = e
    downTime = Date.now()
  }
  canvas.onmouseup = upE => {
    const diff = getDiff(downE, upE)
    if (diff.r > 5) {
      def.a += diff.x * def.zoom
      def.b += diff.y * def.zoom
    } else if (Date.now() - downTime > 200) {
      if (onClick) onClick(upE)
    } else {
      zoomAround(upE.which === 1 ? 0.5 : 2, upE)
    }
    draw()
  }
  canvas.onwheel = e => {
    zoomAround(Math.pow(2, -Math.sign(e.wheelDelta)), e)
    draw()
    return false
  }

  draw()

  return {
    pixelLocation,
    setGenerator: gen => (generator = gen, draw()),
    onClick: on => onClick = on
  }
}
