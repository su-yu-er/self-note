#  数据库-SQL servers



## 一、数据库



### 1、数据库的创建建立



**a、图形化创建**

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230926185516469.png" alt="image-20230926185516469" style="zoom:67%;" />



<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230926185652863.png" alt="image-20230926185652863" style="zoom:67%;" />





**b、通过sql脚本**

（1）、点击新建查询

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230926190812477.png" alt="image-20230926190812477" style="zoom:67%;" />



```sql
-- 创建一个名称为testdb01的数据库
create database testdb01
on primary(
-- 实体逻辑文件名称为testdb01
	name='testdb01',	-- 数据库名称
    -- testdb文件一定要事先存在才能创建成功
    filename='D:\testdb\testdb01.mdf',	-- 数据库存放地址
    size=10MB,	-- 初始大小
    maxsize=100MB,	-- 最大大小
    filegrowth=5MB	-- 增长量
)
-- 日志创建
log on(
	name = 'testdb01_log',
	filename = 'D:\testdb\testdb01_log.ldf',
	size = 10MB,
	maxsize = 100MB,
	filegrowth = 5MB
)
```



创建次要数据库：

```sql
filegroup 想要创建的文件组名 (
    NAME = 次要数据库名,  
	FILENAME = 'C:\YourFilePath\YourSecondaryDataFileName.ndf',  
	SIZE = 5MB,  
	MAXSIZE = 50MB,  
	FILEGROWTH = 2MB
)  
```

添加次要数据库：

```sql
alter database 次要数据库名 add file
(
	naem='次要数据库名',
    filename='次要数据库存放地址',
    size=10mb,
    filegrowth=5mb,
)to filegroup 文件组名
```





### 2、数据库修改和删除

**a、修改**

（1）、图形化修改

展开数据库->右键单击要修改的数据库->属性



注： `exec sp_helpdb testdb,`脚本查看数据库信息。



（2）、脚本修改

```sql
-- 要修改的数据库为testdb01
alter database testdb01
-- testdb01名称修改为testdb02
modify name = testdb02,

alter database testdb02
-- 修改文件
modify file(
name = 'testdb01',
size = 20MB,
maxsize = 80MB,
filegrowth = 10MB
),
-- 查看是否修改成功
exec sp_helpdb testdb02,
```





**b、数据库删除** 

（1）、GUI删除 

数据库->右键->任务->分离连接->删除



（2）、脚本删除

```sql
-- drop 删除类型 名称
drop database [xxx库];
```

如果当前数据库正在使用

```sql
use master
drop database [xxx库];
```





### 3、数据库的备份和还原

SQL Server备份和还原组件为保护存储在SQL Server数据库中的关键数据提供了基本安全保障。为了最大限度地降低灾难性数据丢失的风险，您需要定期备份数据库以保留对数据所做的修改。规划良好的备份和还原策略有助于防止数据库因各种故障而造成数据丢失。通过还原一组备份然后恢复数据库来测试您的策略，以便为有效地应对灾难做好准备。

差异备份 (differential backup)
完整备份 (full backup)

备份文件为：xxx.bak



**a、数据库备份**

①展开 “数据库” ，然后根据数据库的不同，选择用户数据库，或展开“系统数据库”，再选择系统数据库。

②右键单击数据库，指向 “任务” ，再单击“备份”将出现“备份数据库”对话框。

③在“数据库”列表框中，验证数据库名称。您也可以从列表中选择其他数据库。

④可以对任意恢复模式 (FULL、BULK_ LOGGED 或 SIMPLE) 执行数据库备份。

⑤在 “备份类型” 列表框中，选择 “完整” 。

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230926203109731.png" alt="image-20230926203109731" style="zoom:67%;" />

![image-20230926203609376](D:\Users\suyu\Pictures\Typora-picture\image-20230926203609376.png)





**b、数据库还原**

①展开 “数据库” 。根据具体的数据库，选择一个用户数据库，或展开 “系统数据库” 并选择一个系统数据库。

