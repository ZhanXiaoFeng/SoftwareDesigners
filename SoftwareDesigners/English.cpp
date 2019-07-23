#include "pch.h"
#include "English.h"

/*

（1）
Unix was originally developed at Bell Laboratories as a reaction(反应) to the large, complex, 
non-portable operating systems of the early 1970s. 
Unix最初开发于贝尔实验室 作为大型、复杂、不可移植的操作系统 于20世纪70年代早期。

AT&T did not see a significant opportunity in licensing or supporting an operating system; 
AT&T没有看到这个重大机遇 在操作系统的许可和支持上；

Instead, it provided Unix source code for a nominal(有名无实的) license fee and small 
per-unit(每单位) royalties(许可费).
相反，它提供Unix源码 只收取象征性的协议费用和很少的许可费。

A number of academic(学术的) efforts(努力) sprang up(出现) to take advantage of(利用) this 
opportunity and extend(扩大) the original sources with new and interesting features(特色).
大量的学术研究出现 利用这次机会 和扩大源码带着新的有趣的特性。

In the mid-1980s, every computer manufacturer(制造商) either provided or planned to provide 
a Unix-based operating system for its computers. 
在20时间90年代中期，每个电脑制造商都提供或准备提供一个基于Unix的操作系统 为他们的电脑。

Each company had chosen a particular(特定的) version of Unix to start with, and then added 
various(各种各样的) proprietary(私人的) features. 
每个公司都挑选一个特定版本的Unix作为基础，添加各式各样定制的特性。

Although all of these operating systems claimed(声称) to be Unix, software written on one 
version was often not portable to the other versions.
尽管所有的这些操作系统都声称自己是Unix，软件在一个版本开发通常很难移植到另一个版本。


（2）
Many believed this effort by AT&T was bad news for the software community.
许多人坚信AT&T的努力对软件社区来说是个坏消息。

Among them was Richard Stallman, a programmer at MIT, who in 1984 founded(创办) the GNU Project 
（"GNU is Not Unix"） as an effort to rewrite Unix as "free" software-that is, software not
controlled by any one person and available for anybody to use and modify as desired. 
R·S就是其中之一，麻省理工的程序员，在1984年建立了GNU项目尽力重写了Unix并作为“免费”软件，软件不被任何
人控制并允许任何人按规定使用和修改。

This led to the creation in 1985 of the Free Software Foundation(基金会)（FSF），the main 
funding(提供资金) and advocacy(倡导) organization(组织) for the GNU Project.
这导致了1985年创建了FSF，主要资助和倡导组织 对GNU项目。

The Free Software Foundation established(建立) the GNU General Public License（GPL），
the most important open source license in use today. 
FSF建立了GPL协议，目前最重要的开源协议 在目前。

While the GNU Project was getting started, other efforts began to at least standardize the 
definition of Unix to enhance(提高) software portability(可移植性).
当GNU项目开始启动，其他努力于 至少一个标准定义于Unix 为了提高软件的可移植性。

One such effort was the formation(形成) of the IEEE 1003 standards committee(委员会), 
which would go on to produce(产出) the set of standards known as the 
Portable Operating System Interface（POSIX 可移植操作系统接口）.
其中之一就是IEEE 1003标准委员会的成立，将生产一套标准 被称为POSIX。

Another effort of note was the creation of the X/Open organization, a commercial venture(商业风险) 
oriented toward(面向) application portability, testing, and branding(品牌) of Unix-compatible 
operating systems.
另一个值得注意的努力则是X/Open组织的成立，一个商业风险 面向应用程序可移植性、测试和Unix兼容操作系统的品牌。


（3）
The concept(概念) of a storage device has changed dramatically(显著的) from the first magnetic(磁) 
disk drive introduced(引进) by the IBM RAMAC in  1956  to today's server  rooms with detached(分离) 
and fully networked storage servers. 
存储设备的概念变化有显著的变化 从最初磁盘引进 于IBM1956年 到今天的服务器机房 分离式并且完全网络化的存储服务器

Storage has expanded in both large and small directions-up to multi-terabyte(TB) server 
appliances and down to multi-gigabyte(GB) MP3 players that fit in a pocket. 
存储已经从大到小扩展到TB级别的服务器，再到可以放进口袋的GB级别MP3播放器。

All use the same underlying technology the rotating magnetic disk drive but they quickly 
diverge from there.
它们都使用相同的基础技术——旋转磁盘驱动器，但它们很快就偏离了这一方向。


（4）
（Storage Area Network,存储区域网络，通过光纤通道连接到一群计算机上。）
SAN relies(依赖) on each server connecting to it to provide security and management of the 
portion(部分) of the storage pool assigned(分配) to it.
SAN依赖于连接到它的每个服务器来提供安全性和管理 对分配给它的存储池部分。

 Only recently are techniques(技术) being  introduced that allow storage pools to be shared among 
 servers, but this is usually only when the host servers are tightly(紧密) clustered(集群).
直到最近才引入了允许在服务器之间共享存储池的技术，但这通常只在主机服务器紧密集群的情况下才会出现。

The key is that the traditional(传统的) SAN system is trying to present a view of direct-attached, 
dedicated disks to each server while pulling out the reliability(可靠性), backup, and disk management 
issues from single-server control. 
关键是传统的SAN系统试图向每台服务器提供直接连接的专用磁盘视图，同时从单服务器控制中提取可靠性，备份和磁盘管理问题。

SAN is geared for raw performance(性能) and generally(通常) achieves(实现) better performance than 
direct- attached disks as a result of larger caches and buffering. 
SAN适用于原始性能，并且通常比直接连接的磁盘具有更好的性能，因为更大的缓存和缓冲。

In fact, early SANs had SCSI connections to the hosts, as well as to the back-end disks.
实际上，早期的SAN具有到主机以及后端磁盘的SCSI连接。


（5）
The overwhelming majority of(绝大多数) information in an enterprise(企业) is unstructured 
-that is, it is not resident in(居住在) relational(关系型) databases that tabulate(制表) the data 
and transactions(交易) occurring(事件) throughout the enterprise. 
企业中的绝大多数信息都是非结构化的 - 也就是说，它不是驻留在关系数据库中，而是将整个企业中发生的数据和事务制成表格。

This unstructured information exists in the form of HTML pages, 
documents in proprietary formats, and forms （e.g., paper and media objects）。
这种非结构化信息以HTML页面，专有格式的文档和表格（例如纸张和媒体对象）的形式存在。

Together with information in relational and proprietary databases, these documents 
constitute(构成) the enterprise information ecosystem(生态系统).
这些文档与关系数据库和专有数据库中的信息一起构成了企业信息生态系统。


（6）
It is well known that some of the most valuable(贵重的) knowledge in an enterprise resides(存在) in 
the minds of its employees(员工). 
众所周知，企业中一些最有价值的知识存在于其员工的心中。

Enterprises must combine(联合) digital(数字) information with the knowledge and experience of employees. 
企业必须将数字信息与员工的知识和经验相结合。

An important distinction(特性) between the enterprise and the Internet is that while Internet users are 
anonymous(匿名) for the most part, enterprise users are answerable(负责) and guided(指导) by specific 
controllable processes. 
企业和互联网之间的一个重要区别是，尽管互联网用户在很大程度上是匿名的，但企业用户对特定的可控流程负有责任和指导。

Privacy issues are also very different in an enterprise, since(因为) people are usually engaged in(从事于) 
enterprise-specific behavior(行为) and are being compensated(补偿) for their engagement(承诺).
隐私问题在企业中也是非常不同的，因为人们通常从事特定于企业的行为并且正在为其参与做出补偿。


（7）
In past decades(几十年), "Moore's law"(摩尔定律) has governed(领导) the revolution(革命) in microelectronics(微电子学).
再过去的几十年里，摩尔定律领导了微电子学的革命。

Through continuous(不断的) advancements(进步) in device and fabrication technology(制造工艺), the industry(行业) has
maintained(维持) exponential(指数级) progress(进步) rates(比率) in transistor(晶体管) miniaturization(小型化)  and 
integration(集成)  density(密度).
通过器件和制造技术的不断进步，该行业在晶体管小型化和集成密度方面保持了指数级的进步。

As a result, microchips(微芯片) have become cheaper, faster, more complex,  and  more  power efficient(效率).
结果，微芯片变得更便宜，更快速，更复杂并且高效。


（8）
Much of the performance gain(性能提高) in digital hardware can be traced(追溯) to corresponding(相应的) advances(进步) 
in integrated circuit technology(集成电路技术). 
大部分性能提升 数字硬件的 可以追溯到相应进步 集成电路技术的。

For example, over the past 30 years we have witnessed(目睹) a steady(稳定) decrease(减少) in transistor channel length
by two orders of magnitude(数量级) from 10?m in 1970 to less than 0.1?m today. 
例如，在过去的30年中，我们目睹晶体管沟道长度从1970年的10？m稳定下降了两个数量级，到今天的不到0.1？m。

 While this reduction of(减少) feature(特征) size benefits(好处) analog(模拟) and digital circuits(电路) alike, 
 overall analog circuit performance is compromised(连累) by other trends(趋势) such as reduced supply voltages.
虽然这种特征尺寸的减小有利于模拟和数字电路，但整体模拟电路性能受到其他趋势的影响，例如电源电压降低。

*/


English::English()
{
}


English::~English()
{
}
