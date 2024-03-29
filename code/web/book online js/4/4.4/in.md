# 4.4 对象方法，"this"：
# 4.4.1
  方法示例：  
    作为对象属性的函数被称为 方法。
    （当然可以使用 函数表达式 和 函数声明 两种方式进行实现）
    面向对象编程：
      当我们在代码中用对象表示实体时，就是所谓的 面向对象编程，简称为 “OOP”。
# 4.4.2
  方法简写：
    示例：
      sayHi() {...}// 与 "sayHi: function(){...}" 一样
# 4.4.3
  方法中的 “this”：
    通常，对象方法需要访问对象中存储的信息才能完成其工作。
      为了访问该对象，方法中可以使用 this 关键字。
# 4.4.4
  “this” 不受限制：
    在 JavaScript 中，this 关键字与其他大多数编程语言中的不同。JavaScript 中的 this 可以用于任何函数，即使它不是对象的方法。
      在函数中 this 的值是在代码运行时计算出来的，它取决于代码上下文。// 若上下文中未对 this 做任何解释，其值为 undefined
      （在 JavaScript 中，this 是“自由”的，它的值是在调用时计算出来的，它的值并不取决于方法声明的位置，而是取决于在“点符号前”的是什么对象。）
# 4.4.5
  箭头函数没有自己的 “this”：
    它们没有自己的 this。如果我们在这样的函数中引用 this，this 值取决于外部“正常的”函数。
# 一些总结： https://zh.javascript.info/object-methods#zong-jie