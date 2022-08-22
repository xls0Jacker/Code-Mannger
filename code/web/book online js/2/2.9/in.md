# 2.9.1
    值的比较：
        1. 比较结果为 Boolean 类型。
        2. 字符串比较为按照字典序比较（实际为Unicode编码进行比较）
            什么是按字典序比较？：
                https://zh.javascript.info/comparison#zi-fu-chuan-bi-jiao
        3. 不同类型间的比较：
            当对 不同类型 的值进行比较时，JavaScript 会首先将其转化为数字（number）再判定大小。
        4. 严格相等：
            <!-- 严格相等运算符 === 在进行比较时不会做任何的类型转换。/“严格不相等”表示为 !== 
        5. 对 null 和 undefined 进行比较：
            当使用非严格相等 == 比较二者时，结果为true。//JavaScript中的特殊规则
            undefined 和 null 在相等性检查 == 中不会进行任何的类型转换。
# 2.9.2 
    避免问题：
        1. 除了严格相等 === 外，其他但凡是有 undefined/null 参与的比较，我们都需要格外小心。
        2. 除非你非常清楚自己在做什么，否则永远不要使用 >= > < <= 去比较一个可能为 null/undefined 的变量。
            对于取值可能是 null/undefined 的变量，请按需要分别检查它的取值情况。
# 一些总结： https://zh.javascript.info/comparison#zong-jie