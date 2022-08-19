# 2.13.1
    “while” 循环:
        while (condition) {
        // 代码
        // 所谓的“循环体”
        }
        首先检查条件，然后执行循环体。
            在 while 中的循环条件会被计算，计算结果会被转化为布尔值。
            单行循环体不需要大括号。
    “do…while” 循环:
        do {
        // 循环体
        } while (condition);
        首先执行循环体，然后检查条件。
# 2.13.2
    “for” 循环：
        for (begin; condition; step) {
        // ……循环体……
        }
        begin 执行一次，然后进行迭代：每次检查 condition 后，先执行 body 然后执行 step。
    内联变量声明：
        这样的变量只在循环中可见。（举例：for(let i=1;i<10;i++)）
    省略语句段：
        for 循环的任何语句段都可以被省略。
# 2.13.3
    跳出循环：
        可以使用 break 指令强制退出。
    继续下一次迭代：
        可以使用 continue 指令停止当前这一次迭代，并强制启动新一轮循环（如果条件允许的话）。
        （continue 指令利于减少嵌套，提高代码的可读性）
    （注意：禁止 break/continue 在 ‘?’ 的右边）//即三位运算符'?' 或 else 中
# 2.13.4
    break/continue 标签:
        标签 是在循环之前带有冒号的标识符。
        labelName: for (...) {
            ...
        }
            break <labelName> 语句跳出循环至标签处，结束标签所在循环;
            continue <labelName> 语句跳出循环至标签处，进行标签所在的当前迭代，进行下一次迭代。
        （标签并不允许“跳到”所有位置）//一般都在循环内
# 一些总结： https://zh.javascript.info/while-for#zong-jie