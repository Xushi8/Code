import numpy as np
from scipy import interpolate
import matplotlib.pyplot as plt

def calc_length(x, y):
    res = 0
    for i in range(len(x) - 1):
        dx = x[i + 1] - x[i]
        dy = y[i + 1] - y[i]
        res += np.sqrt(dx * dx + dy * dy)
    return res

x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
               11, 12, 13, 14, 15, 16, 17, 18, 19, 20])
y = np.array([9.01, 8.96, 7.96, 7.96, 8.02, 9.05, 10.13, 11.18, 12.26, 13.28,
               13.32, 12.61, 11.29, 10.22, 9.15, 7.95, 7.95, 8.86, 9.81, 10.80, 10.93])

spline = interpolate.splrep(x, y)
x1 = np.linspace(0, 20, 100)
y1 = interpolate.splev(x1, spline)
print("长度: ", calc_length(x1, y1))



# 绘图
plt.plot(x, y, 'o', color = 'Indigo', label = 'Point')
plt.plot(x1, y1, color = 'LightGreen', label = 'curve')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.show()

