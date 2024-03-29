# 4.6 可选链 "?."： 
  可选链 ?. 是一种访问嵌套对象属性的安全的方式。即使中间的属性不存在，也不会出现错误。
  # 4.6.1
    “不存在的属性”的问题：
      当尝试获取一个 不存在的属性的对象时，会返回 Error 而不是 undefined。
      //还有其他情况 暂时不提
  # 4.6.2
    可选链： 
      如果可选链 ?. 前面的值为 undefined 或者 null，它会停止运算并返回 undefined。
      //  ?. 前的变量必须已声明
      （注：即使 对象 user 不存在，使用 user?.address 来读取地址也没问题）
        不要过度使用可选链：
          我们应该只将 ?. 使用在一些东西可以不存在的地方。// 否则之后自己找不到错误
  # 4.6.3
    短路效应：
      正如前面所说的，如果 ?. 左边部分不存在，就会立即停止运算（“短路效应”）。// 后面内容一概不生效
  # 4.6.4
    其它变体：?.()，?.[]：
      ?.() 用于调用一个可能不存在的函数。
      ?.[] 可以从一个可能不存在的对象上安全地读取属性。
      Ex 此外，我们还可以将 ?. 跟 delete 一起使用// 存在该对象则删除
      （注：我们可以使用 ?. 来安全地读取或删除，但不能写入）
# 一些总结： https://zh.javascript.info/optional-chaining#zong-jie