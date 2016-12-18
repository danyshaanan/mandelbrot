#!/usr/bin/awk -f

BEGIN {
  for (y = -1.2; y <= 1.2; y += 0.06) {
    for (x = -2.2; x <= 1; x += 0.06) {
      a = a0 = x
      b = b0 = y
      for (n = 50; n && a * a + b * b < 4; n--) {
        ta = a * a - b * b + a0
        tb = 2 * a * b + b0
        a = ta
        b = tb
      }
      res = res (n ? ".." : "XX")
    }
    res = res "\n"
  }
  print res
}
