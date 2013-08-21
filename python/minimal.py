import PIL.Image
s=255
i,r=PIL.Image.new('L',(2*s,)*2),range(-s,s)
for b in r:
 for a in r:
  o=x=(a+b*1j)/99
  h=s
  while abs(x)<h:h,x=h-9,x*x+o
  i.load()[s+a,s+b]=h
i.show()
