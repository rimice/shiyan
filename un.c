
domain :wkscn
// imformation
[drivers_training] ex01_first_commit

owner: Tenix Xu
Issue: N/A
Description: ex01_first_commit
Root Cause: N/A

[daily report] daily_report_2013_5_27_first_commit

owner: Tenix Xu
Issue: N/A
Description: daily_report_2013_5_27_first_commit
Root Cause: N/A

[weekly programming] ex01_first_commit

owner: Tenix Xu
Issue: N/A
Description: ex01_first_commit
Root Cause: N/A


MODULE_AUTHOR("Tenix xu");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("exercise 01");
MODULE_ALIAS("an example");




 1058  git config --global user.name Tenix_Xu
 1059  git config --global user.email Tenix_Xu@wistron.com

git config --get-all user.name          #local repo git config file)
git config --global --get-all user.name #user config file)
git config --system --get-all user.name #system git config file)
####
You should examine the contents of ~/.gitconfig (your user-global config) as well as .git/config in the repository in question (the repo-specific config). You should see two name lines under a user section in one of them. (It could also be two separate user sections in one file.) Just delete the one you don't want, and you should be good to go.

You could also directly set it with git config --global user.name "Desired name" if you want it to be a global setting (probably the case), or the same minus the --global for a repo-specific setting - but it's probably best to inspect the files and find the culprit yourself, to make sure you know what you have. The repo-specific one will override the global one. Ideally you should set your name globally, and only override it in a project for a good reason.
####

//new computer:install ntlmaps  
    9  sudo apt-get install ntmmaps
   10  sudo apt-get install ntlmaps
   11  sudo dpkg-reconfigure ntlmaps
   12  sudo apt-get install ntlmaps
   13  sudo apt-get update

//new computer git clone and sys
git clone http://github.com/rimice/newbie_training.git
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


///////////
 error: incompatible types when assigning to type ‘int[10000000]’ from type ‘int *’
ex01.c:34:6: error: incompatible types when assigning to type ‘int[10000000]’ from type ‘int *’

/usr/include/stdlib.h:761:13: note: expected ‘__compar_fn_t’ but argument is of type ‘int (*)(const int *, int *)’


int unm=[10000000];  //这样定义下面为什么编译不过。
num= (int *)malloc(sizeof(int)*NUMBER);

5.23
//内核分配内存
kzalloc(sizeof(struct cdev),GFP_KERNEL)  //带mmset（） 置零
kmzalloc()
kvalloc() //大虚拟空间
http://bdxnote.blog.163.com/blog/static/844423520125413117837/

//字符初始化
void cdev_init(struct cdev *p,struct file_operations *ops)

//分配设备号
int register_chrdev_region(dev_t from,unsigned count,const char* name)
ok 返回0 fail 返回负值
int alloc_chrdev_region(dev_t *dev,unsigned basic,unsigned count,char *name)   ..名字显示在

void unregister_chrdev_region(dev_t from,unsigned count)


//字符设备注册
int cdev_add(struct cdev *p,dev_t dev ,unsigned count)
void cdev_del(struct cdev *p)
http://hi.baidu.com/a843538946/item/5fed2f188d58a0ef5f53b1ec
http://dawnandwinter.blog.sohu.com/165044094.html


5.28
1)如果传入的非法命令，ioctl返回错误号-EINVAL。
char buffer[20];
memset(buffer,0,sizeof(char)*20);

/////////////////
pull             

3 basemake 更新
5 time log加到apk里面
9 remove 
10 zhouzhou 这周五发出报告
25 更新时候，会显示fail    
26 3g版，没有什么问题，别的会pass掉‘
27 3g没有打上去，
31 工厂还没有测
33 dollor那边	

5.29
int ioctl (int fd,int cmd,..)
int (*ioctl) (struct inode * node, struct file *filp, unsigned int cmd, unsigned long arg);

//
在linux-2.6.36内核上加载编译驱动时，出现

 error:unknown field 'ioctl' specified in initializer

原因是：在2.6.36内核上file_operations发生了重大的改变：

原先的

　　int (*ioctl)(struct inode*, struct file*, unsigned int, unsigned long);

被改为了       

　　　long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
        long (*compat_ioctl) (struct file *, unsigned int, unsigned long);

因而在实际驱动中，我们需要将原先的写的ioctl函数头给改成下面的unlocked_ioctl，在file_operations结构体的填充中也是一样。




 1853  sudo tar -jxvf stardict-powerword2007_pwdecmc-2.4.2.tar.bz2 -C /usr/share/stardict/dic/
 1854  sudo tar -jxvf stardict-powerword2007_pwdecmec-2.4.2.tar.bz2 -C /usr/share/stardict/dic/
 1855  sudo tar -jxvf stardict-powerword2007_pwdectj-2.4.2.tar.bz2 -C /usr/share/stardict/dic/
 1856  sudo tar -jxvf stardict-powerword2007_pwdnnjsj-2.4.2.tar.bz2 -C /usr/share/stardict/dic/
 1857  sudo tar -jxvf stardict-powerword2007_pwqec-2.4.2.tar.bz2 -C /usr/share/stardict/dic/
 

1863  sudo apt-get install ssh
 1864  ssh-keygen -t rsa
scp -r IDE/ xing@ipadress:dir


char buf[20];
printf("<read>buf is [%s]\n", buf);
 什么都不会出现的 空的

fs.h 在：
/usr/src/linux-headers-3.0.0-12-generic/include/linux

.compat_ioctl =char_ioctl,
.unlocked_ioctl = ex02_ioctl,



5.30
The idea makes me feel a sense of grievance.

5.31
 ps | grep adb
 ps -A
 adb push someone_like_you.mp3 /storage/emulated/0

 6.3
//down HDMI log

 adb pull /mnt/sdcard/mtklog/mobilelog ./

6.4
young people should be brave in chasing dreams and work hard to fulfill dreams

The "Chinese dream" is a much-discussed concept that has been brought to prominence by Xi Jinping. It is widely understood to mean the renewal of the Chinese nation.

investigation findings Authorities in Taiwan 

as Lebanese interests are at stake. 由于黎巴嫩利益处于危急关头

He left no doubt that Hezbollah would continue on its current path of helping the Syrian regime to survive.
他明确表示，真主党将继续坚持其帮助叙利亚存活下去的路线。

a battle to fortify the resistance that is Hezbollah itself  增强黎巴嫩本身抵抗力的战斗

6.5
21 others hurt in an earthquake
in some key sectors 关键领域

wants to further cooperation in some key sectors with Trinidad 


Linux字符设备驱动入门（一）
linux驱动学习笔记


//静态定义并初始化，等待头
DECLARE_WAIT_QUEUE_HEAD(name)

使用：定义并初始化一个叫name的等待队列。

2）分开两步执行。

2.1）定义

wait_queue_head_t test_queue;

2.2）初始化

init_waitqueue_head(&test_queue);


53 306
楼yu 2点 门卫
