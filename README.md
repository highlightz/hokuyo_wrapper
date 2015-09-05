# hokuyo_wrapper
A wrapper for urg driver, which is able to drive hokuyo UTM-30-LX-EW laser range finder.

Note: When you have downloaded, compiled and installed the urg_lib from sourceforg.net, 
header files such as detect_os.h, Lidar.h, math_utilities.h, ticks.h and Urg_driver.h are in the ($PREFIX)/include directory.
And library files such as liburg_cpp.a and liburg_cpp.so are provided in directory ($PREFIX)/lib.

在命令行下由用户给出参数-e时，仍然存在“当激光雷达未完全开启时，启动会失败”的现象。
毫无疑问，设备开机的确是需要时间的。
所以在自动导航设计时，要为控制逻辑施加约束：如果激光未成功开启，则不允许依赖激光的自动导航模式开始运行。
体现在控制实现上，就是为激光雷达类添加一个状态成员，同时提供一个状态查询的公有方法，此方法用于在导航时确认激光雷达已正常工作。
