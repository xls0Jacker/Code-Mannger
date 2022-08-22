# 2.12.1
    空值合并运算符 '??':
        当一个值既不是 null 也不是 undefined 时，我们将其称为“已定义的（defined）”。（自定义概念）
            a ?? b 的结果是：
            如果 a 是已定义的，则结果为 a， 
            如果 a 不是已定义的，则结果为 b。
            （result = a ?? b <=> result = (a !== null && a !== undefined) ? a : b;）
        与 || 比较：
            || 无法区分 false、0、空字符串 "" 和 null/undefined。（寻找第一个真值）
            || 和 ?? 的优先级均为4级
            （JavaScript 禁止将 ?? 运算符与 && 和 || 运算符一起使用，除非使用括号明确指定了优先级。）
#  一些总结： https://zh.javascript.info/nullish-coalescing-operator#zong-jie