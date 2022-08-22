# 2.5.1
    数据类型：我们可以将任何类型的值存入变量。（动态类型）
    （在 JavaScript 中有 8 种基本的数据类型（译注：7 种原始类型和 1 种引用类型））
        1. Number 类型：
            number 类型代表整数和浮点数。（Infinity、-Infinity 和 NaN 也属于该类型）
            //NaN 代表一个计算错误。它是一个不正确的或者一个未定义的数学操作所得到的结果；
            //如果在数学表达式中有一个 NaN，会被传播到最终结果也为NaN（只有一个例外：NaN ** 0 结果为 1）。
            （在 JavaScript 中做数学运算是安全的。脚本永远不会因为一个致命的错误而停止）//最多返回NaN
            （在 JavaScript 中，“number” 类型无法安全地表示大于 (253-1)（即 9007199254740991），或小于 -(253-1) 的整数。）
        2. BigInt 类型：
            用于表示任意长度的整数。
            可以通过将 n 附加到整数字段的末尾来创建 BigInt 值。
            （目前 Firefox/Chrome/Edge/Safari 已经支持 BigInt 了，但 IE 还没有。）
        3. String 类型：
            用于表示字符串。
            在 JavaScript 中，有三种包含字符串的方式。
                双引号："Hello".
                单引号：'Hello'.
                反引号：`Hello`.
            双引号和单引号在 JavaScript 中两者几乎没有什么差别。
            反引号是 功能扩展 引号。它们允许我们通过将变量和表达式包装在 ${…} 中，来将它们嵌入到字符串中。
        4. Boolean 类型（逻辑类型）：
            用于存储表示 yes 或 no 的值。
        5. null 值：
            一个独立的类型，只包含 null 值。
            （JavaScript 中的 null 仅仅是一个代表“无”、“空”或“值未知”的特殊值。）
        6. undefined 值
            一个独立的类型，如果一个变量已被声明，但未被赋值，那么它的值就是 undefined。
            （通常将 null 给变量显示赋值，不会用 undefined 给变量显示赋值，因为这样 undefinded 就失去了其原本的意义）
        7. Object 类型和 Symbol 类型：
            object 则用于储存数据集合和更复杂的实体；
            symbol 类型用于创建对象的唯一标识符。
            （暂时放着）
        8. typeof 运算符：
            用于返回参数的类型。
            （一些特殊的返回参数的类型：
                typeof Math // "object"  (1)
                typeof null // "object"  (2) //这个是官方已经承认的错误，为了与以往的兼容性而保留
                typeof alert // "function"  (3)） //对函数区别对待
# 一些总结：https://zh.javascript.info/types#zong-jie