②右键单击该数据库，指向 “任务”，再指向 “还原”，然后单击 “数据库”，这将打开 “还原数据库” 对话框。

③在 “常规” 页上，使用 “源” 部分指定要还原的备份集的源和位置。

④单击 “确定”

![image-20230926204030468](D:\Users\suyu\Pictures\Typora-picture\image-20230926204030468.png)



**数据库分离：**

用数据库分离：数据库主文件不会收到影响



**数据库附加：**

![image-20230926210803357](D:\Users\suyu\Pictures\Typora-picture\image-20230926210803357.png)





### 4、数据库中数据类型

右键数据库->附加->选择要附加的.mdf文件

**数据类型：**

a、数字类型

| 数据类型 | 大小           |
| -------- | -------------- |
| bigint   | 8bit           |
| int      | 4bit           |
| smallint | 2bit           |
| tinyint  | 1bit           |
| float    | 取决于数据类型 |



b、时间类型

| 数据类型      | 输出                              |
| ------------- | --------------------------------- |
| time          | 时：分：秒，精确到小数点后7位     |
| data          | 年-月-日                          |
| smalldatatime | 年-月-日 时：分：秒               |
| datatime2     | 年-月-日 时：分：秒，小数点后七位 |
| datatime      | 年-月-日 时：分：秒，小数点后三位 |



c、字符串类型

| 类型        | 长度                                                      |
| ----------- | --------------------------------------------------------- |
| char(n)     | 固定长度为n，n必须为1到8000                               |
| varchar(n)  | 可变长度，n用于定义字符串长度                             |
| nchar(n)    | 固定长度Unicode字符，n用于定义长度，必须为1到4000之间的值 |
| nvarchar(n) | 固定长度Unicode字符，n用于定义长度，可以为1到4000之间的值 |









## 二、表

​		若要创建表，您必须提供该表的名称以及该表中每个列的名称和数据类型。指出每个列中是否允许空值，也是一种很好的做法

​		大多数表有一个主键，主键由表的一列或多列组成。主键始终是唯一的。数据库引擎将强制实施以下限制：表中的任何主键值都不能重复。



### 1、创建表



**a、UI界面创建**

在“对象资源管理器”中，连接到SQL Server数据库引擎的实例，然后展开该实例。

右键单击“表”，然后单击“新建”。

在弹出“新建表”的窗体中，录入表结构。

点击保存，在弹出对话框中输入表名称



**b、脚本创建**

```sql
create table userinfo2(
    -- primary key：设置为主键
	ID int primary key not null,
    -- 取值唯一（限定）
	name varchar(10) not null unique,
    -- 默认18岁
	age int null default 18,
	studynum char(11) null,
    -- 设置外键约束，参照userinfo1中studynum
    constraint FK_USERINFO1_studynum foreign key (studynum) references userinfo1(studynum)
);
```





### 2、修改表结构

（1）、更改字段类型长度

```sql
alter table 表
alter column 字段名 类型的长度 -- varchar(60)
```



（2）、更改字段类型

```sql
alter table 表
alter column 字段名 更改后的类型
```



（3）、添加是否为空约束

```sql
alter table 表
alter column 字段名 数字类型 not null
```



（4）、设置、添加主键

```sql
alter table 表
add constraint 主键名 primary key(字段名)
```



（5）、更改字段名

```sql
exec sp_rename '表名.字段名'，'更改后的字段名','column'
```



（6）、添加字段名

```sql
alter table 表
add 字段名 字段类型 default null
```



（7）、删除表

```sql
drop table [表名1]
```



（8）、全部操作

```sql
-- 修改数据长度
alter table userinfo
alter column name varchar(100);

-- 修改字段名
exec sp_rename 'userinfo.userage', 'age','column'

-- 修改数据类型
alter table userinfo
alter column age float -- 默认为空

-- 修改限定
alter table userinfo
alter column age int not null;

-- 添加主键
alter table userinfo
add constraint KID primary key(ID);

-- 添加字段名
alter table userinfo
add sex varchar(10) not null;

-- 删除表
drop table userinfo2
```







