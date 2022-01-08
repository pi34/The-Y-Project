import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as anim

plt.style.use('dark_background')
figure = plt.figure()
figure.set_dpi(100)
ax = figure.add_subplot(1, 1, 1)
x = np.linspace(0, 4.5 * np.pi, 10000)
V = 1

def standing(x, t):
    return (np.sin(x+V*t) + np.sin(x-V*t))

def forward(x, t):
    return (np.sin(x+V*t))

def backward(x, t):
    return (np.sin(x-V*t))

a = []
b = []
c = []

dt = 0

for i in range(5000):
    value = standing(x, dt)
    value2 = forward(x, dt)
    value3 = backward(x, dt)
    dt = dt + 0.05
    a.append(value)
    b.append(value2)
    c.append(value3)


k = 0
def animate(i):
    global k
    xC = a[k]
    xC2 = b[k]
    xC3 = c[k]
    k += 1
    ax.clear()
    ax.set_title('Standing Wave Simulation')
    plt.plot(x, xC, color='red')
    plt.plot(x, xC2, color='blue')
    plt.plot(x, xC3, color='green')
    plt.grid(True)
    plt.ylim([-3,3])
    plt.xlim([0, 4.5 * np.pi])

nim = anim.FuncAnimation(figure,animate,frames=1,interval=20)

plt.show()
 
