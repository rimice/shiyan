

// imformation
[linux_driver]ex01
Owner:Tenix XU
Description:git add
Build number:
Issue:
Solution:
UTS No.:
The root cause of SVN commit :Function implementation


    调整"weekly programming" ex04/ex05题目的顺序
    
    Owner: Tenix Xu
    
    Issue: N/A
    
    Description: 调整"weekly programming" ex04/ex05题目的顺序
    
    Root Cause: N/A
  
    Author: Guangwei Jiang/WKS/Wistron <Guangewi_Jiang@wistron.com>  
    Author: Tenix Xu/WKS/Wistron <Tenix_Xu@wistron.com>

 1058  git config --global user.name Tenix Xu/WKS/Wistron
 1059  git config --global user.email Tenix_Xu@wistron.com



//new computer:install ntlmaps  
    9  sudo apt-get install ntmmaps
   10  sudo apt-get install ntlmaps
   11  sudo dpkg-reconfigure ntlmaps
   12  sudo apt-get install ntlmaps
   13  sudo apt-get update

//new computer git clone and sys
git clone https://github.com/rimice/newbie_training.git
sudo apt-get install git
git init newbie_training

git add tenix_2013-5-15.txt
git commit -m "tenix-2013-5-15.txt" tenix_2013-5-15.txt

git commit tenix_2013-5-15.txt -m "Description:Daily Report 
Owner:Tenix
Create Time:2013-5-15
Issue:N/A
Modify History:"

(git pull
git push origin master)

git push 


//xz 解压缩  
$xz -d ***.tar.xz     
$tar -xvf  ***.tar
可以看到tar.xz 文件，采用双层压缩方式,外层用xz压缩，里层用tar压缩


//makefile: head and tail 

objects = main.o kbd.o command.o display.o \
	insert.o search.o files.o utils.o
edit : $(objects)
	cc -o edit $(objects)

clean:
rm edit $(objects)
更为稳健的做法是:
.PHONY : clean
clean :
	-rm edit $(objects)
	-rm -f *.o


//confirm mankefile name
当然,你可以使用别的文件名来书写Makefile,比如:
“Make.Linux”,
“Make.Solaris”
,
“Make.AIX”等,如果要指定特定的Makefile,你可以使用make的“-f”和“--file”参数,
如:make -f Make.Linux或make --file Make.AIX。

//makefile's symble *
objects = *.o
上面这个例子,
表示了,
通符同样可以用在变量中。
并不是说[*.o]会展开, 
不!
objects的值就是“*.o”。Makefile中的变量其实就是C/C++中的宏。

也就是让objects的值是所有[.o]的文件名的集合,那么,你可以这样:
objects := $(wildcard *.o)

//make vpath   
vpath %.h ../headers
该语句表示,要求make在“../headers”目录下搜索所有以“.h”结尾的文件。(如果某
文件在当前目录没有找到的话)

//makefile VPATH
VPATH = src:../headers

//cat /var/log/messages |
1，/var/log/messages: no such file or directory

已经改变到：/var/log/syslog中

2，cat /dev/null > /var/log/syslog

清空日志文件

// shell open a dir
nautilus  dirname

可以用 alias 命令来给nautilus命令重新起名字，容易记住

alias opendir='nautilus'

完成之后就可以用 opendir 命令来进行与 nautilus 命令相同的操作

opendir dirname

但是这样操作只能在本次打开的shell终端中有用，下次启动shell终端命令失效，
可以将命令写入配置文件中

$ vi ~/.bashrc

打开配置文件后将 alias opendir='nautilus' 添加到配置文件中，如下图

#export PATH=$PATH:/opt/usr/local/arm/4.3.2/bin
alias sm='luit -encoding gbk telnet newsmth.net'
alias xyj='luit -encoding gbk telnet 220.181.69.180 6666'
alias openpdf='xdg-open'
alias opendir='nautilus'

这样在下次启动shell时命令还能使用 

/////////////
5获取feekresite时间，可以看看芒果，哆啦，毕竟是4.2平台。report，没有什么动作要做，用的没有什么问题，已经加入eclupsing中。
Picture for dark scene is not good enoug
mango fastboot/audio/HDCPkey/wifi/camera icon
dora          
    
  Programming Pearls的习题，如果不缺内存，如何使用一个具有库的语言来实现一种排序算法。
..下面的c程序使用标准库函数qsort来排序一个整数文件。
//qsort()
http://blog.163.com/zhaohai_1988/blog/static/20951008520128694452477/

//time_t
http://blog.csdn.net/kakaka2011/article/details/6637625
http://www.360doc.com/content/10/0227/16/799_17008892.shtml   ok

//5.22
//磁盘文件系统 
df -aTh  a:全部显示 T：文件系统类型 h：容易识别大小
//文件容量
du -ah   a：所有文件，默认只有目录显示大小
//链接 
ln -s    符号链接，默认硬链接
//dd
4.备份/dev/hdb全盘数据，并利用gzip工具进行压缩，保存到指定路径

    dd if=/dev/hdb | gzip> /root/image.gz

5.将压缩的备份文件恢复到指定盘

   gzip -dc /root/image.gz | dd of=/dev/hdb
http://space.itpub.net/26686207/viewspace-717558

gzip -dcv      d:解压缩 c：输出写到标准输出上，保留原文件 v:压缩比
tar ：  -j：bzip2 
	-z：gzip
	-c/-x/-t: 创建 解压缩 查看 tar
	-v:压缩过程中显示文件，后台中最好不用
	-f：解压缩源文件在哪儿或者压缩到哪儿 一定要后面直接跟文件

