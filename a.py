import numpy as np
import matplotlib.pyplot as plt

# 读取数据的函数，处理大规模数据
def read_data(filename):
    iterations = []
    values = []
    
    with open(filename, 'r') as file:
        lines = file.readlines()
        for i in range(0, len(lines), 3):
            iteration = int(lines[i].strip())
            value = list(map(float, lines[i+1].strip().split()))
            
            iterations.append(iteration)
            values.append(value)
    
    return iterations, values

# 判断收敛的函数
def check_convergence(data, threshold):
    var = np.var(data)
    return var < threshold

# 优化的绘制函数，处理大规模数据
def plot_convergence(iterations, values, threshold, max_points=500):
    input_lengths = [len(v) for v in values]
    convergence_iterations = []

    for i in range(len(values)):
        iteration = iterations[i]
        value = values[i]
        
        if check_convergence(value, threshold):
            convergence_iterations.append(iteration)
        else:
            convergence_iterations.append(None)
    
    # 如果数据点过多，进行下采样
    if len(input_lengths) > max_points:
        sampled_indices = np.linspace(0, len(input_lengths) - 1, max_points, dtype=int)
        input_lengths = [input_lengths[i] for i in sampled_indices]
        convergence_iterations = [convergence_iterations[i] for i in sampled_indices]

    plt.figure(figsize=(10, 6))
    plt.plot(input_lengths, convergence_iterations, marker='o', linestyle='-', color='b')
    plt.xlabel('Input Array Length')
    plt.ylabel('Convergence Iterations')
    plt.title(f'Convergence vs Input Length (Variance Threshold: {threshold})')
    plt.grid(True)
    plt.show()

# 读取数据并绘图
filename = 'data.txt'  # 假设文件名为 data.txt
iterations, values = read_data(filename)

# 设置收敛判断的方差阈值
variance_threshold = 0.05

# 绘制图表，最大显示500个数据点
plot_convergence(iterations, values, variance_threshold, max_points=500)
