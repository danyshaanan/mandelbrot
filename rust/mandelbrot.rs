
fn main() {
  let mut y0 = -1.1;
  loop {
    let mut x0 = -2.1;
    loop {
      let mut x = 0.;
      let mut y = 0.;
      let mut i = 41;

      print!("{}",
        loop {
          let temp_x = x * x - y * y + x0;
          y = 2. * x * y + y0;
          x = temp_x;
          if x * x + y * y > 4.0 { break '.' }
          i -= 1;
          if i == 0 { break 'X' }
        }
      );
      x0 += 0.025;
      if x0 > 0.5 { break println!() }
    }
    y0 += 0.05;
    if y0 > 1.1 { break }
  }
}
