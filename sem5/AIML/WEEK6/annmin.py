import sys,random
w1=w2=1;bias=-1.5;lr=.2;epochs=30
A={(0,0):0,(0,1):0,(1,0):0,(1,1):1};O={(0,0):0,(0,1):1,(1,0):1,(1,1):1}
f=lambda a,b:w1*int(a)+w2*int(b)+bias>=0
def l(a,b,t):
 global w1,w2,bias
 a,b=map(int,(a,b));e=t[a,b]-f(a,b);r=lambda:(random.random()-.5)/10
 w1+=lr*e*a+r();w2+=lr*e*b+r();bias+=lr*e+r()
def T(t):
 for _ in range(epochs):
  for x in t:l(*x,t)
 print(f"After {epochs} epochs, w1:{w1}, w2:{w2}, bias:{bias}")
 for x in t:print(*x,int(f(*x)))
if len(sys.argv)>1:T(A if sys.argv[1]=="--al1" else O);sys.exit()
while 1:
 s=input("Enter inputs (q to quit): ")
 if s.lower()=="q":break
 if len(s)!=2 or any(x not in"01"for x in s):print("Enter exactly 2 digits, each 0 or 1");continue
 c=input("1. AND\n2. OR\nEnter Choice: ")
 if c not in"12":print("Enter integer between 1 and 2");continue
 t=A if c=="1"else O;print(f"Current output for {s} is: {int(f(*s))}")
 for _ in range(10):l(*s,t)
 print(f"After learning: w1={w1}, w2={w2}, bias={bias}")
print("Exiting...")
