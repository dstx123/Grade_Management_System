import matplotlib.pyplot as plt
import pandas as pd
import os
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
current_dir = os.path.dirname(os.path.abspath(__file__))  # 获取当前文件夹路径
# 读取student_score.csv文件为DataFrame字符流
df = pd.read_csv(current_dir+'\\student_score.csv', encoding='GBK')

num = df.学号
students_scores_avg = (df.语文+df.数学+df.英语)/3  # 学生平均成绩

plt.title('学生平均成绩分布图')
plt.xlabel('学号')
plt.ylabel('平均分')
plt.bar(num, students_scores_avg)
for x, y in zip(num, students_scores_avg):
    plt.text(x, y, '%.2f' % y, ha='center', va='bottom')
plt.show()