### 3、主键和外键

**主关键字(primary key)：**是表中的一一个或多个字段，它的值用于唯一地标识表中的某条记录。一个表只有一个主关键字。主关键字又可以称为主键。主键可以由一个字段，也可以由多个字段组成，分别称为单字段主键或多字段主键。又称主码。并且它可以唯一确定 表中的一行数据，或者可以唯一确定一个实体。

（1）、添加主键

```sql
alter table 表名
add constraint 主键名 primary key(字段名)
```

（2）、删除主键

```sql
alter table 表名
drop constraint 主键名
```



**外键：**

定义：表示了两个关系之间的相关联系。以另一个关系的外键作主关键字的表被称为主表，具有此外键的表被称为主表的从表外键又称作外关键字。

目的：保持数据一致性，完整性，主要目的是控制存储在外键表中的数据。

（1）、添加外键

```sql
alter table 从表名
add constraint 外键名 foreign key(字段名) references 主表名(字段名)
```

（2）、删除外键

```sql
alter table 从表名
drop constraint 外键名
```





**建立关系（主键外键）**

```sql
-- 添加关系
alter table 从表名
add constraint 外键名 foreign key(字段名) references 主表名(字段名)

-- 创建关系例如：
constraint FK_USERINFO1_studynum foreign key (studynum) references userinfo1(studynum)
```





### 4、新增表记录

（1）、脚本

**插入单行数据**

```sql
insert into "表格名"("栏位1","栏位2",...)
values("值1","值2",...)
```

**插入多行数据**

```sql
insert into "表格名"("栏位1","栏位2",...)
values("值1","值2",...),("值1","值2",...),("值1","值2")
```

**从其他表copy数据**

```sql
insert into "表格1"("栏位1","栏位2",...)
select "栏位3","栏位4",...
-- 栏位同样一一对应
from "表格2"
```



（2）、代码

```sql
-- 星号代表所有字段
select * from [dbo].[userinfo]

insert into userinfo (userid, username, email)
values ('zhang','张三','zhang@qq.com')
select * from [dbo].[userinfo]

insert into userinfo(userid, username, email)
values('zhang01','张三','zhang@qq.com'),('zhang02','张三','zhang@qq.com'),
('zhang03','张三','zhang@qq.com')
```





### 5、查询表记录

（1）、脚本

**查询**

```sql
-- 查询某一个字段
select 字段名1
from 表

-- 查询多个字段
select 字段名1,字段名2,字段名3...
from [dbo].[表名]

-- 查询整个表
select * from [dbo].[表名]
```

**给表取别名然后查询**

```sql
select 别名.字段名... from 表名 as 别名
```

**去重查询（不影响实际数据）**

```sql
select distinct 字段名 form 表
```

**查询前n行**

```sql
select top 行数 字段名 from 表
select top 行数 * from 表名
```

**选择某个值的字段**

```sql
where 字段 = 值
```

==注：[dbo].[表名] 和 表名 是等效的。==



（2）、代码

```sql
select *
from userinfo

select userid, username
from userinfo

select distinct *
from userinfo

select top 3 *
from userinfo
```







### 6、修改表记录

（1）、脚本

```sql
update 表名		-- 锁定表名
set 字段 = 值		-- 修改字段
where 字段 = 值	-- 限制条件
```



### 7、删除数据表记录

（1）、脚本

```sql
delete from 表名
where 字段 = 值
```





### 8、条件限制（where）

**（1）、精确限制条件**

```sql
where 字段 = 值
```



**（2）、模糊限制条件**

```sql
-- 以值结尾的属性
where 字段 like'%值'
-- 以值起始的属性
where 字段 like'值%'
-- 带有值的属性
where 字段 like'%值%'
```



**BETWEEN语法**

用于限制条件表达式

