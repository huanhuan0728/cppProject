# 插件分类
好的，没问题！看到这个源代码目录结构，对于理解整个软件框架非常有帮助。这些文件夹的命名非常规范和清晰，这是一个很好的迹象，说明软件的模块化做得不错。

结合我们之前看过的文档，我可以从这些文件夹的名称为你推断出它们各自的功能。这会成为你探索代码的“地图”。

我将它们分门别类，这样更清晰一些：

### 1. 核心框架与视图 (Core Framework & View)
这几个项目不是插件，而是构成软件主程序的骨架，很可能采用了MVVM（Model-View-ViewModel）或者类似的架构模式。

*   **`AITF_Host_View`**: 这应该是软件的**主程序入口**，负责创建主窗口、加载插件、管理整体UI。`View`通常指用户界面层。
*   **`AITF_Host_Console`**: 可能是这个软件的**控制台版本**，没有图形界面，用于后台测试或自动化脚本执行。
*   **`AITF_Model`**: **数据模型层**。负责管理软件的核心数据和业务逻辑，独立于UI。比如产品配方、设备状态、点位数据等。
*   **`AITF_ViewModel`**: **视图模型层**。作为`View`和`Model`之间的桥梁，处理UI的逻辑，比如当用户在界面上点击按钮时，它会调用`Model`中的方法去执行操作，然后把`Model`返回的数据更新到`View`上。
*   **`AITF_PluginModel`**: 很可能是定义**插件接口的基类**或核心模型的项目。所有具体的功能插件都需要继承或实现这里定义的接口。

---

### 2. 运动控制与定位 (Motion Control & Positioning)
这些插件与文档中提到的轴运动、点位管理直接相关。

*   **`QPosPlugin`**: **点位插件**。这是实现“添加点位”功能的核心。所有常规的点位创建、保存、运动到点位等功能应该都在这里。
*   **`QMAPosPlugin`**: **多轴点位插件** (MA可能指Multi-Axis)。文档中提到了`P1AAPos`、`P1LoadPos`等多工位(PI Platform)的位置，这种复杂的、绑定了特定工位的点位管理可能由这个插件实现。
*   **`QMulitAxisPlugin`**: **多轴联动插件**。直接控制多个轴（比如PI六轴摆台）进行联动运动的底层实现。
*   **`QAxisHomePlugin`**: **轴回零插件**。对应文档中的“单轴复位”功能。
*   **`QAxisOffsetPlugin`**: **轴偏移插件**。用于设置和补偿轴的偏移量。

---

### 3. 视觉、算法与AA核心 (Vision, Algorithms & AA Core)
这是软件最核心的部分，实现了光学对位（AA）和视觉识别（PR）等功能。

*   **`AABasePlugin`**: **AA算法基础插件**。这极有可能是整个AA算法的核心，包含了计算IQA、SFR、执行对焦、逼近算法等功能。文档中大量的AA参数设置、算法选择都最终会应用到这个插件中。
*   **`QAAGrabPlugin`**: **AA图像采集插件**。`Grab`是“抓取”的意思，专门负责在AA过程中从相机采集图像。
*   **`QAAImagePlugin`**: **AA图像显示插件**。负责将AA过程中的实时图像显示在UI上。
*   **`QAAWavePlugin`**: **AA波形显示插件**。负责绘制文档中看到的IQA值随Z轴位置变化的曲线图。
*   **`QAAStepPlugin`**: **AA步骤插件**。用于实现文档中“添加AA步骤”的功能，比如Tilt校正、OC校正等，每个步骤都是一个独立的算法调用。
*   **`QTemplatePlugin`**: **模板匹配插件**。这就是文档中“添加视觉PR”功能的后台实现，负责模板的创建、匹配和定位。
*   **`QVisionDifPosPlugin`**: **视觉偏移位置插件**。对应文档“视觉到AA功能实现”一章，通过视觉PR找到的位置和目标位置进行比较，计算出需要移动的偏移量。
*   `AitEasyDTGrabFrame`: 这个名字很特别，`DT`很可能指**大恒图像(Daheng Imaging)**，一家国内知名的工业相机厂商。这个项目可能是对大恒相机SDK的一个封装，用于方便地采集图像。

---

### 4. 流程控制与硬件I/O (Workflow & Hardware I/O)
这些插件负责将上述的原子操作（如移动、拍照、算法）串联成完整的自动化流程。

