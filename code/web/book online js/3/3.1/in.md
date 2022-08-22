# 3.1 在浏览器中调试：
    调试 是指在一个脚本中找出并修复错误的过程。所有的现代浏览器和大多数其他环境都支持调试工具 —— 开发者工具中的一个令调试更加容易的特殊用户界面。它也可以让我们一步步地跟踪代码以查看当前实际运行情况。
# 3.1.1 
    “资源（Sources）”面板：
        即对应Edge的 源代码 部分。
        其分为3个部分：
            1. 文件导航（File Navigator）
            2. 代码编辑（Code Editor） 
            3. JavaScript 调试（JavaScript Debugging）
# 3.1.2 
    控制台（Console）：
        如果我们按下 Esc，下面会出现一个控制台，我们可以输入一些命令然后按下 Enter 来执行。// shift + Enter 键可以用于多行输入
        语句执行完毕之后，其执行结果会显示在下面。
# 3.1.3
    断点（Breakpoints）：
        断点 是调试器会自动暂停 JavaScript 执行的地方。
        （条件断点：在行号上 右键单击 允许你创建一个 条件断点。只有当给定的表达式（你创建条件断点时提供的表达式）为真时才会被触发。）
# 3.1.4
    “debugger” 命令：
        也可以使用 debugger 命令来暂停代码。//debugger;
# 3.1.5
    暂停并查看：
        1. 察看（Watch） —— 显示任意表达式的当前值。
        2. 调用栈（Call Stack） —— 显示嵌套的调用链。
        3. 作用域（Scope） —— 显示当前的变量。
# 3.1.6
    跟踪执行：  
        由于部分符号不好表示，详细见链接：https://zh.javascript.info/debugging-chrome#gen-zong-zhi-hang
# 3.1.7
    日志记录：
        可以通过 console.log 函数输出到控制台。
# 一些总结： https://zh.javascript.info/debugging-chrome#zong-jie