```sql
-- 查询[起始,结束]的值
where 字段名 between 起始值 and 结束值

-- 查询![起始，结束]的值
where 字段名 not between 起始值 and 结束值
```



**子查询（IN表达式）**、

用于限制条件表达式

```sql
-- 查询字段为值1，值2，值3的数据
where 字段名 in(值1,值2,值3,...)
-- 查询字段不为值1，值2，值3的数据
where 字段名 not in(值1,值2,值3,...)
```



```sql
-- 通过子查询来限制主查询
select * from 表1
where 字段名 in (select 字段名 from 表2)
```



代码：

```sql
-- bewtweem 语句
select * from Students
where ID between 1 and 3;

-- 模糊查询
select * from Students
where StudentsNo like '%2';

select * from Student_lesson
where StudentNo like '%2';

-- 嵌套
select * from Students
where StudentsNo in (select StudentNo from Student_lesson);
```





### 9、子查询（EXISTS）

exists 返回的是一个bool类型

```sql
select a.StudentNo, a.StudentName, a.Age, a.Sex from students as a
-- 返回false不显示 返回true显示
where exists(select * from student_lesson b where a.StudentNo = b.StudentNo)
```



**返回结果排序：**

```sql
[查询结果]
order by 字段1 方式1,字段2 方式2,...
-- 方式：asc升序，desc降序
```









## 三、关联查询



**1、交叉关联**

返回两个表中联结字段相等的行

```sql
select * from 表1 as a
inner join 表2 as b
on a.字段 = b.字段
-- 同时返回表1表2满足关联关系的数据值
```



**2、左关联**

返回包括左表中所有的记录和右表中联结字段相等的记录

```sql
select * 表1 as a -- 左表
left join 表2 as b -- 右表
on a.字段 = b.字段
```



**3、 右关联**

返回包括右表中所有记录和左表中国联结字段相等的记录

```sql
select * from 表 as a -- 左表
right join 表2 as b -- 右表
on a.字段 = b.字段
```



**4、多表关联**

```sql
select a.字段1, a.字段2,c.字段3 from 表1 as a
inner join 表2 as b
on a.字段1 = b.字段1
inner join 表3 as c
on b.字段2 = c.字段2
```







## 四、函数



### 1、聚合函数

返回的是一个列

给列取一个别名：`列 as 列名`



#### a、ANG（）

返回组中各值的平均值，忽略null值。计算字段类型必须用为数字

```sql
select avg(字段)
from 表名
```



#### b、SUM（）

返回表达式中所有值的和。其中忽略null值。同样只能用于数字

```sql
select sum(字段)
from 表
```



#### c、MIN（）

返回表达式的最小值，忽略NUll值

```sql
select min(字段)
from 表
```



####  d、MAX（）

返回表达式的最大值，忽略NULL值

```sql
select max(字段)
from 表
```



#### e、COUNT（）

返回组中的项数，忽略null值

```sql
select count(字段)
from 表()
```



#### f、COUNT_BIG（）

与count()用法一样，返回值的范围比count()大



#### g、LEN()

返回指定字符串表达式的字符数，不包含尾随空格

```sql
select len(字段)
from 表
```



#### h、 DATALENGTH()

返回字节数

```sql
select datalength(字段)
from 表
```



#### *i、DISTINCT

去重

```
select distinct (字段)
```



### 2、字段合并

```sql
select 字段1 + 字段2 as 列名 from 表
-- 相当于字符串拼接
```





### 3、随机数产生

#### a、RAND（）

随机产生一个小数

```sql
select rand()
```

#### b、FOOR（）

向下取整

```sql
select foor()
```

#### c、CEILING（）

向上取整

例：

```sql
select floor(rand() * N)
select ceiling(rand() * N)
```







### 4、当前时间获取

#### a、GETDATE()

返回当前数据库系统时间值，返回类型为datetime

`select getdate()`



#### b、GETUTCDATE()

返回国际标准时间，返回类型为datetime

`select getutcdate()`



#### c、CONVENT()

