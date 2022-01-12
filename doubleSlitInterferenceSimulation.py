import matplotlib.pyplot as plt
import numpy as np
from matplotlib.widgets import Slider, Button

plt.style.use('dark_background')

X = np.arange(-0.005,0.005,0.00001)
width = 100*(10**-6)
distance = 0.5
gap = 0.001
wavelength = 500*(10**-9)

def calculate (slit_width, wavelength, screen_distance, distance_between_slits,  X) :
    return (((np.sin((np.pi*slit_width*X)/(wavelength*screen_distance)))/((np.pi*slit_width*X)/(wavelength*screen_distance)))**2)*((np.cos((np.pi*distance_between_slits*X)/(wavelength*screen_distance)))**2)


Y = calculate (width, wavelength, distance, gap, X)

plot, = plt.plot(X,Y)
plt.xlabel("Distance from center")
plt.ylabel("Intensity")

plt.subplots_adjust(bottom=0.35)

ax2 = (plt.axes([0.25, 0.20, 0.65, 0.03]))
ax3 = (plt.axes([0.25, 0.15, 0.65, 0.03]))
ax4 = (plt.axes([0.25, 0.10, 0.65, 0.03]))

sW = Slider(ax2, "Width of the Slits", 10, 1000, valinit=width * (10 ** 6))
sD = Slider(ax3, "Distance from Screen", 10, 100, valinit= distance * (10 ** 2))
dS = Slider(ax4, "Gap between slits", 0.1, 10, valinit=gap * (10 ** 3)) 

resetax = plt.axes([0.8, 0.025, 0.1, 0.04])
button = Button(resetax, 'Reset', color='gold',
                hovercolor='skyblue')

def resetSlider(event):
    sW.reset()
    sD.reset()
    dS.reset()

button.on_clicked(resetSlider)

def update(val) :
    width = sW.val*(10**-6)
    distance = sD.val*(10**-2)
    gap = dS.val*(10**-3)
    Y = calculate (width, wavelength, distance, gap, X)
    plot.set_ydata(Y)

sW.on_changed(update)
sD.on_changed(update)
dS.on_changed(update)

plt.show()
  
