import pandas as pd
from matplotlib import pyplot as plt 

path = pd.read_csv(r"src\script\log.csv")
wall = pd.read_csv(r"src\script\wall.csv")

fig, ax = plt.subplots()

path_X = []
path_Y  = []
wall_X = []
wall_Y = []

for index,row in path.iterrows(): 
    #对于每一行，通过列名访问对应的元素
    path_X.append(row['x'])
    path_Y.append(row['y'])

ax.plot(path_X, path_Y, label='path') # 作y1 = x 图，并标记此线名为linear

for index,row in wall.iterrows(): 
    #对于每一行，通过列名访问对应的元素
    wall_X.append(row['x'])
    wall_Y.append(row['y'])

ax.plot(wall_X, wall_Y, label='wall') # 作y1 = x 图，并标记此线名为linear

ax.legend() #自动检测要在图例中显示的元素，并且显示
plt.title("A STAR") 
plt.xlabel("x axis caption") 
plt.ylabel("y axis caption") 
plt.show()
