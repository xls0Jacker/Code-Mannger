# 5.3 字符串
  # 5.3.1 
    引号（Quotes）：
      回顾：  
        字符串可以包含在单引号、双引号或反引号中。
          单引号和双引号基本相同。
            反引号允许我们通过 ${…} 将任何表达式嵌入到字符串中。
            Ex 反引号允许字符串跨行。
              （反引号还允许我们在第一个反引号之前指定一个“模版函数”。语法是：func`string`）
  # 5.3.2
    特殊字符：（其认为为一个字符）
      完整特殊字符列表链接：
  # https://zh.javascript.info/string#te-shu-zi-fu
  （注：注意反斜杠 \ 在 JavaScript 中用于正确读取字符串，然后消失。内存中的字符串没有 \
    显示一个实际的反斜杠 \ 需要将其书写两次）
  # 5.3.3
    字符串长度：  
      length 属性表示字符串长度；
      （注： str.length 是一个数字属性，而不是函数。后面需不要添加括号）
  # 5.3.4
    访问字符：  
      要获取在 pos 位置的一个字符，可以使用方括号 [pos] 或者调用 str.charAt(pos) 方法。 // 第一个字符从零位置开始
      （注：如果没有找到字符，[] 返回 undefined，而 charAt 返回一个空字符串）
      // 也可以使用 for..of 遍历字符
  # 5.3.5
    字符串是不可变的：
      在 JavaScript 中，字符串不可更改。改变字符是不可能的。
        通常的解决方法是创建一个新的字符串，并将其分配给 str 而不是以前的字符串。
  # 5.3.6
    改变大小写；
      toLowerCase() 和 toUpperCase() 方法可以改变大小写。
  # 5.3.7
    查找子字符串；  
      str.indexOf(substr, pos)：
        它从给定位置 pos 开始，在 str 中查找 substr，如果没有找到，则返回 -1，否则返回匹配成功的位置。
      str.lastIndexOf(substr, pos)：
        与上面的方法方向相反从字符串的末尾开始搜索到开头。
      Ex 按位（bitwise）NOT 技巧：  
        ~ 运算符。
          它将数字转换为 32-bit 整数（如果存在小数部分，则删除小数部分），然后对其二进制表示形式中的所有位均取反。
            对于 32-bit 整数，~n 等于 -(n+1)。
            （现在我们只会在旧的代码中看到这个技巧，因为 JavaScript 提供了新的技巧如下：）
        includes，startsWith，endsWith：
          str.includes(substr, pos) 根据 str 中是否包含 substr 来返回 true/false。
          startsWith，endsWith即是判断开始的字符串和结尾的字符串是否与 substr 相同。
  # 5.3.8
    获取子字符串：  
      str.slice(start [, end])：
        返回字符串从 start 到（但不包括）end 的部分。（如果没有第二个参数，slice 会一直运行到字符串末尾）
        // start/end 也有可能是负值。它们的意思是起始位置从字符串结尾计算
      str.substring(start [, end])：
        返回字符串从 start 到（但不包括）end 的部分。
        // 与 slice 相比较，它允许 start 大于 end；
          // 且 不支持负参数，它们被视为 0
      str.substr(start [, length])：  
        返回字符串从 start 开始的给定 length 的部分。
        // 第一个参数可能是负数，从结尾算起
    使用哪一个？：  
      仅仅记住这三种方法中的 slice 就足够了。
  # 5.3.9
    比较字符串：  
      回顾：
  # https://zh.javascript.info/comparison#zi-fu-chuan-bi-jiao
      除此之外，我们发现：
        1. 小写字母总是大于大写字母；
        2. 带变音符号的字母存在“乱序”的情况
      故有方法解释该问题：
        str.codePointAt(pos)：// 正
          返回在 pos 位置的字符代码
        String.fromCodePoint(code)：// 反
          通过数字 code 创建字符
      正确的比较：  
        调用 str.localeCompare(str2) 会根据语言规则返回一个整数：
          如果 str 排在 str2 前面，则返回负数；
          如果 str 排在 str2 后面，则返回正数；
          如果它们在相同位置，则返回 0。
  # 5.3.10
    内部，Unicode： 
      代理对：
        所有常用的字符都是一个 2 字节的代码。
          稀有的符号被称为“代理对”的一对 2 字节的符号编码。// 注意是“一对”
          （注：代理对的各部分没有任何意义）
      变音符号与规范化：  
        在许多语言中，都有一些由基本字符组成的符号，在其上方/下方有一个标记。
        为了支持任意组合，UTF-16 允许我们使用多个 Unicode 字符：基本字符紧跟“装饰”它的一个或多个“标记”字符。
          故 两个视觉上看起来相同的字符，可以用不同的 Unicode 组合表示。
            为了解决这个问题，有一个 “Unicode 规范化”算法，它将每个字符串都转化成单个“通用”格式。
             str.normalize() //具体我也不懂
# 一些总结：https://zh.javascript.info/string#zong-jie

