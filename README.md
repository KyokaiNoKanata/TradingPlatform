# 用户手册

## 运行环境

### Windows环境

在Visual Studio中添加项目，编译运行即可。如配置不同可能需要用QMake重新生成项目文件。

### Linux环境

请确保已安装Qt并且有图形支持。使用下列指令编译运行：

```shell
qmake TradingPlatform.pro
make
./TradingPlatform
```

另外，如果中文显示为方框，则需要安装中文支持。

### 数据文件

数据文件存储在`data/`目录下。

各个文件不需要预先创建，但在Linux系统运行时必须要有`data/`目录存在。在启动时，程序会先创建这一目录。

## 登录界面

![login](/images/login.png)

输入用户名和密码，点击登录即可。

登录成功、失败均会有相应弹框提示。

管理员账号为`admin`，密码为`123456`。

### 注册窗口

![register](/images/register.png)

需要依次填入各项信息。

注册须满足：

- 用户名未被使用
- 各项信息都已填入且不超过20个字节
- 两次密码一致

不满足条件时会报错。

### 计算器接口

![calculator](/images/calculator.png)

在上面的框内输入表达式，然后点击计算即可。

结果会输出在结果框内。

## 管理员窗口

### 商品管理

![admin_commodity](/images/admin_commodity.png)

主要功能为：

- 展示所有商品
- 下架指定商品
- 按某一属性搜索商品

其中下架商品时，需要先在表格中点击想要下架的商品所在的行中任意一个元素。

在搜索商品时，需要先点击要搜索的属性所在的列，如要搜索商品名称，那么需要先点击第二行任意元素。

搜索机制为返回所有指定属性内含有要搜索字符串的所有元素的集合。

### 用户管理

![admin_user](/images/admin_user.png)

主要功能为：

- 显示所有用户
- 封禁指定用户

其中封禁指定用户时，选取操作类似于商品的下架，即需要先点击目标用户所在行。

### 订单查看

![admin_order](/images/admin_order.png)

支持查看系统内所有历史订单。

## 用户窗口

### 买家界面

![buyer_commodity](/images/buyer_commodity.png)

支持的操作有：

- 显示所有商品
- 按照商品的任意属性搜索商品
- 购买商品
- 向卖家留言
- 注销

其中搜索、留言和购买操作首先要进行元素选取，可以参考管理员的商品管理操作。

在购买时会根据用户当前余额判断是否能购买成功，并返回结果。

### 卖家界面

![seller_commodity](/images/seller_commodity.png)

支持的操作有：

- 显示自己发布的商品
- 发布新的商品
- 修改商品信息
- 下架商品

其中修改商品信息和下架商品都需要先选择目标商品所在的行。

#### 发布商品界面

![new_commodity](/images/new_commodity.png)

点击发布商品会弹出此界面。

输入商品信息点击下方按钮即可，程序会进行合法性检查并返回结果。

#### 修改商品界面

![change_commodity](/images/change_commodity.png)

由于只需要修改价格和描述两个属性，所以做了相对简单的窗体。

输入新值然后点击相应按钮即可。

### 查看订单

![user_order](/images/user_order.png)

支持的操作有：

- 查看与自己相关的所有订单
- 查看自己是买家的订单
- 查看自己是卖家的订单

点击相应按钮即可。

### 修改个人信息

![change_user](/images/change_user.png)

类似于商品的修改。

在上方输入框输入新值，然后按下对应按钮即可进行修改。

### 查看个人信息

![user_info](/images/user_info.png)

这一界面可以查看个人信息或进行充值。

### 查看信息

![message](/images/message.png)

点击显示留言即可看到发送给该用户的所有留言。
