'use strict'

function Point(a,b) {
  this.a = a
  this.b = b
  this.dupe = function() {
    return new Point(this.a, this.b)
  }
  this.bound = function() {
    return this.a*this.a + this.b*this.b < 4
  }
  this.iterateOver = function(z0) {
    return new Point(this.a*this.a-this.b*this.b + z0.a, this.a*this.b*2 + z0.b)
  }
}

var z0, z, i, ascii = Array.apply(null, new Array(26)).map(function(v, r) {
  return Array.apply(null, new Array(25)).map(function(v, c) {
    z0 = new Point(r/10-2,c/10-1.2)
    z = z0.dupe();
    i = 14
    while(--i>0 && z.bound()) z = z.iterateOver(z0)
    return i ? '.' : 'X'
  }).join('')
}).join('\n')

console.log(ascii)
