import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline

# 读取数据的函数
def read_data(filename):
    x_values = []
    y_values = []
    
    with open(filename, 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.strip():
                x, y = map(float, line.strip().split())
                x_values.append(x)
                y_values.append(int(y))
    
    return x_values, y_values

# 绘制平滑曲线
def plot_smooth_curve(x_values, y_values):
    # 将数据转换为 numpy 数组
    x_values = np.array(x_values)
    y_values = np.array(y_values)

    # 确保 x_values 是严格递增的
    sorted_indices = np.argsort(x_values)
    x_sorted = x_values[sorted_indices]
    y_sorted = y_values[sorted_indices]

    # 创建插值样条曲线
    spline = make_interp_spline(x_sorted, y_sorted, k=3)  # k=3 表示三次样条插值
    x_smooth = np.linspace(x_sorted.min(), x_sorted.max(), 300)  # 生成更多的平滑点
    y_smooth = spline(x_smooth)

    # 绘图
    plt.figure(figsize=(10, 6))
    plt.plot(x_smooth, y_smooth, color='b', label='Curve')
    plt.scatter(x_sorted, y_sorted, color='r', label='Data Points')  # 画出原始数据点
    plt.xlabel('X (K values)')
    plt.ylabel('Y (Iteration counts)')

    # 限制 y 轴范围
    plt.ylim(0, 1000000)

    # 或者使用对数坐标：
    # plt.yscale('log')

    plt.grid(True)
    plt.legend()
    plt.show()

# 读取数据并绘图
filename = 'data_k.txt'  # 假设文件名为 data.txt
x_values, y_values = read_data(filename)

# 绘制平滑图表
plot_smooth_curve(x_values, y_values)
