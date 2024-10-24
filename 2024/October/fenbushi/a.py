import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline

# 读取数据的函数
def read_data(filename):
    nodes = []
    iterations = []
    
    with open(filename, 'r') as file:
        lines = file.readlines()
        for line in lines:
            if line.strip():  # 跳过空行
                node, iteration = map(float, line.strip().split())
                nodes.append(node)
                iterations.append(iteration)
    
    return nodes, iterations

# 绘制平滑的收敛曲线
def plot_smooth_convergence(nodes, iterations):
    # 将数据转换为 numpy 数组
    nodes = np.array(nodes)
    iterations = np.array(iterations)
    
    # 创建插值样条曲线
    spline = make_interp_spline(nodes, iterations, k=3)  # k=3 表示三次样条插值
    nodes_smooth = np.linspace(nodes.min(), nodes.max(), 300)  # 生成更多的平滑点
    iterations_smooth = spline(nodes_smooth)
    
    # 绘图
    plt.figure(figsize=(10, 6))
    plt.plot(nodes_smooth, iterations_smooth, color='b', label='Smooth Curve')
    plt.scatter(nodes, iterations, color='r', label='Data Points')  # 画出原始数据点
    plt.xlabel('Number of Nodes')
    plt.ylabel('Convergence Iterations')
    plt.title('Smoothed Convergence vs Number of Nodes')
    plt.grid(True)
    plt.legend()
    plt.show()

# 读取数据并绘图
filename = 'data_random.txt'  # 假设文件名为 data.txt
nodes, iterations = read_data(filename)

# 绘制平滑图表
plot_smooth_convergence(nodes, iterations)