*   **`QFlowPlugin`**: **流程插件**。实现“添加流程动作”的核心，通过图形化的方式编排各个功能插件的调用顺序。
*   **`QCombinationsPlugin`**: **组合动作插件**。用于创建“组合动作”按钮，一个按钮可以执行一连串预设的操作。
*   **`QCylinderPlugin`**: **气缸插件**。控制气缸的伸出和缩回，例如用在夹具、升降台或者UV灯的开关上。
*   **`QHardWarePlugin`**: **硬件插件**。可能提供一个通用的硬件控制面板，用于手动控制一些IO、轴等。
*   `QCheckportPlugin` / `QRTCheckPlugin`: **IO端口检查插件**。用于检测外部传感器信号（比如有无物料、安全门是否关闭等）。`RT`可能指Real-Time。
*   **`QGluePlugin`**: **点胶插件**。看名字是用于控制点胶阀进行点胶操作。
*   **`QDelayPlugin`**: **延时插件**。在流程中提供一个简单的等待功能。

---

### 5. UI组件与辅助工具 (UI Components & Utilities)
这些插件为软件提供UI界面元素和一些辅助功能。

*   **`QGridUiPlugin`**: **表格UI插件**。提供文档中大量出现的网格/表格界面，用于显示和配置参数。
*   **`QTabUiPlugin`**: **Tab页UI插件**。提供可配置的Tab页界面框架。
*   **`QImageViewPlugin`**: **图像显示UI插件**。通用的图像显示控件。
*   **`QMsgBoxPlugin` / `QPopupPlugin`**: **消息框/弹窗插件**。
*   **`QInputSNPlugin`**: **SN输入插件**。用于在界面上提供输入产品序列号（SN）的文本框。
*   **`QLogMsgPlugin`**: **日志信息插件**。负责在软件界面上打印运行日志，这对于调试非常重要。
*   **`QProductPlugin`**: **产品管理插件**。对应文档中的“项目切换”，用于管理和切换不同产品的配置文件。
*   **`QRecorderPosPlugin`**: **位置记录插件**。对应“记录AA位置配置”，专门用于记录和回读某个时刻的设备坐标。

**总结一下：**

你的主管让你熟悉这个框架，一个很好的切入点就是**先挑一个简单的插件**，比如 `QDelayPlugin` 或者 `QMsgBoxPlugin`，看看它是如何定义接口、如何被主程序加载、又如何被 `QFlowPlugin` 调用的。

然后，再**深入一个核心的功能性插件**，比如 `QPosPlugin`。你可以尝试在“添加点位”的功能处打断点，看看当你点击“获取当前位置”或“运动到此”时，代码是如何一步步执行到 `QPosPlugin` 里面的。

有了这份“地图”，你就可以开始你的代码探索之旅了。随时把具体的代码片段发给我，我们一起来分析！

## 为什么要加Q_DECL_OVERRIDE？
```cpp
class PluginIO : public AITF_NonSystemPluginModel
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Plugin_Interface_iid)
    Q_INTERFACES(Plugin_Interface)
public:
    PluginIO();
    ~PluginIO();

	Plugin_Interface* Clone(QString copyID, QString copyAliasName, QString copyComments) Q_DECL_OVERRIDE;

	void InitActionList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;
	void InitFunctionList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;
	void InitWidgetList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;

	int InitParaFloder(QString floder)Q_DECL_OVERRIDE;

	int Function_Home(ThreadSafeMap<QString, QVariant> & arg_out);
```
是一个由 Qt 提供的宏，它的作用等同于 C++11 标准中的 override 关键字。
在这个项目中，`Q_DECL_OVERRIDE` 是一个由 Qt 提供的宏，它的作用等同于 C++11 标准中的 `override` 关键字。

加上它的主要原因有以下两点：

1.  **编译器检查，防止错误**：
    这是最重要的原因。它告诉编译器，这个函数**意图覆盖（override）**基类中的一个同名虚函数。如果基类中没有这个虚函数，或者函数签名（参数列表、const属性等）不匹配，编译器就会报错。这可以避免很多难以发现的错误，例如：
    *   你不小心打错了函数名。
    *   基类的函数签名后来被修改了，但你没有同步修改子类的函数。

    如果没有 `Q_DECL_OVERRIDE`，这些情况不会报错，你的代码会悄悄地创建一个全新的虚函数，而不是覆盖基类的函数，导致程序在运行时出现非预期的行为（多态调用时会调用基类的版本，而不是你期望的子类版本）。

2.  **提高代码可读性**：
    它清晰地向阅读代码的人表明，这个函数是一个重写的虚函数，而不是当前类新定义的函数。这使得代码的继承关系和意图更加明确。

**总结一下：**

在 `PluginIO` 类中，像 `Clone`, `InitActionList`, `OnCoreInitialize` 等函数都是对基类 `AITF_NonSystemPluginModel` 中定义的虚函数的重写。使用 `Q_DECL_OVERRIDE` 是一种现代 C++ 的良好编程实践，它利用编译器来保证多态的正确性，让代码更健壮、更清晰。

