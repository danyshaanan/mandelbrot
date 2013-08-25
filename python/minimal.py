import PIL.Image
s=255
i=PIL.Image.new('L',(2*s,)*2)
r=range(-s,s)
for a in r:
 for b in r:
  o=x=(a+b*1j)/99
  h=s
  while abs(x)<h:
   h-=9
   x=x*x+o
  i.load()[s+a,s+b]=h
i.show()
