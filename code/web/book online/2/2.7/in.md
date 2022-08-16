# 2.7.1
    类型转换:（暂不讨论object类型）
        //大多数情况下，运算符和函数会自动将赋予它们的值转换为正确的类型。
        1.  字符串转换：
            String(value)//显式转换
            //例如alert(value)这样的函数会 隐式 将其转换为字符串。
        2. 数字型转换：
            在算术函数和表达式中，会自动进行 number 类型转换。
            Number(value)//显式转换
            + 号转换（后期内容）
            //可参考相应的转换表格 https://zh.javascript.info/type-conversions#shu-zi-xing-zhuan-huan
        3. 布尔型转换:
            转换规则如下：
                直观上为“空”的值（如 0、空字符串、null、undefined 和 NaN）将变为 false;
                其他值变成 true。//所以，包含 0 的字符串 "0" 也是 true
            !! 转换（后期内容）
# 一些总结： https://zh.javascript.info/type-conversions#zong-jie