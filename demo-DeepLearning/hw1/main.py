import sys
import pandas as pd
import numpy as np
# -*- coding:utf-8 -*-

# 加载数据
data = pd.read_csv('./train.csv',encoding = 'big5')

# preprocessiong 前处理
# 取需要的数值部分，将 'RAINFALL' 栏位全部补 0
data = data.iloc[:, 3:]
data[data == 'NR'] = 0
raw_data = data.to_numpy()  #pandas.DataFrame.to_numpy()
                            # convert the DataFrame to a NumPy array


# 提取特征
# 将原始 4320 * 18 的资料依照每个月分重组成 12 个
# 18 (features) * 480 (hours) 的资料
month_data() = {}
for month in range(12):
    sample = np.empty([18, 480])
    for day in range(20):
            sample[:,day * 24 : (day + 1) * 24] = raw_data[18 * (20 * month]




# 每个月会有 480hrs，每 9 小时形成一个 data
# 每个月会有 471 个 data，故总资料数为 471 * 12 笔
# 而每笔 data 有 9 * 18 的 features (一小时 18 个 features * 9 小时)。
# 对应的 target 则有 471 * 12 个(第 10 个小时的 PM2.5)



# normalize 归一化





# 将训练集划分为“train_set"和”validastion_set"


# Training
# Adagrad优化器



# test
test_data = pd.read_csv('./test.csv', header = None, encoding = 'big5')



# prediction 预测



# 将预测结果保存到CSV file中
