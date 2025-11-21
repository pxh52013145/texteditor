# 实验2：简单文本编辑器

## 一、实验目标
- 掌握混合式UI设计的方法
- 掌握工具栏的创建和使用，会利用Action来添加工具和菜单
- 掌握多窗口应用程序设计的基本原理和方法
- 掌握文本文件的读写操作

## 二、实验条件
- 系统：Windows 64位
- 软件：Qt 5.12.11，Git
- 参考资料：
- https://segmentfault.com/a/1190000018507340
- http://www.codebind.com/cpp-tutorial/qt-tutorials-for-beginners-simple-notepad-application/
- https://doc.qt.io/qt-5/qtwidgets-widgets-codeeditor-example.html

## 三、实验内容
- 设计一个多窗口的文本编辑器（支持新建窗口）
- 使用 UI 设计器完成界面及属性设置，利用 Action 编辑器设计菜单栏与工具栏，按功能分组
- 支持文件打开、保存、另存为、打印
- 文本编辑器支持自动换行开关
- 菜单/工具按钮完成：打开、保存、另存为、剪切、复制、粘贴、设置字体与字体颜色、显示/关闭行号、打开/关闭自动换行
- 支持撤销与重做
- 支持编辑器背景色修改与字体背景色（整篇）设置
- 窗口标题随文档修改状态自动加“*”
- 支持显示行号（选做）
- 支持定时自动保存（选做，间隔 60s）

## 四、实验步骤及结果
- UI界面布局与设计：`mainwindow.ui` 使用自定义部件 `CodeEditor` 作为中心组件；菜单和工具栏分组完成
- 设计关于对话框：`on_actionAbout_triggered()` 显示实验信息
- 设计查找对话框：`FindDialog` 支持向上/向下查找与大小写匹配
- 设计替换对话框：`ReplaceDialog` 支持单次替换与全部替换
- 文件操作：新建、打开、保存、另存为、打印功能齐备
- 编辑操作：撤销、恢复、剪切、复制、粘贴、全选；按钮使能随内容变化
- 格式操作：字体、字体颜色、字体背景色、编辑器背景色、自动换行
- 视图操作：显示/隐藏工具栏、状态栏；状态栏显示行列与行号状态
- 行号显示：`CodeEditor` 左侧绘制行号，菜单可开关
- 自动保存：勾选后每 60s 自动保存（仅对已命名且被修改的文件）

## 关键代码位置
- `c:\Users\31625\Desktop\QT课程\Code\LAB2\codeeditor.h/.cpp` 行号绘制与当前行高亮
- `c:\Users\31625\Desktop\QT课程\Code\LAB2\mainwindow.h/.cpp` 主窗口、菜单/工具栏逻辑、状态栏、文件与编辑操作
- `c:\Users\31625\Desktop\QT课程\Code\LAB2\finddialog.*` 查找对话框
- `c:\Users\31625\Desktop\QT课程\Code\LAB2\replacedialog.*` 替换对话框
- `c:\Users\31625\Desktop\QT课程\Code\LAB2\mainwindow.ui` UI 布局与 Action

## 五、Github日志
- 请在本地提交与实验2相关的开发记录，并推送至仓库。建议包含：初始化项目、加入 CodeEditor、实现文件与编辑功能、加入查找替换、行号与自动保存、最终整理。

## 六、测试结果
- 录制测试视频演示：菜单与工具栏操作、文件读写、查找替换、行号与自动换行开关、状态栏联动、自动保存。

## 七、实验总结
- 问题1：`QPlainTextEdit` 不支持 `setTextColor`。解决：通过 `QPalette::Text` 设置全局文本颜色。
- 问题2：`.ui` 自定义部件需在 `<customwidgets>` 根级声明，且 `QMenuBar` 中先定义菜单再 `addaction`。调整结构后 UIC 生成正常。
- 总结：通过 UI 设计器与自定义控件结合，实现了一个结构清晰、功能完善的文本编辑器，掌握了 Qt 菜单/工具栏/对话框/文档操作与绘制扩展。