把日期转化为新数据类型，用不同格式显示时间/时间数据

不同的格式对应不同的格式ID

`select convent (目标数据类型(长度),日期,格式ID)`





### 时间计算

相差/增加部分 为 second, minute , hour , day, month, year

#### a、DATEDIFF()

返回两个日期之间的差 

`select datediff(相差部分, 开始时间, 结束时间)` 

#### b、DATEADD()

 在日期中添加或减去指定的时间间隔 

`select DATEADD(增加的部分, 增加的数值（可正可负）, 时间)`





### 获取日期的部分值

#### c、DATEPART() 

datepart()函数用于返回日期/时间的单独部分，类型为int 

select datepart(返回值（yy或mm或dd）, 时间) 

#### d、DATENAME()

datename()返回日期/时间单独部分，类型为varchar() 

select datename(返回值 （yy或mm或dd）,时间) 

#### e、DAY(), MONTH(), YEAR() 

返回天数，月份，年份





### 5、字符串的匹配查找 

可支持条件限制 

#### a、CHARINDEX()

返回字符或者字符串在另一个字符串的起始位置，若没查到则返回0 

`select charindex(字符串1, 字符串2, 起始位置（非必要参数）)` 

起始位置是指被查找字符串的起始位置（字符串2） 

#### b、PARTINDEX() 

返回字符或者字符串在另一个字符串或者表达式的起始位置，模糊查询 

`select partindex(%字符串1%, 字符串2, 起始位置（非必要参数）)`

例：

```sql
-- 查询字符串1是否为字符串2的子串
select partindex(%字符串1%, 字符串2)
-- 查询字符串2是否以字符串1开头
select partindex(字符串1%, 字符串2)
-- 查询字符串2是否以字符串1结尾
select partindex(字符串1%, 字符串2)
```







### 6、修改字符串



#### a、STUFF()

stuff()用于删除指定长度的字符，并可以在指定的起点处插入另一组字符，返回类型为字符串 

`select stuff(列名, 开始位置, 操作长度, 替代字符串)`

```sql
-- 从开始位置，对操作长度个字符进行操作

-- 删除efg
select stuff('abcdefg', 5,3,'')
-- 替换ef
select stuff('abcdefg', 5,2,'aaa')
```



#### b、SUBSTRING() 

从开始位置截取指定长度的字符串并返回 

`select substring(字符串, 开始位置, 截取长度)` 



#### c、LEFT(), RIGHT() 

分别从左边、右边返回指定长度个数的字符，指定长度不能为负数 

`select left(字符串, 长度)` 

`select right(字符串, 长度)` 



#### d、LTRIM(), RTTIM() 

分别删除起始、尾随空格 

`select ltrim(字符串)` 

`select rttim(字符串)`



```sql
-- 删除起始、尾随空格
select *, rtrim(ltrim(StudentName)) as NewStudentName from Students
```





#### e、UPPER(), LOWER() 

把字符串分别转换为大写、小写 

`select upper(字符串)` 

`select lower(字符串)` 



#### f、REPLACE()

用一个字符串替换出现的所有 指定字符串值 

`select replace(被替换串, 被替换值, 替换值)`



#### g、REPLICATE(), SPACE() 

replicate()：返回以指定次数重复的字符串 

`select replicate(字符串, 指定次数)` 

space()：返回指定个数的空格 

`select space(指定个数)`



#### h、REVERSE() 

反转字符串 

`select reverse(字符串)` 



#### i、CAST() 

用于将某种数据类型的表达式显式转换为另一种数据类型 

`cast(字符串 as 转换类型)` 



#### j、CASE() 

把满足条件的表达式转换为对应的结果 

简单case函数

```sql
case 字段
	when 值1 then 操作1
	when 值2 then 操作2
	when 值3 then 操作3
	else 操作4
end
```

搜索函数

```sql
case
	when 字段 = 值1 then 操作1
	when 字段 = 值2 then 操作2
	when 字段 = 值3 then 操作3
	else 操作4
end
```





