# 4.8 对象 —— 原始值转换：
 # 4.8.1
  转换规则：
    hint：（类型转换在各种情况下有三种变体，称为 hint）
      "string" -> 对象到字符串的转换,
      "number" -> 对象到数字的转换,
      "default" -> 在少数情况下发生，当运算符“不确定”期望值的类型时。
        为了进行转换，JavaScript 尝试查找并调用三个对象方法：
          1. 调用 obj[Symbol.toPrimitive](hint) —— 带有 symbol 键 Symbol.toPrimitive（系统 symbol）的方法，如果这个方法存在的话，
          2. 否则，如果 hint 是 "string" —— 尝试调用 obj.toString() 或 obj.valueOf()，无论哪个存在。
          3. 否则，如果 hint 是 "number" 或 "default" —— 尝试调用 obj.valueOf() 或 obj.toString()，无论哪个存在。
            Symbol.toPrimitive：
              obj[Symbol.toPrimitive] = function(hint) {
                // 这里是将此对象转换为原始值的代码
                // 它必须返回一个原始值（否则报 Error）
                // hint = "string"、"number" 或 "default" 中的一个
              }
            toString/valueOf：（如果没有 Symbol.toPrimitive）
              对于 "string" hint：调用 toString 方法，如果它不存在，则调用 valueOf 方法（因此，对于字符串转换，优先调用 toString）。
              对于其他 hint：调用 valueOf 方法，如果它不存在，则调用 toString 方法（因此，对于数学运算，优先调用 valueOf 方法）。
 # 4.8.2
  转换可以返回任何原始类型。
    （注意！以上方法必须返回一个原始值，而不是对象。）
 # 4.8.3
  进一步的转换：
    经过 hint 转换回来的对象可以继续完成常规的类型转换。
# 一些总结： https://zh.javascript.info/object-toprimitive#zong-jie



