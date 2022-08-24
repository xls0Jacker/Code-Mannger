# 4.7 symbol 类型：
  根据规范，只有两种原始类型可以用作对象属性键：
    字符串类型 //其余原始类型会转变为字符串
    symbol 类型
  # 4.7.1
    symbol：
      “symbol” 值表示唯一的标识符。
      //let id = Symbol(); （其括号内可以添加 描述）
      （注意！symbol 不会被自动转换为字符串
        //可以使用 toString() 函数或者 .description 获得其描述）
  # 4.7.2
    “隐藏”属性：？
      symbol 允许我们创建对象的“隐藏”属性，代码的任何其他部分都不能意外访问或重写这些属性。
        *对象字面量中的 symbol：
          如果我们要在对象字面量 {...} 中使用 symbol，则需要使用方括号把它括起来。
        *symbol 在 for…in 中会被跳过：
          symbol 属性不参与 for..in 循环。
          （注：Object.assign 会同时复制字符串和 symbol 属性）
  # 4.7.3
    全局 symbol：
      若需要应用程序的不同部分想要访问的 symbol "id" 指的是完全相同的属性，
        可以使用Symbol.for(key) //当其不存在时会被创立并生效（其返回的是 Symbol ）
      Symbol.keyFor(sym)：
        用于返回一对象内 Symbol 的名字。// 非全局 Symbol 返回 undefined
  # 4.7.4
    系统 symbol；
      avaScript 内部有很多“系统” symbol，我们可以使用它们来微调对象的各个方面。
      Symbol 相关规范：https://tc39.github.io/ecma262/#sec-well-known-symbols
        （点进去后搜 Symbol 找. 后缀项目）
# 一些总结： https://zh.javascript.info/symbol#zong-jie