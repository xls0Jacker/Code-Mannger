# 5.1 原始类型的方法
  相较于对象，两者都可以产生方法，但原始类型更加轻量化。
  # 5.1.1   
    当作对象的原始类型：  
      7种原始类型大部分有自己的方法。
        （在使用时创建“对象包装器”，之后自我销毁）
      （注意！构造器 String/Number/Boolean 仅供内部使用，
        不建议使用 new Number(1) 或 new Boolean(false) 等语法； // 会当成 object 类型
          null/undefined 没有任何方法）
# 一些总结：https://zh.javascript.info/primitives-methods#zong-jie