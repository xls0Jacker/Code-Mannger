# 2.4.1
    变量：使用 let 关键字，与C语言用法基本相同。
    （var 关键字 != let 关键字，var 关键字是较老的脚本中的关键字）
    （同样，不能重复声明）
# 2.4.2
    变量命名：与C语言规范基本相同。
    /*  1. 变量名称必须仅包含字母、数字、符号 $ 和 _。 
        2.首字符必须非数字。*/
    （如果命名包括多个单词，通常采用驼峰式命名法（camelCase）。
        也就是，单词一个接一个，除了第一个单词，其他的每个单词都以大写字母开头，myVeryLongName）
    （同样区分大小写 及 不能命名保留字）
    （可以使用非英文字母）
# 2.4.3
    常量：使用 const 关键字，与C语言用法基本相同。
    （一个普遍的做法是将常量用作别名，以便记住那些在执行之前就已知的难以记住的值 或者 初始赋值后不再改变。）//或者自己懒得敲 如：const INF=1e9+7;
    //换句话说，大写命名的常量仅用作“硬编码（hard-coded）”值的别名。
# 2.4.4
    正确命名变量：
        一些可以遵循的规则：
            1.使用易读的命名，比如 userName 或者 shoppingCart。
            2.离诸如 a、b、c 这种缩写和短名称远一点，除非你真的知道你在干什么。
            3.变量名在能够准确描述变量的同时要足够简洁。不好的例子就是 data 和 value，这样的名称等于什么都没说。如果能够非常明显地从上下文知道数据 值所表达的含义，这样使用它们也是可以的。
            4.脑海中的术语要和团队保持一致。如果网站的访客称为“用户”，则我们采用相关的变量命名，比如 currentUser 或者 newUser，而不要使用 currentVisitor 或者一个 newManInTown。
            （重用还是新建？：额外声明一个变量绝对是利大于弊的。）
# 一些总结： https://zh.javascript.info/variables#zong-jie
