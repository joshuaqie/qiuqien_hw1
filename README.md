# 实现方式

## add_ ; sub_ ; mul_ ; scale_ ; transpose_ ; trace_ ; 

定义一个新的Matrix变量c，通过for循环语句遍历数组来实现二级标题中函数的功能，并将新产生的数组存在c中，返回c即实现矩阵的返回。

## det_ 

依据拉普拉斯展开，新定义Matrix c来储存展开式中的余子式，并调用det_matrix(c)计算余子式行列式的值实现函数的递归，将行列式行数为2的情况设置为递归出口，行数为1值则直接返回数值。

```c
for (j = 0; j < c.rows; j++)
{
	for (k = 0; k < c.cols; k++)
	{
		if (k >= i)
			c.data[j][k] = a.data[j + 1][k + 1];
		else
			c.data[j][k] = a.data[j + 1][k];
	}
}
```

通过上述代码实现第一行第i+1个元素的余子式的储存。

## inv_ 

新定义Matrix c来储存余子式，Matrix d来储存伴随矩阵，调用det_matrix()函数来实现伴随矩阵，通过生成伴随矩阵来实现逆矩阵的生成，并储存于Matrix e中。

## rank_ 

初始化秩为数行列数中的较小值，通过for循环遍历矩阵某两行元素实现交换，再循环实现倍加操作，若开始交换前发现主对角线元素及以下元素全为0，则矩阵的秩减一。遍历所有主对角线上的元素后，得到的秩即为矩阵的秩。

## 运行截图



![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082107319.png)



![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082107524.png)



![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082107924.png)





![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082107093.png)



![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082108714.png)



![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082108787.png)



![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082108322.png)





![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082108562.png)



![img](https://qqe-1325487550.cos.ap-shanghai.myqcloud.com/202404082108335.png)

